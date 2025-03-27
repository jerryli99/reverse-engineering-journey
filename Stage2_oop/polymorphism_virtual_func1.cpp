/*
say we are in a game developement context, where different game entities
(charaters, items, obstacles) need to be updated each frame using a common interface.
*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Forward declarations
class Player;
class Enemy;
class Collectible;

// Visitor interface
//Uhmmmmm, well, we will see...
class EntityVisitor {
public:
    virtual ~EntityVisitor() = default;
    virtual void visit(Player& player) = 0;
    virtual void visit(Enemy& enemy) = 0;
    virtual void visit(Collectible& collectible) = 0;
};

// Base class for all game entities
class GameEntity {
public:
    GameEntity(const std::string& name) : name(name) {}
    virtual ~GameEntity() = default;
    
    virtual void update(float deltaTime) = 0;
    virtual void render() const = 0;
    virtual void accept(EntityVisitor& visitor) = 0;
    
    const std::string& getName() const { return name; }

protected:
    std::string name;
};

// Player class
class Player : public GameEntity {
public:
    Player(const std::string& name, float health) 
        : GameEntity(name), health(health), stamina(100.0f) {}
        
    void update(float deltaTime) override {
        stamina = std::min(100.0f, stamina + 10.0f * deltaTime);
        std::cout << "[" << name << "]: Stamina: " << stamina << std::endl;
    }
    
    void render() const override {
        std::cout << "Rendering player " << name 
                  << " (HP: " << health << ")" << std::endl;
    }
    
    void accept(EntityVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    void takeDamage(float amount) {
        health -= amount;
        std::cout << "[" << name << "]: Took " << amount << " damage!" << std::endl;
    }
    
    float getHealth() const { return health; }

private:
    float health;
    float stamina;
};

// Enemy class
class Enemy : public GameEntity {
public:
    Enemy(const std::string& name, float strength) 
        : GameEntity(name), strength(strength) {}
        
    void update(float deltaTime) override {
        std::cout << "[" << name << "]: Enemy is patrolling" << std::endl;
    }
    
    void render() const override {
        std::cout << "Rendering enemy " << name 
                  << " (Strength: " << strength << ")" << std::endl;
    }
    
    void accept(EntityVisitor& visitor) override {
        visitor.visit(*this);
    }

    float getStrength() const { return strength; }

private:
    float strength;
};

// Collectible class
class Collectible : public GameEntity {
public:
    Collectible(const std::string& name, int value) 
        : GameEntity(name), value(value) {}
        
    void update(float deltaTime) override {
        std::cout << "[" << name << "]: Collectible is shimmering" << std::endl;
    }
    
    void render() const override {
        std::cout << "Rendering collectible " << name 
                  << " (Value: " << value << ")" << std::endl;
    }
    
    void accept(EntityVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    int collect() {
        std::cout << "[" << name << "]: Collected! +" << value << " points" << std::endl;
        return value;
    }

private:
    int value;
};

// Concrete visitor for frame-specific operations
class Frame2Visitor : public EntityVisitor {
public:
    void visit(Player& player) override {
        player.takeDamage(10.0f);
    }
    
    void visit(Enemy& enemy) override {
        // Do nothing for enemies in frame 2
    }
    
    void visit(Collectible& collectible) override {
        collectible.collect();
    }
};

int main() {
    std::vector<std::unique_ptr<GameEntity>> gameWorld;
    gameWorld.emplace_back(std::make_unique<Player>("Hero", 100.0f));
    gameWorld.emplace_back(std::make_unique<Enemy>("Orc", 15.0f));
    gameWorld.emplace_back(std::make_unique<Collectible>("Gold Coin", 50));
    
    const float deltaTime = 1.0f / 60.0f;
    
    for (int frame = 0; frame < 5; ++frame) {
        std::cout << "\n--- Frame " << frame << " ---" << std::endl;
        
        for (const auto& entity : gameWorld) {
            entity->update(deltaTime);
            entity->render();
        }
        
        if (frame == 2) {
            Frame2Visitor visitor;
            for (const auto& entity : gameWorld) {
                entity->accept(visitor);
            }
        }
    }
    
    return 0;
}