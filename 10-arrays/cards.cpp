#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <random>
#include "cards.h"

char getRankCode(const CardRank rank)
{
  switch (rank)
  {
    case CardRank::two:
      return '2';
    case CardRank::three:
      return '3';
    case CardRank::four:
      return '4';
    case CardRank::five:
      return '5';
    case CardRank::six:
      return '6';
    case CardRank::seven:
      return '7';
    case CardRank::eight:
      return '8';
    case CardRank::nine:
      return '9';
    case CardRank::ten:
      return 'T';
    case CardRank::jack:
      return 'J';
    case CardRank::queen:
      return 'Q';
    case CardRank::king:
      return 'K';
    case CardRank::ace:
      return 'A';
    default:
      assert(false && "invalid card rank");
  }
}

char getSuitCode(const CardSuit suit)
{
  switch (suit)
  {
    case CardSuit::clubs:
      return 'C';
    case CardSuit::diamonds:
      return 'D';
    case CardSuit::hearts:
      return 'H';
    case CardSuit::spades:
      return 'S';
    default:
      assert(false && "invalid card suit");
  }
}

void printCard(const Card& card)
{
  std::cout << getRankCode(card.rank) << getSuitCode(card.suit);
}

deck_t createDeck()
{
  const int numSuits{static_cast<int>(CardSuit::max_suits)};
  const int numRanks{static_cast<int>(CardRank::max_ranks)};

  deck_t deck{};

  for (int suit{0}; suit < numSuits; ++suit)
  {
    for (int rank{0}; rank < numRanks; ++rank)
    {
      deck[suit * numRanks + rank] = Card{static_cast<CardRank>(rank), static_cast<CardSuit>(suit)};
    }
  }

  return deck;
}

void printDeck(const deck_t& deck)
{
  const std::size_t size{deck.size()};

  for (std::size_t i{0}; i < size; ++i)
  {
    printCard(deck[i]);

    if (i < size - 1)
    {
      std::cout << ' ';
    }
  }

  std::cout << '\n';
}

void shuffleDeck(deck_t& deck)
{
  static std::random_device rd{};
  static std::mt19937 mersenne(rd());
  std::shuffle(deck.begin(), deck.end(), mersenne);
}

int getCardValue(const Card& card)
{
  switch (card.rank)
  {
    case CardRank::two:
      return 2;
    case CardRank::three:
      return 3;
    case CardRank::four:
      return 4;
    case CardRank::five:
      return 5;
    case CardRank::six:
      return 6;
    case CardRank::seven:
      return 7;
    case CardRank::eight:
      return 8;
    case CardRank::nine:
      return 9;
    case CardRank::ten:
    case CardRank::jack:
    case CardRank::queen:
    case CardRank::king:
      return 10;
    case CardRank::ace:
      return 11;
    default:
      assert(false && "invalid card rank");
  }
}

// int main()
// {
//   auto deck{createDeck()};

//   printDeck(deck);

//   shuffleDeck(deck);

//   printDeck(deck);

//   return 0;
// }