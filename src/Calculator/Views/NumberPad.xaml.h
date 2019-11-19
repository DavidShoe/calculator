// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

//
// NumberPad.xaml.h
// Declaration of the NumberPad class
//

#pragma once

#include "Views/NumberPad.g.h"
#include "CalcViewModel/Common/KeyboardShortcutManager.h"
#include "Views/GraphingCalculator/EquationInputArea.xaml.h"

namespace CalculatorApp
{
    [Windows::Foundation::Metadata::WebHostHidden] public ref class NumberPad sealed
    {
    public:
        NumberPad();
        DEPENDENCY_PROPERTY_OWNER(NumberPad);

        DEPENDENCY_PROPERTY(Windows::UI::Xaml::Style ^, ButtonStyle);

        property bool IsErrorVisualState
        {
            bool get();
            void set(bool value);
        }

        void ProgModeRadixChange();

        property EquationInputArea ^ TargetEIA
        {
            EquationInputArea^ get()
            {
                return m_targetEIA;
            }

            void set(EquationInputArea ^ value)
            {
                m_targetEIA = value;
            }
        }

    private:
        bool m_isErrorVisualState;
        EquationInputArea ^ m_targetEIA;
        void ButtonClick(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
        void OnDataContextChanged(Windows::UI::Xaml::FrameworkElement ^ sender, Windows::UI::Xaml::DataContextChangedEventArgs ^ args);
    };
}
