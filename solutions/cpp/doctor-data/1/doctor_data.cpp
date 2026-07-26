// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#include "doctor_data.h"



heaven::Vessel heaven::Vessel::replicate(std::string name) const {
    return heaven::Vessel(name, this->generation + 1, this->current_system);
}

void heaven::Vessel::make_buster() {
    ++busters;
}

bool heaven::Vessel::shoot_buster() {
    if (busters > 0) {
        --busters;
        return true;
    }
    return false;   
}

std::string heaven::get_older_bob(const heaven::Vessel &a, const heaven::Vessel &b) {
    return a.generation < b.generation ? a.m_name : b.m_name;
}

bool heaven::in_the_same_system(const heaven::Vessel &a, const heaven::Vessel &b) {
    return a.current_system == b.current_system;
}