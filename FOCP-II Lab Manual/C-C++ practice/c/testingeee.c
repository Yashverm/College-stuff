#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/select.h>
#endif

// ------------------ Structures ------------------
typedef struct {
    char username[50];
    int gamesPlayed;
    int wins;
    int losses;
    int streak;
    int longestStreak;
    int rockCount, paperCount, scissorsCount;
} Player;

// ------------------ Global Variables ------------------
Player currentPlayer;
Player secondPlayer;

// ------------------ Utility Functions ------------------
int randomChoice() {
    return rand() % 3; // 0=Rock, 1=Paper, 2=Scissors
}

void clearScreen() {
    printf("\n----------------------------------------\n");
}

void showChoice(int choice) {
    if (choice == 0) printf("Rock");
    else if (choice == 1) printf("Paper");
    else printf("Scissors");
}

void countdown() {
    printf("\nRock...\n");
#ifdef _WIN32
    Sleep(1000);
#else
    sleep(1);
#endif
    printf("Paper...\n");
#ifdef _WIN32
    Sleep(1000);
#else
    sleep(1);
#endif
    printf("Scissors...\n");
#ifdef _WIN32
    Sleep(1000);
#else
    sleep(1);
#endif
    printf("Shoot!\n");
}

void showRules() {
    clearScreen();
    printf("\n========== GAME RULES ==========\n");
    printf("1. Rock-Paper-Scissors logic:\n");
    printf("   - Rock beats Scissors\n");
    printf("   - Paper beats Rock\n");
    printf("   - Scissors beats Paper\n");
    printf("2. Each round starts with: Rock... Paper... Scissors... Shoot!\n");
    printf("3. Enter your choice AFTER 'Shoot!'\n");
    printf("   - Player 1 keys: A=Rock, S=Paper, D=Scissors\n");
    printf("   - Player 2 keys: J=Rock, K=Paper, L=Scissors\n");
    printf("4. Both players have 3 seconds to respond.\n");
    printf("   - If one player fails, they LOSE the round.\n");
    printf("   - If BOTH fail, the round is a TIE.\n");
    printf("================================\n\n");

    // Wait for Enter key
    printf("Press ENTER to continue...");
    while (getchar() != '\n');  // consume any leftover input
    getchar();                  // wait for actual Enter
}

// ------------------ Timed Input ------------------
int timedInputPlayer1(double seconds) {
    int choice = -1;
#ifdef _WIN32
    int elapsed = 0;
    int limit = (int)(seconds * 1000);
    while (elapsed < limit) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' || ch == 'A') choice = 0;
            else if (ch == 's' || ch == 'S') choice = 1;
            else if (ch == 'd' || ch == 'D') choice = 2;
            break;
        }
        Sleep(50);
        elapsed += 50;
    }
#else
    struct timeval tv;
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    tv.tv_sec = (int)seconds;
    tv.tv_usec = (int)((seconds - (int)seconds) * 1000000);
    if (select(1, &fds, NULL, NULL, &tv)) {
        char ch;
        scanf(" %c", &ch);
        if (ch == 'a' || ch == 'A') choice = 0;
        else if (ch == 's' || ch == 'S') choice = 1;
        else if (ch == 'd' || ch == 'D') choice = 2;
    }
#endif
    return choice; // -1 => timeout/invalid key
}

int timedInputPlayer2(double seconds) {
    int choice = -1;
#ifdef _WIN32
    int elapsed = 0;
    int limit = (int)(seconds * 1000);
    while (elapsed < limit) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'j' || ch == 'J') choice = 0;
            else if (ch == 'k' || ch == 'K') choice = 1;
            else if (ch == 'l' || ch == 'L') choice = 2;
            break;
        }
        Sleep(50);
        elapsed += 50;
    }
#else
    struct timeval tv;
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    tv.tv_sec = (int)seconds;
    tv.tv_usec = (int)((seconds - (int)seconds) * 1000000);
    if (select(1, &fds, NULL, NULL, &tv)) {
        char ch;
        scanf(" %c", &ch);
        if (ch == 'j' || ch == 'J') choice = 0;
        else if (ch == 'k' || ch == 'K') choice = 1;
        else if (ch == 'l' || ch == 'L') choice = 2;
    }
#endif
    return choice; // -1 => timeout/invalid key
}

// ------------------ Authentication ------------------
void registerUser() {
    printf("Enter new username: ");
    scanf(" %[^\n]", currentPlayer.username);
    currentPlayer.gamesPlayed = currentPlayer.wins = currentPlayer.losses = 0;
    currentPlayer.streak = currentPlayer.longestStreak = 0;
    currentPlayer.rockCount = currentPlayer.paperCount = currentPlayer.scissorsCount = 0;
    printf("Registration successful! Welcome, %s.\n", currentPlayer.username);
}

void loginUser() {
    printf("Enter username: ");
    scanf(" %[^\n]", currentPlayer.username);
    printf("Login successful! Welcome back, %s.\n", currentPlayer.username);
}

// ------------------ Statistics ------------------
void updateStats(int result, int choice) {
    currentPlayer.gamesPlayed++;
    if (choice == 0) currentPlayer.rockCount++;
    else if (choice == 1) currentPlayer.paperCount++;
    else if (choice == 2) currentPlayer.scissorsCount++;

    if (result == 1) {
        currentPlayer.wins++;
        currentPlayer.streak++;
        if (currentPlayer.streak > currentPlayer.longestStreak)
            currentPlayer.longestStreak = currentPlayer.streak;
    } else if (result == -1) {
        currentPlayer.losses++;
        currentPlayer.streak = 0;
    }
}

void showStats(Player p) {
    printf("\n--- Statistics for %s ---\n", p.username);
    printf("Games Played: %d\n", p.gamesPlayed);
    printf("Wins: %d, Losses: %d\n", p.wins, p.losses);
    printf("Win Percentage: %.2f%%\n", p.gamesPlayed ? (p.wins * 100.0 / p.gamesPlayed) : 0.0);
    printf("Longest Streak: %d\n", p.longestStreak);
    printf("Choice Preferences: Rock=%d, Paper=%d, Scissors=%d\n",
           p.rockCount, p.paperCount, p.scissorsCount);
}

// ------------------ Gameplay ------------------
int decideWinner(int p1, int p2) {
    if (p1 == p2) return 0;
    if ((p1 == 0 && p2 == 2) || (p1 == 1 && p2 == 0) || (p1 == 2 && p2 == 1))
        return 1;
    return -1;
}

// Quick Match (human vs computer)
void quickMatch() {
    showRules();
    countdown();

    printf("Player must respond within 3 seconds (A=Rock, S=Paper, D=Scissors):\n");
    int playerChoice = timedInputPlayer1(3.0);

    if (playerChoice < 0) {
        printf("\nYou failed to respond! Round is a TIE.\n");
        return;
    }

    int compChoice = randomChoice();
    printf("You chose: "); showChoice(playerChoice);
    printf("\nComputer chose: "); showChoice(compChoice);

    int result = decideWinner(playerChoice, compChoice);
    if (result == 1) printf("\nYou WIN!\n");
    else if (result == -1) printf("\nYou LOSE!\n");
    else printf("\nIt's a DRAW!\n");

    updateStats(result, playerChoice);
}

// Best-of Series (human vs computer)
void bestOfSeries(int rounds) {
    showRules();
    int playerScore = 0, compScore = 0;

    for (int i = 0; i < rounds; i++) {
        printf("\n--- Round %d ---\n", i + 1);
        countdown();

        printf("Player must respond within 3 seconds (A=Rock, S=Paper, D=Scissors):\n");
        int playerChoice = timedInputPlayer1(3.0);

        if (playerChoice < 0) {
            printf("\nYou failed to respond! You LOSE this round.\n");
            compScore++;
            continue;
        }

        int compChoice = randomChoice();

        printf("You chose: "); showChoice(playerChoice);
        printf("\nComputer chose: "); showChoice(compChoice);

        int result = decideWinner(playerChoice, compChoice);
        if (result == 1) {
            printf("\nYou WIN this round!\n");
            playerScore++;
        } else if (result == -1) {
            printf("\nComputer WINS this round!\n");
            compScore++;
        } else {
            printf("\nDRAW!\n");
        }

        updateStats(result, playerChoice);
    }

    printf("\nFinal Score: You=%d, Computer=%d\n", playerScore, compScore);
    if (playerScore > compScore) printf("You win the series!\n");
    else if (compScore > playerScore) printf("Computer wins the series!\n");
    else printf("Series is a draw!\n");
}

// Survival Mode (human vs computer)
void survivalMode() {
    showRules();
    int score = 0;

    while (1) {
        countdown();

        printf("Player must respond within 3 seconds (A=Rock, S=Paper, D=Scissors):\n");
        int playerChoice = timedInputPlayer1(3.0);

        if (playerChoice < 0) {
            printf("\nYou failed to respond! Survival ends.\n");
            updateStats(-1, 0);
            break;
        }

        int compChoice = randomChoice();

        printf("You chose: "); showChoice(playerChoice);
        printf("\nComputer chose: "); showChoice(compChoice);

        int result = decideWinner(playerChoice, compChoice);
        if (result == 1) {
            printf("\nYou WIN!\n");
            score++;
            updateStats(result, playerChoice);
        } else if (result == 0) {
            printf("\nDRAW! Continue...\n");
            updateStats(result, playerChoice);
        } else {
            printf("\nYou LOST! Survival score = %d\n", score);
            updateStats(result, playerChoice);
            break;
        }
    }
}

// Multiplayer Mode (two humans)
void multiplayerMode() {
    // Read usernames (allow spaces)
    printf("Enter Player 1 username: ");
    scanf(" %[^\n]", currentPlayer.username);
    printf("Enter Player 2 username: ");
    scanf(" %[^\n]", secondPlayer.username);

    // Rounds input with validation
    int rounds;
    printf("Enter number of rounds: ");
    while (scanf("%d", &rounds) != 1 || rounds <= 0) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid rounds! Enter a positive integer: ");
    }

    showRules();

    int score1 = 0, score2 = 0;

    for (int i = 0; i < rounds; i++) {
        printf("\n--- Round %d ---\n", i + 1);
        countdown();

        printf("%s must respond within 3 seconds (A=Rock, S=Paper, D=Scissors):\n", currentPlayer.username);
        int c1 = timedInputPlayer1(1.5);

        printf("%s must respond within 3 seconds (J=Rock, K=Paper, L=Scissors):\n", secondPlayer.username);
        int c2 = timedInputPlayer2(1.5);

        // Both failed → tie
        if ((c1 < 0) && (c2 < 0)) {
            printf("\nBoth players failed to respond in time! Round is a TIE.\n");
            continue;
        }

        // One failed → that player loses
        if (c1 < 0) {
            printf("\n%s failed to respond! %s LOSES this round.\n", currentPlayer.username, currentPlayer.username);
            score2++;
            continue;
        }
        if (c2 < 0) {
            printf("\n%s failed to respond! %s LOSES this round.\n", secondPlayer.username, secondPlayer.username);
            score1++;
            continue;
        }

        // Both responded → reveal and decide
        printf("%s chose: ", currentPlayer.username); showChoice(c1);
        printf("\n%s chose: ", secondPlayer.username); showChoice(c2);

        int result = decideWinner(c1, c2);
        if (result == 1) {
            printf("\n%s WINS this round!\n", currentPlayer.username);
            score1++;
        } else if (result == -1) {
            printf("\n%s WINS this round!\n", secondPlayer.username);
            score2++;
        } else {
            printf("\nDRAW!\n");
        }
    }

    printf("\nFinal Score: %s=%d, %s=%d\n", currentPlayer.username, score1, secondPlayer.username, score2);
}

// ------------------ Main Menu ------------------
void menu() {
    int choice;
    do {
        clearScreen();
        printf("\n--- Rock Paper Scissors Game ---\n");
        printf("1. Quick Match\n");
        printf("2. Best of Series\n");
        printf("3. Survival Mode\n");
        printf("4. Multiplayer Mode\n");
        printf("5. Show Statistics\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        while (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Invalid input. Enter choice (1-6): ");
        }

        switch (choice) {
            case 1: quickMatch(); break;
            case 2: {
                int rounds;
                printf("Enter series length (3/5/7 or any positive integer): ");
                while (scanf("%d", &rounds) != 1 || rounds <= 0) {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    printf("Invalid rounds! Enter a positive integer: ");
                }
                bestOfSeries(rounds);
                break;
            }
            case 3: survivalMode(); break;
            case 4: multiplayerMode(); break;
            case 5: showStats(currentPlayer); break;
            case 6: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
}

// ------------------ Main ------------------
int main() {
    srand((unsigned int)time(NULL));

    int authChoice;
    printf("Welcome to Rock Paper Scissors!\n");
    printf("1. Register\n2. Login\nEnter choice: ");

    while (scanf("%d", &authChoice) != 1 || (authChoice != 1 && authChoice != 2)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid input. Enter 1 (Register) or 2 (Login): ");
    }

    // Clear trailing newline before next scanf(" %[^\n]")
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    if (authChoice == 1) registerUser();
    else loginUser();

    menu();
    return 0;
}
