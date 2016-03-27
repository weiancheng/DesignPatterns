/*
 * 2016/3/27
 * author: Weian Cheng
 * Command Pattern with C++.
*/
#include  <iostream>
#include <string>
#include <map>

class Player;

class IPlayerCommand
{
public:
	IPlayerCommand(void) 
	{
		mPlayer = NULL;
	}

	virtual bool Execute(void) = 0;
	virtual std::string getCmdName(void) = 0;

protected:
	std::string mCmdName;
	Player *mPlayer;
};

class Player
{
private:
	std::string mPath;
	bool misPlaying;

public:
	bool getState(void)
	{
		return misPlaying;
	}

	void setState(bool state)
	{
		misPlaying = state;
	}

	void setPath(std::string path)
	{
		mPath = path;
	}
};

class PlayCommand : public IPlayerCommand
{
public:
	PlayCommand(Player *player)
	{
		mCmdName = "Play";
		mPlayer = player;
	}

	bool Execute(void)
	{
		if(mPlayer->getState())
		{
			std::cout << "music is playing ..." << std::endl;
			return false;
		}
		else
		{
			mPlayer->setState(true);
			std::cout << "start playing music ..." << std::endl;
			return true;
		}
	}

	std::string getCmdName()
	{
		return mCmdName;
	}

private:

};

class StopCommand : public IPlayerCommand
{
public:
	StopCommand(Player *player)
	{
		mPlayer = player;
		mCmdName = "Stop";
	}

	bool Execute(void) 
	{
		if (mPlayer->getState())
		{
			mPlayer->setState(false);
			std::cout << "stop playing music ..." << std::endl;
		}
		else
		{
			std::cout << "music is already stop ..." << std::endl;
		}

		return true;
	}

	std::string getCmdName()
	{
		return mCmdName;
	}
};

class PauseCommand : public IPlayerCommand
{
public:
	PauseCommand(Player *player) 
	{
		mPlayer = player;
		mCmdName = "Pause";
	}

	bool Execute(void)
	{
		if(mPlayer->getState())
		{
			mPlayer->setState(false);
			std::cout << "pause playing music ..." << std::endl;
		}
		else
		{
			std::cout << "music is already stop or pause" << std::endl;
		}

		return true;
	}

	std::string getCmdName()
	{
		return mCmdName;
	}
};

class StateCommand : public IPlayerCommand
{
public:
	StateCommand(Player *player) 
	{ 
		mPlayer = player;
		mCmdName = "isPlaying";
	}

	bool Execute(void)
	{
		return mPlayer->getState();
	}

	std::string getCmdName()
	{
		return mCmdName;
	}
};

class SetMusicCommand : public IPlayerCommand
{
public:
	SetMusicCommand(Player *player) 
	{
		mPlayer = player;
		mCmdName = "SetMusic";
	}

	bool Execute(void)
	{
		mPlayer->setPath("test.mp3");
		return true;
	}

	std::string getCmdName()
	{
		return mCmdName;
	}
};

class PlayerInvoker
{
public:
	void setCommand(IPlayerCommand *cmd)
	{
		mCommands.insert(std::pair<std::string, IPlayerCommand *>(cmd->getCmdName(), cmd));
	}

	bool exeCommand(std::string cmd)
	{
		return mCommands[cmd]->Execute();
	}

private:	
	std::map<std::string, IPlayerCommand *> mCommands;

};

int main(int argc, char **argv)
{
	std::cout << "success !!!" << std::endl;

	Player p;
	IPlayerCommand *play = new PlayCommand(&p);
	IPlayerCommand *stop = new StopCommand(&p);
	IPlayerCommand *pause = new PauseCommand(&p);
	IPlayerCommand *state = new StateCommand(&p);
	IPlayerCommand *setmusic = new SetMusicCommand(&p);

	PlayerInvoker player;
	player.setCommand(play);
	player.setCommand(stop);
	player.setCommand(pause);
	player.setCommand(state);
	player.setCommand(setmusic);

	player.exeCommand("SetMusic");
	player.exeCommand("Play");
	player.exeCommand("Pause");
	player.exeCommand("Stop");
	player.exeCommand("Play");
	std::cout << "state: " << (player.exeCommand("isPlaying")?"yes":"no") << std::endl;
	player.exeCommand("Stop");


	delete play;
	delete stop;
	delete pause;
	delete state;
	delete setmusic;

	return 0;
}
