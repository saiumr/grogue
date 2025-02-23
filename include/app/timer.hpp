#pragma once

#include "core/pch.hpp"
#include "app/manager.hpp"

class Time final {
public:
    using TimeType = uint64_t;
    static void UpdateSystem(ecs::Commands&, ecs::Querier, ecs::Resources,
                             ecs::Events&);
    static void SetFPS(uint32_t fps) {
        fps_ = fps;
        fpsDuration_ = 1000.0 / fps;
    }
    static uint32_t GetSetFPS() { return fps_; }

    Time();

    TimeType Elapse() const { return elapse_ > 0 ? elapse_ : 1; }

private:
    static uint32_t fps_;
    static uint32_t fpsDuration_;

    uint64_t curTime_;
    uint64_t elapse_;
};

class Timer;
using TimerHandle = Handle<Timer>;

class Timer final {
public:
    using TickFunc = std::function<void()>;

    Timer(TimerHandle handle, Time::TimeType time, int loop = 0) : handle_(handle), dstTime_(time), loop_(loop) { }

    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;

    void Update(const Time& t) {
        if (!isTicking_) return;

        curTime_ += t.Elapse();
        if (curTime_ > dstTime_) {
            curTime_ = 0; 
            if (func_) {
                func_();
            }
            if (loop_ > 0) {
                loop_--; 
            }
            if (loop_ == 0) {
                Stop(); 
            }
        }
    }

    void Start() { isTicking_ = true; }

    void Pause() {
        isTicking_ = false;
        curTime_ = 0;
     }

    void Stop() { isTicking_ = false; }

private:
    Handle<Timer> handle_;
    TickFunc func_ = nullptr;
    int loop_ = 0;
    bool isTicking_ = false;
    Time::TimeType curTime_{};
    Time::TimeType dstTime_;
};

class TimerManager : public ResourceManager<Timer> {
public:
    static void UpdateSystem(ecs::Commands&, ecs::Querier, ecs::Resources,
                        ecs::Events&);

    TimerHandle Create(Time::TimeType time, Timer::TickFunc func);
};
