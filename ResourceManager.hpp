#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    ResourceManager() {
        resource = new Resource();
    }
    ResourceManager(const ResourceManager& other) {
        resource = new Resource(*other.resource);
    }
    double get() {
        return resource->get();
    }
    ResourceManager(ResourceManager&& other) {
        resource = other.resource;
        other.resource = nullptr;
    }
    ResourceManager& operator=(const ResourceManager& other) {
        delete resource;
        resource = new Resource(*other.resource);
        return *this;
    }
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        delete resource;
        resource = other.resource;
        other.resource = nullptr;
        return *this;
    }
    ~ResourceManager() {
        if (resource != nullptr)
        {
            delete resource;
        }
    }

private:
    Resource* resource;
};

