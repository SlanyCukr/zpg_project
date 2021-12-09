#pragma once
#include "Model.h"
class TangentModel : public Model
{
public:
	TangentModel(const char* path);
protected:
	void extract_data(std::vector<float> data, aiMesh* mesh, int i, int j);
	void attrib_pointer_array();
};

