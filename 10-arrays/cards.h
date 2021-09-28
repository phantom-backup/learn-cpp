#ifndef CARDS_H
#define CARDS_H

#include <array>

enum class CardRank
{
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  jack,
  queen,
  king,
  ace,
  max_ranks
};

enum class CardSuit
{
  clubs,
  diamonds,
  hearts,
  spades,
  max_suits
};

struct Card
{
  CardRank rank{};
  CardSuit suit{};
};

char getSuitCode(const CardSuit suit);
void printCard(const Card& card);

constexpr int deck_size{52};
using deck_t = std::array<Card, deck_size>;

deck_t createDeck();
void printDeck(const deck_t& deck);
void shuffleDeck(deck_t& deck);
int getCardValue(const Card& card);

#endif