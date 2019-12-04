//
// GridSIPControl.xaml.h
// Declaration of the GridSIPControl class
//

#pragma once

#include "GridSIPControl.g.h"
#include "Views/GraphingCalculator/EquationInputArea.xaml.h"
#include "Views\NumberPad.xaml.h"

namespace CalculatorApp
{
    namespace Controls
    {
        [Windows::Foundation::Metadata::WebHostHidden] public ref class GridSIPControl sealed
        {
        public:
            GridSIPControl();

            property EquationInputArea ^ TargetEIA {

                EquationInputArea^ get() { return m_targetEIA; }

                void set(EquationInputArea ^ value);
            }
        private:
            EquationInputArea ^ m_targetEIA;
            void ButtonClick(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
        };
    }
}
