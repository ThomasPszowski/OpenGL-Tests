#version 460 core

out vec4 FragColor;
in vec2 TexCoords; // UV coordinates from vertex shader

uniform float zoom;  // Uniform variable for zoom level

const int MAX_ITER = 1000;  // Maximum number of iterations
const vec2 CENTER = vec2(-0.743643887037158704752191506114774, 0.131825904205311970493132056385139); // Mandelbrot set center

void main() {
    // Convert screen coordinates to complex plane (-2, 2)
    vec2 c = vec2((TexCoords.x - 0.5) * 3.0 / zoom + CENTER.x,
                  (TexCoords.y - 0.5) * 3.0 / zoom + CENTER.y);

    vec2 z = vec2(0.0, 0.0);
    int iter;
    
    for (iter = 0; iter < MAX_ITER; iter++) {
        float x = z.x * z.x - z.y * z.y + c.x;
        float y = 2.0 * z.x * z.y + c.y;
        z = vec2(x, y);
        
        if (dot(z, z) > 4.0) break;  // If z > 2, escape
    }

    // Coloring based on iteration count
    float t = float(iter) / float(MAX_ITER);
    FragColor = vec4(vec3(t), 1.0); // Grayscale
}
