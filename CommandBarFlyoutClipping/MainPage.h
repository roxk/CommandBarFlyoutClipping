#pragma once

#include "MainPage.g.h"

namespace winrt::CommandBarFlyoutClipping::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
        void commandBarFlyout_Opened(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& e);
    private:
        Windows::Foundation::IAsyncAction AppendCommand();
    };
}

namespace winrt::CommandBarFlyoutClipping::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
