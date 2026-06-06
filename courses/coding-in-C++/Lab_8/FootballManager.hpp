#ifndef FOOTBALL_MANAGER_HPP
#define FOOTBALL_MANAGER_HPP

#include <string>

/*
SOLID findings in the original implementation:

SRP: FootballManager violated the Single Responsibility Principle because it
selected strategies, trained players, saved data and sent messages.

OCP: FootballManager::select_strategy violated the Open/Closed Principle
because every new strategy required another if/else branch inside the class.

ISP: ClubService violated the Interface Segregation Principle because one
large interface forced implementers to provide training, saving and messaging
functions even if they only needed one of those responsibilities.

LSP: InjuredPlayer was problematic for the Liskov Substitution Principle
because it overrode Player::train and rejected intensity values that a normal
Player accepted. A caller using a Player reference could pass a valid value
such as 70 and unexpectedly fail when the object was an InjuredPlayer.

DIP: FootballManager depended directly on concrete classes
FilePlayerRepository and EmailNotifier. Those dependencies should be replaced
by abstractions such as PlayerRepository and PlayerMessenger.
*/

enum class PlayerCondition
{
    Fit,
    Injured
};

class Player
{
private:
    std::string name;
    int age;
    PlayerCondition condition;

public:
    Player(const std::string &name, int age, PlayerCondition condition = PlayerCondition::Fit);
    virtual ~Player() = default;

    std::string get_name() const;
    int get_age() const;
    bool is_injured() const;
};

class InjuredPlayer : public Player
{
public:
    InjuredPlayer(const std::string &name, int age);
};

class MatchStrategy
{
public:
    virtual ~MatchStrategy() = default;

    virtual void apply() const = 0;
};

class OffensiveStrategy : public MatchStrategy
{
public:
    void apply() const override;
};

class DefensiveStrategy : public MatchStrategy
{
public:
    void apply() const override;
};

class BalancedStrategy : public MatchStrategy
{
public:
    void apply() const override;
};

class PlayerTrainer
{
public:
    virtual ~PlayerTrainer() = default;

    virtual void train(Player &player, int intensity) = 0;
};

class PlayerRepository
{
public:
    virtual ~PlayerRepository() = default;

    virtual void save(const Player &player) = 0;
};

class PlayerMessenger
{
public:
    virtual ~PlayerMessenger() = default;

    virtual void send(const Player &player, const std::string &message) = 0;
};

class SponsorReporter
{
public:
    virtual ~SponsorReporter() = default;

    virtual void print_report(const Player &player) = 0;
};

class RecoveryAwareTrainer : public PlayerTrainer
{
public:
    void train(Player &player, int intensity) override;
};

class FilePlayerRepository : public PlayerRepository
{
public:
    void save(const Player &player) override;
};

class EmailNotifier : public PlayerMessenger
{
public:
    void send(const Player &player, const std::string &message) override;
};

class ConsoleSponsorReporter : public SponsorReporter
{
public:
    void print_report(const Player &player) override;
};

class FootballManager
{
private:
    PlayerTrainer &trainer;
    PlayerRepository &repository;
    PlayerMessenger &messenger;
    SponsorReporter &sponsor_reporter;

    void select_strategy(const MatchStrategy &strategy) const;

public:
    FootballManager(
        PlayerTrainer &trainer,
        PlayerRepository &repository,
        PlayerMessenger &messenger,
        SponsorReporter &sponsor_reporter);

    void manage_player(Player &player, const MatchStrategy &strategy);

    void train_player(Player &player, int intensity);
    void save_player(const Player &player);
    void notify_player(const Player &player, const std::string &message);
    void print_sponsor_report(const Player &player);
};

#endif
