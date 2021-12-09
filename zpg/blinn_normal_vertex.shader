#version 330
layout(location = 0) in vec3 in_Position;
layout(location = 1) in vec3 in_Normal;
layout(location = 2) in vec2 in_Uv;
layout(location = 3) in vec3 in_Tg;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 ex_worldNormal;
out vec4 ex_worldPosition;
out vec2 ex_Uv;
out mat3 ex_Tbn;

void main() {
    gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(in_Position, 1.0);
    ex_worldPosition = modelMatrix * vec4(in_Position, 1.0);
    ex_worldNormal = normalize(transpose(inverse(mat3(modelMatrix))) * in_Normal);
    //ex_worldNormal = modelMatrix * vec4(in_Normal, 1.0);
    ex_Uv = in_Uv;

    //Gram–Schmidt orthonormalization
    vec3 _normal = normalize(in_Normal);
    vec3 _tangent = normalize(in_Tg);
    _tangent = normalize(_tangent - dot(_tangent, _normal) * _normal);
    vec3 _bitangent = cross(_normal, _tangent);

    //TBN Matrix
    vec3 T = normalize(vec3(ex_worldNormal * _tangent));
    vec3 B = normalize(vec3(ex_worldNormal * _bitangent));
    vec3 N = normalize(vec3(ex_worldNormal * _normal));
    ex_Tbn = mat3(T, B, N);
};