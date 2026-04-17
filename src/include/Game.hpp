#pragma once
#include "Entity.hpp"
#include <glad/glad.h>
#include "Components/Components.hpp"
#include <vector>
#include <unordered_map>
#include <queue>

class Game
{
public:
    Game(){
        max_entity_size = 100;
        for(GLuint i = 0; i < max_entity_size; i++){
            m_Vaildentities.emplace(i);
        }
        resize(max_entity_size);
    };
    ~Game(){
    };
    Entity createEntity()
    {
        if(!m_Vaildentities.empty()){
            Entity e = Entity(m_Vaildentities.front());
            m_Vaildentities.pop();
            m_entities.push_back(e);
            return e;
        }else{
            max_entity_size += 100;
            for(GLuint i = max_entity_size; i < max_entity_size; i++){
                m_Vaildentities.emplace(i);
            }
            resize(max_entity_size);
            Entity e = Entity(m_Vaildentities.front());
            m_Vaildentities.pop();
            m_entities.push_back(e);
            return e;
        }
    };

    void destoryEntity(Entity e)
    {
        //清除所有组件
        m_Vaildentities.push(e);
    }

    void addTexture(Entity e,GLuint TextureID)
    {
        m_textures[e.OBJid] = TextureID;
    }
    void addTransform(Entity e, Transform& t)
    {
        m_transforms[e.OBJid] = t;
    }
    void resize(size_t newSize)
    {
        m_transforms.resize(newSize);
        m_textures.resize(newSize);
    }
    inline static std::vector<Entity> m_entities;
    inline static std::vector<Transform> m_transforms;
    inline static std::vector<GLuint> m_textures;

    inline static std::queue<Entity> m_Vaildentities;
    inline static GLuint max_entity_size;
};