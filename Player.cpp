#include "Player.h"

/********************
File: Player.cpp
Project: CMSC 202 Project 2, Fall 2022
Author: Hasnain Ali
Date: 10/8/22
Section: 10/15
Email: hali6@umbc.edu

This file contains code for mannaging the user's
character and their information
********************/

// Player()
// Sets default values for a character named "Beannie"
Player::Player() {
  string name = "Beannie";
  SetName(name);
  m_wins = 0;
  m_falls = 0;
  m_races = 0;
  m_stat[0] = START_STAT;
  m_stat[1] = START_STAT;
  m_stat[2] = START_STAT;
}

// Player(string name)
// Sets default values for a character with user entered name
Player::Player(string name) {
  SetName(name);
  m_wins = 0;
  m_falls = 0;
  m_races = 0;
  m_stat[0] = START_STAT;
  m_stat[1] = START_STAT;
  m_stat[2] = START_STAT;
}

// GetName
// Getter for Player name 
string Player::GetName() {
  return m_name;
}

// SetName
// Given the name, sets it as m_name
void Player::SetName(string name) {
  m_name = name;
}

// GetSpeed
// Gets the speed of the user's player 
int Player::GetSpeed() {
  return m_stat[0];
}

// GetAgility
// Gets the agility of the user's player
int Player::GetAgility() {
  return m_stat[1];
}

// GetJump
// Gets the jump of the user's player
int Player::GetJump() {
  return m_stat[2];
}

// GetRaces
// Gets the total number of races the user's player has
int Player::GetRaces() {
  return m_races;
}

// GetFalls
// Gets the total number of falls the user's player has
int Player::GetFalls() {
  return m_falls;
}

// SetRaces
// Given the number of races, sets it as m_races
void Player::SetRaces(int races) {
  m_races = races;
}

// SetFalls
// Given the number of falls, sets it as m_falls
void Player::SetFalls(int falls) {
  m_falls = falls;
}

// DisplayStatus
// Displays the user's information
void Player::DisplayStatus() {
  cout << "***** The Mighty Racer " << m_name << " ***** \n";
  cout << "Races: " << m_races << "\n";
  cout << "Wins: " << m_wins << "\n";
  cout << "Falls: " << m_falls << "\n";
  cout << "\n";
  cout << "Stats \n";
  cout << "Speed: " << m_stat[0] << "\n";
  cout << "Agility: " << m_stat[1] << "\n";;
  cout << "Jump: " << m_stat[2] << "\n";;
}

// IncreaseStat
// Increases the stat the user picks
void Player::IncreaseStat() {
  bool validChoice = 0;                                                  // A boolean for the while loop to determine if the user entered a valid choice
  int userChoice;                                                        // An integer that represents the user's choice from 1-3
  while (validChoice == 0) {
    cout << "Which stat would you like to increase? \n";
    cout << "1. Speed \n";
    cout << "2. Agility \n";
    cout << "3. Jump \n";
    cin >> userChoice;
    // If the user enters a valid choice
    if ((userChoice == 1) || (userChoice == 2) || (userChoice == 3)) {
      // If the stat the user picked is alreadey maxed out
      if (m_stat[userChoice-1] == MAX_STAT) {
	cout << "This stat has already been maxed out \n";
	validChoice = 0;
      }
      else {
	validChoice = 1;
      }
    }
    else {
      // The user did not enter a 1, 2 or a 3
      cout << "A valid number was not entered \n";
      validChoice = 0;
    }
  }
  // Adds one to the stat the user picked
  m_stat[userChoice-1] = m_stat[userChoice-1] + 1;
}

// GetStat
// Given the stat chosen (1 for speed, 2 for agility, or 3 for jump), returns the value of the stat
int Player::GetStat(int stat) {
  return m_stat[stat];
}

// IncreaseWins
// Increments the number of wins by one
void Player::IncreaseWins() {
  m_wins = m_wins + 1;
}
