#pragma once

#include <EASTL/array.h>
#include <EASTL/bitset.h>
#include <EASTL/queue.h>

#include "Component.hh"
#include "psyqo/trigonometry.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard {

using Entity = uint16_t;  // uint32_t ??
const Entity MAX_ENTITIES = 4096;

using Signature = eastl::bitset<MAX_COMPONENTS>;

class EntityManager {
public:
  EntityManager() {
    // Initialize the queue with all possible entity IDs
    for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
      available_entities.push(entity);
    }
  }

  Entity create_entity() {
    assert(active_entity_count < MAX_ENTITIES && "Too many entities in existence.");

    // Take an ID from the front of the queue
    Entity id = available_entities.front();
    available_entities.pop();
    ++active_entity_count;

    return id;
  }

  void destroy_entity(Entity entity) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    // Invalidate the destroyed entity's signature
    signatures[entity].reset();

    // Put the destroyed ID at the back of the queue
    available_entities.push(entity);
    --active_entity_count;
  }

  void set_signature(Entity entity, Signature signature) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    // Put this entity's signature into the array
    signatures[entity] = signature;
  }

  Signature get_signature(Entity entity) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    // Get this entity's signature from the array
    return signatures[entity];
  }

private:
  eastl::queue<Entity> available_entities{};
  eastl::array<Signature, MAX_ENTITIES> signatures{};
  uint32_t active_entity_count{};
};
}  // namespace HauntedGraveyard
