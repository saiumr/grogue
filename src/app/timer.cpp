#include "app/timer.hpp"

uint32_t Time::fps_ = 60;
uint32_t Time::fpsDuration_ = 1000 / 60.0;

Time::Time() : elapse_(1) {
    curTime_ = SDL_GetTicks64();
}

void Time::UpdateSystem(ecs::Commands&, ecs::Querier, ecs::Resources resources,
                         ecs::Events&) {
    if (resources.Has<Time>()) {
        auto& timer = resources.Get<Time>();
        timer.elapse_ = SDL_GetTicks64() - timer.curTime_;

        if (timer.Elapse() < fpsDuration_) {
            auto duration = fpsDuration_ - timer.Elapse();
            SDL_Delay(duration);
        }

        timer.curTime_ = SDL_GetTicks64();

    }
}

void TimerManager::UpdateSystem(ecs::Commands&, ecs::Querier, ecs::Resources resources,
    ecs::Events&) {
    auto& time = resources.Get<Time>();
    auto& timer = resources.Get<TimerManager>();
    for (auto& t : timer.datas_) {
        t.second->Update(time);
    }
}
