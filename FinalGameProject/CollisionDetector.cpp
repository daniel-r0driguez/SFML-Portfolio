// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "CollisionDetector.h"
#include <iostream>

bool CollisionDetector::isColliding(GameObject &object1, GameObject &object2)
{
    // First check if both objects are collidable.
    // If one is not a collidable, simply return false.
    if (!object1.isCollidable() || !object2.isCollidable())
    {
        return false;
    }

    // Step 1. Grab the all the vertices (points) of both possibly colliding shapes.
    std::vector<sf::Vector2f> object1Vertices = getVertices(object1);
    std::vector<sf::Vector2f> object2Vertices = getVertices(object2);

    // Step 2. calculate the normals (unit vectors perpendicular to the edges) of the shapes.
    std::vector<sf::Vector2f> object1Normals = getNormals(object1Vertices);
    std::vector<sf::Vector2f> object2Normals = getNormals(object2Vertices);

    // Step 3. Project the vertices of both GameObject objects onto the collection of normals.
    // We MUST project the vertices of both objects onto the normals of the first object, and the
    // normals of the second object.

    // We also need to calculate the MTV (Minimum Translation Vector).
    // The variable unitVector represents a unit vector, which shows the direction of where the collision is occurring.
    sf::Vector2f unitVector;
    // The minimum overlap distance is necessary to calculate the MTV.
    float minimumOverlap = std::numeric_limits<float>::infinity();

    // Project all vertices onto all normals...
    if (hasSeparatingAxis(object1Vertices, object2Vertices, object1Normals, unitVector, minimumOverlap) ||
        hasSeparatingAxis(object2Vertices, object1Vertices, object2Normals, unitVector, minimumOverlap))
    {
        // ..however, if a separating axis is found, simply return false, indicating there is no collision.
        return false;
    }
    // Otherwise if we iterate throughout all the normals and find no axis (on the normal) that separates the two objects,
    // that indicates there is a collision between them. But before returning true, we must continue calculating the MTV.

    // We must project the difference of positions between the two shapes onto the unit vector.
    if (dot(unitVector, object2.getPosition() - object1.getPosition()) > 0)
    {
        unitVector = -unitVector;
    }
    // Multiply the unit vector by the minimumOverlap to get the true MTV (Minimum Translation Vector).
    sf::Vector2f minimumTranslationVector =  unitVector * minimumOverlap;

    // Finally, pass this MTV to the objects and let them handle the collision themselves.
    object1.handleCollision(minimumTranslationVector, &object2);
//    object2.handleCollision(minimumTranslationVector, &object1);
    return true;
}

std::vector<sf::Vector2f> CollisionDetector::getNormals(const std::vector<sf::Vector2f> &vertices)
{
    std::vector<sf::Vector2f> edges;
    edges.reserve(vertices.size());
    // First calculate the edge vectors (edges) of the shape using its vertices.
    for (int i = 0; i < vertices.size() - 1; ++i)
    {
        edges.push_back(vertices.at(i) - vertices.at(i + 1));
    }
    edges.push_back(vertices.at(vertices.size() - 1) - vertices.at(0));

    // Next, modify each edge.
    for (sf::Vector2f& edge : edges)
    {
        // First rotate it by 90 degrees...
        makeOrthogonal(edge);
        // ...then convert that vector into a unit vector (normal)
        makeNormal(edge);
    }
    // Edges now contains all the normals (unit vectors perpendicular to the edges) of the current shape.
    return edges;
}

std::vector<sf::Vector2f> CollisionDetector::getVertices(const GameObject &component)
{
    std::vector<sf::Vector2f> vertices;
    vertices.reserve(component.getPointCount());
    // Grab all the vertices (points) of the component in the 2D world.
    for (int i = 0; i < component.getPointCount(); ++i)
    {
        vertices.push_back({component.getTransformedPoint(i)});
    }
    return vertices;
}

float CollisionDetector::dot(const sf::Vector2f& v, const sf::Vector2f& u)
{
    // Dot product is simply the product of x-components plus the product of the y-components of v and u.
    return (v.x * u.x) + (v.y * u.y);
}

void CollisionDetector::makeOrthogonal(sf::Vector2f &v)
{
    // Rotate the vector 90 degrees
    // Ex. (x, y) rotated 90 degrees is (-y, x)
    float temp = v.x;
    v.x = -v.y;
    v.y = temp;
}

void CollisionDetector::makeNormal(sf::Vector2f &v)
{
    // To make a vector normal, simply divide the vector by its magnitude.
    float mag = magnitude(v);
    v.x /= mag;
    v.y /= mag;
}

float CollisionDetector::magnitude(const sf::Vector2f &v)
{
    // Magnitude of a vector is simply the Pythagorean Theorem.
    return static_cast<float>(sqrt((v.x * v.x) + (v.y * v.y)));
}

bool CollisionDetector::hasSeparatingAxis(const std::vector<sf::Vector2f>& vertices1,
                                          const std::vector<sf::Vector2f>& vertices2,
                                          const std::vector<sf::Vector2f>& normals,
                                          sf::Vector2f& MTV, float& minimumOverlap)
{
    for (const sf::Vector2f& normal : normals)
    {
        float minA = std::numeric_limits<float>::infinity();
        float maxA = -std::numeric_limits<float>::infinity();
        float minB = std::numeric_limits<float>::infinity();
        float maxB = -std::numeric_limits<float>::infinity();

        // Project the vertices of the first GameObject object onto the axis of the current normal.
        for (const sf::Vector2f& vertex: vertices1)
        {
            float projectionScalar = dot(vertex, normal);
            // Keep track of the minimumA projection and maximumA projection on the current axis.
            minA = std::min(minA, projectionScalar);
            maxA = std::max(maxA, projectionScalar);
        }

        // Next, project the vertices of the second GameObject object onto the axis of the same normal.
        for (const sf::Vector2f& vertex: vertices2)
        {
            float projectionScalar = dot(vertex, normal);
            // Keep track of the minimumB projection and maximumB projection on the current axis.
            minB = std::min(minB, projectionScalar);
            maxB = std::max(maxB, projectionScalar);
        }

        // If there is no overlap in the intervals of the two objects in the current axis of the normal,
        // return true since we found an axis that separates the two objects, indicating there is no collision.
        if (minA > maxB || minB > maxA)
        {
            return true;
        }
        float curMinOverlap = std::abs(std::min(maxA, maxB) - std::max(minA, minB));
        if (curMinOverlap < minimumOverlap)
        {
            minimumOverlap = curMinOverlap;
            MTV = normal;
        }
    }
    // Otherwise, return false, indicating there is no axis separating the two objects.
    return false;
}