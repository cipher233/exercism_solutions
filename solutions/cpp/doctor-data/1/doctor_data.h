// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

#pragma once

#include <string>

namespace star_map {

enum class System {
    BetaHydri,
    Sol,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani,
};
    
}

namespace heaven {

class Vessel {
    public:
        Vessel() = default;
        Vessel(std::string name): m_name{name}{}
        Vessel(std::string name, int g): m_name{name}, generation{g} {}
        Vessel(std::string name, int g, star_map::System sys): m_name{name}, generation{g}, current_system{sys} {}
    
        Vessel replicate(std::string name) const;
        void make_buster();
        bool shoot_buster();
        
    public:
        std::string m_name{};
        int generation{};
        star_map::System current_system{star_map::System::Sol}; 
        int busters{};
};

std::string get_older_bob(const Vessel &a, const Vessel &b);
bool in_the_same_system(const Vessel &a, const Vessel &b);
    
}

