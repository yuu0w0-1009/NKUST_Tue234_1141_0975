#include <stdio.h>

int main() {
    int cards[7];

    while (scanf("%d %d %d %d %d %d %d", 
                &cards[0], &cards[1], &cards[2], &cards[3], 
                &cards[4], &cards[5], &cards[6]) == 7) {
        
        int ranks[14] = {0}; 
        int suits[4] = {0};  
        int suit_rank[4][14] = {0};

        for (int i = 0; i < 7; i++) {
            int k = cards[i];
            int s = k / 13;
            int r = k % 13;

            suits[s]++;
            ranks[r]++;
            suit_rank[s][r] = 1;

            if (r == 0) { 
                ranks[13]++;
                suit_rank[s][13] = 1;
            }
        }

        int is_straight_flush = 0;
        for (int s = 0; s < 4; s++) {
            if (suits[s] >= 5) {
                int streak = 0;
                for (int r = 0; r <= 13; r++) {
                    if (suit_rank[s][r]) streak++;
                    else streak = 0;
                    if (streak >= 5) is_straight_flush = 1;
                }
            }
        }

        int fours = 0, threes = 0, pairs = 0;
        for (int r = 0; r < 13; r++) {
            if (ranks[r] == 4) fours++;
            else if (ranks[r] == 3) threes++;
            else if (ranks[r] == 2) pairs++;
        }

        int is_four = (fours > 0);

        int is_full_house = ((threes >= 1 && pairs >= 1) || (threes >= 2));

        int is_flush = (suits[0] >= 5 || suits[1] >= 5 || suits[2] >= 5 || suits[3] >= 5);

        int is_straight = 0;
        int streak = 0;
        for (int r = 0; r <= 13; r++) {
            if (ranks[r] > 0) streak++;
            else streak = 0;
            if (streak >= 5) is_straight = 1;
        }

        int is_three = (threes > 0);
        int is_two_pair = (pairs >= 2);
        int is_one_pair = (pairs == 1);

        if (is_straight_flush) printf("Straight Flush\n");
        else if (is_four) printf("Four of a Kind\n");
        else if (is_full_house) printf("Full House\n");
        else if (is_flush) printf("Flush\n");
        else if (is_straight) printf("Straight\n");
        else if (is_three) printf("Three of a Kind\n");
        else if (is_two_pair) printf("Two Pair\n");
        else if (is_one_pair) printf("One Pair\n");
        else printf("High Card\n");
    }

    return 0;
}