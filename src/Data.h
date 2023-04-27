#pragma once
#include "pch.h"

namespace Player::Data {
	struct MusicInfo {
		using String = winrt::hstring;
		String title;
		String album;
		String genre;
		String artist;
		String albumartist;
		String path;
		long long duration;
        int32_t year;
		uint32_t bitrate;
		uint32_t track;
	};
	struct PlayList {
		using String = std::wstring;
		String name;
		std::vector<MusicInfo> list;
	};
	struct Library {
		enum class Protocol {
			Local, Samba, WebDAV, FTP
		};
		using String = std::wstring;
		String name;
		Protocol procotol;
		String path;
		String Icon;
	};
	using Equalizer = std::array<int8_t, 10>;

	auto sample{ R"(
{
    "library":[
        {
            "name":"system",
            "list":[{
                "title":"",
                "album":"",
                "genre":"",
                "artist":"",
                "albumartist":"",
                "year":"",
                "path":"",
                "duration":0,
                "bitrate":0,
                "track":0,
                "samplerate":0,
                "cd":0
            }
            ]
        },
        {
            "name":"xxxx",
            "list":[

            ]
        }
    ],
    "current":{
        "library":"",
        "path":"",
        "index":0,
        "list":[

        ]
    }
}
)" };
}