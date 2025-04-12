#ifndef NUM_SHADER_EXTENSION_INFO_H
#define NUM_SHADER_EXTENSION_INFO_H

typedef void(*NumShader)(long long*);

typedef struct {
  NumShader shader;
} NumShaderExtensionInfo;

#endif // !NUM_SHADER_EXTENSION_INFO_H
