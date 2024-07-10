#include "Track.h"

/********************
Title: Track.cpp
Project: CMSC 202 Project 2, Fall 2022
Author: Hasnain Ali
Date: 10/9/22
Section: 10/15
Email: hali6@umbc.edu

This file contains code for managing the track, managing
player's locations, and generating obstacles
********************/

Track::Track() {
  m_length = DEFAULT_LENGTH;
}

// SetLength
// Sets the length of the track with a user specified length
void Track::SetLength(int length) {
  m_length = length - 1;
}

// PopulateObstacles
// Assigns the obstacle array with their obstacles
void Track::PopulateObstacles() {
  // Iterated through m_obstacle and randomly assigns obstacles for the length
  for (int i = 0; i < m_length; i++) {
    m_obstacle[i] = 1 + (rand() % 2);
  }
}

// GetStatus
// Describes the current obstacle and location for every player
void Track::GetStatus() {
  // Iterates through each racer
  for (int i = 0; i < NUM_RACERS; i++) {
    // Converts the obstacle number for each player to what it actually
    // is in terms of a string
    string playerObstacle = ConvertObstacle(i);                                      // A string that represents the name of the current obstacle
    if (i == 0) {
      cout << "You are on a " << playerObstacle << " obstacle (obstacle " << m_track[i] + 1 << " of " << m_length + 1 << ") \n";
      }
    else {
      cout << "Player" << i << " is on a " << playerObstacle << " obstacle in (obstacle " << m_track[i] + 1 << " of " << m_length + 1 << ") \n";
    }
  }
} 

// CheckWin
// Checks to see if a player won
int Track::CheckWin() {
  // Iterates through each player
  for (int i = 0; i < NUM_RACERS; i++) {
    // If their location exceeds the length of the track
    if (m_track[i] > m_length) {
      // When i is 0, the user is being referenced
      if (i == 0) {
	cout << "You have won the race! \n";
	return i;
	}
      else {
	cout << "Player" << i << " won the race \n";
	return i;
      }
    }
  }
  // If no one has won
  int noWinner = -1;                                                                 // An int that holds the value of -1
  return noWinner;
}

// GetObstacle
// Given the player's location, Gets the obstacle at said location
int Track::GetObstacle(int location) {
  return m_obstacle[location];
}

// IncrementLocation
// Given the player, increments their location by one
void Track::IncrementLocation(int player) {
  m_track[player] = m_track[player] + 1;
}

// ResetLocation
// Resets all player's locations back to 0
void Track::ResetLocation() {
  // Resets the location of each player after someone wins the race
  for (int i = 0; i < NUM_RACERS; i++) {
    m_track[i] = 0;
  }
}

// ConvertObstacle
// Given the player, returns the string value of the obstacle they are on
string Track::ConvertObstacle(int player) {
  // Uses the current location of the player (m_track[player]) to
  // determine the location of the current obstacle on the obstacle array
  int obstacleLocation = m_track[player];                                           // An int that represents the location of the current obstacle
  // Uses the location to determine the int value of the current obstacle
  int obstacleType = GetObstacle(obstacleLocation);                                 // An int that represents the type of obstacle the player is currently on
  // Returns the string value of the current obstacle the player is on
  return OBSTACLE_TYPE[obstacleType];
}
