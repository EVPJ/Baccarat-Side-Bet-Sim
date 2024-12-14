Video_bacc_6deck_kickr_test.cpp:
This file was made to simulate the broken Kickr baccarat game, where natural 8s and 9s are ignored by player and banker under the following conditions:
Player always hits on 5 or below
Banker always hits on 3 or below
This is different from how baccarat is supposed to work, where natural 8s and 9s stop all hits.
According to my simulations, this changes the RTP on Player bet from 98.7% to 99.3%, making it better than banker for Kickr.
This simulation re-shuffles a 6 deck shoe after every hand, as per the baccarat rules listed on Kickr

Live_8deck.cpp:
This is made to simulate an 8 deck shoe that is played all the way to a cut card that is placed 14 cards before the end of the shoe.
I want this to simulate brick and mortar side bets in the future, which are vulnerable to specialized card counting systems
