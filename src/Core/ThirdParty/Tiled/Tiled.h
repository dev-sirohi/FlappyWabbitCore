#pragma once

#include <Core/Includes.h>

namespace Tiled
{
    struct Property
    {
        std::string Name;
        std::string Type;
        std::string Value;
    };

    struct Tile
    {
        int Id;
        std::vector<Property> Properties;
    };

    struct TileSet
    {
        std::string Image;
        int ImageWidth;
        int ImageHeight;
        int TileWidth;
        int TileHeight;
        int Columns;
        int FirstGid;
        std::unordered_map<int, Tile> Tiles;
    };

    struct Layer
    {
        std::string Name;
        std::vector<int> Data;
    };

    struct Object
    {
        std::string Name;
        std::string Type;
        float X;
        float Y;
        float Width;
        float Height;
        std::unordered_map<std::string, Property> Properties;
    };

    struct ObjectLayer
    {
        std::string Name;
        std::vector<Object> Objects;
    };

    struct TileMap
    {
        int Width;
        int Height;
        int TileWidth;
        int TileHeight;
        TileSet TileSet;
        std::vector<Layer> TileLayers;
        ObjectLayer ObjectLayerData;
    };

    TileMap LoadTileMap(const std::string &path);

} // namespace Tiled