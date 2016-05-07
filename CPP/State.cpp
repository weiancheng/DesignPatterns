#include <iostream>

class IState;

class MusicPlayer {
public:
    MusicPlayer(void);
    ~MusicPlayer(void);

    bool Play(void);
    bool Stop(void);
    bool Pause(void);
    bool Record(void);
    void setState(IState * state);

private:
    IState * mState;
};

class IState {
public:
    IState() {}
    virtual ~IState() {}

    virtual bool setStatePlay(MusicPlayer *player) {
        std::cout << "state could not set play" << std::endl;
        return false;
    }

    virtual bool setStateRecord(MusicPlayer *player) {
        std::cout << "state could not set record." << std::endl;
        return false;
    }

    virtual bool setStateStop(MusicPlayer *player) {
        std::cout << "state could not set stop." << std::endl;
        return false;
    }

    virtual bool setStatePause(MusicPlayer *player) {
        std::cout << "state could not set pause." << std::endl;
        return false;
    }
};

class StatePlay : public IState {
public:
    StatePlay(void) {}
    virtual ~StatePlay() {}

    virtual bool setStatePause(MusicPlayer * player);
    virtual bool setStateStop(MusicPlayer * player);
};

class StateRecord : public IState {
public:
    StateRecord() {}
    virtual ~StateRecord() {}

    virtual bool setStateStop(MusicPlayer * player);
};

class StateStop : public IState {
public:
    StateStop() {}
    virtual ~StateStop() {}

    virtual bool setStatePlay(MusicPlayer * player);
    virtual bool setStateRecord(MusicPlayer * player);
};

class StatePause : public IState {
public:
    StatePause() {}
    virtual ~StatePause() {}

    virtual bool setStatePlay(MusicPlayer * player);
    virtual bool setStateStop(MusicPlayer * player);
};

bool StatePlay::setStateStop(MusicPlayer * player) {
    std::cout << "state is going to set stop." << std::endl;
    IState * state = new StateStop();
    player->setState(state);
    return true;
}

bool StatePlay::setStatePause(MusicPlayer * player) {
    std::cout << "state is going to set pause." << std::endl;
    player->setState(new StatePause());
    return true;
}

bool StateRecord::setStateStop(MusicPlayer *player) {
    std::cout << "state is going to change to stop" << std::endl;
    player->setState(new StateStop());
    return true;
}

bool StateStop::setStatePlay(MusicPlayer *player) {
    std::cout << "state is going to change to play" << std::endl;
    player->setState(new StatePlay());
    return true;
}

bool StateStop::setStateRecord(MusicPlayer *player) {
    std::cout << "state is going to change to record" << std::endl;
    player->setState(new StateRecord());
    return true;
}

bool StatePause::setStatePlay(MusicPlayer *player) {
    std::cout << "state is going to change to play" << std::endl;
    player->setState(new StatePlay());
    return true;
}

bool StatePause::setStateStop(MusicPlayer *player) {
    std::cout << "state is going to change to stop" << std::endl;
    player->setState(new StateStop());
    return true;
}

MusicPlayer::MusicPlayer() {
    mState = new StateStop();
}

MusicPlayer::~MusicPlayer() {
    delete mState;
}

bool MusicPlayer::Play() {
    return mState->setStatePlay(this);
}

bool MusicPlayer::Stop() {
    return mState->setStateStop(this);
}

bool MusicPlayer::Record() {
    return mState->setStateRecord(this);
}

bool MusicPlayer::Pause() {
    return mState->setStatePause(this);
}

void MusicPlayer::setState(IState *state) {
    delete mState;
    mState = state;
}

int main(int argc, char **argv) {
    MusicPlayer player;

    player.Play();
    player.Record();
    player.Pause();
    player.Stop();
    player.Stop();

    return 0;
}

