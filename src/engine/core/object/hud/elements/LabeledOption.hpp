#pragma once

#include "../../HudObject.hpp"
#include "../../../../DEFINITIONS.hpp"

namespace Gengine {
    class LabeledOption : public HudObject {
        public:
            LabeledOption() {};
            LabeledOption(GameComponentsRef& data) : HudObject(data) {};
            ~LabeledOption() {};
    };
}