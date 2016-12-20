#include "CShaderResource.hpp"

CShaderResource::CShaderResource(vbcString filename)
: CResource(filename)
{
	#ifdef DEBUG_MODE
	printf("Creating shader resource: %s\n", m_Filename.c_str());
	#endif

	loadResource();
}

CShaderResource::~CShaderResource()
{
	#ifdef DEBUG_MODE
	printf("Destroying shader resource: %s\n", m_Filename.c_str());
	#endif

	glDeleteProgram(m_ID);
}


void CShaderResource::loadResource()
{
	GLuint vsh = LoadVertexShader(m_Filename.c_str());
	GLuint fsh = LoadFragmentShader(m_Filename.c_str());

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Link the program
	fprintf(stdout, "Linking program\n");
	m_ID = glCreateProgram();
	glAttachShader(m_ID, vsh);
	glAttachShader(m_ID, fsh);
	glLinkProgram(m_ID);

	// Check the program
	glGetProgramiv(m_ID, GL_LINK_STATUS, &Result);
	glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ProgramErrorMessage( std::max(InfoLogLength, int(1)) );
	glGetProgramInfoLog(m_ID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);


	glDeleteShader(vsh);
	glDeleteShader(fsh);
}



GLuint CShaderResource::LoadVertexShader(const char* shader_file)
{
	// Create the shader
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;

	bool vertexShaderFound = false;
	bool shaderCode = false;

	std::ifstream VertexShaderStream(shader_file, std::ios::in);

	if( VertexShaderStream.is_open() )
	{
		std::string Line = "";

		while( getline(VertexShaderStream, Line) )
		{
			if( Line == "VERTEX_SHADER" )
				vertexShaderFound = true;

			if( vertexShaderFound && Line == "[[" )
			{
				shaderCode = true;
				continue;
			}

			if( vertexShaderFound && Line == "]]" )
			{
				vertexShaderFound = false;
				shaderCode = false;
				continue;
			}

			if( shaderCode )
			{
				VertexShaderCode += "\n" + Line;
				//printf("%s\n", Line.c_str());
			}

		} // while

		VertexShaderStream.close();
	} // if


	GLint Result = GL_FALSE;
	int InfoLogLength;



	// Compile Vertex Shader
	printf("Compiling shader : %s\n", shader_file);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> VertexShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);

	return VertexShaderID;
}


GLuint CShaderResource::LoadFragmentShader(const char* shader_file)
{
	// Create the shader
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string FragmentShaderCode;

	bool fragmentShaderFound = false;
	bool shaderCode = false;

	std::ifstream FragmentShaderStream(shader_file, std::ios::in);

	if( FragmentShaderStream.is_open() )
	{
		std::string Line = "";

		while( getline(FragmentShaderStream, Line) )
		{
			if( Line == "FRAGMENT_SHADER" )
				fragmentShaderFound = true;

			if( fragmentShaderFound && Line == "[[" )
			{
				shaderCode = true;
				continue;
			}

			if( fragmentShaderFound && Line == "]]" )
			{
				fragmentShaderFound = false;
				shaderCode = false;
				continue;
			}

			if( shaderCode )
			{
				FragmentShaderCode += "\n" + Line;
				//printf("%s\n", Line.c_str());
			}

		} // while

		FragmentShaderStream.close();
	} // if


	GLint Result = GL_FALSE;
	int InfoLogLength;



	// Compile Vertex Shader
	printf("Compiling shader : %s\n", shader_file);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Vertex Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);

	return FragmentShaderID;
}

