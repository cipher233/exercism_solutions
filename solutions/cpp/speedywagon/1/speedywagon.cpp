#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    if (data_array == nullptr || data_array->empty()) {
        return 0; // 💡 判空，防止解引用空指针或除以 0
    }
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool connection_check(pillar_men_sensor* sensor) {
    return sensor == nullptr ? false : true;
}


int activity_counter(pillar_men_sensor* sensor_array, int capacity) {
    if (sensor_array == nullptr) return 0;

    int total_activity = 0;
    for (int i = 0; i < capacity; ++i) {
        // 累加每个传感器的 activity 成员
        total_activity += (sensor_array + i)->activity; 
        // 或者使用下标语法: total_activity += sensor_array[i].activity;
    }
    return total_activity;
}

bool alarm_control(pillar_men_sensor* sensor) {
    if (!connection_check(sensor)) return false;
    return sensor->activity > 0;
}

bool uv_alarm(pillar_men_sensor* sensor) {
    if (sensor == nullptr) return false;
    int result = uv_light_heuristic(&(sensor->data));
    if (result > sensor->activity) return true;
    return false;
}
    
}  // namespace speedywagon
