#ifndef NUM_SHADER_WRAPPER_H
#define NUM_SHADER_WRAPPER_H

typedef void(*NumShader)(long long*);

typedef struct {
  NumShader shader;
} NumShaderExtensionInfo;

#endif // !NUM_SHADER_WRAPPER_H
