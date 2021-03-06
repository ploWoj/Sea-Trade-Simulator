#pragma once
#include <memory>
#include <string>
#include <vector>
#include "cargo.hpp"
#include "iObserver.hpp"
#include "time.hpp"
#include "player.hpp"

class Cargo;
// Class responsible for managing Ship in the game.
class Ship : public IObserver
{
public:
    Ship();
    Ship(size_t capacity, size_t maxCrew, size_t crew, size_t speed, const std::string &name, size_t id);
    Ship(size_t capacity, size_t maxCrew, size_t crew, size_t speed, const std::string& name, size_t id, const std::shared_ptr<Time>& time);
    ~Ship();

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    virtual size_t getCapacity() const;
    virtual  size_t getMaxCrew() const;
    virtual size_t getSpeed() const;
    virtual size_t getCrew() const;
    virtual std::string getName() const;
    virtual size_t getId() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;    
    std::vector<std::shared_ptr<Cargo>> getCargosVector() const;

    std::vector<std::shared_ptr<Cargo>>::iterator findMatchCargo(std::shared_ptr<Cargo> cargo);

    virtual void setName(const std::string& name);

    virtual void addCargo(const std::shared_ptr<Cargo>& cargo, size_t amount);

    virtual void unload(const std::shared_ptr<Cargo>& cargo, size_t amount);
    virtual void load(const std::shared_ptr<Cargo>& cargo, size_t amount);

    friend std::ostream& operator<<(std::ostream& os, const Ship& ship);
    void nextDay() override;

    void setOwner(const std::shared_ptr<Player>& owner);

    std::shared_ptr<Time> getTime() const;

protected:
    std::vector<std::shared_ptr<Cargo>> cargos_{};

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::shared_ptr<Time> time_{ nullptr };
    std::string name_;
    const size_t id_;
    std::shared_ptr<Player> owner_{ nullptr };
};