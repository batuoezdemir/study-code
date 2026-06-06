#include "FootballManager.hpp"

#include <iostream>

constexpr int MIN_PROFESSIONAL_AGE = 16;
constexpr int DEFAULT_TRAINING_INTENSITY = 70;
constexpr int MAX_RECOVERY_INTENSITY = 30;

Player::Player(const std::string &name, int age, PlayerCondition condition)
    : name(name),
      age(age),
      condition(condition)
{
}

std::string Player::get_name() const
{
    return name;
}

int Player::get_age() const
{
    return age;
}

bool Player::is_injured() const
{
    return condition == PlayerCondition::Injured;
}

InjuredPlayer::InjuredPlayer(const std::string &name, int age)
    : Player(name, age, PlayerCondition::Injured)
{
}

void OffensiveStrategy::apply() const
{
    std::cout << "Strategy: offensive pressing.\n";
}

void DefensiveStrategy::apply() const
{
    std::cout << "Strategy: compact defense.\n";
}

void BalancedStrategy::apply() const
{
    std::cout << "Strategy: balanced default strategy.\n";
}

void RecoveryAwareTrainer::train(Player &player, int intensity)
{
    if (intensity < 0 || intensity > 100)
    {
        std::cout << "Invalid intensity. Use a value between 0 and 100.\n";
        return;
    }

    int applied_intensity = intensity;

    if (player.is_injured())
    {
        if (intensity > MAX_RECOVERY_INTENSITY)
        {
            applied_intensity = MAX_RECOVERY_INTENSITY;
            std::cout << player.get_name()
                      << " is injured, so the plan is adjusted to recovery intensity "
                      << applied_intensity << ".\n";
        }

        std::cout << player.get_name() << " performs recovery training with intensity "
                  << applied_intensity << ".\n";
        return;
    }

    std::cout << player.get_name() << " trains with intensity "
              << applied_intensity << ".\n";
}

void FilePlayerRepository::save(const Player &player)
{
    std::cout << "Saving " << player.get_name() << " to player_file.txt.\n";
}

void EmailNotifier::send(const Player &player, const std::string &message)
{
    std::cout << "Sending email to " << player.get_name() << ": " << message << "\n";
}

void ConsoleSponsorReporter::print_report(const Player &player)
{
    std::cout << "Sponsor Report\n";
    std::cout << "Player: " << player.get_name() << "\n";
    std::cout << "Age: " << player.get_age() << "\n";
    std::cout << "Status: " << (player.is_injured() ? "recovery" : "match ready") << "\n";
}

FootballManager::FootballManager(
    PlayerTrainer &trainer,
    PlayerRepository &repository,
    PlayerMessenger &messenger,
    SponsorReporter &sponsor_reporter)
    : trainer(trainer),
      repository(repository),
      messenger(messenger),
      sponsor_reporter(sponsor_reporter)
{
}

void FootballManager::manage_player(Player &player, const MatchStrategy &strategy)
{
    if (player.get_age() < MIN_PROFESSIONAL_AGE)
    {
        std::cout << player.get_name() << " is too young for the professional team.\n";
        return;
    }

    select_strategy(strategy);
    train_player(player, DEFAULT_TRAINING_INTENSITY);
    save_player(player);
    notify_player(player, "Training preparation completed.");
    print_sponsor_report(player);
}

void FootballManager::train_player(Player &player, int intensity)
{
    trainer.train(player, intensity);
}

void FootballManager::save_player(const Player &player)
{
    repository.save(player);
}

void FootballManager::notify_player(const Player &player, const std::string &message)
{
    messenger.send(player, message);
}

void FootballManager::print_sponsor_report(const Player &player)
{
    sponsor_reporter.print_report(player);
}

void FootballManager::select_strategy(const MatchStrategy &strategy) const
{
    strategy.apply();
}

int main()
{
    Player player("Alex Striker", 24);
    InjuredPlayer injured_player("Ben Defender", 29);

    RecoveryAwareTrainer trainer;
    FilePlayerRepository repository;
    EmailNotifier notifier;
    ConsoleSponsorReporter sponsor_reporter;

    FootballManager manager(trainer, repository, notifier, sponsor_reporter);

    OffensiveStrategy offensive;
    DefensiveStrategy defensive;

    manager.manage_player(player, offensive);
    std::cout << "\n";
    manager.manage_player(injured_player, defensive);

    return 0;
}
