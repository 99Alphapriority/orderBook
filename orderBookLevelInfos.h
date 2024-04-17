#include "levelInfo.h"

class OrderBookLevelInfos
{
private:
	LevelInfos bids_;
	LevelInfos asks_;

public:
	//constructor
	OrderBookLevelInfos(const LevelInfos& bids, const LevelInfos& asks):
		bids_{bids},	//initialises bids_ with bids 
		asks_{asks}		//initialises asks_ with asks
	{}

	const LevelInfos& getBids() const
	{
		return bids_;
	}

	const LevelInfos& getAsks() const
	{
		return asks_;
	}
};
