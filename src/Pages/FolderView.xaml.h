#pragma once

#include "FolderView.g.h"

namespace winrt::Player::implementation
{
    struct FolderView: FolderViewT<FolderView>
    {
        FolderView();

        // binding helpers
        static winrt::hstring TransformBitrate(uint32_t);
        static winrt::hstring TransformDuration(int64_t);
        winrt::hstring CalculateTrueFolderCount(uint32_t);
        static winrt::hstring DecisionTitle(winrt::hstring const&, winrt::hstring const&);
        static const winrt::hstring& DecisionArtist(winrt::hstring const&, winrt::hstring const&);
        // runtime properties
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> FolderList();
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::Player::InfoViewModel> MusicList();
        // event handlers
        winrt::Windows::Foundation::IAsyncAction OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const&);

    private:
        // data for private use
        std::vector<winrt::hstring> path_stack_;
        std::vector<winrt::Data::Music> whole_library;
        std::vector<std::vector<std::reference_wrapper<const winrt::Data::Music>>> folders_stack_;

        // data from root page
        winrt::Data::Library library_{};
        winrt::Player::PlayerViewModel player_view_model_{ nullptr };
        winrt::Windows::Media::Playback::MediaPlaybackList play_list_{ nullptr };
        winrt::Windows::Foundation::Collections::IVector<winrt::Data::Music> info_list_{ nullptr };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::Windows::Media::Playback::MediaPlaybackItem> music_list_{ nullptr };

        // UI helpers
        void Build();
        void Rebuild();
        void BuildRoot();
        void UpdateUI(std::vector<winrt::hstring> const&, std::vector<winrt::Player::InfoViewModel> const&);

        // runtime properties implement
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> folders_view_{ winrt::single_threaded_observable_vector<winrt::hstring>() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::Player::InfoViewModel> music_view_{ winrt::single_threaded_observable_vector<winrt::Player::InfoViewModel>() };
    };
}

namespace winrt::Player::factory_implementation
{
    struct FolderView: FolderViewT<FolderView, implementation::FolderView>
    {
    };
}
