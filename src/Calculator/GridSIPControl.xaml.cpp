//
// GridSIPControl.xaml.cpp
// Implementation of the GridSIPControl class
//

#include "pch.h"
#include "GridSIPControl.xaml.h"
#include "Controls/CalculatorButton.h"

using namespace CalculatorApp;
using namespace CalculatorApp::Controls;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

GridSIPControl::GridSIPControl()
{
    InitializeComponent();
}

void GridSIPControl::TargetEIA::set(EquationInputArea ^ value)
{
    m_targetEIA = value;
    NumberPad->TargetEIA = value;
}

void GridSIPControl::ButtonClick(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e)
{
    std::wstring newString;

    Controls::CalculatorButton ^ button = safe_cast<Controls::CalculatorButton ^>(sender);
    auto cont = button->Content;

    TextBlock ^ tb = dynamic_cast<TextBlock ^>(cont);
    String ^ newText = dynamic_cast<String ^>(cont);
    if (tb != nullptr)
    {
        newString = tb->Text->Data();
    }
  /*  {
        wchar_t* t = dynamic_cast<wchar_t*>(cont);
        if (t != nullptr)
        {
            newString = t;
        }
    }*/

    // String ^ newText = ref new String(newString.c_str());

    m_targetEIA->ETB->InsertText(newText);
}
