#pragma once

#include "NowPlaying.g.h"

namespace winrt::Player::implementation
{
    struct NowPlaying: NowPlayingT<NowPlaying>
    {
        NowPlaying();

    private:
        // data from rootpage
        winrt::Player::PlayerViewModel player_view_model{ nullptr };
        winrt::Windows::Media::Playback::MediaPlaybackList play_list_{ nullptr };
        winrt::Windows::Foundation::Collections::IVector<winrt::Data::Music> info_list_{ nullptr };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::Windows::Media::Playback::MediaPlaybackItem> music_list_{ nullptr };
        // runtime prop
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::Player::InfoViewModel> music_view_{ winrt::single_threaded_observable_vector<winrt::Player::InfoViewModel>() };
    };
}

namespace winrt::Player::factory_implementation
{
    struct NowPlaying: NowPlayingT<NowPlaying, implementation::NowPlaying>
    {
    };
}
