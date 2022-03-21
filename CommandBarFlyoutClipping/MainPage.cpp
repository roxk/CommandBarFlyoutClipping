#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <winrt/Windows.UI.Core.h>
#include <chrono>

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace std::chrono_literals;

namespace winrt::CommandBarFlyoutClipping::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
    }
}


void winrt::CommandBarFlyoutClipping::implementation::MainPage::commandBarFlyout_Opened(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& e)
{
    const auto defaultCount = 2;
    if (commandBarFlyout().SecondaryCommands().Size() > defaultCount)
    {
        commandBarFlyout().SecondaryCommands().RemoveAtEnd();
    }
    AppendCommand();
}

Windows::Foundation::IAsyncAction winrt::CommandBarFlyoutClipping::implementation::MainPage::AppendCommand()
{
    co_await 1s;
    co_await resume_foreground(Dispatcher());
    AppBarButton button;
    button.Label(L"Dynamic loooooooooooooooooooooooong name");
    commandBarFlyout().SecondaryCommands().Append(button);
}
