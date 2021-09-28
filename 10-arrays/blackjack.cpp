#include <cassert>
#include <iostream>
#include <limits>
#include "cards.h"

constexpr int max_score{21};
constexpr int dealer_stand{17};

enum class GameResult
{
  player_wins,
  dealer_wins,
  tie
};

// Return true if player chooses to hit, false otherwise
bool playerHits()
{
  while (true)
  {
    std::cout << "Hit or stand? (h/s): ";
    char input{};
    std::cin >> input;

    if (std::cin.fail() || (input != 'h' && input != 's'))
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input.\n";
    }
    else
    {
      std::cout << '\n';
      return input == 'h';
    }
  }
}

// Returns true if player busts, false otherwise
bool playerTurn(int& score, int& nextCardIndex, const deck_t& deck)
{
  while (true)
  {
    if (score > max_score)
    {
      break;
    }

    if (playerHits())
    {
      int value{getCardValue(deck.at(nextCardIndex++))};
      score += value;
      std::cout << "You were dealt a " << value << " and now have: " << score << '\n';
    }
    else
    {
      break;
    }
  }

  return score > max_score;
}

// Returns true if dealer hits, false otherwise
bool dealerTurn(int& score, int& nextCardIndex, const deck_t& deck)
{
  while (true)
  {
    if (score > max_score)
    {
      break;
    }

    if (score < dealer_stand)
    {
      int value{getCardValue(deck.at(nextCardIndex++))};
      score += value;
      std::cout << "The dealer drew a " << value << " and now has: " << score << '\n';
    }
    else
    {
      break;
    }
  }

  return score > max_score;
}

GameResult playBlackjack(const deck_t& deck)
{
  int nextCardIndex{0};
  int playerScore{getCardValue(deck.at(nextCardIndex++))};
  int dealerScore{getCardValue(deck.at(nextCardIndex++))};
  playerScore += getCardValue(deck.at(nextCardIndex++));

  std::cout << "The dealer is showing: " << dealerScore << '\n';
  std::cout << "You have: " << playerScore << '\n';

  if (playerTurn(playerScore, nextCardIndex, deck))
  {
    return GameResult::dealer_wins;
  }

  if (dealerTurn(dealerScore, nextCardIndex, deck))
  {
    return GameResult::player_wins;
  }

  if (playerScore == dealerScore)
  {
    return GameResult::tie;
  }
  else if (playerScore > dealerScore)
  {
    return GameResult::player_wins;
  }
  else
  {
    return GameResult::dealer_wins;
  }
}

int main()
{
  auto deck{createDeck()};

  shuffleDeck(deck);

  GameResult result{playBlackjack(deck)};

  switch (result)
  {
    case GameResult::player_wins:
      std::cout << "You win!\n";
      break;
    case GameResult::dealer_wins:
      std::cout << "You lose!\n";
      break;
    case GameResult::tie:
      std::cout << "The game is a tie.\n";
      break;
  }

  return 0;
}