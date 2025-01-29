#pragma once
//The file for Grid Based Games

//Uncle ben what happened????
//
//  __________________.___________      ________    _____      _____  ___________ _________._._._._._._.
// /  _____/\______   \   \______ \    /  _____/   /  _  \    /     \ \_   _____//   _____/| | | | | | |
///   \  ___ |       _/   ||    |  \  /   \  ___  /  /_\  \  /  \ /  \ |    __)_ \_____  \ | | | | | | |
//\    \_\  \|    |   \   ||    `   \ \    \_\  \/    |    \/    Y    \|        \/        \ \|\|\|\|\|\|
// \______  /|____|_  /___/_______  /  \______  /\____|__  /\____|__  /_______  /_______  / ____________
//        \/        \/            \/          \/         \/         \/        \/        \/  \/\/\/\/\/\/

class GridPiece {
	int YTilePosition;
	int XTilePosition;
	int MoveTiles();
	int Battle();
	bool IsAlive = true;

	
	int MoveTiles(int XPositionOffset, int YPositionOffset)
	{
		XTilePosition += XPositionOffset;
		YTilePosition += YPositionOffset;
	}
	int Battle(int Piece)
	{

	}
};

