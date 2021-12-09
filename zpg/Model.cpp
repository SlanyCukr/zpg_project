#include "Model.h"
#include <glm/ext/vector_float4.hpp>

Model::Model(const float points[], int length, std::vector<int> sizes)
{
    this->length = length;

    //vertex buffer object (VBO)
    VBO = 0;
    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, length * sizeof(points[0]), points, GL_STATIC_DRAW);

    //Vertex Array Object (VAO)
    VAO = 0;
    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    for(int i = 0; i < sizes.size(); i++)
        glEnableVertexAttribArray(i);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    int sizes_sum = 0;
    for (int i = 0; i < sizes.size(); i++)
        sizes_sum += sizes[i];

    for (int i = 0; i < sizes.size(); i++)
        glVertexAttribPointer(i, sizes[i], GL_FLOAT, GL_FALSE, sizes_sum * sizeof(points[0]), (GLvoid*)(get_safe_previous_size(i - 1, sizes) * sizeof(GL_FLOAT)));
}

Model::Model(const char* path)
{
    Assimp::Importer importer;
    unsigned int importOptions = aiProcess_Triangulate
        | aiProcess_OptimizeMeshes              // slouèení malých plošek
        | aiProcess_JoinIdenticalVertices       // NUTNÉ jinak hodnì duplikuje
        | aiProcess_Triangulate                 // prevod vsech ploch na trojuhelniky
        | aiProcess_CalcTangentSpace;           // vypocet tangenty, nutny pro spravne pouziti normalove mapy

        //aiProcess_GenNormals/ai_Process_GenSmoothNormals - vypocet normal s jemnych prechodem v pripade, ze objekt neobsahuje normaly

    const aiScene* scene = importer.ReadFile(path, importOptions);
    int count = 0;
    if (scene)
    {
        aiMesh* mesh = scene->mMeshes[0];
        count = mesh->mNumFaces * 3;
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            for (unsigned int j = 0; j < 3; j++)
            {
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].y);
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].z);
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].y);
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].z);
            }
        }
    }

    // set size
    length = data.size();

    //Vertex Array Object (VAO)
    VBO = 0;
    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

    VAO = 0;
    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(sizeof(float) * 3));
}

int Model::get_safe_previous_size(int index, std::vector<int> sizes) 
{
    int sum = 0;
    for (int i = 0; i <= index; i++)
        sum += sizes[i];
    
    return sum;
}

void Model::render()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, length);
}
