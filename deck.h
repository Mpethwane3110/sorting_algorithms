#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - fun for enumeration of card suits.
 * @SPADE: spades suit.
 * @HEART: hearts suit.
 * @CLUB: clubs suit.
 * @DIAMOND: diamonds suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - playing card
 * @value: value of the card
 * From "Ace" to "King"
 * @kind: type of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - deck of card
 * @card: ptr to the card of the node
 * @prev: ptr to the previous node of the list
 * @next: ptr to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
