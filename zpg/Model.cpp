#include "Model.h"

Model::Model(const float points[], int length, int row_len, int dimensions, int attribs_count)
{
    this->length = length;
    this->row_len = row_len;

    //vertex buffer object (VBO)
    VBO = 0;
    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, length * sizeof(points[0]), points, GL_STATIC_DRAW);

    //Vertex Array Object (VAO)
    VAO = 0;
    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    for(int i = 0; i < attribs_count; i++)
        glEnableVertexAttribArray(i);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    for(int i = 0; i < attribs_count; i++)
        glVertexAttribPointer(i, dimensions, GL_FLOAT, GL_FALSE, 6 * sizeof(points[0]), (GLvoid*) (i * dimensions * sizeof(GL_FLOAT)));
}

void Model::render()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, length);
}
