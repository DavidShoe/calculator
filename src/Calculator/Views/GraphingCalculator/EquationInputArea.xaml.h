#pragma once

#include "Views/GraphingCalculator/EquationInputArea.g.h"
#include "CalcViewModel/Common/Utils.h"
#include "CalcViewModel/GraphingCalculator/EquationViewModel.h"
#include "EquationStylePanelControl.xaml.h"
#include "CalcViewModel/Common/KeyboardShortcutManager.h"
#include "Controls/EquationTextBox.h"

namespace CalculatorApp
{
public
    ref class EquationInputArea sealed : public Windows::UI::Xaml::Data::INotifyPropertyChanged
    {
    public:
        EquationInputArea();

        OBSERVABLE_OBJECT_CALLBACK(OnPropertyChanged);
        OBSERVABLE_PROPERTY_RW(Windows::Foundation::Collections::IObservableVector<ViewModel::EquationViewModel ^> ^, Equations);

        property Controls::EquationTextBox^ ETB
        {
            Controls::EquationTextBox ^ get() {
                return m_EquationTextBox;
            }
        }

    private:
        void OnPropertyChanged(Platform::String ^ propertyName);
        void OnEquationsPropertyChanged();

        void AddEquationButton_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
        void AddNewEquation();

        void InputTextBox_GotFocus(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
        void InputTextBox_LostFocus(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
        void InputTextBox_Submitted(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);

    private:
        int m_lastLineColorIndex;
        Controls::EquationTextBox ^ m_EquationTextBox;
        void EquationTextBox_RemoveButtonClicked(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
        void EquationTextBoxLoaded(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
    };
}
