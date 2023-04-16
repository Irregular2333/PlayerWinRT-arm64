#pragma once

#include "EditLibrary.g.h"

namespace winrt::Player::implementation
{
    struct EditLibrary : EditLibraryT<EditLibrary>
    {
        EditLibrary();
    };
}

namespace winrt::Player::factory_implementation
{
    struct EditLibrary : EditLibraryT<EditLibrary, implementation::EditLibrary>
    {
    };
}
