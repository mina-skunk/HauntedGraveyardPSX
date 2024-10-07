#pragma once

#include <EASTL/array.h>
#include <EASTL/unordered_map.h>

#include "EntityManager.hh"
#include "psyqo/trigonometry.hh"
#include "psyqo/vector.hh"

namespace HauntedGraveyard {

using ComponentType = uint8_t;
const ComponentType MAX_COMPONENTS = 32;

struct Transform {
  psyqo::Vec2 position;
  psyqo::Angle rotation;
  psyqo::Vec2 scale;
};

class ComponentArrayBase {
public:
  virtual ~ComponentArrayBase() = default;
  virtual void entity_destroyed(Entity entity) = 0;
};

template <typename T>
class ComponentArray : public ComponentArrayBase {
public:
  void insert_data(Entity entity, T component) {
    assert(entity_to_index_map.find(entity) == entity_to_index_map.end() && "Component added to same entity more than once.");

    // Put new entry at end and update the maps
    size_t new_index = size;
    entity_to_index_map[entity] = new_index;
    index_to_entity_map[new_index] = entity;
    component_array[new_index] = component;
    ++size;
  }

  void RemoveData(Entity entity) {
    assert(entity_to_index_map.find(entity) != entity_to_index_map.end() && "Removing non-existent component.");

    // Copy element at end into deleted element's place to maintain density
    size_t indexOfRemovedEntity = entity_to_index_map[entity];
    size_t indexOfLastElement = size - 1;
    component_array[indexOfRemovedEntity] = component_array[indexOfLastElement];

    // Update map to point to moved spot
    Entity entityOfLastElement = index_to_entity_map[indexOfLastElement];
    entity_to_index_map[entityOfLastElement] = indexOfRemovedEntity;
    index_to_entity_map[indexOfRemovedEntity] = entityOfLastElement;

    entity_to_index_map.erase(entity);
    index_to_entity_map.erase(indexOfLastElement);

    --size;
  }

  T& GetData(Entity entity) {
    assert(entity_to_index_map.find(entity) != entity_to_index_map.end() && "Retrieving non-existent component.");

    // Return a reference to the entity's component
    return component_array[entity_to_index_map[entity]];
  }

  void EntityDestroyed(Entity entity) override {
    if (entity_to_index_map.find(entity) != entity_to_index_map.end()) {
      // Remove the entity's component if it existed
      RemoveData(entity);
    }
  }

private:
  // The packed array of components (of generic type T),
  // set to a specified maximum amount, matching the maximum number
  // of entities allowed to exist simultaneously, so that each entity
  // has a unique spot.
  eastl::array<T, MAX_ENTITIES> component_array;

  // Map from an entity ID to an array index.
  eastl::unordered_map<Entity, size_t> entity_to_index_map;

  // Map from an array index to an entity ID.
  eastl::unordered_map<size_t, Entity> index_to_entity_map;

  // Total size of valid entries in the array.
  size_t size;
};

}  // namespace HauntedGraveyard
