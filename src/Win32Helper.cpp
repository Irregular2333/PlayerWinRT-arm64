#include "pch.h"
#include "Win32Helper.h"

namespace Win32Helper {
    /// <summary>
    /// Make app only has one instance
    /// call at entry point
    /// </summary>
    /// <param name="appname">size lesser than 16, zero ending</param>
    /// <param name="exitcode">exit code</param>
    void DisableMultiInstanceEntry(std::wstring_view const appname, UINT const exitcode) {
        using namespace std::literals;
        auto const max_size{ 16 };
        assert(appname.size() < max_size);
        // use user's temp folder pathname + appname as part of mutex name
        // name buffer, initialized to be zero
        auto name{ std::to_array<wchar_t, (MAX_PATH + 2) + max_size>({}) };
        // get tmp folder path, not guaranteed availablity
        auto length{ ::GetTempPathW(static_cast<DWORD>(name.size()), &name[0]) };
        // append appname to path
        std::memcpy(&name[length], appname.data(), appname.size() * sizeof(wchar_t));
        // mutex name can't contain '\'
        std::replace(&name[0], &name[length], '\\', '/');
        // if mutex is held by another instance, NO NEED TO USE GetLastError
        if (!::CreateMutexExW(nullptr, &name[0], CREATE_MUTEX_INITIAL_OWNER, NULL)) [[likely]] {
            // enumerate all direct child windows of desktop
            for (auto pre{ ::FindWindowExW(nullptr, nullptr, nullptr, nullptr) };
                // return null if at the end
                pre != nullptr;
                // pass the pre as the 2nd argument to get next handle
                pre = ::FindWindowExW(nullptr, pre, nullptr, nullptr)) [[likely]]
            {
                // check if window_ has the specified property
                // set in MainWindow constructor
                if (::GetPropW(pre, appname.data())) [[unlikely]] {
                    // show and restore window_
                    ::ShowWindow(pre, SW_RESTORE);
                    // activate, set foreground and get forcus
                    ::SetForegroundWindow(pre);
                }
            }
            ::ExitProcess(exitcode);
        }
    }

    /// warp ::GetDpiForMonitor
    UINT GetDpiXForMonitor(HMONITOR hmonitor) {
        auto dpiX{ UINT{} };
        auto dpiY{ UINT{} };
#pragma comment(lib, "Shcore.lib")
        ::GetDpiForMonitor(hmonitor, MDT_DEFAULT, &dpiX, &dpiY);
        return dpiX;
    }
    HWND GetHandleFromWindow(winrt::Microsoft::UI::Xaml::Window const& window) {
        auto hWnd{ HWND{} };
        window.as<::IWindowNative>()->get_WindowHandle(&hWnd);
        return hWnd;
    }
    winrt::Microsoft::UI::WindowId GetWindowIdFromWindow(winrt::Microsoft::UI::Xaml::Window const& window) {
        return winrt::Microsoft::UI::GetWindowIdFromWindow(GetHandleFromWindow(window));
    }
    /// <summary>
    /// Make app only has one instance
    /// call at window_ initialized
    /// </summary>
    /// <param name="appname">size lesser than 16</param>
    /// <param name="handle">handle of window_</param>
    void DisableMultiInstanceWindow(winrt::Microsoft::UI::Xaml::Window const& window, std::wstring_view const appname) {
        auto handle{ GetHandleFromWindow(window) };
        ::SetPropW(handle, appname.data(), handle);
    }
    double GetScaleAdjustment(winrt::Microsoft::UI::Xaml::Window const& window) {
        auto dpiX{ ::GetDpiForWindow(GetHandleFromWindow(window)) };
        auto scaleFactorPercent{ (dpiX * 100 + (96 >> 1)) / 96 };
        return scaleFactorPercent / 100.;
    }
    std::atomic<uintptr_t> old_proc;
    LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        auto scaleFactor(::GetDpiForWindow(hWnd));
        if (WM_GETMINMAXINFO == uMsg) {
            reinterpret_cast<MINMAXINFO*>(lParam)->ptMinTrackSize.x = (362 * scaleFactor * 100 + (96 >> 1)) / 9600;
            reinterpret_cast<MINMAXINFO*>(lParam)->ptMinTrackSize.y = (170 * scaleFactor * 100 + (96 >> 1)) / 9600;
        }
        return ::CallWindowProcW(reinterpret_cast<WNDPROC>(old_proc.load(std::memory_order_acquire)), hWnd, uMsg, wParam, lParam);
    }
    void RegisterWindowMinWidth(winrt::Microsoft::UI::Xaml::Window const& window) {
        old_proc.store(
            ::SetWindowLongPtrW(GetHandleFromWindow(window), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&WindowProc)),
            std::memory_order_release);
    }
}
