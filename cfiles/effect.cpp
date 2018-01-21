#include <lib/sj-lib-common/common.h>
#ifdef WIN32
#define GLEW_STATIC
#include <windows.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
/**
* Maximum number of attributes per vertex
*
* @private
*/
#define MAX_VERTEX_ATTRIBUTE 16    
#ifdef EMSCRIPTEN
#include <GLES3/gl3.h>
#endif
#ifdef __APPLE__
#include <OpenGL/gl.h>
#endif
#ifdef EMSCRIPTEN
#include <SDL.h>
#endif
#ifdef WIN32
#include <SDL2/SDL.h>
#endif
#ifdef __APPLE__
#include <SDL2/SDL.h>
#endif
#include <assert.h>
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#ifdef EMSCRIPTEN
#include <emscripten/html5.h>
#endif
#include <float.h>
#include <ft2build.h>
#include <lib/sj-lib-ui/obj_parser.h>
#include <limits.h>
#include <math.h>
#include <png.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include FT_FREETYPE_H
#include FT_LCD_FILTER_H
#include FT_STROKER_H

typedef struct vector_td vector_t;
typedef struct vertex_attribute_td vertex_attribute_t;
typedef struct vertex_buffer_td vertex_buffer_t;
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string1 = { 1, 38, 37, "assets/sj-lib-ui/shaders/v3f-t2f.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[48];
} sjg_string10 = { 1, 48, 47, "assets/sj-lib-ui/shaders/v3f-t2f-n3f-phong.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[48];
} sjg_string11 = { 1, 48, 47, "assets/sj-lib-ui/shaders/v3f-t2f-n3f-phong.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[42];
} sjg_string12 = { 1, 42, 41, "assets/sj-lib-ui/shaders/v3f-t2f-c4f.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[42];
} sjg_string13 = { 1, 42, 41, "assets/sj-lib-ui/shaders/v3f-t2f-c4f.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[33];
} sjg_string14 = { 1, 33, 32, "vertex:3f,tex_coord:2f,normal:3f"};
struct {
    int refcount;
    int size;
    int count;
    char data[39];
} sjg_string15 = { 1, 39, 38, "assets/sj-lib-ui/shaders/saturate.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[31];
} sjg_string16 = { 1, 31, 30, "viewport being pop'ed is wrong"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string17 = { 1, 10, 9, "viewModel"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string18 = { 1, 10, 9, "normalMat"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string19 = { 1, 11, 10, "projection"};
struct {
    int refcount;
    int size;
    int count;
    char data[46];
} sjg_string2 = { 1, 46, 45, "assets/sj-lib-ui/shaders/blur-horizontal.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string20 = { 1, 9, 8, "lightPos"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string21 = { 1, 13, 12, "diffuseColor"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string22 = { 1, 10, 9, "specColor"};
struct {
    int refcount;
    int size;
    int count;
    char data[3];
} sjg_string23 = { 1, 3, 2, ", "};
struct {
    int refcount;
    int size;
    int count;
    char data[2];
} sjg_string24 = { 1, 2, 1, " "};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string25 = { 1, 18, 17, "assets/teapot.obj"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string26 = { 1, 15, 14, "assets/cat.png"};
struct {
    int refcount;
    int size;
    int count;
    char data[33];
} sjg_string27 = { 1, 33, 32, "assets/sj-lib-ui/fonts/arial.ttf"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string28 = { 1, 8, 7, "texture"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string29 = { 1, 6, 5, "model"};
struct {
    int refcount;
    int size;
    int count;
    char data[44];
} sjg_string3 = { 1, 44, 43, "assets/sj-lib-ui/shaders/blur-vertical.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string30 = { 1, 5, 4, "view"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string31 = { 1, 6, 5, "Hello"};
struct {
    int refcount;
    int size;
    int count;
    char data[19];
} sjg_string32 = { 1, 19, 18, "Framebuffer failed"};
struct {
    int refcount;
    int size;
    int count;
    char data[34];
} sjg_string33 = { 1, 34, 33, "framebuffer being pop'ed is wrong"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string34 = { 1, 6, 5, "sigma"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string35 = { 1, 9, 8, "blurSize"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string36 = { 1, 6, 5, "alpha"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string37 = { 1, 7, 6, "amount"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string38 = { 1, 6, 5, "FPS: "};
struct {
    int refcount;
    int size;
    int count;
    char data[35];
} sjg_string4 = { 1, 35, 34, "assets/sj-lib-ui/shaders/fade.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string5 = { 1, 38, 37, "assets/sj-lib-ui/shaders/v3f-c4f.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string6 = { 1, 38, 37, "assets/sj-lib-ui/shaders/v3f-c4f.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[38];
} sjg_string7 = { 1, 38, 37, "assets/sj-lib-ui/shaders/v3f-t2f.frag"};
struct {
    int refcount;
    int size;
    int count;
    char data[44];
} sjg_string8 = { 1, 44, 43, "assets/sj-lib-ui/shaders/v3f-n3f-phong.vert"};
struct {
    int refcount;
    int size;
    int count;
    char data[44];
} sjg_string9 = { 1, 44, 43, "assets/sj-lib-ui/shaders/v3f-n3f-phong.frag"};

struct {
    int refcount;
    int size;
    int count;
    char data[0];
} g_empty = { 1, 0, 0 };
typedef struct {
    float x, y, z;    // position
    float r, g, b, a; // color
} vertex3_color4_t; 
typedef struct {
    float x, y, z;    // position
    float s, t;       // texture
} vertex3_texture2_t;   
typedef struct {
    float x, y, z;    // position
    float s, t;       // texture
    float r, g, b, a; // color
} vertex3_texture2_color3_t;    
/**
* Tuple of 4 ints.
*
* Each field can be addressed using several aliases:
*  - First component:  <b>x</b>, <b>r</b>, <b>red</b> or <b>vstart</b>
*  - Second component: <b>y</b>, <b>g</b>, <b>green</b> or <b>vcount</b>
*  - Third component:  <b>z</b>, <b>b</b>, <b>blue</b>, <b>width</b> or <b>istart</b>
*  - Fourth component: <b>w</b>, <b>a</b>, <b>alpha</b>, <b>height</b> or <b>icount</b>
*
*/
typedef union
{
    int data[4];    /**< All compoments at once     */
    struct {
        int x;      /**< Alias for first component  */
        int y;      /**< Alias for second component */
        int z;      /**< Alias for third component  */
        int w;      /**< Alias for fourht component */
    };
    struct {
        int x_;     /**< Alias for first component  */
        int y_;     /**< Alias for second component */
        int width;  /**< Alias for third component  */
        int height; /**< Alias for fourth component */
    };
    struct {
        int r;      /**< Alias for first component  */
        int g;      /**< Alias for second component */
        int b;      /**< Alias for third component  */
        int a;      /**< Alias for fourth component */
    };
    struct {
        int red;    /**< Alias for first component  */
        int green;  /**< Alias for second component */
        int blue;   /**< Alias for third component  */
        int alpha;  /**< Alias for fourth component */
    };
    struct {
        int vstart; /**< Alias for first component  */
        int vcount; /**< Alias for second component */
        int istart; /**< Alias for third component  */
        int icount; /**< Alias for fourth component */
    };
} ivec4;
/**
* Tuple of 3 ints.
*
* Each field can be addressed using several aliases:
*  - First component:  <b>x</b>, <b>r</b> or <b>red</b>
*  - Second component: <b>y</b>, <b>g</b> or <b>green</b>
*  - Third component:  <b>z</b>, <b>b</b> or <b>blue</b>
*
*/
typedef union
{
    int data[3];    /**< All compoments at once     */
    struct {
        int x;      /**< Alias for first component  */
        int y;      /**< Alias for second component */
        int z;      /**< Alias for third component  */
    };
    struct {
        int r;      /**< Alias for first component  */
        int g;      /**< Alias for second component */
        int b;      /**< Alias for third component  */
    };
    struct {
        int red;    /**< Alias for first component  */
        int green;  /**< Alias for second component */
        int blue;   /**< Alias for third component  */
    };
} ivec3;
/**
* Tuple of 2 ints.
*
* Each field can be addressed using several aliases:
*  - First component: <b>x</b>, <b>s</b> or <b>start</b>
*  - Second component: <b>y</b>, <b>t</b> or <b>end</b>
*
*/
typedef union
{
    int data[2];    /**< All compoments at once     */
    struct {
        int x;      /**< Alias for first component  */
        int y;      /**< Alias for second component */
    };
    struct {
        int s;      /**< Alias for first component  */
        int t;      /**< Alias for second component */
    };
    struct {
        int start;  /**< Alias for first component  */
        int end;    /**< Alias for second component */
    };
} ivec2;
/**
* Tuple of 4 floats.
*
* Each field can be addressed using several aliases:
*  - First component:  <b>x</b>, <b>left</b>, <b>r</b> or <b>red</b>
*  - Second component: <b>y</b>, <b>top</b>, <b>g</b> or <b>green</b>
*  - Third component:  <b>z</b>, <b>width</b>, <b>b</b> or <b>blue</b>
*  - Fourth component: <b>w</b>, <b>height</b>, <b>a</b> or <b>alpha</b>
*/
typedef union
{
    float data[4];    /**< All compoments at once    */
    struct {
        float x;      /**< Alias for first component */
        float y;      /**< Alias for second component */
        float z;      /**< Alias for third component  */
        float w;      /**< Alias for fourth component */
    };
    struct {
        float left;   /**< Alias for first component */
        float top;    /**< Alias for second component */
        float width;  /**< Alias for third component  */
        float height; /**< Alias for fourth component */
    };
    struct {
        float r;      /**< Alias for first component */
        float g;      /**< Alias for second component */
        float b;      /**< Alias for third component  */
        float a;      /**< Alias for fourth component */
    };
    struct {
        float red;    /**< Alias for first component */
        float green;  /**< Alias for second component */
        float blue;   /**< Alias for third component  */
        float alpha;  /**< Alias for fourth component */
    };
} vec4;
/**
* Tuple of 3 floats
*
* Each field can be addressed using several aliases:
*  - First component:  <b>x</b>, <b>r</b> or <b>red</b>
*  - Second component: <b>y</b>, <b>g</b> or <b>green</b>
*  - Third component:  <b>z</b>, <b>b</b> or <b>blue</b>
*/
typedef union
{
    float data[3];   /**< All compoments at once    */
    struct {
        float x;     /**< Alias for first component */
        float y;     /**< Alias fo second component */
        float z;     /**< Alias fo third component  */
    };
    struct {
        float r;     /**< Alias for first component */
        float g;     /**< Alias fo second component */
        float b;     /**< Alias fo third component  */
    };
    struct {
        float red;   /**< Alias for first component */
        float green; /**< Alias fo second component */
        float blue;  /**< Alias fo third component  */
    };
} vec3;
/**
* Tuple of 2 floats
*
* Each field can be addressed using several aliases:
*  - First component:  <b>x</b> or <b>s</b>
*  - Second component: <b>y</b> or <b>t</b>
*/
typedef union
{
    float data[2]; /**< All components at once     */
    struct {
        float x;   /**< Alias for first component  */
        float y;   /**< Alias for second component */
    };
    struct {
        float s;   /**< Alias for first component  */
        float t;   /**< Alias for second component */
    };
} vec2;
/**
* A texture atlas is used to pack several small regions into a single texture.
*/
typedef struct texture_atlas_t
{
    /**
    * Allocated nodes
    */
    vector_t * nodes;
    /**
    *  Width (in pixels) of the underlying texture
    */
    size_t width;
    /**
    * Height (in pixels) of the underlying texture
    */
    size_t height;
    /**
    * Depth (in bytes) of the underlying texture
    */
    size_t depth;
    /**
    * Allocated surface size
    */
    size_t used;
    /**
    * Texture identity (OpenGL)
    */
    unsigned int id;
    /**
    * Atlas data
    */
    unsigned char * data;
} texture_atlas_t;    
#undef __FTERRORS_H__
#define FT_ERRORDEF( e, v, s )  { e, s },
#define FT_ERROR_START_LIST     {
#define FT_ERROR_END_LIST       { 0, 0 } };
const struct {
    int          code;
    const char*  message;
} FT_Errors[] =
#include FT_ERRORS_H    
/**
* A list of possible ways to render a glyph.
*/
typedef enum rendermode_t
{
    RENDER_NORMAL,
    RENDER_OUTLINE_EDGE,
    RENDER_OUTLINE_POSITIVE,
    RENDER_OUTLINE_NEGATIVE,
    RENDER_SIGNED_DISTANCE_FIELD
} rendermode_t;
/**
* A structure that hold a kerning value relatively to a Unicode
* codepoint.
*
* This structure cannot be used alone since the (necessary) right
* Unicode codepoint is implicitely held by the owner of this structure.
*/
typedef struct kerning_t
{
    /**
    * Left Unicode codepoint in the kern pair in UTF-32 LE encoding.
    */
    uint32_t codepoint;
    /**
    * Kerning value (in fractional pixels).
    */
    float kerning;
} kerning_t;
/*
* Glyph metrics:
* --------------
*
*                       xmin                     xmax
*                        |                         |
*                        |<-------- width -------->|
*                        |                         |
*              |         +-------------------------+----------------- ymax
*              |         |    ggggggggg   ggggg    |     ^        ^
*              |         |   g:::::::::ggg::::g    |     |        |
*              |         |  g:::::::::::::::::g    |     |        |
*              |         | g::::::ggggg::::::gg    |     |        |
*              |         | g:::::g     g:::::g     |     |        |
*    offset_x -|-------->| g:::::g     g:::::g     |  offset_y    |
*              |         | g:::::g     g:::::g     |     |        |
*              |         | g::::::g    g:::::g     |     |        |
*              |         | g:::::::ggggg:::::g     |     |        |
*              |         |  g::::::::::::::::g     |     |      height
*              |         |   gg::::::::::::::g     |     |        |
*  baseline ---*---------|---- gggggggg::::::g-----*--------      |
*            / |         |             g:::::g     |              |
*     origin   |         | gggggg      g:::::g     |              |
*              |         | g:::::gg   gg:::::g     |              |
*              |         |  g::::::ggg:::::::g     |              |
*              |         |   gg:::::::::::::g      |              |
*              |         |     ggg::::::ggg        |              |
*              |         |         gggggg          |              v
*              |         +-------------------------+----------------- ymin
*              |                                   |
*              |------------- advance_x ---------->|
*/
/**
* A structure that describe a glyph.
*/
typedef struct texture_glyph_t
{
    /**
    * Unicode codepoint this glyph represents in UTF-32 LE encoding.
    */
    uint32_t codepoint;
    /**
    * Glyph's width in pixels.
    */
    size_t width;
    /**
    * Glyph's height in pixels.
    */
    size_t height;
    /**
    * Glyph's left bearing expressed in integer pixels.
    */
    int offset_x;
    /**
    * Glyphs's top bearing expressed in integer pixels.
    *
    * Remember that this is the distance from the baseline to the top-most
    * glyph scanline, upwards y coordinates being positive.
    */
    int offset_y;
    /**
    * For horizontal text layouts, this is the horizontal distance (in
    * fractional pixels) used to increment the pen position when the glyph is
    * drawn as part of a string of text.
    */
    float advance_x;
    /**
    * For vertical text layouts, this is the vertical distance (in fractional
    * pixels) used to increment the pen position when the glyph is drawn as
    * part of a string of text.
    */
    float advance_y;
    /**
    * First normalized texture coordinate (x) of top-left corner
    */
    float s0;
    /**
    * Second normalized texture coordinate (y) of top-left corner
    */
    float t0;
    /**
    * First normalized texture coordinate (x) of bottom-right corner
    */
    float s1;
    /**
    * Second normalized texture coordinate (y) of bottom-right corner
    */
    float t1;
    /**
    * A vector of kerning pairs relative to this glyph.
    */
    vector_t * kerning;
    /**
    * Mode this glyph was rendered
    */
    rendermode_t rendermode;
    /**
    * Glyph outline thickness
    */
    float outline_thickness;
} texture_glyph_t;
typedef enum location_enum_td {
    TEXTURE_FONT_FILE = 0,
    TEXTURE_FONT_MEMORY,
} location_enum;
typedef struct texture_atlas_t texture_atlas_td; 
/**
*  Texture font structure.
*/
typedef struct texture_font_t
{
    /**
    * Vector of glyphs contained in this font.
    */
    vector_t * glyphs;
    /**
    * Atlas structure to store glyphs data.
    */
    texture_atlas_td * atlas;
    /**
    * font location
    */
    location_enum location;
    union {
        /**
        * Font filename, for when location == TEXTURE_FONT_FILE
        */
        char *filename;
        /**
        * Font memory address, for when location == TEXTURE_FONT_MEMORY
        */
        struct {
            const void *base;
            size_t size;
        } memory;
    };
    /**
    * Font size
    */
    float size;
    /**
    * Whether to use autohint when rendering font
    */
    int hinting;
    /**
    * Mode the font is rendering its next glyph
    */
    rendermode_t rendermode;
    /**
    * Outline thickness
    */
    float outline_thickness;
    /**
    * Whether to use our own lcd filter.
    */
    int filtering;
    /**
    * LCD filter weights
    */
    unsigned char lcd_weights[5];
    /**
    * Whether to use kerning if available
    */
    int kerning;
    /**
    * This field is simply used to compute a default line spacing (i.e., the
    * baseline-to-baseline distance) when writing text with this font. Note
    * that it usually is larger than the sum of the ascender and descender
    * taken as absolute values. There is also no guarantee that no glyphs
    * extend above or below subsequent baselines when using this distance.
    */
    float height;
    /**
    * This field is the distance that must be placed between two lines of
    * text. The baseline-to-baseline distance should be computed as:
    * ascender - descender + linegap
    */
    float linegap;
    /**
    * The ascender is the vertical distance from the horizontal baseline to
    * the highest 'character' coordinate in a font face. Unfortunately, font
    * formats define the ascender differently. For some, it represents the
    * ascent of all capital latin characters (without accents), for others it
    * is the ascent of the highest accented character, and finally, other
    * formats define it as being equal to bbox.yMax.
    */
    float ascender;
    /**
    * The descender is the vertical distance from the horizontal baseline to
    * the lowest 'character' coordinate in a font face. Unfortunately, font
    * formats define the descender differently. For some, it represents the
    * descent of all capital latin characters (without accents), for others it
    * is the ascent of the lowest accented character, and finally, other
    * formats define it as being equal to bbox.yMin. This field is negative
    * for values below the baseline.
    */
    float descender;
    /**
    * The position of the underline line for this face. It is the center of
    * the underlining stem. Only relevant for scalable formats.
    */
    float underline_position;
    /**
    * The thickness of the underline for this face. Only relevant for scalable
    * formats.
    */
    float underline_thickness;
} texture_font_t;
/**
*  Generic vector structure.
*
* @memberof vector
*/
struct vector_td
{
    /** Pointer to dynamically allocated items. */
    void * items;
    /** Number of items that can be held in currently allocated storage. */
    size_t capacity;
    /** Number of items. */
    size_t size;
    /** Size (in bytes) of a single item. */
    size_t item_size;
};
/**
*  Generic vertex attribute.
*/
struct vertex_attribute_td
{
    /**
    *  atribute name
    */
    GLchar * name;
    /**
    * index of the generic vertex attribute to be modified.
    */
    GLuint index;
    /**
    * Number of components per generic vertex attribute.
    *
    * Must be 1, 2, 3, or 4. The initial value is 4.
    */
    GLint size;
    /**
    *  data type of each component in the array.
    *
    *  Symbolic constants GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT,
    *  GL_UNSIGNED_SHORT, GL_INT, GL_UNSIGNED_INT, GL_FLOAT, or GL_DOUBLE are
    *  accepted. The initial value is GL_FLOAT.
    */
    GLenum type;
    /**
    *  whether fixed-point data values should be normalized (GL_TRUE) or
    *  converted directly as fixed-point values (GL_FALSE) when they are
    *  accessed.
    */
    GLboolean normalized;
    /**
    *  byte offset between consecutive generic vertex attributes.
    *
    *  If stride is 0, the generic vertex attributes are understood to be
    *  tightly packed in the array. The initial value is 0.
    */
    GLsizei stride;
    /**
    *  pointer to the first component of the first attribute element in the
    *  array.
    */
    GLvoid * pointer;
    /**
    * pointer to the function that enable this attribute.
    */
    void ( * enable )(void *);
};
/**
* Generic vertex buffer.
*/
struct vertex_buffer_td
{
    /** Format of the vertex buffer. */
    char * format;
    /** Vector of vertices. */
    vector_t * vertices;
    #ifdef FREETYPE_GL_USE_VAO
    /** GL identity of the Vertex Array Object */
    GLuint VAO_id;
    #endif
    /** GL identity of the vertices buffer. */
    GLuint vertices_id;
    /** Vector of indices. */
    vector_t * indices;
    /** GL identity of the indices buffer. */
    GLuint indices_id;
    /** Current size of the vertices buffer in GPU */
    size_t GPU_vsize;
    /** Current size of the indices buffer in GPU*/
    size_t GPU_isize;
    /** GL primitives to render. */
    GLenum mode;
    /** Whether the vertex buffer needs to be uploaded to GPU memory. */
    char state;
    /** Individual items */
    vector_t * items;
    /** Array of attributes. */
    vertex_attribute_t *attributes[MAX_VERTEX_ATTRIBUTE];
};
#define sjs_hash_type_bool_typeId 36
#define sjs_log_typeId 41
#define sjs_array_char_typeId 44
#define sjs_string_typeId 42
#define sjs_windowrenderer_typeId 48
#define sjs_color_typeId 50
#define sjs_size_typeId 54
#define sjs_mat4_typeId 55
#define sjs_rect_typeId 56
#define sjs_scene2d_typeId 53
#define sjs_vec3_typeId 58
#define sjs_light_typeId 57
#define sji_model_typeId 59
#define sjs_array_heap_iface_model_typeId 143
#define sjs_list_heap_iface_model_typeId 60
#define sjs_point_typeId 111
#define sjs_mouseevent_typeId 61
#define sjs_hash_string_weak_iface_model_typeId 62
#define sji_element_typeId 67
#define sjs_hash_string_weak_iface_element_typeId 68
#define sjs_array_heap_iface_animation_typeId 74
#define sjs_list_heap_iface_animation_typeId 73
#define sjs_animator_typeId 71
#define sji_animation_typeId 72
#define sjs_shader_typeId 75
#define sjs_fontkey_typeId 76
#define sjs_font_typeId 77
#define sjs_hash_fontkey_weak_font_typeId 78
#define sjs_array_rect_typeId 85
#define sjs_list_rect_typeId 84
#define sjs_array_u32_typeId 87
#define sjs_list_u32_typeId 86
#define sjs_style_typeId 88
#define sjs_array_heap_iface_element_typeId 92
#define sjs_margin_typeId 93
#define sjs_array_gridunit_typeId 95
#define sjs_gridlayout_typeId 91
#define sjs_gridunit_typeId 94
#define sjs_array_i32_typeId 101
#define sji_gridchild_typeId 106
#define sji_effect_typeId 117
#define sjs_filllayout_typeId 114
#define cb_rect_void_typeId 115
#define cb_rect_void_heap_typeId 115
#define cb_scene2d_void_typeId 116
#define cb_scene2d_void_heap_typeId 116
#define sjs_boxrenderer_typeId 130
#define sjs_boxelement_typeId 129
#define sjs_scene3delement_typeId 142
#define cb_heap_iface_model_heap_iface_model_i32_typeId 164
#define cb_heap_iface_model_heap_iface_model_i32_heap_typeId 164
#define cb_local_iface_model_local_iface_model_i32_typeId 170
#define cb_local_iface_model_local_iface_model_i32_heap_typeId 170
#define sjs_array_vertex_location_texture_normal_typeId 221
#define sjs_vertexbuffer_vertex_location_texture_normal_typeId 184
#define sjs_texture_typeId 192
#define sjs_model_typeId 182
#define sjs_vec2_typeId 189
#define sjs_vertex_location_texture_normal_typeId 183
#define sjs_vec4_typeId 194
#define sjs_list_i32_typeId 219
#define sjs_list_vertex_location_texture_normal_typeId 220
#define sjs_array_vec3_typeId 241
#define sjs_textrenderer_typeId 263
#define sjs_textelement_typeId 258
#define sji_textelement_typeId 328
#define sjs_boxvertexbuffer_typeId 276
#define sjs_framebuffer_typeId 278
#define sjs_renderbuffer_typeId 279
#define sjs_scenebuffer_typeId 277
#define sjs_blureffect_typeId 275
#define sjs_fadeeffect_typeId 311
#define sjs_saturateeffect_typeId 315

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_windowrenderer sjs_windowrenderer;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_mat4 sjs_mat4;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_scene2d sjs_scene2d;
typedef struct td_sjs_vec3 sjs_vec3;
typedef struct td_sjs_light sjs_light;
typedef struct td_sji_model sji_model;
typedef struct td_sjs_array_heap_iface_model sjs_array_heap_iface_model;
typedef struct td_sjs_list_heap_iface_model sjs_list_heap_iface_model;
typedef struct td_sjs_point sjs_point;
typedef struct td_sjs_mouseevent sjs_mouseevent;
typedef struct td_sji_model_vtbl sji_model_vtbl;
typedef struct td_sjs_hash_string_weak_iface_model sjs_hash_string_weak_iface_model;
typedef struct td_sji_element_vtbl sji_element_vtbl;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_hash_string_weak_iface_element sjs_hash_string_weak_iface_element;
typedef struct td_sjs_array_heap_iface_animation sjs_array_heap_iface_animation;
typedef struct td_sjs_list_heap_iface_animation sjs_list_heap_iface_animation;
typedef struct td_sjs_animator sjs_animator;
typedef struct td_sji_animation_vtbl sji_animation_vtbl;
typedef struct td_sji_animation sji_animation;
typedef struct td_sjs_shader sjs_shader;
typedef struct td_sjs_fontkey sjs_fontkey;
typedef struct td_sjs_font sjs_font;
typedef struct td_sjs_hash_fontkey_weak_font sjs_hash_fontkey_weak_font;
typedef struct td_sjs_array_rect sjs_array_rect;
typedef struct td_sjs_list_rect sjs_list_rect;
typedef struct td_sjs_array_u32 sjs_array_u32;
typedef struct td_sjs_list_u32 sjs_list_u32;
typedef struct td_sjs_style sjs_style;
typedef struct td_sjs_array_heap_iface_element sjs_array_heap_iface_element;
typedef struct td_sjs_margin sjs_margin;
typedef struct td_sjs_array_gridunit sjs_array_gridunit;
typedef struct td_sjs_gridlayout sjs_gridlayout;
typedef struct td_sjs_gridunit sjs_gridunit;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sji_gridchild_vtbl sji_gridchild_vtbl;
typedef struct td_sji_gridchild sji_gridchild;
typedef struct td_sji_effect_vtbl sji_effect_vtbl;
typedef struct td_sji_effect sji_effect;
typedef struct td_sjs_filllayout sjs_filllayout;
typedef struct td_cb_rect_void cb_rect_void;
typedef struct td_cb_rect_void_heap cb_rect_void_heap;
typedef struct td_cb_scene2d_void cb_scene2d_void;
typedef struct td_cb_scene2d_void_heap cb_scene2d_void_heap;
typedef struct td_sjs_boxrenderer sjs_boxrenderer;
typedef struct td_sjs_boxelement sjs_boxelement;
typedef struct td_sjs_scene3delement sjs_scene3delement;
typedef struct td_cb_heap_iface_model_heap_iface_model_i32 cb_heap_iface_model_heap_iface_model_i32;
typedef struct td_cb_heap_iface_model_heap_iface_model_i32_heap cb_heap_iface_model_heap_iface_model_i32_heap;
typedef struct td_cb_local_iface_model_local_iface_model_i32 cb_local_iface_model_local_iface_model_i32;
typedef struct td_cb_local_iface_model_local_iface_model_i32_heap cb_local_iface_model_local_iface_model_i32_heap;
typedef struct td_sjs_array_vertex_location_texture_normal sjs_array_vertex_location_texture_normal;
typedef struct td_sjs_vertexbuffer_vertex_location_texture_normal sjs_vertexbuffer_vertex_location_texture_normal;
typedef struct td_sjs_texture sjs_texture;
typedef struct td_sjs_model sjs_model;
typedef struct td_sjs_vec2 sjs_vec2;
typedef struct td_sjs_vertex_location_texture_normal sjs_vertex_location_texture_normal;
typedef struct td_sjs_vec4 sjs_vec4;
typedef struct td_sjs_list_i32 sjs_list_i32;
typedef struct td_sjs_list_vertex_location_texture_normal sjs_list_vertex_location_texture_normal;
typedef struct td_sjs_array_vec3 sjs_array_vec3;
typedef struct td_sjs_textrenderer sjs_textrenderer;
typedef struct td_sjs_textelement sjs_textelement;
typedef struct td_sji_textelement_vtbl sji_textelement_vtbl;
typedef struct td_sji_textelement sji_textelement;
typedef struct td_sjs_boxvertexbuffer sjs_boxvertexbuffer;
typedef struct td_sjs_framebuffer sjs_framebuffer;
typedef struct td_sjs_renderbuffer sjs_renderbuffer;
typedef struct td_sjs_scenebuffer sjs_scenebuffer;
typedef struct td_sjs_blureffect sjs_blureffect;
typedef struct td_sjs_fadeeffect sjs_fadeeffect;
typedef struct td_sjs_saturateeffect sjs_saturateeffect;

struct td_sjs_hash_type_bool {
    int _refCount;
    void* _hash;
};

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
    sjs_hash_type_bool traceincludes;
    sjs_hash_type_bool debugincludes;
    sjs_hash_type_bool infoincludes;
    sjs_hash_type_bool warnincludes;
    sjs_hash_type_bool errorincludes;
    sjs_hash_type_bool fatalincludes;
};

struct td_sjs_array_char {
    int _refCount;
    void* v;
};

struct td_sjs_string {
    int _refCount;
    int32_t offset;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
};

struct td_sjs_windowrenderer {
    int _refCount;
    SDL_Window* win;
    SDL_Renderer* ren;
};

struct td_sjs_color {
    int _refCount;
    float r;
    float g;
    float b;
    float a;
};

struct td_sjs_size {
    int _refCount;
    int32_t w;
    int32_t h;
};

struct td_sjs_mat4 {
    int _refCount;
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
};

struct td_sjs_rect {
    int _refCount;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_scene2d {
    int _refCount;
    sjs_size _size;
    sjs_mat4 model;
    sjs_mat4 view;
    sjs_mat4 projection;
    sjs_rect windowrect;
};

struct td_sjs_vec3 {
    int _refCount;
    float x;
    float y;
    float z;
};

struct td_sjs_light {
    int _refCount;
    sjs_vec3 pos;
    sjs_color diffusecolor;
    sjs_color speccolor;
};

struct td_sji_model {
    sjs_object* _parent;
    sji_model_vtbl* _vtbl;
};

struct td_sjs_array_heap_iface_model {
    int _refCount;
    void* v;
};

struct td_sjs_list_heap_iface_model {
    int _refCount;
    sjs_array_heap_iface_model arr;
};

struct td_sjs_point {
    int _refCount;
    int32_t x;
    int32_t y;
};

struct td_sjs_mouseevent {
    int _refCount;
    int32_t eventtype;
    sjs_point point;
    bool iscaptured;
    bool isleftdown;
};

struct td_sji_model_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*update)(sjs_object* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
    void (*getz)(sjs_object* _parent, float* _return);
    void (*getcenter)(sjs_object* _parent, sjs_vec3* _return);
    void (*getcenter_heap)(sjs_object* _parent, sjs_vec3** _return);
    void (*getworld)(sjs_object* _parent, sjs_mat4* _return);
    void (*getworld_heap)(sjs_object* _parent, sjs_mat4** _return);
    void (*renderorqueue)(sjs_object* _parent, sjs_list_heap_iface_model* zqueue);
    void (*render)(sjs_object* _parent);
    void (*firemouseevent)(sjs_object* _parent, sjs_mouseevent* mouseevent);
};

struct td_sjs_hash_string_weak_iface_model {
    int _refCount;
    void* _hash;
};

struct td_sji_element_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*getsize)(sjs_object* _parent, sjs_size* maxsize, sjs_size* _return);
    void (*getsize_heap)(sjs_object* _parent, sjs_size* maxsize, sjs_size** _return);
    void (*getrect)(sjs_object* _parent, sjs_rect* _return);
    void (*getrect_heap)(sjs_object* _parent, sjs_rect** _return);
    void (*setrect)(sjs_object* _parent, sjs_rect* rect);
    void (*render)(sjs_object* _parent, sjs_scene2d* scene);
    void (*firemouseevent)(sjs_object* _parent, sjs_mouseevent* mouseevent, bool* _return);
};

struct td_sji_element {
    sjs_object* _parent;
    sji_element_vtbl* _vtbl;
};

struct td_sjs_hash_string_weak_iface_element {
    int _refCount;
    void* _hash;
};

struct td_sjs_array_heap_iface_animation {
    int _refCount;
    void* v;
};

struct td_sjs_list_heap_iface_animation {
    int _refCount;
    sjs_array_heap_iface_animation arr;
};

struct td_sjs_animator {
    int _refCount;
    sjs_list_heap_iface_animation animations;
    int32_t current;
};

struct td_sji_animation_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*nextframe)(sjs_object* _parent, int32_t time, bool* _return);
};

struct td_sji_animation {
    sjs_object* _parent;
    sji_animation_vtbl* _vtbl;
};

struct td_sjs_shader {
    int _refCount;
    sjs_string vertex;
    sjs_string pixel;
    GLuint id;
};

struct td_sjs_fontkey {
    int _refCount;
    sjs_string src;
    float size;
};

struct td_sjs_font {
    int _refCount;
    sjs_string src;
    float size;
    texture_font_t* font;
    texture_atlas_t* atlas;
};

struct td_sjs_hash_fontkey_weak_font {
    int _refCount;
    void* _hash;
};

struct td_sjs_array_rect {
    int _refCount;
    void* v;
};

struct td_sjs_list_rect {
    int _refCount;
    sjs_array_rect arr;
};

struct td_sjs_array_u32 {
    int _refCount;
    void* v;
};

struct td_sjs_list_u32 {
    int _refCount;
    sjs_array_u32 arr;
};

struct td_sjs_style {
    int _refCount;
};

struct td_sjs_array_heap_iface_element {
    int _refCount;
    void* v;
};

struct td_sjs_margin {
    int _refCount;
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;
};

struct td_sjs_array_gridunit {
    int _refCount;
    void* v;
};

struct td_sjs_gridlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    sjs_array_gridunit cols;
    sjs_array_gridunit rows;
    sjs_rect _rect;
};

struct td_sjs_gridunit {
    int _refCount;
    int32_t amount;
    int32_t unittype;
};

struct td_sjs_array_i32 {
    int _refCount;
    void* v;
};

struct td_sji_gridchild_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*getrow)(sjs_object* _parent, int32_t* _return);
    void (*getcol)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_gridchild {
    sjs_object* _parent;
    sji_gridchild_vtbl* _vtbl;
};

struct td_sji_effect_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*getrect)(sjs_object* _parent, sjs_rect* _return);
    void (*getrect_heap)(sjs_object* _parent, sjs_rect** _return);
    void (*setrect)(sjs_object* _parent, sjs_rect* rect, cb_rect_void cb);
    void (*render)(sjs_object* _parent, sjs_scene2d* scene, cb_scene2d_void cb);
};

struct td_sji_effect {
    sjs_object* _parent;
    sji_effect_vtbl* _vtbl;
};

struct td_sjs_filllayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    sji_effect effect;
    sjs_rect _rect;
};

struct td_cb_rect_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_rect*);
};

struct td_cb_rect_void_heap {
    cb_rect_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_scene2d_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_scene2d*);
};

struct td_cb_scene2d_void_heap {
    cb_scene2d_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_boxrenderer {
    int _refCount;
    sjs_rect rect;
    sjs_color color;
    vertex_buffer_t* buffer;
};

struct td_sjs_boxelement {
    int _refCount;
    sjs_color color;
    sjs_size idealsize;
    sjs_rect rect;
    sjs_boxrenderer boxrenderer;
};

struct td_sjs_scene3delement {
    int _refCount;
    sjs_array_heap_iface_model children;
    sjs_vec3 camera;
    sjs_vec3 lookat;
    sjs_vec3 up;
    float fieldofview;
    float znear;
    float zfar;
    sjs_light light;
    sjs_mat4 projection;
    sjs_mat4 view;
    sjs_mat4 world;
    sjs_rect _rect;
};

struct td_cb_heap_iface_model_heap_iface_model_i32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_model, sji_model, int32_t* _return);
};

struct td_cb_heap_iface_model_heap_iface_model_i32_heap {
    cb_heap_iface_model_heap_iface_model_i32 inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_local_iface_model_local_iface_model_i32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_model, sji_model, int32_t* _return);
};

struct td_cb_local_iface_model_local_iface_model_i32_heap {
    cb_local_iface_model_local_iface_model_i32 inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_array_vertex_location_texture_normal {
    int _refCount;
    void* v;
};

struct td_sjs_vertexbuffer_vertex_location_texture_normal {
    int _refCount;
    sjs_string format;
    sjs_array_i32 indices;
    sjs_array_vertex_location_texture_normal vertices;
    vertex_buffer_t* buffer;
};

struct td_sjs_texture {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_model {
    int _refCount;
    sjs_vertexbuffer_vertex_location_texture_normal vertexbuffer;
    sjs_shader shader;
    sjs_texture texture;
    sjs_mat4 model;
    sjs_vec3 center;
    bool hasalpha;
    sjs_string id;
    sjs_mat4 _projection;
    sjs_mat4 _view;
    sjs_mat4 _world;
    sjs_light _light;
    sjs_vec3 _projectedcenter;
};

struct td_sjs_vec2 {
    int _refCount;
    float x;
    float y;
};

struct td_sjs_vertex_location_texture_normal {
    int _refCount;
    sjs_vec3 location;
    sjs_vec2 texture;
    sjs_vec3 normal;
};

struct td_sjs_vec4 {
    int _refCount;
    float x;
    float y;
    float z;
    float w;
};

struct td_sjs_list_i32 {
    int _refCount;
    sjs_array_i32 arr;
};

struct td_sjs_list_vertex_location_texture_normal {
    int _refCount;
    sjs_array_vertex_location_texture_normal arr;
};

struct td_sjs_array_vec3 {
    int _refCount;
    void* v;
};

struct td_sjs_textrenderer {
    int _refCount;
    sjs_string text;
    sjs_point point;
    sjs_color color;
    sjs_font* font;
    vertex_buffer_t* buffer;
};

struct td_sjs_textelement {
    int _refCount;
    sjs_string id;
    sjs_font* font;
    sjs_string text;
    sjs_color color;
    sjs_margin margin;
    int32_t halign;
    int32_t valign;
    sjs_size idealsize;
    sjs_rect _rect;
    sjs_textrenderer _textrenderer;
};

struct td_sji_textelement_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*gettext)(sjs_object* _parent, sjs_string* _return);
    void (*gettext_heap)(sjs_object* _parent, sjs_string** _return);
    void (*settext)(sjs_object* _parent, sjs_string* v);
};

struct td_sji_textelement {
    sjs_object* _parent;
    sji_textelement_vtbl* _vtbl;
};

struct td_sjs_boxvertexbuffer {
    int _refCount;
    sjs_rect rect;
    vertex_buffer_t* buffer;
};

struct td_sjs_framebuffer {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_renderbuffer {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_scenebuffer {
    int _refCount;
    sjs_size size;
    sjs_framebuffer framebuffer;
    sjs_texture texture;
    sjs_renderbuffer renderbuffer;
};

struct td_sjs_blureffect {
    int _refCount;
    float radius;
    sjs_rect _rect;
    sjs_boxvertexbuffer _vertexbuffer1;
    sjs_boxvertexbuffer _vertexbuffer2;
    sjs_scenebuffer _scenebuffer1;
    sjs_scenebuffer _scenebuffer2;
    sjs_scene2d _innerscene;
};

struct td_sjs_fadeeffect {
    int _refCount;
    float alpha;
    sjs_rect _rect;
    sjs_boxvertexbuffer _vertexbuffer;
    sjs_scenebuffer _scenebuffer;
    sjs_scene2d _innerscene;
};

struct td_sjs_saturateeffect {
    int _refCount;
    float amount;
    sjs_rect _rect;
    sjs_boxvertexbuffer _vertexbuffer;
    sjs_scenebuffer _scenebuffer;
    sjs_scene2d _innerscene;
};

sji_effect_vtbl sjs_blureffect_effect_vtbl;
sji_element_vtbl sjs_boxelement_element_vtbl;
sji_effect_vtbl sjs_fadeeffect_effect_vtbl;
sji_element_vtbl sjs_filllayout_element_vtbl;
sji_element_vtbl sjs_gridlayout_element_vtbl;
sji_model_vtbl sjs_model_model_vtbl;
sji_effect_vtbl sjs_saturateeffect_effect_vtbl;
sji_element_vtbl sjs_scene3delement_element_vtbl;
sji_element_vtbl sjs_textelement_element_vtbl;
sji_textelement_vtbl sjs_textelement_textelement_vtbl;
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
char* string_char(sjs_string* str);
#ifndef string_weak_iface_model_hash_typedef
#define string_weak_iface_model_hash_typedef
KHASH_INIT_TYPEDEF(string_weak_iface_model_hash_type, sjs_string, sji_model)
#endif
#ifndef string_weak_iface_model_hash_typedef
#define string_weak_iface_model_hash_typedef
KHASH_INIT_TYPEDEF(string_weak_iface_model_hash_type, sjs_string, sji_model)
#endif
#ifndef string_weak_iface_element_hash_typedef
#define string_weak_iface_element_hash_typedef
KHASH_INIT_TYPEDEF(string_weak_iface_element_hash_type, sjs_string, sji_element)
#endif
#ifndef string_weak_iface_element_hash_typedef
#define string_weak_iface_element_hash_typedef
KHASH_INIT_TYPEDEF(string_weak_iface_element_hash_type, sjs_string, sji_element)
#endif
double *
make_distance_mapd( double *img,
unsigned int width, unsigned int height );
unsigned char *
make_distance_mapb( unsigned char *img,
unsigned int width, unsigned int height );    
/*
* Compute the local gradient at edge pixels using convolution filters.
* The gradient is computed only at edge pixels. At other places in the
* image, it is never used, and it's mostly zero anyway.
*/
void computegradient(double *img, int w, int h, double *gx, double *gy);
/*
* A somewhat tricky function to approximate the distance to an edge in a
* certain pixel, with consideration to either the local gradient (gx,gy)
* or the direction to the pixel (dx,dy) and the pixel greyscale value a.
* The latter alternative, using (dx,dy), is the metric used by edtaa2().
* Using a local estimate of the edge gradient (gx,gy) yields much better
* accuracy at and near edges, and reduces the error even at distant pixels
* provided that the gradient direction is accurately estimated.
*/
double edgedf(double gx, double gy, double a);
double distaa3(double *img, double *gximg, double *gyimg, int w, int c, int xc, int yc, int xi, int yi);
// Shorthand macro: add ubiquitous parameters dist, gx, gy, img and w and call distaa3()
#define DISTAA(c,xc,yc,xi,yi) (distaa3(img, gx, gy, w, c, xc, yc, xi, yi))
void edtaa3(double *img, double *gx, double *gy, int w, int h, short *distx, short *disty, double *dist);  
#ifndef fontkey_weak_font_hash_typedef
#define fontkey_weak_font_hash_typedef
KHASH_INIT_TYPEDEF(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*)
#endif
#ifndef fontkey_weak_font_hash_typedef
#define fontkey_weak_font_hash_typedef
KHASH_INIT_TYPEDEF(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*)
#endif
void glid_retain(GLuint id);
bool glid_release(GLuint id);
void glid_gethash(GLuint id, uint32_t* result);
void glid_isequal(GLuint id1, GLuint id2, bool* result);
/* Freetype GL - A C OpenGL Freetype engine
*
* Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
* file `LICENSE` for more details.
*/
/**
* Read a fragment or vertex shader from a file
*
* @param filename file to read shader from
* @return         a newly-allocated text buffer containing code. This buffer
*                 must be freed after usage.
*
*/
char *
shader_read( const char *filename );
/**
* Compile a shader from a text buffer.
*
* @param source code of the shader
* @param type   type of the shader
*
* @return a handle on the compiled program
*
*/
GLuint
shader_compile( const char* source,
const GLenum type );
/**
* Load a vertex and fragment shader sources and build program
*
* @param  vert_filename vertex shader filename
* @param  frag_filename fragment shader filename
*
* @return a handle on the built program
*
*/
GLuint
shader_load( const char * vert_filename,
const char * frag_filename );    
void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, int textlen, vec4 * color, vec2 * pen);   
vec2 get_text_size(texture_font_t * font, char *text);
/**
* Creates a new empty texture atlas.
*
* @param   width   width of the atlas
* @param   height  height of the atlas
* @param   depth   bit depth of the atlas
* @return          a new empty texture atlas.
*
*/
texture_atlas_t *
texture_atlas_new( const size_t width,
const size_t height,
const size_t depth );
/**
*  Deletes a texture atlas.
*
*  @param self a texture atlas structure
*
*/
void
texture_atlas_delete( texture_atlas_t * self );
/**
*  Allocate a new region in the atlas.
*
*  @param self   a texture atlas structure
*  @param width  width of the region to allocate
*  @param height height of the region to allocate
*  @return       Coordinates of the allocated region
*
*/
ivec4
texture_atlas_get_region( texture_atlas_t * self,
const size_t width,
const size_t height );
/**
*  Upload data to the specified atlas region.
*
*  @param self   a texture atlas structure
*  @param x      x coordinate the region
*  @param y      y coordinate the region
*  @param width  width of the region
*  @param height height of the region
*  @param data   data to be uploaded into the specified region
*  @param stride stride of the data
*
*/
void
texture_atlas_set_region( texture_atlas_t * self,
const size_t x,
const size_t y,
const size_t width,
const size_t height,
const unsigned char *data,
const size_t stride );
/**
*  Remove all allocated regions from the atlas.
*
*  @param self   a texture atlas structure
*/
void
texture_atlas_clear( texture_atlas_t * self );    
/**
* This function creates a new texture font from given filename and size.  The
* texture atlas is used to store glyph on demand. Note the depth of the atlas
* will determine if the font is rendered as alpha channel only (depth = 1) or
* RGB (depth = 3) that correspond to subpixel rendering (if available on your
* freetype implementation).
*
* @param atlas     A texture atlas
* @param pt_size   Size of font to be created (in points)
* @param filename  A font filename
*
* @return A new empty font (no glyph inside yet)
*
*/
texture_font_t *
texture_font_new_from_file( texture_atlas_t * atlas,
const float pt_size,
const char * filename );
/**
* This function creates a new texture font from a memory location and size.
* The texture atlas is used to store glyph on demand. Note the depth of the
* atlas will determine if the font is rendered as alpha channel only
* (depth = 1) or RGB (depth = 3) that correspond to subpixel rendering (if
* available on your freetype implementation).
*
* @param atlas       A texture atlas
* @param pt_size     Size of font to be created (in points)
* @param memory_base Start of the font file in memory
* @param memory_size Size of the font file memory region, in bytes
*
* @return A new empty font (no glyph inside yet)
*
*/
texture_font_t *
texture_font_new_from_memory( texture_atlas_t *atlas,
float pt_size,
const void *memory_base,
size_t memory_size );
/**
* Delete a texture font. Note that this does not delete the glyph from the
* texture atlas.
*
* @param self a valid texture font
*/
void
texture_font_delete( texture_font_t * self );
/**
* Request a new glyph from the font. If it has not been created yet, it will
* be.
*
* @param self      A valid texture font
* @param codepoint Character codepoint to be loaded in UTF-8 encoding.
*
* @return A pointer on the new glyph or 0 if the texture atlas is not big
*         enough
*
*/
texture_glyph_t *
texture_font_get_glyph( texture_font_t * self,
const char * codepoint );
/** 
* Request an already loaded glyph from the font. 
* 
* @param self      A valid texture font
* @param codepoint Character codepoint to be found in UTF-8 encoding.
*
* @return A pointer on the glyph or 0 if the glyph is not loaded
*/
texture_glyph_t *
texture_font_find_glyph( texture_font_t * self,
const char * codepoint );
/**
* Request the loading of a given glyph.
*
* @param self       A valid texture font
* @param codepoints Character codepoint to be loaded in UTF-8 encoding.
*
* @return One if the glyph could be loaded, zero if not.
*/
int
texture_font_load_glyph( texture_font_t * self,
const char * codepoints );
/**
* Request the loading of several glyphs at once.
*
* @param self       A valid texture font
* @param codepoints Character codepoints to be loaded in UTF-8 encoding. May
*                   contain duplicates.
*
* @return Number of missed glyph if the texture is not big enough to hold
*         every glyphs.
*/
size_t
texture_font_load_glyphs( texture_font_t * self,
const char * codepoints );
/*
*Increases the size of a fonts texture atlas
*Invalidates all pointers to font->atlas->data
*Changes the UV Coordinates of existing glyphs in the font
*
*@param self A valid texture font
*@param width_new Width of the texture atlas after resizing (must be bigger or equal to current width)
*@param height_new Height of the texture atlas after resizing (must be bigger or equal to current height)
*/
void
texture_font_enlarge_atlas( texture_font_t * self, size_t width_new,
size_t height_new);
/**
* Get the kerning between two horizontal glyphs.
*
* @param self      A valid texture glyph
* @param codepoint Character codepoint of the peceding character in UTF-8 encoding.
*
* @return x kerning value
*/
float
texture_glyph_get_kerning( const texture_glyph_t * self,
const char * codepoint );
/**
* Creates a new empty glyph
*
* @return a new empty glyph (not valid)
*/
texture_glyph_t *
texture_glyph_new( void );    
/**
* Returns the size in bytes of a given UTF-8 encoded character surrogate
*
* @param character  An UTF-8 encoded character
*
* @return  The length of the surrogate in bytes.
*/
size_t
utf8_surrogate_len( const char* character );
/**
* Return the length of the given UTF-8 encoded and
* NULL terminated string.
*
* @param string  An UTF-8 encoded string
*
* @return  The length of the string in characters.
*/
size_t
utf8_strlen( const char* string );
/**
* Converts a given UTF-8 encoded character to its UTF-32 LE equivalent
*
* @param character  An UTF-8 encoded character
*
* @return  The equivalent of the given character in UTF-32 LE
*          encoding.
*/
uint32_t
utf8_to_utf32( const char * character );
/**
* @file   vector.h
* @author Nicolas Rougier (Nicolas.Rougier@inria.fr)
*
* @defgroup vector Vector
*
* The vector structure and accompanying functions loosely mimic the STL C++
* vector class. It is used by @ref texture-atlas (for storing nodes), @ref
* texture-font (for storing glyphs) and @ref font-manager (for storing fonts).
* More information at http://www.cppreference.com/wiki/container/vector/start
*/
/**
* Creates a new empty vector.
*
* @param   item_size    item size in bytes
* @return               a new empty vector
*
*/
vector_t *
vector_new( size_t item_size );
/**
*  Deletes a vector.
*
*  @param self a vector structure
*
*/
void
vector_delete( vector_t *self );
/**
*  Returns a pointer to the item located at specified index.
*
*  @param  self  a vector structure
*  @param  index the index of the item to be returned
*  @return       pointer on the specified item
*/
const void *
vector_get( const vector_t *self,
size_t index );
/**
*  Returns a pointer to the first item.
*
*  @param  self  a vector structure
*  @return       pointer on the first item
*/
const void *
vector_front( const vector_t *self );
/**
*  Returns a pointer to the last item
*
*  @param  self  a vector structure
*  @return pointer on the last item
*/
const void *
vector_back( const vector_t *self );
/**
*  Check if an item is contained within the vector.
*
*  @param  self  a vector structure
*  @param  item  item to be searched in the vector
*  @param  cmp   a pointer a comparison function
*  @return       1 if item is contained within the vector, 0 otherwise
*/
int
vector_contains( const vector_t *self,
const void *item,
int (*cmp)(const void *, const void *) );
/**
*  Checks whether the vector is empty.
*
*  @param  self  a vector structure
*  @return       1 if the vector is empty, 0 otherwise
*/
int
vector_empty( const vector_t *self );
/**
*  Returns the number of items
*
*  @param  self  a vector structure
*  @return       number of items
*/
size_t
vector_size( const vector_t *self );
/**
*  Reserve storage such that it can hold at last size items.
*
*  @param  self  a vector structure
*  @param  size  the new storage capacity
*/
void
vector_reserve( vector_t *self,
const size_t size );
/**
*  Returns current storage capacity
*
*  @param  self  a vector structure
*  @return       storage capacity
*/
size_t
vector_capacity( const vector_t *self );
/**
*  Decrease capacity to fit actual size.
*
*  @param  self  a vector structure
*/
void
vector_shrink( vector_t *self );
/**
*  Removes all items.
*
*  @param  self  a vector structure
*/
void
vector_clear( vector_t *self );
/**
*  Replace an item.
*
*  @param  self  a vector structure
*  @param  index the index of the item to be replaced
*  @param  item  the new item
*/
void
vector_set( vector_t *self,
const size_t index,
const void *item );
/**
*  Erase an item.
*
*  @param  self  a vector structure
*  @param  index the index of the item to be erased
*/
void
vector_erase( vector_t *self,
const size_t index );
/**
*  Erase a range of items.
*
*  @param  self  a vector structure
*  @param  first the index of the first item to be erased
*  @param  last  the index of the last item to be erased
*/
void
vector_erase_range( vector_t *self,
const size_t first,
const size_t last );
/**
*  Appends given item to the end of the vector.
*
*  @param  self a vector structure
*  @param  item the item to be inserted
*/
void
vector_push_back( vector_t *self,
const void *item );
/**
*  Removes the last item of the vector.
*
*  @param  self a vector structure
*/
void
vector_pop_back( vector_t *self );
/**
*  Resizes the vector to contain size items
*
*  If the current size is less than size, additional items are appended and
*  initialized with value. If the current size is greater than size, the
*  vector is reduced to its first size elements.
*
*  @param  self a vector structure
*  @param  size the new size
*/
void
vector_resize( vector_t *self,
const size_t size );
/**
*  Insert a single item at specified index.
*
*  @param  self  a vector structure
*  @param  index location before which to insert item
*  @param  item  the item to be inserted
*/
void
vector_insert( vector_t *self,
const size_t index,
const void *item );
/**
*  Insert raw data at specified index.
*
*  @param  self  a vector structure
*  @param  index location before which to insert item
*  @param  data  a pointer to the items to be inserted
*  @param  count the number of items to be inserted
*/
void
vector_insert_data( vector_t *self,
const size_t index,
const void * data,
const size_t count );
/**
*  Append raw data to the end of the vector.
*
*  @param  self  a vector structure
*  @param  data  a pointer to the items to be inserted
*  @param  count the number of items to be inserted
*/
void
vector_push_back_data( vector_t *self,
const void * data,
const size_t count );
/**
*  Sort vector items according to cmp function.
*
*  @param  self  a vector structure
*  @param  cmp   a pointer a comparison function
*/
void
vector_sort( vector_t *self,
int (*cmp)(const void *, const void *) );    
/**
* Create an attribute from the given parameters.
*
* @param size       number of component
* @param type       data type
* @param normalized Whether fixed-point data values should be normalized
(GL_TRUE) or converted directly as fixed-point values
(GL_FALSE) when they are  accessed.
* @param stride     byte offset between consecutive attributes.
* @param pointer    pointer to the first component of the first attribute
*                   element in the array.
* @return           a new initialized vertex attribute.
*
* @private
*/
vertex_attribute_t *
vertex_attribute_new( GLchar * name,
GLint size,
GLenum type,
GLboolean normalized,
GLsizei stride,
GLvoid *pointer );
/**
* Delete a vertex attribute.
*
* @param  self a vertex attribute
*
*/
void
vertex_attribute_delete( vertex_attribute_t * self );
/**
* Create an attribute from the given description.
*
* @param  format Format string specifies the format of a vertex attribute.
* @return        an initialized vertex attribute
*
* @private
*/
vertex_attribute_t *
vertex_attribute_parse( char *format );
/**
* Enable a vertex attribute.
*
* @param attr  a vertex attribute
*
* @private
*/
void
vertex_attribute_enable( vertex_attribute_t *attr );    
#ifdef WIN32
// strndup() is not available on Windows
char *strndup( const char *s1, size_t n);
#endif
/**
* Creates an empty vertex buffer.
*
* @param  format a string describing vertex format.
* @return        an empty vertex buffer.
*/
vertex_buffer_t *
vertex_buffer_new( const char *format );
/**
* Deletes vertex buffer and releases GPU memory.
*
* @param  self  a vertex buffer
*/
void
vertex_buffer_delete( vertex_buffer_t * self );
/**
*  Returns the number of items in the vertex buffer
*
*  @param  self  a vertex buffer
*  @return       number of items
*/
size_t
vertex_buffer_size( const vertex_buffer_t *self );
/**
*  Returns vertex format
*
*  @param  self  a vertex buffer
*  @return       vertex format
*/
const char *
vertex_buffer_format( const vertex_buffer_t *self );
/**
* Print information about a vertex buffer
*
* @param  self  a vertex buffer
*/
void
vertex_buffer_print( vertex_buffer_t * self );
/**
* Prepare vertex buffer for render.
*
* @param  self  a vertex buffer
* @param  mode  render mode
*/
void
vertex_buffer_render_setup ( vertex_buffer_t *self,
GLenum mode );
/**
* Finish rendering by setting back modified states
*
* @param  self  a vertex buffer
*/
void
vertex_buffer_render_finish ( vertex_buffer_t *self );
/**
* Render vertex buffer.
*
* @param  self  a vertex buffer
* @param  mode  render mode
*/
void
vertex_buffer_render ( vertex_buffer_t *self,
GLenum mode );
/**
* Render a specified item from the vertex buffer.
*
* @param  self   a vertex buffer
* @param  index index of the item to be rendered
*/
void
vertex_buffer_render_item ( vertex_buffer_t *self,
size_t index );
/**
* Upload buffer to GPU memory.
*
* @param  self  a vertex buffer
*/
void
vertex_buffer_upload( vertex_buffer_t *self );
/**
* Clear all items.
*
* @param  self  a vertex buffer
*/
void
vertex_buffer_clear( vertex_buffer_t *self );
/**
* Appends indices at the end of the buffer.
*
* @param  self     a vertex buffer
* @param  indices  indices to be appended
* @param  icount   number of indices to be appended
*
* @private
*/
void
vertex_buffer_push_back_indices ( vertex_buffer_t *self,
const GLuint * indices,
const size_t icount );
/**
* Appends vertices at the end of the buffer.
*
* @note Internal use
*
* @param  self     a vertex buffer
* @param  vertices vertices to be appended
* @param  vcount   number of vertices to be appended
*
* @private
*/
void
vertex_buffer_push_back_vertices ( vertex_buffer_t *self,
const void * vertices,
const size_t vcount );
/**
* Insert indices in the buffer.
*
* @param  self    a vertex buffer
* @param  index   location before which to insert indices
* @param  indices indices to be appended
* @param  icount  number of indices to be appended
*
* @private
*/
void
vertex_buffer_insert_indices ( vertex_buffer_t *self,
const size_t index,
const GLuint *indices,
const size_t icount );
/**
* Insert vertices in the buffer.
*
* @param  self     a vertex buffer
* @param  index    location before which to insert vertices
* @param  vertices vertices to be appended
* @param  vcount   number of vertices to be appended
*
* @private
*/
void
vertex_buffer_insert_vertices ( vertex_buffer_t *self,
const size_t index,
const void *vertices,
const size_t vcount );
/**
* Erase indices in the buffer.
*
* @param  self   a vertex buffer
* @param  first  the index of the first index to be erased
* @param  last   the index of the last index to be erased
*
* @private
*/
void
vertex_buffer_erase_indices ( vertex_buffer_t *self,
const size_t first,
const size_t last );
/**
* Erase vertices in the buffer.
*
* @param  self   a vertex buffer
* @param  first  the index of the first vertex to be erased
* @param  last   the index of the last vertex to be erased
*
* @private
*/
void
vertex_buffer_erase_vertices ( vertex_buffer_t *self,
const size_t first,
const size_t last );
/**
* Append a new item to the collection.
*
* @param  self   a vertex buffer
* @param  vcount   number of vertices
* @param  vertices raw vertices data
* @param  icount   number of indices
* @param  indices  raw indices data
*/
size_t
vertex_buffer_push_back( vertex_buffer_t * self,
const void * vertices, const size_t vcount,
const GLuint * indices, const size_t icount );
/**
* Insert a new item into the vertex buffer.
*
* @param  self      a vertex buffer
* @param  index     location before which to insert item
* @param  vertices  raw vertices data
* @param  vcount    number of vertices
* @param  indices   raw indices data
* @param  icount    number of indices
*/
size_t
vertex_buffer_insert( vertex_buffer_t * self,
const size_t index,
const void * vertices, const size_t vcount,
const GLuint * indices, const size_t icount );
/**
* Erase an item from the vertex buffer.
*
* @param  self     a vertex buffer
* @param  index    index of the item to be deleted
*/
void
vertex_buffer_erase( vertex_buffer_t * self,
const size_t index );    
int32_t g_borderposition_bottom;
int32_t g_borderposition_fill;
int32_t g_borderposition_left;
int32_t g_borderposition_right;
int32_t g_borderposition_top;
int32_t g_clickstate_entered;
int32_t g_clickstate_none;
int32_t g_clickstate_pressed;
int32_t g_flowlayoutorientation_bottomtop;
int32_t g_flowlayoutorientation_leftright;
int32_t g_flowlayoutorientation_rightleft;
int32_t g_flowlayoutorientation_topbottom;
int32_t g_glblendfunctype_gl_constant_alpha;
int32_t g_glblendfunctype_gl_constant_color;
int32_t g_glblendfunctype_gl_dst_alpha;
int32_t g_glblendfunctype_gl_dst_color;
int32_t g_glblendfunctype_gl_one;
int32_t g_glblendfunctype_gl_one_minus_constant_alpha;
int32_t g_glblendfunctype_gl_one_minus_constant_color;
int32_t g_glblendfunctype_gl_one_minus_dst_alpha;
int32_t g_glblendfunctype_gl_one_minus_dst_color;
int32_t g_glblendfunctype_gl_one_minus_src_alpha;
int32_t g_glblendfunctype_gl_one_minus_src_color;
int32_t g_glblendfunctype_gl_src_alpha;
int32_t g_glblendfunctype_gl_src_alpha_saturate;
int32_t g_glblendfunctype_gl_src_color;
int32_t g_glblendfunctype_gl_zero;
int32_t g_gldrawmode_gl_line_loop;
int32_t g_gldrawmode_gl_line_strip;
int32_t g_gldrawmode_gl_lines;
int32_t g_gldrawmode_gl_points;
int32_t g_gldrawmode_gl_triangle_fan;
int32_t g_gldrawmode_gl_triangle_strip;
int32_t g_gldrawmode_gl_triangles;
int32_t g_glfeature_gl_blend;
int32_t g_glfeature_gl_cull_face;
int32_t g_glfeature_gl_depth_test;
int32_t g_glfeature_gl_dither;
int32_t g_glfeature_gl_polygon_offset_fill;
int32_t g_glfeature_gl_sample_alpha_to_coverage;
int32_t g_glfeature_gl_sample_coverage;
int32_t g_glfeature_gl_scissor_test;
int32_t g_glfeature_gl_stencil_test;
int32_t g_glframebufferattachment_gl_color_attachment0;
int32_t g_glframebufferattachment_gl_depth_attachment;
int32_t g_glframebufferattachment_gl_stencil_attachment;
int32_t g_glframebufferstatus_gl_framebuffer_complete;
int32_t g_glframebufferstatus_gl_framebuffer_incomplete_attachment;
int32_t g_glframebufferstatus_gl_framebuffer_incomplete_missing_attachment;
int32_t g_glframebufferstatus_gl_framebuffer_unsupported;
int32_t g_glframebuffertexture_gl_texture_2d;
int32_t g_glframebuffertexture_gl_texture_cube_map_negative_x;
int32_t g_glframebuffertexture_gl_texture_cube_map_negative_y;
int32_t g_glframebuffertexture_gl_texture_cube_map_negative_z;
int32_t g_glframebuffertexture_gl_texture_cube_map_positive_x;
int32_t g_glframebuffertexture_gl_texture_cube_map_positive_y;
int32_t g_glframebuffertexture_gl_texture_cube_map_positive_z;
int32_t g_glrenderbufferformat_gl_depth_component16;
int32_t g_glrenderbufferformat_gl_rgb565;
int32_t g_glrenderbufferformat_gl_rgb5_a1;
int32_t g_glrenderbufferformat_gl_rgba4;
int32_t g_glrenderbufferformat_gl_stencil_index8;
int32_t g_gltexture_gl_texture_2d;
int32_t g_gltexture_gl_texture_cube_map;
int32_t g_gltextureattribute_gl_texture_mag_filter;
int32_t g_gltextureattribute_gl_texture_min_filter;
int32_t g_gltextureattribute_gl_texture_wrap_s;
int32_t g_gltextureattribute_gl_texture_wrap_t;
int32_t g_gltextureformat_gl_alpha;
int32_t g_gltextureformat_gl_luminance;
int32_t g_gltextureformat_gl_luminance_alpha;
int32_t g_gltextureformat_gl_rgb;
int32_t g_gltextureformat_gl_rgba;
int32_t g_gltexturetype_gl_unsigned_byte;
int32_t g_gltexturetype_gl_unsigned_short_4_4_4_4;
int32_t g_gltexturetype_gl_unsigned_short_5_5_5_1;
int32_t g_gltexturetype_gl_unsigned_short_5_6_5;
int32_t g_gltexturevalue_gl_clamp_to_edge;
int32_t g_gltexturevalue_gl_linear;
int32_t g_gltexturevalue_gl_linear_mipmap_linear;
int32_t g_gltexturevalue_gl_linear_mipmap_nearest;
int32_t g_gltexturevalue_gl_mirrored_repeat;
int32_t g_gltexturevalue_gl_nearest;
int32_t g_gltexturevalue_gl_nearest_mipmap_linear;
int32_t g_gltexturevalue_gl_nearest_mipmap_nearest;
int32_t g_gltexturevalue_gl_repeat;
int32_t g_gridunittype_fixed;
int32_t g_gridunittype_star;
int32_t g_imagestretch_aspectratio;
int32_t g_imagestretch_center;
int32_t g_imagestretch_fill;
int32_t g_listlayoutorientation_bottomtop;
int32_t g_listlayoutorientation_leftright;
int32_t g_listlayoutorientation_rightleft;
int32_t g_listlayoutorientation_topbottom;
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;
int32_t g_mouseeventtype_down;
int32_t g_mouseeventtype_move;
int32_t g_mouseeventtype_up;
int32_t g_texthorizontal_center;
int32_t g_texthorizontal_left;
int32_t g_texthorizontal_right;
int32_t g_textvertical_bottom;
int32_t g_textvertical_center;
int32_t g_textvertical_top;

sjs_animator g_animator = { -1 };
sjs_shader g_blurhorizontalshader = { -1 };
sjs_shader g_blurverticalshader = { -1 };
sjs_shader g_boxshader = { -1 };
int32_t g_clocks_per_sec;
sjs_color g_colors_black = { -1 };
sjs_color g_colors_blue = { -1 };
sjs_color g_colors_gray = { -1 };
sjs_color g_colors_green = { -1 };
sjs_color g_colors_red = { -1 };
sjs_color g_colors_white = { -1 };
sjs_hash_string_weak_iface_element g_elementsbyid = { -1 };
float g_f32_pi;
sjs_shader g_fadeshader = { -1 };
sjs_hash_fontkey_weak_font g_fonthash = { -1 };
sjs_list_u32 g_glframebuffers = { -1 };
sjs_list_rect g_glviewports = { -1 };
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_shader g_imageshader = { -1 };
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
sjs_rect g_looplastrect = { -1 };
int32_t g_mainloop_frames;
int32_t g_mainloop_lasttick;
bool g_mainloop_shouldcontinue;
bool g_mainloop_showfps;
sjs_hash_string_weak_iface_model g_modelsbyid = { -1 };
sji_element g_mouse_captureelement = { 0 };
sjs_shader g_phongcolorshader = { -1 };
sjs_shader g_phongtextureshader = { -1 };
sji_element g_root = { 0 };
sjs_scene2d g_rootscene = { -1 };
sjs_windowrenderer g_rootwindowrenderer = { -1 };
sjs_shader g_saturateshader = { -1 };
sjs_style g_style = { -1 };
sjs_shader g_textshader = { -1 };
uint32_t g_u32_maxvalue;
sjs_string g_vertex_location_texture_normal_format = { -1 };
int32_t result1;
sjs_filllayout* sjt_call128 = 0;
sjs_blureffect* sjt_call129 = 0;
sjs_filllayout* sjt_call148 = 0;
sjs_fadeeffect* sjt_call149 = 0;
sjs_filllayout* sjt_call157 = 0;
sjs_saturateeffect* sjt_call158 = 0;
sjs_gridunit sjt_call166 = { -1 };
sjs_gridunit sjt_call167 = { -1 };
sjs_gridunit sjt_call168 = { -1 };
sjs_gridunit sjt_call169 = { -1 };
sjs_gridlayout* sjt_call3 = 0;
sjs_filllayout* sjt_call5 = 0;
sjs_filllayout* sjt_cast15 = 0;
sjs_blureffect* sjt_cast16 = 0;
sjs_gridlayout* sjt_cast2 = 0;
sjs_filllayout* sjt_cast21 = 0;
sjs_fadeeffect* sjt_cast22 = 0;
sjs_filllayout* sjt_cast23 = 0;
sjs_saturateeffect* sjt_cast24 = 0;
sjs_filllayout* sjt_cast4 = 0;
int32_t sjt_functionParam409;
sji_element sjt_functionParam410 = { 0 };
int32_t sjt_functionParam411;
sji_element sjt_functionParam412 = { 0 };
int32_t sjt_functionParam45;
sji_element sjt_functionParam46 = { 0 };
int32_t sjt_functionParam583;
sji_element sjt_functionParam584 = { 0 };
int32_t sjt_functionParam585;
sji_element sjt_functionParam586 = { 0 };
int32_t sjt_functionParam61;
sji_element sjt_functionParam62 = { 0 };
int32_t sjt_functionParam620;
sji_element sjt_functionParam621 = { 0 };
int32_t sjt_functionParam622;
sji_element sjt_functionParam623 = { 0 };
int32_t sjt_functionParam657;
sjs_gridunit* sjt_functionParam658 = 0;
int32_t sjt_functionParam659;
sjs_gridunit* sjt_functionParam660 = 0;
int32_t sjt_functionParam661;
sjs_gridunit* sjt_functionParam662 = 0;
int32_t sjt_functionParam663;
sjs_gridunit* sjt_functionParam664 = 0;
sjs_array_heap_iface_element* sjt_parent307 = 0;
sjs_array_heap_iface_element* sjt_parent308 = 0;
sjs_array_heap_iface_element* sjt_parent338 = 0;
sjs_array_heap_iface_element* sjt_parent339 = 0;
sjs_array_heap_iface_element* sjt_parent346 = 0;
sjs_array_heap_iface_element* sjt_parent347 = 0;
sjs_array_gridunit* sjt_parent354 = 0;
sjs_array_gridunit* sjt_parent355 = 0;
sjs_array_gridunit* sjt_parent356 = 0;
sjs_array_gridunit* sjt_parent357 = 0;
sjs_array_heap_iface_element* sjt_parent41 = 0;
sjs_array_heap_iface_element* sjt_parent64 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };
sji_effect sjt_value12 = { 0 };
sji_effect sjt_value4 = { 0 };
sji_effect sjt_value9 = { 0 };

void sjf_animator(sjs_animator* _this);
void sjf_animator_copy(sjs_animator* _this, sjs_animator* _from);
void sjf_animator_destroy(sjs_animator* _this);
void sjf_animator_heap(sjs_animator* _this);
void sjf_animator_nextframe(sjs_animator* _parent, int32_t time);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_create_i32(int32_t size, int32_t item, sjs_array_i32* _return);
void sjf_array_create_i32_heap(int32_t size, int32_t item, sjs_array_i32** _return);
void sjf_array_create_vec3(int32_t size, sjs_vec3* item, sjs_array_vec3* _return);
void sjf_array_create_vec3_heap(int32_t size, sjs_vec3* item, sjs_array_vec3** _return);
void sjf_array_gridunit(sjs_array_gridunit* _this);
void sjf_array_gridunit_copy(sjs_array_gridunit* _this, sjs_array_gridunit* _from);
void sjf_array_gridunit_destroy(sjs_array_gridunit* _this);
void sjf_array_gridunit_getat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* _return);
void sjf_array_gridunit_getat_heap(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit** _return);
void sjf_array_gridunit_getcount(sjs_array_gridunit* _parent, int32_t* _return);
void sjf_array_gridunit_heap(sjs_array_gridunit* _this);
void sjf_array_gridunit_initat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* item);
void sjf_array_heap_iface_animation(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from);
void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_animation_getat_heap(sjs_array_heap_iface_animation* _parent, int32_t index, sji_animation* _return);
void sjf_array_heap_iface_animation_getcount(sjs_array_heap_iface_animation* _parent, int32_t* _return);
void sjf_array_heap_iface_animation_heap(sjs_array_heap_iface_animation* _this);
void sjf_array_heap_iface_element(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from);
void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_getat_heap(sjs_array_heap_iface_element* _parent, int32_t index, sji_element* _return);
void sjf_array_heap_iface_element_getcount(sjs_array_heap_iface_element* _parent, int32_t* _return);
void sjf_array_heap_iface_element_heap(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_initat(sjs_array_heap_iface_element* _parent, int32_t index, sji_element item);
void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model__quicksortcallback(sjs_array_heap_iface_model* _parent, int32_t left, int32_t right, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_array_heap_iface_model_clone(sjs_array_heap_iface_model* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_heap_iface_model* _return);
void sjf_array_heap_iface_model_clone_heap(sjs_array_heap_iface_model* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_heap_iface_model** _return);
void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from);
void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_getat_heap(sjs_array_heap_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_array_heap_iface_model_getcount(sjs_array_heap_iface_model* _parent, int32_t* _return);
void sjf_array_heap_iface_model_gettotalcount(sjs_array_heap_iface_model* _parent, int32_t* _return);
void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_initat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_heap_iface_model_setat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_heap_iface_model_sortcb(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_clone(sjs_array_i32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_i32* _return);
void sjf_array_i32_clone_heap(sjs_array_i32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_i32** _return);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_getcount(sjs_array_i32* _parent, int32_t* _return);
void sjf_array_i32_gettotalcount(sjs_array_i32* _parent, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_i32_setat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_rect(sjs_array_rect* _this);
void sjf_array_rect_clone(sjs_array_rect* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_rect* _return);
void sjf_array_rect_clone_heap(sjs_array_rect* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_rect** _return);
void sjf_array_rect_copy(sjs_array_rect* _this, sjs_array_rect* _from);
void sjf_array_rect_destroy(sjs_array_rect* _this);
void sjf_array_rect_getat(sjs_array_rect* _parent, int32_t index, sjs_rect* _return);
void sjf_array_rect_getat_heap(sjs_array_rect* _parent, int32_t index, sjs_rect** _return);
void sjf_array_rect_getcount(sjs_array_rect* _parent, int32_t* _return);
void sjf_array_rect_gettotalcount(sjs_array_rect* _parent, int32_t* _return);
void sjf_array_rect_heap(sjs_array_rect* _this);
void sjf_array_rect_initat(sjs_array_rect* _parent, int32_t index, sjs_rect* item);
void sjf_array_u32(sjs_array_u32* _this);
void sjf_array_u32_clone(sjs_array_u32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_u32* _return);
void sjf_array_u32_clone_heap(sjs_array_u32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_u32** _return);
void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from);
void sjf_array_u32_destroy(sjs_array_u32* _this);
void sjf_array_u32_getat(sjs_array_u32* _parent, int32_t index, uint32_t* _return);
void sjf_array_u32_getcount(sjs_array_u32* _parent, int32_t* _return);
void sjf_array_u32_gettotalcount(sjs_array_u32* _parent, int32_t* _return);
void sjf_array_u32_heap(sjs_array_u32* _this);
void sjf_array_u32_initat(sjs_array_u32* _parent, int32_t index, uint32_t item);
void sjf_array_vec3(sjs_array_vec3* _this);
void sjf_array_vec3_copy(sjs_array_vec3* _this, sjs_array_vec3* _from);
void sjf_array_vec3_destroy(sjs_array_vec3* _this);
void sjf_array_vec3_getat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* _return);
void sjf_array_vec3_getat_heap(sjs_array_vec3* _parent, int32_t index, sjs_vec3** _return);
void sjf_array_vec3_heap(sjs_array_vec3* _this);
void sjf_array_vec3_setat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* item);
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_clone(sjs_array_vertex_location_texture_normal* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_clone_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_vertex_location_texture_normal** _return);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_getat_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal** _return);
void sjf_array_vertex_location_texture_normal_getcount(sjs_array_vertex_location_texture_normal* _parent, int32_t* _return);
void sjf_array_vertex_location_texture_normal_gettotalcount(sjs_array_vertex_location_texture_normal* _parent, int32_t* _return);
void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_array_vertex_location_texture_normal_setat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_blureffect(sjs_blureffect* _this);
void sjf_blureffect_as_sji_effect(sjs_blureffect* _this, sji_effect* _return);
void sjf_blureffect_asinterface(sjs_blureffect* _this, int typeId, sjs_interface* _return);
void sjf_blureffect_copy(sjs_blureffect* _this, sjs_blureffect* _from);
void sjf_blureffect_destroy(sjs_blureffect* _this);
void sjf_blureffect_getclasstype(sjs_object* _this, int* _return);
void sjf_blureffect_getrect(sjs_blureffect* _parent, sjs_rect* _return);
void sjf_blureffect_getrect_heap(sjs_blureffect* _parent, sjs_rect** _return);
void sjf_blureffect_heap(sjs_blureffect* _this);
void sjf_blureffect_render(sjs_blureffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb);
void sjf_blureffect_setrect(sjs_blureffect* _parent, sjs_rect* rect_, cb_rect_void cb);
void sjf_boxelement(sjs_boxelement* _this);
void sjf_boxelement_as_sji_element(sjs_boxelement* _this, sji_element* _return);
void sjf_boxelement_asinterface(sjs_boxelement* _this, int typeId, sjs_interface* _return);
void sjf_boxelement_copy(sjs_boxelement* _this, sjs_boxelement* _from);
void sjf_boxelement_destroy(sjs_boxelement* _this);
void sjf_boxelement_firemouseevent(sjs_boxelement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_boxelement_getclasstype(sjs_object* _this, int* _return);
void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect* _return);
void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return);
void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_boxelement_heap(sjs_boxelement* _this);
void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene);
void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_);
void sjf_boxrenderer(sjs_boxrenderer* _this);
void sjf_boxrenderer_copy(sjs_boxrenderer* _this, sjs_boxrenderer* _from);
void sjf_boxrenderer_destroy(sjs_boxrenderer* _this);
void sjf_boxrenderer_heap(sjs_boxrenderer* _this);
void sjf_boxrenderer_render(sjs_boxrenderer* _parent, sjs_scene2d* scene);
void sjf_boxvertexbuffer(sjs_boxvertexbuffer* _this);
void sjf_boxvertexbuffer_copy(sjs_boxvertexbuffer* _this, sjs_boxvertexbuffer* _from);
void sjf_boxvertexbuffer_destroy(sjs_boxvertexbuffer* _this);
void sjf_boxvertexbuffer_heap(sjs_boxvertexbuffer* _this);
void sjf_boxvertexbuffer_render(sjs_boxvertexbuffer* _parent, sjs_scene2d* scene);
void sjf_color(sjs_color* _this);
void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return);
void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_f32_asstring(float val, sjs_string* _return);
void sjf_f32_asstring_heap(float val, sjs_string** _return);
void sjf_f32_atan2(float y, float x, float* _return);
void sjf_f32_compare(float l, float r, int32_t* _return);
void sjf_f32_hash(float val, uint32_t* _return);
void sjf_f32_max(float a, float b, float* _return);
void sjf_f32_min(float a, float b, float* _return);
void sjf_f32_random(float* _return);
void sjf_f32_sqrt(float v, float* _return);
void sjf_f32_tan(float v, float* _return);
void sjf_fadeeffect_as_sji_effect(sjs_fadeeffect* _this, sji_effect* _return);
void sjf_fadeeffect_asinterface(sjs_fadeeffect* _this, int typeId, sjs_interface* _return);
void sjf_fadeeffect_copy(sjs_fadeeffect* _this, sjs_fadeeffect* _from);
void sjf_fadeeffect_destroy(sjs_fadeeffect* _this);
void sjf_fadeeffect_getclasstype(sjs_object* _this, int* _return);
void sjf_fadeeffect_getrect(sjs_fadeeffect* _parent, sjs_rect* _return);
void sjf_fadeeffect_getrect_heap(sjs_fadeeffect* _parent, sjs_rect** _return);
void sjf_fadeeffect_heap(sjs_fadeeffect* _this);
void sjf_fadeeffect_render(sjs_fadeeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb);
void sjf_fadeeffect_setrect(sjs_fadeeffect* _parent, sjs_rect* rect_, cb_rect_void cb);
void sjf_filllayout(sjs_filllayout* _this);
void sjf_filllayout_as_sji_element(sjs_filllayout* _this, sji_element* _return);
void sjf_filllayout_asinterface(sjs_filllayout* _this, int typeId, sjs_interface* _return);
void sjf_filllayout_copy(sjs_filllayout* _this, sjs_filllayout* _from);
void sjf_filllayout_destroy(sjs_filllayout* _this);
void sjf_filllayout_firemouseevent(sjs_filllayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_filllayout_getclasstype(sjs_object* _this, int* _return);
void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return);
void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return);
void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_filllayout_heap(sjs_filllayout* _this);
void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene);
void sjf_filllayout_renderinner(sjs_filllayout* _parent, sjs_scene2d* scene);
void sjf_filllayout_setrect(sjs_filllayout* _parent, sjs_rect* rect_);
void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect);
void sjf_font(sjs_font* _this);
void sjf_font_copy(sjs_font* _this, sjs_font* _from);
void sjf_font_destroy(sjs_font* _this);
void sjf_font_gettextsize(sjs_font* _parent, sjs_string* str, sjs_size* _return);
void sjf_font_gettextsize_heap(sjs_font* _parent, sjs_string* str, sjs_size** _return);
void sjf_font_heap(sjs_font* _this);
void sjf_font_load_heap(sjs_string* src, float size, sjs_font** _return);
void sjf_fontkey(sjs_fontkey* _this);
void sjf_fontkey_copy(sjs_fontkey* _this, sjs_fontkey* _from);
void sjf_fontkey_destroy(sjs_fontkey* _this);
void sjf_fontkey_hash(sjs_fontkey* _parent, uint32_t* _return);
void sjf_fontkey_heap(sjs_fontkey* _this);
void sjf_fontkey_isequal(sjs_fontkey* _parent, sjs_fontkey* x, bool* _return);
void sjf_framebuffer(sjs_framebuffer* _this);
void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from);
void sjf_framebuffer_destroy(sjs_framebuffer* _this);
void sjf_framebuffer_heap(sjs_framebuffer* _this);
void sjf_glbindrenderbuffer(sjs_renderbuffer* renderbuffer);
void sjf_glbindtexture(int32_t t, sjs_texture* texture);
void sjf_glblendfunc(int32_t sfactor, int32_t dfactor);
void sjf_glcheckframebufferstatus(int32_t* _return);
void sjf_glclearcolor(sjs_color* color);
void sjf_gldisable(int32_t feature);
void sjf_glenable(int32_t feature);
void sjf_glframebufferrenderbuffer(int32_t attachment, sjs_renderbuffer* renderbuffer);
void sjf_glframebuffertexture2d(int32_t attachment, int32_t target, sjs_texture* texture, int32_t level);
void sjf_glgenframebuffer(sjs_size* size, sjs_framebuffer* _return);
void sjf_glgenframebuffer_heap(sjs_size* size, sjs_framebuffer** _return);
void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return);
void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return);
void sjf_glgentexture(sjs_size* size, sjs_texture* _return);
void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return);
void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return);
void sjf_glpopframebuffer(sjs_framebuffer* framebuffer);
void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_glpushframebuffer(sjs_framebuffer* framebuffer);
void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_glrenderbufferstorage(int32_t format, sjs_size* size);
void sjf_glteximage2d(int32_t t, int32_t level, int32_t format, sjs_size* size, int32_t datatype, void* data);
void sjf_gltexparameteri(int32_t t, int32_t attribute, int32_t val);
void sjf_gluniformf32(int32_t loc, float v);
void sjf_gluniformi32(int32_t loc, int32_t v);
void sjf_gluniformmat4(int32_t loc, sjs_mat4* m);
void sjf_gluniformvec3(int32_t loc, sjs_vec3* v);
void sjf_gluseprogram(sjs_shader* shader);
void sjf_gridlayout(sjs_gridlayout* _this);
void sjf_gridlayout_as_sji_element(sjs_gridlayout* _this, sji_element* _return);
void sjf_gridlayout_asinterface(sjs_gridlayout* _this, int typeId, sjs_interface* _return);
void sjf_gridlayout_copy(sjs_gridlayout* _this, sjs_gridlayout* _from);
void sjf_gridlayout_destroy(sjs_gridlayout* _this);
void sjf_gridlayout_firemouseevent(sjs_gridlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_gridlayout_getclasstype(sjs_object* _this, int* _return);
void sjf_gridlayout_getrect(sjs_gridlayout* _parent, sjs_rect* _return);
void sjf_gridlayout_getrect_heap(sjs_gridlayout* _parent, sjs_rect** _return);
void sjf_gridlayout_getsize(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_gridlayout_getsize_heap(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_gridlayout_heap(sjs_gridlayout* _this);
void sjf_gridlayout_render(sjs_gridlayout* _parent, sjs_scene2d* scene);
void sjf_gridlayout_setrect(sjs_gridlayout* _parent, sjs_rect* rect_);
void sjf_gridunit(sjs_gridunit* _this);
void sjf_gridunit_copy(sjs_gridunit* _this, sjs_gridunit* _from);
void sjf_gridunit_destroy(sjs_gridunit* _this);
void sjf_gridunit_heap(sjs_gridunit* _this);
void sjf_halt(sjs_string* reason);
void sjf_hash_fontkey_weak_font(sjs_hash_fontkey_weak_font* _this);
void sjf_hash_fontkey_weak_font__weakptrremovekey(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key);
void sjf_hash_fontkey_weak_font__weakptrremovevalue(sjs_hash_fontkey_weak_font* _parent, sjs_font* val);
void sjf_hash_fontkey_weak_font_copy(sjs_hash_fontkey_weak_font* _this, sjs_hash_fontkey_weak_font* _from);
void sjf_hash_fontkey_weak_font_destroy(sjs_hash_fontkey_weak_font* _this);
void sjf_hash_fontkey_weak_font_getat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font** _return);
void sjf_hash_fontkey_weak_font_getat_heap(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font** _return);
void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this);
void sjf_hash_fontkey_weak_font_setat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font* val);
void sjf_hash_string_weak_iface_element(sjs_hash_string_weak_iface_element* _this);
void sjf_hash_string_weak_iface_element__weakptrremovekey(sjs_hash_string_weak_iface_element* _parent, sjs_string* key);
void sjf_hash_string_weak_iface_element__weakptrremovevalue(sjs_hash_string_weak_iface_element* _parent, sji_element val);
void sjf_hash_string_weak_iface_element_copy(sjs_hash_string_weak_iface_element* _this, sjs_hash_string_weak_iface_element* _from);
void sjf_hash_string_weak_iface_element_destroy(sjs_hash_string_weak_iface_element* _this);
void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this);
void sjf_hash_string_weak_iface_element_setat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element val);
void sjf_hash_string_weak_iface_model(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model__weakptrremovekey(sjs_hash_string_weak_iface_model* _parent, sjs_string* key);
void sjf_hash_string_weak_iface_model__weakptrremovevalue(sjs_hash_string_weak_iface_model* _parent, sji_model val);
void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from);
void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model_heap(sjs_hash_string_weak_iface_model* _this);
void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_light(sjs_light* _this);
void sjf_light_copy(sjs_light* _this, sjs_light* _from);
void sjf_light_destroy(sjs_light* _this);
void sjf_light_heap(sjs_light* _this);
void sjf_list_heap_iface_animation(sjs_list_heap_iface_animation* _this);
void sjf_list_heap_iface_animation_copy(sjs_list_heap_iface_animation* _this, sjs_list_heap_iface_animation* _from);
void sjf_list_heap_iface_animation_destroy(sjs_list_heap_iface_animation* _this);
void sjf_list_heap_iface_animation_getat_heap(sjs_list_heap_iface_animation* _parent, int32_t index, sji_animation* _return);
void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return);
void sjf_list_heap_iface_animation_heap(sjs_list_heap_iface_animation* _this);
void sjf_list_heap_iface_animation_removeat(sjs_list_heap_iface_animation* _parent, int32_t index);
void sjf_list_heap_iface_model(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_add(sjs_list_heap_iface_model* _parent, sji_model item);
void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from);
void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_getat_heap(sjs_list_heap_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return);
void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_list_i32(sjs_list_i32* _this);
void sjf_list_i32_add(sjs_list_i32* _parent, int32_t item);
void sjf_list_i32_copy(sjs_list_i32* _this, sjs_list_i32* _from);
void sjf_list_i32_destroy(sjs_list_i32* _this);
void sjf_list_i32_getat(sjs_list_i32* _parent, int32_t index, int32_t* _return);
void sjf_list_i32_getcount(sjs_list_i32* _parent, int32_t* _return);
void sjf_list_i32_heap(sjs_list_i32* _this);
void sjf_list_rect(sjs_list_rect* _this);
void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item);
void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from);
void sjf_list_rect_destroy(sjs_list_rect* _this);
void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return);
void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return);
void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return);
void sjf_list_rect_heap(sjs_list_rect* _this);
void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index);
void sjf_list_u32(sjs_list_u32* _this);
void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item);
void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from);
void sjf_list_u32_destroy(sjs_list_u32* _this);
void sjf_list_u32_getat(sjs_list_u32* _parent, int32_t index, uint32_t* _return);
void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return);
void sjf_list_u32_heap(sjs_list_u32* _this);
void sjf_list_u32_removeat(sjs_list_u32* _parent, int32_t index);
void sjf_list_vertex_location_texture_normal(sjs_list_vertex_location_texture_normal* _this);
void sjf_list_vertex_location_texture_normal_add(sjs_list_vertex_location_texture_normal* _parent, sjs_vertex_location_texture_normal* item);
void sjf_list_vertex_location_texture_normal_copy(sjs_list_vertex_location_texture_normal* _this, sjs_list_vertex_location_texture_normal* _from);
void sjf_list_vertex_location_texture_normal_destroy(sjs_list_vertex_location_texture_normal* _this);
void sjf_list_vertex_location_texture_normal_getat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_list_vertex_location_texture_normal_getat_heap(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal** _return);
void sjf_list_vertex_location_texture_normal_getcount(sjs_list_vertex_location_texture_normal* _parent, int32_t* _return);
void sjf_list_vertex_location_texture_normal_heap(sjs_list_vertex_location_texture_normal* _this);
void sjf_list_vertex_location_texture_normal_setat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_mainloop(void);
void sjf_margin(sjs_margin* _this);
void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from);
void sjf_margin_destroy(sjs_margin* _this);
void sjf_margin_heap(sjs_margin* _this);
void sjf_mat4(sjs_mat4* _this);
void sjf_mat4_copy(sjs_mat4* _this, sjs_mat4* _from);
void sjf_mat4_destroy(sjs_mat4* _this);
void sjf_mat4_determinant(sjs_mat4* _parent, float* _return);
void sjf_mat4_heap(sjs_mat4* _this);
void sjf_mat4_identity(sjs_mat4* _return);
void sjf_mat4_identity_heap(sjs_mat4** _return);
void sjf_mat4_invert(sjs_mat4* _parent, sjs_mat4* _return);
void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return);
void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return);
void sjf_mat4_lookatlh_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4** _return);
void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return);
void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return);
void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return);
void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return);
void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return);
void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return);
void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return);
void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return);
void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return);
void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4** _return);
void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return);
void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4** _return);
void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return);
void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return);
void sjf_model_as_sji_model(sjs_model* _this, sji_model* _return);
void sjf_model_asinterface(sjs_model* _this, int typeId, sjs_interface* _return);
void sjf_model_copy(sjs_model* _this, sjs_model* _from);
void sjf_model_destroy(sjs_model* _this);
void sjf_model_firemouseevent(sjs_model* _parent, sjs_mouseevent* mouseevent);
void sjf_model_getcenter(sjs_model* _parent, sjs_vec3* _return);
void sjf_model_getcenter_heap(sjs_model* _parent, sjs_vec3** _return);
void sjf_model_getclasstype(sjs_object* _this, int* _return);
void sjf_model_getworld(sjs_model* _parent, sjs_mat4* _return);
void sjf_model_getworld_heap(sjs_model* _parent, sjs_mat4** _return);
void sjf_model_getz(sjs_model* _parent, float* _return);
void sjf_model_heap(sjs_model* _this, sjs_model** _return);
void sjf_model_render(sjs_model* _parent);
void sjf_model_renderorqueue(sjs_model* _parent, sjs_list_heap_iface_model* zqueue);
void sjf_model_update(sjs_model* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return);
void sjf_model_zsort_callback(void * _parent, sji_model l, sji_model r, int32_t* _return);
void sjf_mouseevent(sjs_mouseevent* _this);
void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from);
void sjf_mouseevent_destroy(sjs_mouseevent* _this);
void sjf_mouseevent_firechildren(sjs_mouseevent* _parent, sjs_array_heap_iface_element* children, bool* _return);
void sjf_mouseevent_heap(sjs_mouseevent* _this);
void sjf_point(sjs_point* _this);
void sjf_point_copy(sjs_point* _this, sjs_point* _from);
void sjf_point_destroy(sjs_point* _this);
void sjf_point_heap(sjs_point* _this);
void sjf_rect(sjs_rect* _this);
void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_rect_heap(sjs_rect* _this);
void sjf_rect_isequal(sjs_rect* _parent, sjs_rect* rect, bool* _return);
void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return);
void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return);
void sjf_renderbuffer(sjs_renderbuffer* _this);
void sjf_renderbuffer_copy(sjs_renderbuffer* _this, sjs_renderbuffer* _from);
void sjf_renderbuffer_destroy(sjs_renderbuffer* _this);
void sjf_renderbuffer_heap(sjs_renderbuffer* _this);
void sjf_runloop(void);
void sjf_saturateeffect(sjs_saturateeffect* _this);
void sjf_saturateeffect_as_sji_effect(sjs_saturateeffect* _this, sji_effect* _return);
void sjf_saturateeffect_asinterface(sjs_saturateeffect* _this, int typeId, sjs_interface* _return);
void sjf_saturateeffect_copy(sjs_saturateeffect* _this, sjs_saturateeffect* _from);
void sjf_saturateeffect_destroy(sjs_saturateeffect* _this);
void sjf_saturateeffect_getclasstype(sjs_object* _this, int* _return);
void sjf_saturateeffect_getrect(sjs_saturateeffect* _parent, sjs_rect* _return);
void sjf_saturateeffect_getrect_heap(sjs_saturateeffect* _parent, sjs_rect** _return);
void sjf_saturateeffect_heap(sjs_saturateeffect* _this);
void sjf_saturateeffect_render(sjs_saturateeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb);
void sjf_saturateeffect_setrect(sjs_saturateeffect* _parent, sjs_rect* rect_, cb_rect_void cb);
void sjf_scene2d(sjs_scene2d* _this);
void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from);
void sjf_scene2d_destroy(sjs_scene2d* _this);
void sjf_scene2d_end(sjs_scene2d* _parent);
void sjf_scene2d_heap(sjs_scene2d* _this);
void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size);
void sjf_scene2d_start(sjs_scene2d* _parent);
void sjf_scene3delement(sjs_scene3delement* _this);
void sjf_scene3delement_as_sji_element(sjs_scene3delement* _this, sji_element* _return);
void sjf_scene3delement_asinterface(sjs_scene3delement* _this, int typeId, sjs_interface* _return);
void sjf_scene3delement_copy(sjs_scene3delement* _this, sjs_scene3delement* _from);
void sjf_scene3delement_destroy(sjs_scene3delement* _this);
void sjf_scene3delement_firemouseevent(sjs_scene3delement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_scene3delement_getclasstype(sjs_object* _this, int* _return);
void sjf_scene3delement_getrect(sjs_scene3delement* _parent, sjs_rect* _return);
void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return);
void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_scene3delement_heap(sjs_scene3delement* _this);
void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene);
void sjf_scene3delement_setrect(sjs_scene3delement* _parent, sjs_rect* rect_);
void sjf_scenebuffer(sjs_scenebuffer* _this);
void sjf_scenebuffer_copy(sjs_scenebuffer* _this, sjs_scenebuffer* _from);
void sjf_scenebuffer_destroy(sjs_scenebuffer* _this);
void sjf_scenebuffer_heap(sjs_scenebuffer* _this);
void sjf_shader(sjs_shader* _this);
void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from);
void sjf_shader_destroy(sjs_shader* _this);
void sjf_shader_heap(sjs_shader* _this);
void sjf_size(sjs_size* _this);
void sjf_size_addmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return);
void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return);
void sjf_size_copy(sjs_size* _this, sjs_size* _from);
void sjf_size_destroy(sjs_size* _this);
void sjf_size_heap(sjs_size* _this);
void sjf_size_isequal(sjs_size* _parent, sjs_size* size, bool* _return);
void sjf_size_max(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_size_subtractmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return);
void sjf_size_subtractmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sjf_string_nullterminate(sjs_string* _parent);
void sjf_style(sjs_style* _this);
void sjf_style_copy(sjs_style* _this, sjs_style* _from);
void sjf_style_destroy(sjs_style* _this);
void sjf_style_getfont_heap(sjs_style* _parent, sjs_font** _return);
void sjf_style_heap(sjs_style* _this);
void sjf_testscene_heap(sji_element* _return);
void sjf_textelement_as_sji_element(sjs_textelement* _this, sji_element* _return);
void sjf_textelement_as_sji_textelement(sjs_textelement* _this, sji_textelement* _return);
void sjf_textelement_asinterface(sjs_textelement* _this, int typeId, sjs_interface* _return);
void sjf_textelement_copy(sjs_textelement* _this, sjs_textelement* _from);
void sjf_textelement_destroy(sjs_textelement* _this);
void sjf_textelement_firemouseevent(sjs_textelement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_textelement_getclasstype(sjs_object* _this, int* _return);
void sjf_textelement_getrect(sjs_textelement* _parent, sjs_rect* _return);
void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return);
void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_textelement_gettext(sjs_textelement* _parent, sjs_string* _return);
void sjf_textelement_gettext_heap(sjs_textelement* _parent, sjs_string** _return);
void sjf_textelement_heap(sjs_textelement* _this);
void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene);
void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_);
void sjf_textelement_settext(sjs_textelement* _parent, sjs_string* text_);
void sjf_textrenderer(sjs_textrenderer* _this);
void sjf_textrenderer_copy(sjs_textrenderer* _this, sjs_textrenderer* _from);
void sjf_textrenderer_destroy(sjs_textrenderer* _this);
void sjf_textrenderer_heap(sjs_textrenderer* _this);
void sjf_textrenderer_render(sjs_textrenderer* _parent, sjs_scene2d* scene);
void sjf_texture(sjs_texture* _this);
void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from);
void sjf_texture_destroy(sjs_texture* _this);
void sjf_texture_frompng(sjs_string* filename, sjs_texture* _return);
void sjf_texture_frompng_heap(sjs_string* filename, sjs_texture** _return);
void sjf_texture_heap(sjs_texture* _this);
void sjf_type_hash(int32_t val, uint32_t* _return);
void sjf_type_isequal(int32_t l, int32_t r, bool* _return);
void sjf_vec2(sjs_vec2* _this);
void sjf_vec2_asstring(sjs_vec2* _parent, sjs_string* _return);
void sjf_vec2_asstring_heap(sjs_vec2* _parent, sjs_string** _return);
void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from);
void sjf_vec2_destroy(sjs_vec2* _this);
void sjf_vec2_getrawsize(int32_t* _return);
void sjf_vec2_heap(sjs_vec2* _this);
void sjf_vec2_rawcopy(sjs_vec2* v, void* p, void** _return);
void sjf_vec3(sjs_vec3* _this);
void sjf_vec3_add(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_add_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return);
void sjf_vec3_asstring(sjs_vec3* _parent, sjs_string* _return);
void sjf_vec3_asstring_heap(sjs_vec3* _parent, sjs_string** _return);
void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from);
void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return);
void sjf_vec3_destroy(sjs_vec3* _this);
void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return);
void sjf_vec3_getrawsize(int32_t* _return);
void sjf_vec3_heap(sjs_vec3* _this);
void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return);
void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return);
void sjf_vec3_rawcopy(sjs_vec3* v, void* p, void** _return);
void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return);
void sjf_vec4(sjs_vec4* _this);
void sjf_vec4_copy(sjs_vec4* _this, sjs_vec4* _from);
void sjf_vec4_destroy(sjs_vec4* _this);
void sjf_vec4_heap(sjs_vec4* _this);
void sjf_vertex_location_texture_normal(sjs_vertex_location_texture_normal* _this);
void sjf_vertex_location_texture_normal_copy(sjs_vertex_location_texture_normal* _this, sjs_vertex_location_texture_normal* _from);
void sjf_vertex_location_texture_normal_destroy(sjs_vertex_location_texture_normal* _this);
void sjf_vertex_location_texture_normal_getrawsize(int32_t* _return);
void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this);
void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return);
void sjf_vertexbuffer_loadobj(sjs_string* filename, sjs_vertexbuffer_vertex_location_texture_normal* _return);
void sjf_vertexbuffer_loadobj_heap(sjs_string* filename, sjs_vertexbuffer_vertex_location_texture_normal** _return);
void sjf_vertexbuffer_vertex_location_texture_normal(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_copy(sjs_vertexbuffer_vertex_location_texture_normal* _this, sjs_vertexbuffer_vertex_location_texture_normal* _from);
void sjf_vertexbuffer_vertex_location_texture_normal_destroy(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_heap(sjs_vertexbuffer_vertex_location_texture_normal* _this);
void sjf_vertexbuffer_vertex_location_texture_normal_render(sjs_vertexbuffer_vertex_location_texture_normal* _parent, int32_t gldrawmode);
void sjf_windowrenderer(sjs_windowrenderer* _this);
void sjf_windowrenderer_copy(sjs_windowrenderer* _this, sjs_windowrenderer* _from);
void sjf_windowrenderer_destroy(sjs_windowrenderer* _this);
void sjf_windowrenderer_getsize(sjs_windowrenderer* _parent, sjs_size* _return);
void sjf_windowrenderer_getsize_heap(sjs_windowrenderer* _parent, sjs_size** _return);
void sjf_windowrenderer_heap(sjs_windowrenderer* _this);
void sjf_windowrenderer_present(sjs_windowrenderer* _parent);
void main_destroy(void);

#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
char* string_char(sjs_string* str) {
    sjf_string_nullterminate(str);
    return ((sjs_array*)str->data.v)->data + str->offset;
}
#include <lib/sj-lib-common/common.cpp>
#ifndef string_weak_iface_model_hash_function
#define string_weak_iface_model_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_weak_iface_model_hash_type, sjs_string, sji_model, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_weak_iface_model_hash_type, sjs_string, sji_model, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_weak_iface_model_hash_function
#define string_weak_iface_model_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_weak_iface_model_hash_type, sjs_string, sji_model, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_weak_iface_model_hash_type, sjs_string, sji_model, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_weak_iface_element_hash_function
#define string_weak_iface_element_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_weak_iface_element_hash_type, sjs_string, sji_element, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_weak_iface_element_hash_type, sjs_string, sji_element, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
#ifndef string_weak_iface_element_hash_function
#define string_weak_iface_element_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(string_weak_iface_element_hash_type, sjs_string, sji_element, 1, sjf_string_hash, sjf_string_isequal)
#else
KHASH_INIT_FUNCTION(string_weak_iface_element_hash_type, sjs_string, sji_element, 1, sjf_string_hash, sjf_string_isequal)
#endif
#endif
double *
make_distance_mapd( double *data, unsigned int width, unsigned int height )
{
    short * xdist = (short *)  malloc( width * height * sizeof(short) );
    short * ydist = (short *)  malloc( width * height * sizeof(short) );
    double * gx   = (double *) calloc( width * height, sizeof(double) );
    double * gy      = (double *) calloc( width * height, sizeof(double) );
    double * outside = (double *) calloc( width * height, sizeof(double) );
    double * inside  = (double *) calloc( width * height, sizeof(double) );
    double vmin = DBL_MAX;
    unsigned int i;
    // Compute outside = edtaa3(bitmap); % Transform background (0's)
    computegradient( data, width, height, gx, gy);
    edtaa3(data, gx, gy, width, height, xdist, ydist, outside);
    for( i=0; i<width*height; ++i)
    if( outside[i] < 0.0 )
    outside[i] = 0.0;
    // Compute inside = edtaa3(1-bitmap); % Transform foreground (1's)
    memset( gx, 0, sizeof(double)*width*height );
    memset( gy, 0, sizeof(double)*width*height );
    for( i=0; i<width*height; ++i)
    data[i] = 1 - data[i];
    computegradient( data, width, height, gx, gy );
    edtaa3( data, gx, gy, width, height, xdist, ydist, inside );
    for( i=0; i<width*height; ++i )
    if( inside[i] < 0 )
    inside[i] = 0.0;
    // distmap = outside - inside; % Bipolar distance field
    for( i=0; i<width*height; ++i)
    {
        outside[i] -= inside[i];
        if( outside[i] < vmin )
        vmin = outside[i];
    }
    vmin = fabs(vmin);
    for( i=0; i<width*height; ++i)
    {
        double v = outside[i];
        if     ( v < -vmin) outside[i] = -vmin;
        else if( v > +vmin) outside[i] = +vmin;
        data[i] = (outside[i]+vmin)/(2*vmin);
    }
    free( xdist );
    free( ydist );
    free( gx );
    free( gy );
    free( outside );
    free( inside );
    return data;
}
unsigned char *
make_distance_mapb( unsigned char *img,
unsigned int width, unsigned int height )
{
    double * data    = (double *) calloc( width * height, sizeof(double) );
    unsigned char *out = (unsigned char *) malloc( width * height * sizeof(unsigned char) );
    unsigned int i;
    // find minimimum and maximum values
    double img_min = DBL_MAX;
    double img_max = DBL_MIN;
    for( i=0; i<width*height; ++i)
    {
        double v = img[i];
        data[i] = v;
        if (v > img_max)
        img_max = v;
        if (v < img_min)
        img_min = v;
    }
    // Map values from 0 - 255 to 0.0 - 1.0
    for( i=0; i<width*height; ++i)
    data[i] = (img[i]-img_min)/img_max;
    data = make_distance_mapd(data, width, height);
    // map values from 0.0 - 1.0 to 0 - 255
    for( i=0; i<width*height; ++i)
    out[i] = (unsigned char)(255*(1-data[i]));
    free( data );
    return out;
}
/*
* Compute the local gradient at edge pixels using convolution filters.
* The gradient is computed only at edge pixels. At other places in the
* image, it is never used, and it's mostly zero anyway.
*/
void computegradient(double *img, int w, int h, double *gx, double *gy)
{
    int i,j,k;
    double glength;
    #define SQRT2 1.4142136
    // Avoid edges where the kernels would spill over
    for(i = 1; i < h-1; i++) {
        for(j = 1; j < w-1; j++) {
            k = i*w + j;
            // Compute gradient for edge pixels only
            if((img[k]>0.0) && (img[k]<1.0)) {
                gx[k] = -img[k-w-1] - SQRT2*img[k-1] - img[k+w-1] + img[k-w+1] + SQRT2*img[k+1] + img[k+w+1];
                gy[k] = -img[k-w-1] - SQRT2*img[k-w] - img[k-w+1] + img[k+w-1] + SQRT2*img[k+w] + img[k+w+1];
                glength = gx[k]*gx[k] + gy[k]*gy[k];
                if(glength > 0.0) {
                    // Avoid division by zero
                    glength = sqrt(glength);
                    gx[k]=gx[k]/glength;
                    gy[k]=gy[k]/glength;
                }
            }
        }
    }
    // TODO: Compute reasonable values for gx, gy also around the image edges.
    // (These are zero now, which reduces the accuracy for a 1-pixel wide region
    // around the image edge.) 2x2 kernels would be suitable for this.
}
/*
* A somewhat tricky function to approximate the distance to an edge in a
* certain pixel, with consideration to either the local gradient (gx,gy)
* or the direction to the pixel (dx,dy) and the pixel greyscale value a.
* The latter alternative, using (dx,dy), is the metric used by edtaa2().
* Using a local estimate of the edge gradient (gx,gy) yields much better
* accuracy at and near edges, and reduces the error even at distant pixels
* provided that the gradient direction is accurately estimated.
*/
double edgedf(double gx, double gy, double a)
{
    double df, glength, temp, a1;
    // Either A) gu or gv are zero, or B) both
    if ((gx == 0) || (gy == 0)) {
        // Linear approximation is A) correct or B) a fair guess
        df = 0.5-a;  
    } else {
        glength = sqrt(gx*gx + gy*gy);
        if(glength>0) {
            gx = gx/glength;
            gy = gy/glength;
        }
        /* Everything is symmetric wrt sign and transposition,
        * so move to first octant (gx>=0, gy>=0, gx>=gy) to
        * avoid handling all possible edge directions.
        */
        gx = fabs(gx);
        gy = fabs(gy);
        if(gx<gy) {
            temp = gx;
            gx = gy;
            gy = temp;
        }
        a1 = 0.5*gy/gx;
        if (a < a1) {
            // 0 <= a < a1
            df = 0.5*(gx + gy) - sqrt(2.0*gx*gy*a);
        } else if (a < (1.0-a1)) {
            // a1 <= a <= 1-a1
            df = (0.5-a)*gx;
        } else {
            // 1-a1 < a <= 1
            df = -0.5*(gx + gy) + sqrt(2.0*gx*gy*(1.0-a));
        }
    }
    return df;
}
double distaa3(double *img, double *gximg, double *gyimg, int w, int c, int xc, int yc, int xi, int yi)
{
    double di, df, dx, dy, gx, gy, a;
    int closest;
    closest = c-xc-yc*w; // Index to the edge pixel pointed to from c
    a = img[closest];    // Grayscale value at the edge pixel
    gx = gximg[closest]; // X gradient component at the edge pixel
    gy = gyimg[closest]; // Y gradient component at the edge pixel
    if(a > 1.0) a = 1.0;
    if(a < 0.0) a = 0.0; // Clip grayscale values outside the range [0,1]
    if(a == 0.0) return 1000000.0; // Not an object pixel, return "very far" ("don't know yet")
    dx = (double)xi;
    dy = (double)yi;
    di = sqrt(dx*dx + dy*dy); // Length of integer vector, like a traditional EDT
    if(di==0) {
        // Use local gradient only at edges
        // Estimate based on local gradient only
        df = edgedf(gx, gy, a);
    } else {
        // Estimate gradient based on direction to edge (accurate for large di)
        df = edgedf(dx, dy, a);
    }
    return di + df; // Same metric as edtaa2, except at edges (where di=0)
}
// Shorthand macro: add ubiquitous parameters dist, gx, gy, img and w and call distaa3()
#define DISTAA(c,xc,yc,xi,yi) (distaa3(img, gx, gy, w, c, xc, yc, xi, yi))
void edtaa3(double *img, double *gx, double *gy, int w, int h, short *distx, short *disty, double *dist)
{
    int x, y, i, c;
    int offset_u, offset_ur, offset_r, offset_rd,
    offset_d, offset_dl, offset_l, offset_lu;
    double olddist, newdist;
    int cdistx, cdisty, newdistx, newdisty;
    int changed;
    double epsilon = 1e-3;
    /* Initialize index offsets for the current image width */
    offset_u = -w;
    offset_ur = -w+1;
    offset_r = 1;
    offset_rd = w+1;
    offset_d = w;
    offset_dl = w-1;
    offset_l = -1;
    offset_lu = -w-1;
    /* Initialize the distance images */
    for(i=0; i<w*h; i++) {
        distx[i] = 0; // At first, all pixels point to
        disty[i] = 0; // themselves as the closest known.
        if(img[i] <= 0.0)
        {
            dist[i]= 1000000.0; // Big value, means "not set yet"
        }
        else if (img[i]<1.0) {
            dist[i] = edgedf(gx[i], gy[i], img[i]); // Gradient-assisted estimate
        }
        else {
            dist[i]= 0.0; // Inside the object
        }
    }
    /* Perform the transformation */
    do
    {
        changed = 0;
        /* Scan rows, except first row */
        for(y=1; y<h; y++)
        {
            /* move index to leftmost pixel of current row */
            i = y*w;
            /* scan right, propagate distances from above & left */
            /* Leftmost pixel is special, has no left neighbors */
            olddist = dist[i];
            if(olddist > 0) // If non-zero distance or not set yet
            {
                c = i + offset_u; // Index of candidate for testing
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx;
                newdisty = cdisty+1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_ur;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx-1;
                newdisty = cdisty+1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    changed = 1;
                }
            }
            i++;
            /* Middle pixels have all neighbors */
            for(x=1; x<w-1; x++, i++)
            {
                olddist = dist[i];
                if(olddist <= 0) continue; // No need to update further
                c = i+offset_l;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx+1;
                newdisty = cdisty;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_lu;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx+1;
                newdisty = cdisty+1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_u;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx;
                newdisty = cdisty+1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_ur;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx-1;
                newdisty = cdisty+1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    changed = 1;
                }
            }
            /* Rightmost pixel of row is special, has no right neighbors */
            olddist = dist[i];
            if(olddist > 0) // If not already zero distance
            {
                c = i+offset_l;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx+1;
                newdisty = cdisty;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_lu;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx+1;
                newdisty = cdisty+1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_u;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx;
                newdisty = cdisty+1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    changed = 1;
                }
            }
            /* Move index to second rightmost pixel of current row. */
            /* Rightmost pixel is skipped, it has no right neighbor. */
            i = y*w + w-2;
            /* scan left, propagate distance from right */
            for(x=w-2; x>=0; x--, i--)
            {
                olddist = dist[i];
                if(olddist <= 0) continue; // Already zero distance
                c = i+offset_r;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx-1;
                newdisty = cdisty;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    changed = 1;
                }
            }
        }
        /* Scan rows in reverse order, except last row */
        for(y=h-2; y>=0; y--)
        {
            /* move index to rightmost pixel of current row */
            i = y*w + w-1;
            /* Scan left, propagate distances from below & right */
            /* Rightmost pixel is special, has no right neighbors */
            olddist = dist[i];
            if(olddist > 0) // If not already zero distance
            {
                c = i+offset_d;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx;
                newdisty = cdisty-1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_dl;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx+1;
                newdisty = cdisty-1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    changed = 1;
                }
            }
            i--;
            /* Middle pixels have all neighbors */
            for(x=w-2; x>0; x--, i--)
            {
                olddist = dist[i];
                if(olddist <= 0) continue; // Already zero distance
                c = i+offset_r;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx-1;
                newdisty = cdisty;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_rd;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx-1;
                newdisty = cdisty-1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_d;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx;
                newdisty = cdisty-1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_dl;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx+1;
                newdisty = cdisty-1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    changed = 1;
                }
            }
            /* Leftmost pixel is special, has no left neighbors */
            olddist = dist[i];
            if(olddist > 0) // If not already zero distance
            {
                c = i+offset_r;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx-1;
                newdisty = cdisty;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_rd;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx-1;
                newdisty = cdisty-1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    olddist=newdist;
                    changed = 1;
                }
                c = i+offset_d;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx;
                newdisty = cdisty-1;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    changed = 1;
                }
            }
            /* Move index to second leftmost pixel of current row. */
            /* Leftmost pixel is skipped, it has no left neighbor. */
            i = y*w + 1;
            for(x=1; x<w; x++, i++)
            {
                /* scan right, propagate distance from left */
                olddist = dist[i];
                if(olddist <= 0) continue; // Already zero distance
                c = i+offset_l;
                cdistx = distx[c];
                cdisty = disty[c];
                newdistx = cdistx+1;
                newdisty = cdisty;
                newdist = DISTAA(c, cdistx, cdisty, newdistx, newdisty);
                if(newdist < olddist-epsilon)
                {
                    distx[i]=newdistx;
                    disty[i]=newdisty;
                    dist[i]=newdist;
                    changed = 1;
                }
            }
        }
    }
    while(changed); // Sweep until no more updates are made
    /* The transformation is completed. */
}
#ifndef fontkey_weak_font_hash_function
#define fontkey_weak_font_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*, 1, sjf_fontkey_hash, sjf_fontkey_isequal)
#else
KHASH_INIT_FUNCTION(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*, 1, sjf_fontkey_hash, sjf_fontkey_isequal)
#endif
#endif
#ifndef fontkey_weak_font_hash_function
#define fontkey_weak_font_hash_function
#if true
KHASH_INIT_FUNCTION_DEREF(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*, 1, sjf_fontkey_hash, sjf_fontkey_isequal)
#else
KHASH_INIT_FUNCTION(fontkey_weak_font_hash_type, sjs_fontkey, sjs_font*, 1, sjf_fontkey_hash, sjf_fontkey_isequal)
#endif
#endif
KHASH_INIT_TYPEDEF(glid_hash_type, GLuint, int)
KHASH_INIT_FUNCTION(glid_hash_type, GLuint, int, 1, glid_gethash, glid_isequal)
khash_t(glid_hash_type)* glid_hash;
void glid_gethash(GLuint id, uint32_t* result) {
    *result = kh_int_hash_func(id);
}
void glid_isequal(GLuint id1, GLuint id2, bool* result) {
    *result = (id1 == id2);
}
void glid_init() {
    glid_hash = kh_init(glid_hash_type);
}
void glid_retain(GLuint id) {
    khiter_t k = kh_get(glid_hash_type, glid_hash, id);
    if (k == kh_end(glid_hash)) {
        int ret;
        khiter_t k = kh_put(glid_hash_type, glid_hash, id, &ret);
        if (!ret) kh_del(glid_hash_type, glid_hash, k);
        kh_value(glid_hash, k) = 1;
    }
    else {
        kh_value(glid_hash, k)++;
    }
}
bool glid_release(GLuint id) {
    khiter_t k = kh_get(glid_hash_type, glid_hash, id);
    if (k != kh_end(glid_hash)) {
        kh_value(glid_hash, k)--;
        if (kh_value(glid_hash, k) == 0) {
            kh_del(glid_hash_type, glid_hash, k);
        }
        return false;
    }
    return true;
}
char *repl_str(const char *str, const char *from, const char *to) {
    /* Adjust each of the below values to suit your needs. */
    /* Increment positions cache size initially by this number. */
    size_t cache_sz_inc = 16;
    /* Thereafter, each time capacity needs to be increased,
    * multiply the increment by this factor. */
    const size_t cache_sz_inc_factor = 3;
    /* But never increment capacity by more than this number. */
    const size_t cache_sz_inc_max = 1048576;
    char *pret, *ret = NULL;
    const char *pstr2, *pstr = str;
    size_t i, count = 0;
    #if (__STDC_VERSION__ >= 199901L)
    uintptr_t *pos_cache_tmp, *pos_cache = NULL;
    #else
    ptrdiff_t *pos_cache_tmp, *pos_cache = NULL;
    #endif
    size_t cache_sz = 0;
    size_t cpylen, orglen, retlen, tolen = 0, fromlen = strlen(from);
    /* Find all matches and cache their positions. */
    while ((pstr2 = strstr(pstr, from)) != NULL) {
        count++;
        /* Increase the cache size when necessary. */
        if (cache_sz < count) {
            cache_sz += cache_sz_inc;
            #if (__STDC_VERSION__ >= 199901L)
            pos_cache_tmp = (uintptr_t*)realloc(pos_cache, sizeof(*pos_cache) * cache_sz);
            #else
            pos_cache_tmp = (ptrdiff_t*)realloc(pos_cache, sizeof(*pos_cache) * cache_sz);
            #endif
            if (pos_cache_tmp == NULL) {
                goto end_repl_str;
            } else pos_cache = pos_cache_tmp;
            cache_sz_inc *= cache_sz_inc_factor;
            if (cache_sz_inc > cache_sz_inc_max) {
                cache_sz_inc = cache_sz_inc_max;
            }
        }
        pos_cache[count-1] = pstr2 - str;
        pstr = pstr2 + fromlen;
    }
    orglen = pstr - str + strlen(pstr);
    /* Allocate memory for the post-replacement string. */
    if (count > 0) {
        tolen = strlen(to);
        retlen = orglen + (tolen - fromlen) * count;
    } else  retlen = orglen;
    ret = (char*)malloc(retlen + 1);
    if (ret == NULL) {
        goto end_repl_str;
    }
    if (count == 0) {
        /* If no matches, then just duplicate the string. */
        strcpy(ret, str);
    } else {
        /* Otherwise, duplicate the string whilst performing
        * the replacements using the position cache. */
        pret = ret;
        memcpy(pret, str, pos_cache[0]);
        pret += pos_cache[0];
        for (i = 0; i < count; i++) {
            memcpy(pret, to, tolen);
            pret += tolen;
            pstr = str + pos_cache[i] + fromlen;
            cpylen = (i == count-1 ? orglen : pos_cache[i+1]) - pos_cache[i] - fromlen;
            memcpy(pret, pstr, cpylen);
            pret += cpylen;
        }
        ret[retlen] = '\0';
    }
    end_repl_str:
    /* Free the cache and return the post-replacement string,
    * which will be NULL in the event of an error. */
    free(pos_cache);
    return ret;
}
// ------------------------------------------------------------ shader_read ---
char *
shader_read( const char *filename )
{
    FILE * file;
    char * buffer;
    size_t size;
    #ifdef WIN32
    errno_t err;
    if( (err  = fopen_s( &file, filename, "rb" )) !=0 ) {
        #else
        file = fopen( filename, "rb" );
        if( !file ) {
            #endif
            fprintf( stderr, "Unable to open file \"%s\".\n", filename );
            return 0;
        }
        fseek( file, 0, SEEK_END );
        size = ftell( file );
        fseek(file, 0, SEEK_SET );
        buffer = (char *) malloc( (size+1) * sizeof( char *) );
        fread( buffer, sizeof(char), size, file );
        buffer[size] = 0;
        fclose( file );
        #ifdef __APPLE__
        char* prev = buffer;
        buffer = repl_str(buffer, "mediump", "");
        free(prev);
        #endif
        return buffer;
    }
    // --------------------------------------------------------- shader_compile ---
    GLuint
    shader_compile( const char* source,
    const GLenum type )
    {
        GLint compile_status;
        GLuint handle = glCreateShader( type );
        glShaderSource( handle, 1, &source, 0 );
        glCompileShader( handle );
        glGetShaderiv( handle, GL_COMPILE_STATUS, &compile_status );
        if( compile_status == GL_FALSE )
        {
            GLchar messages[256];
            glGetShaderInfoLog( handle, sizeof(messages), 0, &messages[0] );
            halt("%s: %s\n", source, messages);
        }
        return handle;
    }
    // ------------------------------------------------------------ shader_load ---
    GLuint
    shader_load( const char * vert_filename,
    const char * frag_filename )
    {
        GLuint handle = glCreateProgram( );
        GLint link_status;
        if( vert_filename && strlen( vert_filename ) )
        {
            char *vert_source = shader_read( vert_filename );
            GLuint vert_shader = shader_compile( vert_source, GL_VERTEX_SHADER);
            glAttachShader( handle, vert_shader);
            glDeleteShader( vert_shader );
            free( vert_source );
        }
        if( frag_filename && strlen( frag_filename ) )
        {
            char *frag_source = shader_read( frag_filename );
            GLuint frag_shader = shader_compile( frag_source, GL_FRAGMENT_SHADER);
            glAttachShader( handle, frag_shader);
            glDeleteShader( frag_shader );
            free( frag_source );
        }
        glLinkProgram( handle );
        glGetProgramiv( handle, GL_LINK_STATUS, &link_status );
        if (link_status == GL_FALSE)
        {
            GLchar messages[256];
            glGetProgramInfoLog( handle, sizeof(messages), 0, &messages[0] );
            halt("%s\n", messages );
        }
        return handle;
    }
    void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, int textlen, vec4 * color, vec2 * pen) {
        pen->y += (float)(int)font->ascender;
        size_t i;
        float r = color->red, g = color->green, b = color->blue, a = color->alpha;
        for (i = 0; i < (size_t)textlen; ++i) {
            texture_glyph_t *glyph = texture_font_get_glyph( font, text + i );
            if (glyph != NULL) {
                float kerning = 0.0f;
                if( i > 0) {
                    kerning = texture_glyph_get_kerning( glyph, text + i - 1 );
                }
                pen->x += kerning;
                float x0 = (float)(int)( pen->x + glyph->offset_x );
                float y0 = (float)(int)( pen->y + glyph->height - glyph->offset_y );
                float x1 = (float)(int)( x0 + glyph->width );
                float y1 = (float)(int)( y0 - glyph->height );
                float s0 = glyph->s0;
                float t0 = glyph->t0;
                float s1 = glyph->s1;
                float t1 = glyph->t1;
                GLuint index = (GLuint)buffer->vertices->size;
                GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
                vertex3_texture2_color3_t vertices[] = { //
                { x0, y1, 0.0f,  s0,t0,  r,g,b,a },
                { x0, y0, 0.0f,  s0,t1,  r,g,b,a },
                { x1, y0, 0.0f,  s1,t1,  r,g,b,a },
                { x1, y1, 0.0f,  s1,t0,  r,g,b,a } };
                vertex_buffer_push_back_indices( buffer, indices, 6 );
                vertex_buffer_push_back_vertices( buffer, vertices, 4 );
                pen->x += glyph->advance_x;
            }
        }
    }   
    vec2 get_text_size(texture_font_t * font, char *text) {
        vec2 size = {{ 0, font->height }};
        size_t i;
        for( i = 0; i < strlen(text); ++i ) {
            texture_glyph_t *glyph = texture_font_get_glyph(font, text + i);
            if (glyph != NULL) {
                float kerning = 0.0f;
                if( i > 0) {
                    kerning = texture_glyph_get_kerning(glyph, text + i - 1);
                }
                size.x += kerning;
                size.x += glyph->advance_x;
            }
        }
        return size;
    }   
    GLuint png_texture_load(const char * file_name, int * width, int * height)
    {
        // This function was originally written by David Grayson for
        // https://github.com/DavidEGrayson/ahrs-visualizer
        png_byte header[8];
        FILE *fp = fopen(file_name, "rb");
        if (fp == 0)
        {
            perror(file_name);
            return 0;
        }
        // read the header
        fread(header, 1, 8, fp);
        if (png_sig_cmp(header, 0, 8))
        {
            fprintf(stderr, "error: %s is not a PNG.\n", file_name);
            fclose(fp);
            return 0;
        }
        png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        if (!png_ptr)
        {
            fprintf(stderr, "error: png_create_read_struct returned 0.\n");
            fclose(fp);
            return 0;
        }
        // create png info struct
        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr)
        {
            fprintf(stderr, "error: png_create_info_struct returned 0.\n");
            png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
            fclose(fp);
            return 0;
        }
        // create png info struct
        png_infop end_info = png_create_info_struct(png_ptr);
        if (!end_info)
        {
            fprintf(stderr, "error: png_create_info_struct returned 0.\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
            fclose(fp);
            return 0;
        }
        // the code in this if statement gets called if libpng encounters an error
        if (setjmp(png_jmpbuf(png_ptr))) {
            fprintf(stderr, "error from libpng\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return 0;
        }
        // init png reading
        png_init_io(png_ptr, fp);
        // let libpng know you already read the first 8 bytes
        png_set_sig_bytes(png_ptr, 8);
        // read all the info up to the image data
        png_read_info(png_ptr, info_ptr);
        // variables to pass to get info
        int bit_depth, color_type;
        png_uint_32 temp_width, temp_height;
        // get info about png
        png_get_IHDR(png_ptr, info_ptr, &temp_width, &temp_height, &bit_depth, &color_type,
        NULL, NULL, NULL);
        if (width){ *width = temp_width; }
        if (height){ *height = temp_height; }
        //printf("%s: %lux%lu %d\n", file_name, temp_width, temp_height, color_type);
        if (bit_depth != 8)
        {
            fprintf(stderr, "%s: Unsupported bit depth %d.  Must be 8.\n", file_name, bit_depth);
            return 0;
        }
        GLint format;
        switch(color_type)
        {
            case PNG_COLOR_TYPE_RGB:
            format = GL_RGB;
            break;
            case PNG_COLOR_TYPE_RGB_ALPHA:
            format = GL_RGBA;
            break;
            default:
            fprintf(stderr, "%s: Unknown libpng color type %d.\n", file_name, color_type);
            return 0;
        }
        // Update the png info struct.
        png_read_update_info(png_ptr, info_ptr);
        // Row size in bytes.
        int rowbytes = (int)png_get_rowbytes(png_ptr, info_ptr);
        // glTexImage2d requires rows to be 4-byte aligned
        rowbytes += 3 - ((rowbytes-1) % 4);
        // Allocate the image_data as a big block, to be given to opengl
        png_byte * image_data = (png_byte *)malloc(rowbytes * temp_height * sizeof(png_byte)+15);
        if (image_data == NULL)
        {
            fprintf(stderr, "error: could not allocate memory for PNG image data\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return 0;
        }
        // row_pointers is for pointing to image_data for reading the png with libpng
        png_byte ** row_pointers = (png_byte **)malloc(temp_height * sizeof(png_byte *));
        if (row_pointers == NULL)
        {
            fprintf(stderr, "error: could not allocate memory for PNG row pointers\n");
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            free(image_data);
            fclose(fp);
            return 0;
        }
        // set the individual row_pointers to point at the correct offsets of image_data
        for (unsigned int i = 0; i < temp_height; i++)
        {
            row_pointers[temp_height - 1 - i] = image_data + i * rowbytes;
        }
        // read the png into image_data through row_pointers
        png_read_image(png_ptr, row_pointers);
        // Generate the OpenGL texture object
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexImage2D(GL_TEXTURE_2D, 0, format, temp_width, temp_height, 0, format, GL_UNSIGNED_BYTE, image_data);
        // clean up
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        free(image_data);
        free(row_pointers);
        fclose(fp);
        return texture;
    }
    // ------------------------------------------------------ texture_atlas_new ---
    texture_atlas_t *
    texture_atlas_new( const size_t width,
    const size_t height,
    const size_t depth )
    {
        texture_atlas_t *self = (texture_atlas_t *) malloc( sizeof(texture_atlas_t) );
        // We want a one pixel border around the whole atlas to avoid any artefact when
        // sampling texture
        ivec3 node = {{1,1, (int)width-2}};
        assert( (depth == 1) || (depth == 3) || (depth == 4) );
        if( self == NULL)
        {
            halt("line %d: No more memory for allocating data\n", __LINE__ );
        }
        self->nodes = vector_new( sizeof(ivec3) );
        self->used = 0;
        self->width = width;
        self->height = height;
        self->depth = depth;
        self->id = 0;
        vector_push_back( self->nodes, &node );
        self->data = (unsigned char *)
        calloc( width*height*depth, sizeof(unsigned char) );
        if( self->data == NULL)
        {
            halt("line %d: No more memory for allocating data\n", __LINE__ );
        }
        return self;
    }
    // --------------------------------------------------- texture_atlas_delete ---
    void
    texture_atlas_delete( texture_atlas_t *self )
    {
        assert( self );
        vector_delete( self->nodes );
        if( self->data )
        {
            free( self->data );
        }
        free( self );
    }
    // ----------------------------------------------- texture_atlas_set_region ---
    void
    texture_atlas_set_region( texture_atlas_t * self,
    const size_t x,
    const size_t y,
    const size_t width,
    const size_t height,
    const unsigned char * data,
    const size_t stride )
    {
        size_t i;
        size_t depth;
        size_t charsize;
        assert( self );
        assert( x > 0);
        assert( y > 0);
        assert( x < (self->width-1));
        assert( (x + width) <= (self->width-1));
        assert( y < (self->height-1));
        assert( (y + height) <= (self->height-1));
        //prevent copying data from undefined position 
        //and prevent memcpy's undefined behavior when count is zero
        assert(height == 0 || (data != NULL && width > 0));
        depth = self->depth;
        charsize = sizeof(char);
        for( i=0; i<height; ++i )
        {
            memcpy( self->data+((y+i)*self->width + x ) * charsize * depth,
            data + (i*stride) * charsize, width * charsize * depth  );
        }
    }
    // ------------------------------------------------------ texture_atlas_fit ---
    int
    texture_atlas_fit( texture_atlas_t * self,
    const size_t index,
    const size_t width,
    const size_t height )
    {
        ivec3 *node;
        int x, y, width_left;
        size_t i;
        assert( self );
        node = (ivec3 *) (vector_get( self->nodes, index ));
        x = node->x;
        y = node->y;
        width_left = (int)width;
        i = index;
        if ( (x + width) > (self->width-1) )
        {
            return -1;
        }
        y = node->y;
        while( width_left > 0 )
        {
            node = (ivec3 *) (vector_get( self->nodes, i ));
            if( node->y > y )
            {
                y = node->y;
            }
            if( (y + height) > (self->height-1) )
            {
                return -1;
            }
            width_left -= node->z;
            ++i;
        }
        return y;
    }
    // ---------------------------------------------------- texture_atlas_merge ---
    void
    texture_atlas_merge( texture_atlas_t * self )
    {
        ivec3 *node, *next;
        size_t i;
        assert( self );
        for( i=0; i< self->nodes->size-1; ++i )
        {
            node = (ivec3 *) (vector_get( self->nodes, i ));
            next = (ivec3 *) (vector_get( self->nodes, i+1 ));
            if( node->y == next->y )
            {
                node->z += next->z;
                vector_erase( self->nodes, i+1 );
                --i;
            }
        }
    }
    // ----------------------------------------------- texture_atlas_get_region ---
    ivec4
    texture_atlas_get_region( texture_atlas_t * self,
    const size_t width,
    const size_t height )
    {
        int y, best_index;
        size_t best_height, best_width;
        ivec3 *node, *prev;
        ivec4 region = {{0,0,(int)width,(int)height}};
        size_t i;
        assert( self );
        best_height = UINT_MAX;
        best_index  = -1;
        best_width = UINT_MAX;
        for( i=0; i<self->nodes->size; ++i )
        {
            y = texture_atlas_fit( self, i, width, height );
            if( y >= 0 )
            {
                node = (ivec3 *) vector_get( self->nodes, i );
                if( ( (y + height) < best_height ) ||
                ( ((y + height) == best_height) && (node->z > 0 && (size_t)node->z < best_width)) )
                {
                    best_height = y + height;
                    best_index = (int)i;
                    best_width = node->z;
                    region.x = node->x;
                    region.y = y;
                }
            }
        }
        if( best_index == -1 )
        {
            region.x = -1;
            region.y = -1;
            region.width = 0;
            region.height = 0;
            return region;
        }
        node = (ivec3 *) malloc( sizeof(ivec3) );
        if( node == NULL)
        {
            halt("line %d: No more memory for allocating data\n", __LINE__ );
        }
        node->x = region.x;
        node->y = (int)(region.y + height);
        node->z = (int)width;
        vector_insert( self->nodes, best_index, node );
        free( node );
        for(i = best_index+1; i < self->nodes->size; ++i)
        {
            node = (ivec3 *) vector_get( self->nodes, i );
            prev = (ivec3 *) vector_get( self->nodes, i-1 );
            if (node->x < (prev->x + prev->z) )
            {
                int shrink = prev->x + prev->z - node->x;
                node->x += shrink;
                node->z -= shrink;
                if (node->z <= 0)
                {
                    vector_erase( self->nodes, i );
                    --i;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        texture_atlas_merge( self );
        self->used += width * height;
        return region;
    }
    // ---------------------------------------------------- texture_atlas_clear ---
    void
    texture_atlas_clear( texture_atlas_t * self )
    {
        ivec3 node = {{1,1,1}};
        assert( self );
        assert( self->data );
        vector_clear( self->nodes );
        self->used = 0;
        // We want a one pixel border around the whole atlas to avoid any artefact when
        // sampling texture
        node.z = (int)(self->width-2);
        vector_push_back( self->nodes, &node );
        memset( self->data, 0, self->width*self->height*self->depth );
    }
    #define HRES  64
    #define HRESf 64.f
    #define DPI   72
    // ------------------------------------------------- texture_font_load_face ---
    static int
    texture_font_load_face(texture_font_t *self, float size,
    FT_Library *library, FT_Face *face)
    {
        FT_Error error;
        FT_Matrix matrix = { //
        (int)((1.0/HRES) * 0x10000L),
        (int)((0.0)      * 0x10000L),
        (int)((0.0)      * 0x10000L),
        (int)((1.0)      * 0x10000L)};
        assert(library);
        assert(size);
        /* Initialize library */
        error = FT_Init_FreeType(library);
        if(error) {
            fprintf(stderr, "FT_Error (0x%02x) : %s\n",
            FT_Errors[error].code, FT_Errors[error].message);
            goto cleanup;
        }
        /* Load face */
        switch (self->location) {
            case TEXTURE_FONT_FILE:
            error = FT_New_Face(*library, self->filename, 0, face);
            break;
            case TEXTURE_FONT_MEMORY:
            error = FT_New_Memory_Face(*library,
            (const FT_Byte*)self->memory.base, self->memory.size, 0, face);
            break;
        }
        if(error) {
            fprintf(stderr, "FT_Error (line %d, code 0x%02x) : %s\n",
            __LINE__, FT_Errors[error].code, FT_Errors[error].message);
            goto cleanup_library;
        }
        /* Select charmap */
        error = FT_Select_Charmap(*face, FT_ENCODING_UNICODE);
        if(error) {
            fprintf(stderr, "FT_Error (line %d, code 0x%02x) : %s\n",
            __LINE__, FT_Errors[error].code, FT_Errors[error].message);
            goto cleanup_face;
        }
        /* Set char size */
        error = FT_Set_Char_Size(*face, (int)(size * HRES), 0, DPI * HRES, DPI);
        if(error) {
            fprintf(stderr, "FT_Error (line %d, code 0x%02x) : %s\n",
            __LINE__, FT_Errors[error].code, FT_Errors[error].message);
            goto cleanup_face;
        }
        /* Set transform matrix */
        FT_Set_Transform(*face, &matrix, NULL);
        return 1;
        cleanup_face:
        FT_Done_Face( *face );
        cleanup_library:
        FT_Done_FreeType( *library );
        cleanup:
        return 0;
    }
    // ------------------------------------------------------ texture_glyph_new ---
    texture_glyph_t *
    texture_glyph_new(void)
    {
        texture_glyph_t *self = (texture_glyph_t *) malloc( sizeof(texture_glyph_t) );
        if(self == NULL) {
            fprintf( stderr,
            "line %d: No more memory for allocating data\n", __LINE__);
            return NULL;
        }
        self->codepoint  = -1;
        self->width     = 0;
        self->height    = 0;
        self->rendermode = RENDER_NORMAL;
        self->outline_thickness = 0.0;
        self->offset_x  = 0;
        self->offset_y  = 0;
        self->advance_x = 0.0;
        self->advance_y = 0.0;
        self->s0        = 0.0;
        self->t0        = 0.0;
        self->s1        = 0.0;
        self->t1        = 0.0;
        self->kerning   = vector_new( sizeof(kerning_t) );
        return self;
    }
    // --------------------------------------------------- texture_glyph_delete ---
    void
    texture_glyph_delete( texture_glyph_t *self )
    {
        assert( self );
        vector_delete( self->kerning );
        free( self );
    }
    // ---------------------------------------------- texture_glyph_get_kerning ---
    float
    texture_glyph_get_kerning( const texture_glyph_t * self,
    const char * codepoint )
    {
        size_t i;
        uint32_t ucodepoint = utf8_to_utf32( codepoint );
        assert( self );
        for( i=0; i<vector_size(self->kerning); ++i )
        {
            kerning_t * kerning = (kerning_t *) vector_get( self->kerning, i );
            if( kerning->codepoint == ucodepoint )
            {
                return kerning->kerning;
            }
        }
        return 0;
    }
    // ------------------------------------------ texture_font_generate_kerning ---
    void
    texture_font_generate_kerning( texture_font_t *self,
    FT_Library *library, FT_Face *face )
    {
        size_t i, j;
        FT_UInt glyph_index, prev_index;
        texture_glyph_t *glyph, *prev_glyph;
        FT_Vector kerning;
        assert( self );
        /* For each glyph couple combination, check if kerning is necessary */
        /* Starts at index 1 since 0 is for the special backgroudn glyph */
        for( i=1; i<self->glyphs->size; ++i )
        {
            glyph = *(texture_glyph_t **) vector_get( self->glyphs, i );
            glyph_index = FT_Get_Char_Index( *face, glyph->codepoint );
            vector_clear( glyph->kerning );
            for( j=1; j<self->glyphs->size; ++j )
            {
                prev_glyph = *(texture_glyph_t **) vector_get( self->glyphs, j );
                prev_index = FT_Get_Char_Index( *face, prev_glyph->codepoint );
                FT_Get_Kerning( *face, prev_index, glyph_index, FT_KERNING_UNFITTED, &kerning );
                // printf("%c(%d)-%c(%d): %ld\n",
                //       prev_glyph->codepoint, prev_glyph->codepoint,
                //       glyph_index, glyph_index, kerning.x);
                if( kerning.x )
                {
                    kerning_t k = {prev_glyph->codepoint, kerning.x / (float)(HRESf*HRESf)};
                    vector_push_back( glyph->kerning, &k );
                }
            }
        }
    }
    // ------------------------------------------------------ texture_font_init ---
    static int
    texture_font_init(texture_font_t *self)
    {
        FT_Library library;
        FT_Face face;
        FT_Size_Metrics metrics;
        assert(self->atlas);
        assert(self->size > 0);
        assert((self->location == TEXTURE_FONT_FILE && self->filename)
        || (self->location == TEXTURE_FONT_MEMORY
        && self->memory.base && self->memory.size));
        self->glyphs = vector_new(sizeof(texture_glyph_t *));
        self->height = 0;
        self->ascender = 0;
        self->descender = 0;
        self->rendermode = RENDER_NORMAL;
        self->outline_thickness = 0.0;
        self->hinting = 1;
        self->kerning = 1;
        self->filtering = 1;
        // FT_LCD_FILTER_LIGHT   is (0x00, 0x55, 0x56, 0x55, 0x00)
        // FT_LCD_FILTER_DEFAULT is (0x10, 0x40, 0x70, 0x40, 0x10)
        self->lcd_weights[0] = 0x10;
        self->lcd_weights[1] = 0x40;
        self->lcd_weights[2] = 0x70;
        self->lcd_weights[3] = 0x40;
        self->lcd_weights[4] = 0x10;
        if (!texture_font_load_face(self, self->size * 100.f, &library, &face))
        return -1;
        self->underline_position = face->underline_position / (float)(HRESf*HRESf) * self->size;
        self->underline_position = roundf( self->underline_position );
        if( self->underline_position > -2 )
        {
            self->underline_position = -2.0;
        }
        self->underline_thickness = face->underline_thickness / (float)(HRESf*HRESf) * self->size;
        self->underline_thickness = roundf( self->underline_thickness );
        if( self->underline_thickness < 1 )
        {
            self->underline_thickness = 1.0;
        }
        metrics = face->size->metrics;
        self->ascender = (metrics.ascender >> 6) / 100.0f;
        self->descender = (metrics.descender >> 6) / 100.0f;
        self->height = (metrics.height >> 6) / 100.0f;
        self->linegap = self->height - self->ascender + self->descender;
        FT_Done_Face( face );
        FT_Done_FreeType( library );
        /* NULL is a special glyph */
        texture_font_get_glyph( self, NULL );
        return 0;
    }
    // --------------------------------------------- texture_font_new_from_file ---
    texture_font_t *
    texture_font_new_from_file(texture_atlas_t *atlas, const float pt_size,
    const char *filename)
    {
        texture_font_t *self;
        assert(filename);
        self = (texture_font_t*)calloc(1, sizeof(*self));
        if (!self) {
            fprintf(stderr,
            "line %d: No more memory for allocating data\n", __LINE__);
            return NULL;
        }
        self->atlas = atlas;
        self->size  = pt_size;
        self->location = TEXTURE_FONT_FILE;
        self->filename = strdup(filename);
        if (texture_font_init(self)) {
            texture_font_delete(self);
            return NULL;
        }
        return self;
    }
    // ------------------------------------------- texture_font_new_from_memory ---
    texture_font_t *
    texture_font_new_from_memory(texture_atlas_t *atlas, float pt_size,
    const void *memory_base, size_t memory_size)
    {
        texture_font_t *self;
        assert(memory_base);
        assert(memory_size);
        self = (texture_font_t*)calloc(1, sizeof(*self));
        if (!self) {
            fprintf(stderr,
            "line %d: No more memory for allocating data\n", __LINE__);
            return NULL;
        }
        self->atlas = atlas;
        self->size  = pt_size;
        self->location = TEXTURE_FONT_MEMORY;
        self->memory.base = memory_base;
        self->memory.size = memory_size;
        if (texture_font_init(self)) {
            texture_font_delete(self);
            return NULL;
        }
        return self;
    }
    // ---------------------------------------------------- texture_font_delete ---
    void
    texture_font_delete( texture_font_t *self )
    {
        size_t i;
        texture_glyph_t *glyph;
        assert( self );
        if(self->location == TEXTURE_FONT_FILE && self->filename)
        free( self->filename );
        for( i=0; i<vector_size( self->glyphs ); ++i)
        {
            glyph = *(texture_glyph_t **) vector_get( self->glyphs, i );
            texture_glyph_delete( glyph);
        }
        vector_delete( self->glyphs );
        free( self );
    }
    texture_glyph_t *
    texture_font_find_glyph( texture_font_t * self,
    const char * codepoint )
    {
        size_t i;
        texture_glyph_t *glyph;
        uint32_t ucodepoint = utf8_to_utf32( codepoint );
        for( i = 0; i < self->glyphs->size; ++i )
        {
            glyph = *(texture_glyph_t **) vector_get( self->glyphs, i );
            // If codepoint is -1, we don't care about outline type or thickness
            if( (glyph->codepoint == ucodepoint) &&
            ((ucodepoint == (uint32_t)-1) ||
            ((glyph->rendermode == self->rendermode) &&
            (glyph->outline_thickness == self->outline_thickness)) ))
            {
                return glyph;
            }
        }
        return NULL;
    }
    // ------------------------------------------------ texture_font_load_glyph ---
    int
    texture_font_load_glyph( texture_font_t * self,
    const char * codepoint )
    {
        size_t i, x, y;
        FT_Library library;
        FT_Error error;
        FT_Face face;
        FT_Glyph ft_glyph = { 0 };
        FT_GlyphSlot slot;
        FT_Bitmap ft_bitmap;
        FT_UInt glyph_index;
        texture_glyph_t *glyph;
        FT_Int32 flags = 0;
        int ft_glyph_top = 0;
        int ft_glyph_left = 0;
        ivec4 region;
        if (!texture_font_load_face(self, self->size, &library, &face))
        return 0;
        /* Check if codepoint has been already loaded */
        if (texture_font_find_glyph(self, codepoint)) {
            FT_Done_Face(face);
            FT_Done_FreeType(library);
            return 1;
        }
        /* codepoint NULL is special : it is used for line drawing (overline,
        * underline, strikethrough) and background.
        */
        if( !codepoint )
        {
            ivec4 region = texture_atlas_get_region( self->atlas, 5, 5 );
            texture_glyph_t * glyph = texture_glyph_new( );
            static unsigned char data[4*4*3] = {255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255};
            if ( region.x < 0 )
            {
                fprintf( stderr, "Texture atlas is full (line %d)\n",  __LINE__ );
                FT_Done_Face( face );
                FT_Done_FreeType( library );
                return 0;
            }
            texture_atlas_set_region( self->atlas, region.x, region.y, 4, 4, data, 0 );
            glyph->codepoint = -1;
            glyph->s0 = (region.x+2)/(float)self->atlas->width;
            glyph->t0 = (region.y+2)/(float)self->atlas->height;
            glyph->s1 = (region.x+3)/(float)self->atlas->width;
            glyph->t1 = (region.y+3)/(float)self->atlas->height;
            vector_push_back( self->glyphs, &glyph );
            FT_Done_Face(face);
            FT_Done_FreeType(library);
            return 1;
        }
        flags = 0;
        ft_glyph_top = 0;
        ft_glyph_left = 0;
        glyph_index = FT_Get_Char_Index( face, (FT_ULong)utf8_to_utf32( codepoint ) );
        // WARNING: We use texture-atlas depth to guess if user wants
        //          LCD subpixel rendering
        if( self->rendermode != RENDER_NORMAL && self->rendermode != RENDER_SIGNED_DISTANCE_FIELD )
        {
            flags |= FT_LOAD_NO_BITMAP;
        }
        else
        {
            flags |= FT_LOAD_RENDER;
        }
        if( !self->hinting )
        {
            flags |= FT_LOAD_NO_HINTING | FT_LOAD_NO_AUTOHINT;
        }
        else
        {
            flags |= FT_LOAD_FORCE_AUTOHINT;
        }
        if( self->atlas->depth == 3 )
        {
            FT_Library_SetLcdFilter( library, FT_LCD_FILTER_LIGHT );
            flags |= FT_LOAD_TARGET_LCD;
            if( self->filtering )
            {
                FT_Library_SetLcdFilterWeights( library, self->lcd_weights );
            }
        }
        error = FT_Load_Glyph( face, glyph_index, flags );
        if( error )
        {
            fprintf( stderr, "FT_Error (line %d, code 0x%02x) : %s\n",
            __LINE__, FT_Errors[error].code, FT_Errors[error].message );
            FT_Done_Face( face );
            FT_Done_FreeType( library );
            return 0;
        }
        if( self->rendermode == RENDER_NORMAL || self->rendermode == RENDER_SIGNED_DISTANCE_FIELD )
        {
            slot            = face->glyph;
            ft_bitmap       = slot->bitmap;
            ft_glyph_top    = slot->bitmap_top;
            ft_glyph_left   = slot->bitmap_left;
        }
        else
        {
            FT_Stroker stroker;
            FT_BitmapGlyph ft_bitmap_glyph;
            error = FT_Stroker_New( library, &stroker );
            if( error )
            {
                fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                FT_Errors[error].code, FT_Errors[error].message);
                goto cleanup_stroker;
            }
            FT_Stroker_Set(stroker,
            (int)(self->outline_thickness * HRES),
            FT_STROKER_LINECAP_ROUND,
            FT_STROKER_LINEJOIN_ROUND,
            0);
            error = FT_Get_Glyph( face->glyph, &ft_glyph);
            if( error )
            {
                fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                FT_Errors[error].code, FT_Errors[error].message);
                goto cleanup_stroker;
            }
            if( self->rendermode == RENDER_OUTLINE_EDGE )
            error = FT_Glyph_Stroke( &ft_glyph, stroker, 1 );
            else if ( self->rendermode == RENDER_OUTLINE_POSITIVE )
            error = FT_Glyph_StrokeBorder( &ft_glyph, stroker, 0, 1 );
            else if ( self->rendermode == RENDER_OUTLINE_NEGATIVE )
            error = FT_Glyph_StrokeBorder( &ft_glyph, stroker, 1, 1 );
            if( error )
            {
                fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                FT_Errors[error].code, FT_Errors[error].message);
                goto cleanup_stroker;
            }
            if( self->atlas->depth == 1 )
            error = FT_Glyph_To_Bitmap( &ft_glyph, FT_RENDER_MODE_NORMAL, 0, 1);
            else
            error = FT_Glyph_To_Bitmap( &ft_glyph, FT_RENDER_MODE_LCD, 0, 1);
            if( error )
            {
                fprintf(stderr, "FT_Error (0x%02x) : %s\n",
                FT_Errors[error].code, FT_Errors[error].message);
                goto cleanup_stroker;
            }
            ft_bitmap_glyph = (FT_BitmapGlyph) ft_glyph;
            ft_bitmap       = ft_bitmap_glyph->bitmap;
            ft_glyph_top    = ft_bitmap_glyph->top;
            ft_glyph_left   = ft_bitmap_glyph->left;
            cleanup_stroker:
            FT_Stroker_Done( stroker );
            if( error )
            {
                FT_Done_Face( face );
                FT_Done_FreeType( library );
                return 0;
            }
        }
        struct {
            int left;
            int top;
            int right;
            int bottom;
        } padding = { 0, 0, 1, 1 };
        if( self->rendermode == RENDER_SIGNED_DISTANCE_FIELD )
        {
            padding.top = 1;
            padding.left = 1;
        }
        size_t src_w = ft_bitmap.width/self->atlas->depth;
        size_t src_h = ft_bitmap.rows;
        size_t tgt_w = src_w + padding.left + padding.right;
        size_t tgt_h = src_h + padding.top + padding.bottom;
        region = texture_atlas_get_region( self->atlas, tgt_w, tgt_h );
        if ( region.x < 0 )
        {
            fprintf( stderr, "Texture atlas is full (line %d)\n",  __LINE__ );
            FT_Done_Face( face );
            FT_Done_FreeType( library );
            return 0;
        }
        x = region.x;
        y = region.y;
        unsigned char *buffer = (unsigned char *)calloc( tgt_w * tgt_h * self->atlas->depth, sizeof(unsigned char) );
        unsigned char *dst_ptr = buffer + (padding.top * tgt_w + padding.left) * self->atlas->depth;
        unsigned char *src_ptr = ft_bitmap.buffer;
        for( i = 0; i < src_h; i++ )
        {
            //difference between width and pitch: https://www.freetype.org/freetype2/docs/reference/ft2-basic_types.html
            memcpy( dst_ptr, src_ptr, ft_bitmap.width);
            dst_ptr += tgt_w * self->atlas->depth;
            src_ptr += ft_bitmap.pitch;
        }
        if( self->rendermode == RENDER_SIGNED_DISTANCE_FIELD )
        {
            unsigned char *sdf = make_distance_mapb( buffer, (unsigned int)tgt_w, (unsigned int)tgt_h );
            free( buffer );
            buffer = sdf;
        }
        texture_atlas_set_region( self->atlas, x, y, tgt_w, tgt_h, buffer, tgt_w * self->atlas->depth);
        free( buffer );
        glyph = texture_glyph_new( );
        glyph->codepoint = utf8_to_utf32( codepoint );
        glyph->width    = tgt_w;
        glyph->height   = tgt_h;
        glyph->rendermode = self->rendermode;
        glyph->outline_thickness = self->outline_thickness;
        glyph->offset_x = ft_glyph_left;
        glyph->offset_y = ft_glyph_top;
        glyph->s0       = x/(float)self->atlas->width;
        glyph->t0       = y/(float)self->atlas->height;
        glyph->s1       = (x + glyph->width)/(float)self->atlas->width;
        glyph->t1       = (y + glyph->height)/(float)self->atlas->height;
        // Discard hinting to get advance
        FT_Load_Glyph( face, glyph_index, FT_LOAD_RENDER | FT_LOAD_NO_HINTING);
        slot = face->glyph;
        glyph->advance_x = slot->advance.x / HRESf;
        glyph->advance_y = slot->advance.y / HRESf;
        vector_push_back( self->glyphs, &glyph );
        if( self->rendermode != RENDER_NORMAL && self->rendermode != RENDER_SIGNED_DISTANCE_FIELD )
        FT_Done_Glyph( ft_glyph );
        texture_font_generate_kerning( self, &library, &face );
        FT_Done_Face( face );
        FT_Done_FreeType( library );
        return 1;
    }
    // ----------------------------------------------- texture_font_load_glyphs ---
    size_t
    texture_font_load_glyphs( texture_font_t * self,
    const char * codepoints )
    {
        size_t i;
        /* Load each glyph */
        for( i = 0; i < strlen(codepoints); i += utf8_surrogate_len(codepoints + i) ) {
            if( !texture_font_load_glyph( self, codepoints + i ) )
            return utf8_strlen( codepoints + i );
        }
        return 0;
    }
    // ------------------------------------------------- texture_font_get_glyph ---
    texture_glyph_t *
    texture_font_get_glyph( texture_font_t * self,
    const char * codepoint )
    {
        texture_glyph_t *glyph;
        assert( self );
        assert( self->filename );
        assert( self->atlas );
        /* Check if codepoint has been already loaded */
        if( (glyph = texture_font_find_glyph( self, codepoint )) )
        return glyph;
        /* Glyph has not been already loaded */
        if( texture_font_load_glyph( self, codepoint ) )
        return texture_font_find_glyph( self, codepoint );
        return NULL;
    }
    // ------------------------------------------------- texture_font_enlarge_atlas ---
    void
    texture_font_enlarge_atlas( texture_font_t * self, size_t width_new,
    size_t height_new)
    {
        assert(self);
        assert(self->atlas);
        //ensure size increased
        assert(width_new >= self->atlas->width);
        assert(height_new >= self->atlas->height);
        assert(width_new + height_new > self->atlas->width + self->atlas->height);
        texture_atlas_t* ta = self->atlas;
        size_t width_old = ta->width;
        size_t height_old = ta->height;
        //allocate new buffer
        unsigned char* data_old = ta->data;
        ta->data = (unsigned char *)calloc(1,width_new*height_new * sizeof(char)*ta->depth);
        //update atlas size
        ta->width = width_new;
        ta->height = height_new;
        //add node reflecting the gained space on the right
        if(width_new>width_old){
            ivec3 node;
            node.x = (int)(width_old - 1);
            node.y = 1;
            node.z = (int)(width_new - width_old);
            vector_push_back(ta->nodes, &node);
        }
        //over data from the old buffer, skipping first row and column because of the margin
        size_t pixel_size = sizeof(char) * ta->depth;
        size_t old_row_size = width_old * pixel_size;
        texture_atlas_set_region(ta, 1, 1, width_old - 2, height_old - 2, data_old + old_row_size + pixel_size, old_row_size);
        free(data_old);
        //change uv coordinates of existing glyphs to reflect size change
        float mulw = (float)width_old / width_new;
        float mulh = (float)height_old / height_new;
        size_t i;
        for (i = 0; i < vector_size(self->glyphs); i++) {
            texture_glyph_t* g = *(texture_glyph_t**)vector_get(self->glyphs, i);
            g->s0 *= mulw;
            g->s1 *= mulw;
            g->t0 *= mulh;
            g->t1 *= mulh;
        }
    }
    // ----------------------------------------------------- utf8_surrogate_len ---
    size_t
    utf8_surrogate_len( const char* character )
    {
        size_t result = 0;
        char test_char;
        if (!character)
        return 0;
        test_char = character[0];
        if ((test_char & 0x80) == 0)
        return 1;
        while (test_char & 0x80)
        {
            test_char <<= 1;
            result++;
        }
        return result;
    }
    // ------------------------------------------------------------ utf8_strlen ---
    size_t
    utf8_strlen( const char* string )
    {
        const char* ptr = string;
        size_t result = 0;
        while (*ptr)
        {
            ptr += utf8_surrogate_len(ptr);
            result++;
        }
        return result;
    }
    uint32_t
    utf8_to_utf32( const char * character )
    {
        uint32_t result = -1;
        if( !character )
        {
            return result;
        }
        if( ( character[0] & 0x80 ) == 0x0 )
        {
            result = character[0];
        }
        if( ( character[0] & 0xC0 ) == 0xC0 )
        {
            result = ( ( character[0] & 0x3F ) << 6 ) | ( character[1] & 0x3F );
        }
        if( ( character[0] & 0xE0 ) == 0xE0 )
        {
            result = ( ( character[0] & 0x1F ) << ( 6 + 6 ) ) | ( ( character[1] & 0x3F ) << 6 ) | ( character[2] & 0x3F );
        }
        if( ( character[0] & 0xF0 ) == 0xF0 )
        {
            result = ( ( character[0] & 0x0F ) << ( 6 + 6 + 6 ) ) | ( ( character[1] & 0x3F ) << ( 6 + 6 ) ) | ( ( character[2] & 0x3F ) << 6 ) | ( character[3] & 0x3F );
        }
        if( ( character[0] & 0xF8 ) == 0xF8 )
        {
            result = ( ( character[0] & 0x07 ) << ( 6 + 6 + 6 + 6 ) ) | ( ( character[1] & 0x3F ) << ( 6 + 6 + 6 ) ) | ( ( character[2] & 0x3F ) << ( 6 + 6 ) ) | ( ( character[3] & 0x3F ) << 6 ) | ( character[4] & 0x3F );
        }
        return result;
    }
    // ------------------------------------------------------------- vector_new ---
    vector_t *
    vector_new( size_t item_size )
    {
        vector_t *self = (vector_t *) malloc( sizeof(vector_t) );
        assert( item_size );
        if( !self )
        {
            halt("line %d: No more memory for allocating data\n", __LINE__ );
        }
        self->item_size = item_size;
        self->size      = 0;
        self->capacity  = 1;
        self->items     = malloc( self->item_size * self->capacity );
        return self;
    }
    // ---------------------------------------------------------- vector_delete ---
    void
    vector_delete( vector_t *self )
    {
        assert( self );
        free( self->items );
        free( self );
    }
    // ------------------------------------------------------------- vector_get ---
    const void *
    vector_get( const vector_t *self,
    size_t index )
    {
        assert( self );
        assert( self->size );
        assert( index  < self->size );
        return (char*)(self->items) + index * self->item_size;
    }
    // ----------------------------------------------------------- vector_front ---
    const void *
    vector_front( const vector_t *self )
    {
        assert( self );
        assert( self->size );
        return vector_get( self, 0 );
    }
    // ------------------------------------------------------------ vector_back ---
    const void *
    vector_back( const vector_t *self )
    {
        assert( self );
        assert( self->size );
        return vector_get( self, self->size-1 );
    }
    // -------------------------------------------------------- vector_contains ---
    int
    vector_contains( const vector_t *self,
    const void *item,
    int (*cmp)(const void *, const void *) )
    {
        size_t i;
        assert( self );
        for( i=0; i<self->size; ++i )
        {
            if( (*cmp)(item, vector_get(self,i) ) == 0 )
            {
                return 1;
            }
        }
        return 0;
    }
    // ----------------------------------------------------------- vector_empty ---
    int
    vector_empty( const vector_t *self )
    {
        assert( self );
        return self->size == 0;
    }
    // ------------------------------------------------------------ vector_size ---
    size_t
    vector_size( const vector_t *self )
    {
        assert( self );
        return self->size;
    }
    // --------------------------------------------------------- vector_reserve ---
    void
    vector_reserve( vector_t *self,
    const size_t size )
    {
        assert( self );
        if( self->capacity < size)
        {
            self->items = realloc( self->items, size * self->item_size );
            self->capacity = size;
        }
    }
    // -------------------------------------------------------- vector_capacity ---
    size_t
    vector_capacity( const vector_t *self )
    {
        assert( self );
        return self->capacity;
    }
    // ---------------------------------------------------------- vector_shrink ---
    void
    vector_shrink( vector_t *self )
    {
        assert( self );
        if( self->capacity > self->size )
        {
            self->items = realloc( self->items, self->size * self->item_size );
        }
        self->capacity = self->size;
    }
    // ----------------------------------------------------------- vector_clear ---
    void
    vector_clear( vector_t *self )
    {
        assert( self );
        self->size = 0;
    }
    // ------------------------------------------------------------- vector_set ---
    void
    vector_set( vector_t *self,
    const size_t index,
    const void *item )
    {
        assert( self );
        assert( self->size );
        assert( index  < self->size );
        memcpy( (char *)(self->items) + index * self->item_size,
        item, self->item_size );
    }
    // ---------------------------------------------------------- vector_insert ---
    void
    vector_insert( vector_t *self,
    const size_t index,
    const void *item )
    {
        assert( self );
        assert( index <= self->size);
        if( self->capacity <= self->size )
        {
            vector_reserve(self, 2 * self->capacity );
        }
        if( index < self->size )
        {
            memmove( (char *)(self->items) + (index + 1) * self->item_size,
            (char *)(self->items) + (index + 0) * self->item_size,
            (self->size - index)  * self->item_size);
        }
        self->size++;
        vector_set( self, index, item );
    }
    // ----------------------------------------------------- vector_erase_range ---
    void
    vector_erase_range( vector_t *self,
    const size_t first,
    const size_t last )
    {
        assert( self );
        assert( first < self->size );
        assert( last  < self->size+1 );
        assert( first < last );
        memmove( (char *)(self->items) + first * self->item_size,
        (char *)(self->items) + last  * self->item_size,
        (self->size - last)   * self->item_size);
        self->size -= (last-first);
    }
    // ----------------------------------------------------------- vector_erase ---
    void
    vector_erase( vector_t *self,
    const size_t index )
    {
        assert( self );
        assert( index < self->size );
        vector_erase_range( self, index, index+1 );
    }
    // ------------------------------------------------------- vector_push_back ---
    void
    vector_push_back( vector_t *self,
    const void *item )
    {
        vector_insert( self, self->size, item );
    }
    // -------------------------------------------------------- vector_pop_back ---
    void
    vector_pop_back( vector_t *self )
    {
        assert( self );
        assert( self->size );
        self->size--;
    }
    // ---------------------------------------------------------- vector_resize ---
    void
    vector_resize( vector_t *self,
    const size_t size )
    {
        assert( self );
        if( size > self->capacity)
        {
            vector_reserve( self, size );
            self->size = self->capacity;
        }
        else
        {
            self->size = size;
        }
    }
    // -------------------------------------------------- vector_push_back_data ---
    void
    vector_push_back_data( vector_t *self,
    const void * data,
    const size_t count )
    {
        assert( self );
        assert( data );
        assert( count );
        if( self->capacity < (self->size+count) )
        {
            vector_reserve(self, self->size+count);
        }
        memmove( (char *)(self->items) + self->size * self->item_size, data,
        count*self->item_size );
        self->size += count;
    }
    // ----------------------------------------------------- vector_insert_data ---
    void
    vector_insert_data( vector_t *self,
    const size_t index,
    const void * data,
    const size_t count )
    {
        assert( self );
        assert( index < self->size );
        assert( data );
        assert( count );
        if( self->capacity < (self->size+count) )
        {
            vector_reserve(self, self->size+count);
        }
        memmove( (char *)(self->items) + (index + count ) * self->item_size,
        (char *)(self->items) + (index ) * self->item_size,
        count*self->item_size );
        memmove( (char *)(self->items) + index * self->item_size, data,
        count*self->item_size );
        self->size += count;
    }
    // ------------------------------------------------------------ vector_sort ---
    void
    vector_sort( vector_t *self,
    int (*cmp)(const void *, const void *) )
    {
        assert( self );
        assert( self->size );
        qsort(self->items, self->size, self->item_size, cmp);
    }
    // ----------------------------------------------------------------------------
    vertex_attribute_t *
    vertex_attribute_new( GLchar * name,
    GLint size,
    GLenum type,
    GLboolean normalized,
    GLsizei stride,
    GLvoid *pointer )
    {
        vertex_attribute_t *attribute =
        (vertex_attribute_t *) malloc (sizeof(vertex_attribute_t));
        assert( size > 0 );
        attribute->name       = (GLchar *) strdup( name );
        attribute->index      = (GLuint)-1;
        attribute->size       = size;
        attribute->type       = type;
        attribute->normalized = normalized;
        attribute->stride     = stride;
        attribute->pointer    = pointer;
        return attribute;
    }
    // ----------------------------------------------------------------------------
    void
    vertex_attribute_delete( vertex_attribute_t * self )
    {
        assert( self );
        free( self->name );
        free( self );
    }
    // ----------------------------------------------------------------------------
    vertex_attribute_t *
    vertex_attribute_parse( char *format )
    {
        GLenum type = 0;
        int size;
        int normalized = 0;
        char ctype;
        char *name;
        vertex_attribute_t *attr;
        char *p = strchr(format, ':');
        if( p != NULL)
        {
            name = strndup(format, p-format);
            if( *(++p) == '\0' )
            {
                fprintf( stderr, "No size specified for '%s' attribute\n", name );
                free( name );
                return 0;
            }
            size = *p - '0';
            if( *(++p) == '\0' )
            {
                fprintf( stderr, "No format specified for '%s' attribute\n", name );
                free( name );
                return 0;
            }
            ctype = *p;
            if( *(++p) != '\0' )
            {
                if( *p == 'n' )
                {
                    normalized = 1;
                }
            }
        }
        else
        {
            fprintf(stderr, "Vertex attribute format not understood ('%s')\n", format );
            return 0;
        }
        switch( ctype )
        {
            case 'b': type = GL_BYTE;           break;
            case 'B': type = GL_UNSIGNED_BYTE;  break;
            case 's': type = GL_SHORT;          break;
            case 'S': type = GL_UNSIGNED_SHORT; break;
            case 'i': type = GL_INT;            break;
            case 'I': type = GL_UNSIGNED_INT;   break;
            case 'f': type = GL_FLOAT;          break;
            default:  type = 0;                 break;
        }
        attr = vertex_attribute_new( name, size, type, normalized, 0, 0 );
        free( name );
        return attr;
    }
    // ----------------------------------------------------------------------------
    void
    vertex_attribute_enable( vertex_attribute_t *attr )
    {
        if( attr->index == (GLuint)-1 )
        {
            GLint program;
            glGetIntegerv( GL_CURRENT_PROGRAM, &program );
            if( program == 0)
            {
                return;
            }
            attr->index = glGetAttribLocation( program, attr->name );
            if( attr->index == (GLuint)-1 )
            {
                return;
            }
        }
        glEnableVertexAttribArray( attr->index );
        glVertexAttribPointer( attr->index, attr->size, attr->type,
        attr->normalized, attr->stride, attr->pointer );
    }
    #ifdef WIN32
    // strndup() is not available on Windows
    char *strndup( const char *s1, size_t n)
    {
        char *copy= (char*)malloc( n+1 );
        memcpy( copy, s1, n );
        copy[n] = 0;
        return copy;
    };
    #endif
    /**
    * Buffer status
    */
    #define CLEAN  (0)
    #define DIRTY  (1)
    #define FROZEN (2)
    // ----------------------------------------------------------------------------
    vertex_buffer_t *
    vertex_buffer_new( const char *format )
    {
        size_t i, index = 0, stride = 0;
        const char *start = 0, *end = 0;
        GLchar *pointer = 0;
        vertex_buffer_t *self = (vertex_buffer_t *) malloc (sizeof(vertex_buffer_t));
        if( !self )
        {
            return NULL;
        }
        self->format = strdup( format );
        for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
        {
            self->attributes[i] = 0;
        }
        start = format;
        do
        {
            char *desc = 0;
            vertex_attribute_t *attribute;
            GLuint attribute_size = 0;
            end = (char *) (strchr(start+1, ','));
            if (end == NULL)
            {
                desc = strdup( start );
            }
            else
            {
                desc = strndup( start, end-start );
            }
            attribute = vertex_attribute_parse( desc );
            start = end+1;
            free(desc);
            attribute->pointer = pointer;
            switch( attribute->type )
            {
                case GL_BOOL:           attribute_size = sizeof(GLboolean); break;
                case GL_BYTE:           attribute_size = sizeof(GLbyte); break;
                case GL_UNSIGNED_BYTE:  attribute_size = sizeof(GLubyte); break;
                case GL_SHORT:          attribute_size = sizeof(GLshort); break;
                case GL_UNSIGNED_SHORT: attribute_size = sizeof(GLushort); break;
                case GL_INT:            attribute_size = sizeof(GLint); break;
                case GL_UNSIGNED_INT:   attribute_size = sizeof(GLuint); break;
                case GL_FLOAT:          attribute_size = sizeof(GLfloat); break;
                default:                attribute_size = 0;
            }
            stride  += attribute->size*attribute_size;
            pointer += attribute->size*attribute_size;
            self->attributes[index] = attribute;
            index++;
        } while ( end && (index < MAX_VERTEX_ATTRIBUTE) );
        for( i=0; i<index; ++i )
        {
            self->attributes[i]->stride = (GLsizei)stride;
        }
        #ifdef FREETYPE_GL_USE_VAO
        self->VAO_id = 0;
        #endif
        self->vertices = vector_new( stride );
        self->vertices_id  = 0;
        self->GPU_vsize = 0;
        self->indices = vector_new( sizeof(GLuint) );
        self->indices_id  = 0;
        self->GPU_isize = 0;
        self->items = vector_new( sizeof(ivec4) );
        self->state = DIRTY;
        self->mode = GL_TRIANGLES;
        return self;
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_delete( vertex_buffer_t *self )
    {
        size_t i;
        assert( self );
        for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
        {
            if( self->attributes[i] )
            {
                vertex_attribute_delete( self->attributes[i] );
            }
        }
        #ifdef FREETYPE_GL_USE_VAO
        if( self->VAO_id )
        {
            glDeleteVertexArrays( 1, &self->VAO_id );
        }
        self->VAO_id = 0;
        #endif
        vector_delete( self->vertices );
        self->vertices = 0;
        if( self->vertices_id )
        {
            glDeleteBuffers( 1, &self->vertices_id );
        }
        self->vertices_id = 0;
        vector_delete( self->indices );
        self->indices = 0;
        if( self->indices_id )
        {
            glDeleteBuffers( 1, &self->indices_id );
        }
        self->indices_id = 0;
        vector_delete( self->items );
        if( self->format )
        {
            free( self->format );
        }
        self->format = 0;
        self->state = 0;
        free( self );
    }
    // ----------------------------------------------------------------------------
    const char *
    vertex_buffer_format( const vertex_buffer_t *self )
    {
        assert( self );
        return self->format;
    }
    // ----------------------------------------------------------------------------
    size_t
    vertex_buffer_size( const vertex_buffer_t *self )
    {
        assert( self );
        return vector_size( self->items );
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_print( vertex_buffer_t * self )
    {
        int i = 0;
        static const char *gltypes[9] = {
            "GL_BOOL",
            "GL_BYTE",
            "GL_UNSIGNED_BYTE",
            "GL_SHORT",
            "GL_UNSIGNED_SHORT",
            "GL_INT",
            "GL_UNSIGNED_INT",
            "GL_FLOAT",
            "GL_VOID"
        };
        assert(self);
        fprintf( stderr, "%d vertices, %d indices\n",
        (int)vector_size( self->vertices ), (int)vector_size( self->indices ) );
        while( self->attributes[i] )
        {
            int j = 8;
            switch( self->attributes[i]->type )
            {
                case GL_BOOL:           j=0; break;
                case GL_BYTE:           j=1; break;
                case GL_UNSIGNED_BYTE:  j=2; break;
                case GL_SHORT:          j=3; break;
                case GL_UNSIGNED_SHORT: j=4; break;
                case GL_INT:            j=5; break;
                case GL_UNSIGNED_INT:   j=6; break;
                case GL_FLOAT:          j=7; break;
                default:                j=8; break;
            }
            fprintf(stderr, "%s : %dx%s (+%p)\n",
            self->attributes[i]->name,
            self->attributes[i]->size,
            gltypes[j],
            self->attributes[i]->pointer);
            i += 1;
        }
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_upload ( vertex_buffer_t *self )
    {
        size_t vsize, isize;
        if( self->state == FROZEN )
        {
            return;
        }
        if( !self->vertices_id )
        {
            glGenBuffers( 1, &self->vertices_id );
        }
        if( !self->indices_id )
        {
            glGenBuffers( 1, &self->indices_id );
        }
        vsize = self->vertices->size*self->vertices->item_size;
        isize = self->indices->size*self->indices->item_size;
        // Always upload vertices first such that indices do not point to non
        // existing data (if we get interrupted in between for example).
        // Upload vertices
        glBindBuffer( GL_ARRAY_BUFFER, self->vertices_id );
        if( vsize != self->GPU_vsize )
        {
            glBufferData( GL_ARRAY_BUFFER,
            vsize, self->vertices->items, GL_DYNAMIC_DRAW );
            self->GPU_vsize = vsize;
        }
        else
        {
            glBufferSubData( GL_ARRAY_BUFFER,
            0, vsize, self->vertices->items );
        }
        glBindBuffer( GL_ARRAY_BUFFER, 0 );
        // Upload indices
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, self->indices_id );
        if( isize != self->GPU_isize )
        {
            glBufferData( GL_ELEMENT_ARRAY_BUFFER,
            isize, self->indices->items, GL_DYNAMIC_DRAW );
            self->GPU_isize = isize;
        }
        else
        {
            glBufferSubData( GL_ELEMENT_ARRAY_BUFFER,
            0, isize, self->indices->items );
        }
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_clear( vertex_buffer_t *self )
    {
        assert( self );
        self->state = FROZEN;
        vector_clear( self->indices );
        vector_clear( self->vertices );
        vector_clear( self->items );
        self->state = DIRTY;
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_render_setup ( vertex_buffer_t *self, GLenum mode )
    {
        size_t i;
        #ifdef FREETYPE_GL_USE_VAO
        // Unbind so no existing VAO-state is overwritten,
        // (e.g. the GL_ELEMENT_ARRAY_BUFFER-binding).
        glBindVertexArray( 0 );
        #endif
        if( self->state != CLEAN )
        {
            vertex_buffer_upload( self );
            self->state = CLEAN;
        }
        #ifdef FREETYPE_GL_USE_VAO
        if( self->VAO_id == 0 )
        {
            // Generate and set up VAO
            glGenVertexArrays( 1, &self->VAO_id );
            glBindVertexArray( self->VAO_id );
            glBindBuffer( GL_ARRAY_BUFFER, self->vertices_id );
            for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
            {
                vertex_attribute_t *attribute = self->attributes[i];
                if( attribute == 0 )
                {
                    continue;
                }
                else
                {
                    vertex_attribute_enable( attribute );
                }
            }
            glBindBuffer( GL_ARRAY_BUFFER, 0 );
            if( self->indices->size )
            {
                glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, self->indices_id );
            }
        }
        // Bind VAO for drawing
        glBindVertexArray( self->VAO_id );
        #else
        glBindBuffer( GL_ARRAY_BUFFER, self->vertices_id );
        for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
        {
            vertex_attribute_t *attribute = self->attributes[i];
            if ( attribute == 0 )
            {
                continue;
            }
            else
            {
                vertex_attribute_enable( attribute );
            }
        }
        if( self->indices->size )
        {
            glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, self->indices_id );
        }
        #endif
        self->mode = mode;
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_render_finish ( vertex_buffer_t *self )
    {
        #ifdef FREETYPE_GL_USE_VAO
        glBindVertexArray( 0 );
        #else
        int i;
        for( i=0; i<MAX_VERTEX_ATTRIBUTE; ++i )
        {
            vertex_attribute_t *attribute = self->attributes[i];
            if( attribute == 0 )
            {
                continue;
            }
            else
            {
                glDisableVertexAttribArray( attribute->index );
            }
        }
        glBindBuffer( GL_ARRAY_BUFFER, 0 );
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
        #endif
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_render_item ( vertex_buffer_t *self,
    size_t index )
    {
        ivec4 * item = (ivec4 *) vector_get( self->items, index );
        assert( self );
        assert( index < vector_size( self->items ) );
        if( self->indices->size )
        {
            size_t start = item->istart;
            size_t count = item->icount;
            glDrawElements( self->mode, (GLint)count, GL_UNSIGNED_INT, (void *)(start*sizeof(GLuint)) );
        }
        else if( self->vertices->size )
        {
            size_t start = item->vstart;
            size_t count = item->vcount;
            glDrawArrays( self->mode, (GLint)(start*self->vertices->item_size), (GLint)count);
        }
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_render ( vertex_buffer_t *self, GLenum mode )
    {
        size_t vcount = self->vertices->size;
        size_t icount = self->indices->size;
        vertex_buffer_render_setup( self, mode );
        if( icount )
        {
            glDrawElements( mode, (GLint)icount, GL_UNSIGNED_INT, 0 );
        }
        else
        {
            glDrawArrays( mode, 0, (GLint)vcount );
        }
        vertex_buffer_render_finish( self );
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_push_back_indices ( vertex_buffer_t * self,
    const GLuint * indices,
    const size_t icount )
    {
        assert( self );
        self->state |= DIRTY;
        vector_push_back_data( self->indices, indices, icount );
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_push_back_vertices ( vertex_buffer_t * self,
    const void * vertices,
    const size_t vcount )
    {
        assert( self );
        self->state |= DIRTY;
        vector_push_back_data( self->vertices, vertices, vcount );
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_insert_indices ( vertex_buffer_t *self,
    const size_t index,
    const GLuint *indices,
    const size_t count )
    {
        assert( self );
        assert( self->indices );
        assert( index < self->indices->size+1 );
        self->state |= DIRTY;
        vector_insert_data( self->indices, index, indices, count );
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_insert_vertices( vertex_buffer_t *self,
    const size_t index,
    const void *vertices,
    const size_t vcount )
    {
        size_t i;
        assert( self );
        assert( self->vertices );
        assert( index < self->vertices->size+1 );
        self->state |= DIRTY;
        for( i=0; i<self->indices->size; ++i )
        {
            if( *(GLuint *)(vector_get( self->indices, i )) > index )
            {
                *(GLuint *)(vector_get( self->indices, i )) += index;
            }
        }
        vector_insert_data( self->vertices, index, vertices, vcount );
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_erase_indices( vertex_buffer_t *self,
    const size_t first,
    const size_t last )
    {
        assert( self );
        assert( self->indices );
        assert( first < self->indices->size );
        assert( (last) <= self->indices->size );
        self->state |= DIRTY;
        vector_erase_range( self->indices, first, last );
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_erase_vertices( vertex_buffer_t *self,
    const size_t first,
    const size_t last )
    {
        size_t i;
        assert( self );
        assert( self->vertices );
        assert( first < self->vertices->size );
        assert( last <= self->vertices->size );
        assert( last > first );
        self->state |= DIRTY;
        for( i=0; i<self->indices->size; ++i )
        {
            if( *(GLuint *)(vector_get( self->indices, i )) > first )
            {
                *(GLuint *)(vector_get( self->indices, i )) -= (last-first);
            }
        }
        vector_erase_range( self->vertices, first, last );
    }
    // ----------------------------------------------------------------------------
    size_t
    vertex_buffer_push_back( vertex_buffer_t * self,
    const void * vertices, const size_t vcount,
    const GLuint * indices, const size_t icount )
    {
        return vertex_buffer_insert( self, vector_size( self->items ),
        vertices, vcount, indices, icount );
    }
    // ----------------------------------------------------------------------------
    size_t
    vertex_buffer_insert( vertex_buffer_t * self, const size_t index,
    const void * vertices, const size_t vcount,
    const GLuint * indices, const size_t icount )
    {
        size_t vstart, istart, i;
        ivec4 item;
        assert( self );
        assert( vertices );
        assert( indices );
        self->state = FROZEN;
        // Push back vertices
        vstart = vector_size( self->vertices );
        vertex_buffer_push_back_vertices( self, vertices, vcount );
        // Push back indices
        istart = vector_size( self->indices );
        vertex_buffer_push_back_indices( self, indices, icount );
        // Update indices within the vertex buffer
        for( i=0; i<icount; ++i )
        {
            *(GLuint *)(vector_get( self->indices, istart+i )) += vstart;
        }
        // Insert item
        item.x = (int)vstart;
        item.y = (int)vcount;
        item.z = (int)istart;
        item.w = (int)icount;
        vector_insert( self->items, index, &item );
        self->state = DIRTY;
        return index;
    }
    // ----------------------------------------------------------------------------
    void
    vertex_buffer_erase( vertex_buffer_t * self,
    const size_t index )
    {
        ivec4 * item;
        int vstart;
        size_t vcount, istart, icount, i;
        assert( self );
        assert( index < vector_size( self->items ) );
        item = (ivec4 *) vector_get( self->items, index );
        vstart = item->vstart;
        vcount = item->vcount;
        istart = item->istart;
        icount = item->icount;
        // Update items
        for( i=0; i<vector_size(self->items); ++i )
        {
            ivec4 * item = (ivec4 *) vector_get( self->items, i );
            if( item->vstart > vstart)
            {
                item->vstart -= vcount;
                item->istart -= icount;
            }
        }
        self->state = FROZEN;
        vertex_buffer_erase_indices( self, istart, istart+icount );
        vertex_buffer_erase_vertices( self, vstart, vstart+vcount );
        vector_erase( self->items, index );
        self->state = DIRTY;
    }
    #include <lib/sj-lib-ui/obj_parser.c>
void sjf_animator(sjs_animator* _this) {
}

void sjf_animator_copy(sjs_animator* _this, sjs_animator* _from) {
    _this->animations._refCount = 1;
#line 27 "lib/sj-lib-ui/animation.sj"
    sjf_list_heap_iface_animation_copy(&_this->animations, &_from->animations);
#line 27
    _this->current = _from->current;
}

void sjf_animator_destroy(sjs_animator* _this) {
    if (_this->animations._refCount == 1) { sjf_list_heap_iface_animation_destroy(&_this->animations); }
;
}

void sjf_animator_heap(sjs_animator* _this) {
}

void sjf_animator_nextframe(sjs_animator* _parent, int32_t time) {
    int32_t sjt_capture83;
    sjs_list_heap_iface_animation* sjt_parent359 = 0;

#line 31 "lib/sj-lib-ui/animation.sj"
    _parent->current = time;
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent359 = &_parent->animations;
#line 4
    sjf_list_heap_iface_animation_getcount(sjt_parent359, &sjt_capture83);
    if (sjt_capture83 > 0) {
        int32_t i;
        int32_t sjt_forEnd28;
        int32_t sjt_forStart28;
        sjs_list_heap_iface_animation* sjt_parent360 = 0;

#line 35 "lib/sj-lib-ui/animation.sj"
        sjt_forStart28 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent360 = &_parent->animations;
#line 4
        sjf_list_heap_iface_animation_getcount(sjt_parent360, &sjt_forEnd28);
#line 35 "lib/sj-lib-ui/animation.sj"
        i = sjt_forEnd28 - 1;
        while (i >= sjt_forStart28) {
            sji_animation a = { 0 };
            bool sjt_capture84;
            int32_t sjt_functionParam666;
            int32_t sjt_interfaceParam19;
            sjs_list_heap_iface_animation* sjt_parent362 = 0;
            sji_animation sjt_parent363 = { 0 };

#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent362 = &_parent->animations;
#line 35 "lib/sj-lib-ui/animation.sj"
            sjt_functionParam666 = i;
#line 35
            sjf_list_heap_iface_animation_getat_heap(sjt_parent362, sjt_functionParam666, &a);
#line 2
            sjt_parent363 = a;
#line 31
            sjt_interfaceParam19 = time;
#line 37
            sjt_parent363._vtbl->nextframe(sjt_parent363._parent, sjt_interfaceParam19, &sjt_capture84);
            if (sjt_capture84) {
                int32_t sjt_functionParam667;
                sjs_list_heap_iface_animation* sjt_parent364 = 0;

#line 53 "lib/sj-lib-common/list.sj"
                sjt_parent364 = &_parent->animations;
#line 35 "lib/sj-lib-ui/animation.sj"
                sjt_functionParam667 = i;
#line 35
                sjf_list_heap_iface_animation_removeat(sjt_parent364, sjt_functionParam667);
            }

#line 35
            i--;

            if (a._parent != 0) {
                a._parent->_refCount--;
                if (a._parent->_refCount <= 0) {
                    a._vtbl->destroy(a._parent);
                    free(a._parent);
                }
            }
        }
    }
}

void sjf_array_char(sjs_array_char* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(char), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    char* p = (char*)arr->data + offset;
#line 187
    char* newp = (char*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(char) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_char(_return);
}

void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(char), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    char* p = (char*)arr->data + offset;
#line 187
    char* newp = (char*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(char) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_char_heap((*_return));
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        char* p = (char*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    char* p = (char*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    char* p = (char*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_create_i32(int32_t size, int32_t item, sjs_array_i32* _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(int32_t), size);
#line 6
    int32_t* p = (int32_t*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        #line 2 "lib/sj-lib-common/array.sj"
p[i] = item;
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    _return->_refCount = 1;
#line 13
    _return->v = v;
#line 13
    sjf_array_i32(_return);
}

void sjf_array_create_i32_heap(int32_t size, int32_t item, sjs_array_i32** _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(int32_t), size);
#line 6
    int32_t* p = (int32_t*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        #line 2 "lib/sj-lib-common/array.sj"
p[i] = item;
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    (*_return) = (sjs_array_i32*)malloc(sizeof(sjs_array_i32));
#line 11
    (*_return)->_refCount = 1;
#line 13
    (*_return)->v = v;
#line 13
    sjf_array_i32_heap((*_return));
}

void sjf_array_create_vec3(int32_t size, sjs_vec3* item, sjs_array_vec3* _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(sjs_vec3), size);
#line 6
    sjs_vec3* p = (sjs_vec3*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        p[i]._refCount = 1;
#line 2 "lib/sj-lib-common/array.sj"
sjf_vec3_copy(&p[i], item);
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    _return->_refCount = 1;
#line 13
    _return->v = v;
#line 13
    sjf_array_vec3(_return);
}

void sjf_array_create_vec3_heap(int32_t size, sjs_vec3* item, sjs_array_vec3** _return) {
    void* v;

#line 3 "lib/sj-lib-common/array.sj"
    v = 0;
#line 5
    sjs_array* arr = createarray(sizeof(sjs_vec3), size);
#line 6
    sjs_vec3* p = (sjs_vec3*)arr->data;
#line 7
    for (int i = 0; i < size; i++) {
#line 8
        p[i]._refCount = 1;
#line 2 "lib/sj-lib-common/array.sj"
sjf_vec3_copy(&p[i], item);
;
#line 9
    }
#line 10
    arr->count = size;  
#line 11
    v = arr;
#line 11
    (*_return) = (sjs_array_vec3*)malloc(sizeof(sjs_array_vec3));
#line 11
    (*_return)->_refCount = 1;
#line 13
    (*_return)->v = v;
#line 13
    sjf_array_vec3_heap((*_return));
}

void sjf_array_gridunit(sjs_array_gridunit* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_gridunit_copy(sjs_array_gridunit* _this, sjs_array_gridunit* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_gridunit_destroy(sjs_array_gridunit* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !true
#line 381
        sjs_gridunit* p = (sjs_gridunit*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_gridunit_getat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_gridunit* p = (sjs_gridunit*)arr->data;
#line 48
    _return->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_gridunit_copy(_return, &p[index]);
return;;       
}

void sjf_array_gridunit_getat_heap(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit** _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_gridunit* p = (sjs_gridunit*)arr->data;
#line 48
    (*_return) = (sjs_gridunit*)malloc(sizeof(sjs_gridunit));
(*_return)->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_gridunit_copy((*_return), &p[index]);
return;;       
}

void sjf_array_gridunit_getcount(sjs_array_gridunit* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_gridunit_heap(sjs_array_gridunit* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_gridunit_initat(sjs_array_gridunit* _parent, int32_t index, sjs_gridunit* item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sjs_gridunit* p = (sjs_gridunit*)arr->data;
#line 63
    p[index]._refCount = 1;
#line 52 "lib/sj-lib-common/array.sj"
sjf_gridunit_copy(&p[index], item);
;
#line 64
    arr->count = index + 1;
}

void sjf_array_heap_iface_animation(sjs_array_heap_iface_animation* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_animation_copy(sjs_array_heap_iface_animation* _this, sjs_array_heap_iface_animation* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_heap_iface_animation_destroy(sjs_array_heap_iface_animation* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !false
#line 381
        sji_animation* p = (sji_animation*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_heap_iface_animation_getat_heap(sjs_array_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sji_animation* p = (sji_animation*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_animation_getcount(sjs_array_heap_iface_animation* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_heap_iface_animation_heap(sjs_array_heap_iface_animation* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_element(sjs_array_heap_iface_element* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !false
#line 381
        sji_element* p = (sji_element*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_heap_iface_element_getat_heap(sjs_array_heap_iface_element* _parent, int32_t index, sji_element* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sji_element* p = (sji_element*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_element_getcount(sjs_array_heap_iface_element* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_heap_iface_element_heap(sjs_array_heap_iface_element* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_element_initat(sjs_array_heap_iface_element* _parent, int32_t index, sji_element item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sji_element* p = (sji_element*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
#line 64
    arr->count = index + 1;
}

void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_model__quicksortcallback(sjs_array_heap_iface_model* _parent, int32_t left, int32_t right, cb_heap_iface_model_heap_iface_model_i32 cb) {
    int32_t i;
    int32_t j;
    sji_model pivot = { 0 };
    int32_t sjt_functionParam108;
    bool sjt_while1;

#line 234 "lib/sj-lib-common/array.sj"
    i = left;
#line 234
    j = right;
#line 238
    sjt_functionParam108 = (left + right) / 2;
#line 238
    sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam108, &pivot);
#line 239
    sjt_while1 = i <= j;
    while (sjt_while1) {
        bool shouldcontinue;
        int32_t sjt_capture32;
        bool sjt_while2;
        bool sjt_while3;

#line 240 "lib/sj-lib-common/array.sj"
        shouldcontinue = true;
#line 240
        sjf_array_heap_iface_model_getcount(_parent, &sjt_capture32);
        if (i < sjt_capture32) {
#line 241 "lib/sj-lib-common/array.sj"
            sjt_while2 = shouldcontinue;
        } else {
#line 241 "lib/sj-lib-common/array.sj"
            sjt_while2 = false;
        }

        while (sjt_while2) {
            int32_t sjt_capture33;
            int32_t sjt_capture34;
            sji_model sjt_functionParam109 = { 0 };
            int32_t sjt_functionParam110;
            sji_model sjt_functionParam111 = { 0 };

#line 242 "lib/sj-lib-common/array.sj"
            sjt_functionParam110 = i;
#line 242
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam110, &sjt_functionParam109);
#line 242
            sjt_functionParam111 = pivot;
            if (sjt_functionParam111._parent != 0) {
                sjt_functionParam111._parent->_refCount++;
            }

#line 242
            cb._cb(cb._parent, sjt_functionParam109, sjt_functionParam111, &sjt_capture33);
#line 242
            shouldcontinue = sjt_capture33 < 0;
            if (shouldcontinue) {
#line 244 "lib/sj-lib-common/array.sj"
                i = i + 1;
            }

#line 242
            sjf_array_heap_iface_model_getcount(_parent, &sjt_capture34);
            if (i < sjt_capture34) {
#line 241 "lib/sj-lib-common/array.sj"
                sjt_while2 = shouldcontinue;
            } else {
#line 241 "lib/sj-lib-common/array.sj"
                sjt_while2 = false;
            }

            if (sjt_functionParam109._parent != 0) {
                sjt_functionParam109._parent->_refCount--;
                if (sjt_functionParam109._parent->_refCount <= 0) {
                    sjt_functionParam109._vtbl->destroy(sjt_functionParam109._parent);
                    free(sjt_functionParam109._parent);
                }
            }
            if (sjt_functionParam111._parent != 0) {
                sjt_functionParam111._parent->_refCount--;
                if (sjt_functionParam111._parent->_refCount <= 0) {
                    sjt_functionParam111._vtbl->destroy(sjt_functionParam111._parent);
                    free(sjt_functionParam111._parent);
                }
            }
        }

#line 248
        shouldcontinue = true;
        if (j >= 0) {
#line 249 "lib/sj-lib-common/array.sj"
            sjt_while3 = shouldcontinue;
        } else {
#line 249 "lib/sj-lib-common/array.sj"
            sjt_while3 = false;
        }

        while (sjt_while3) {
            int32_t sjt_capture35;
            sji_model sjt_functionParam112 = { 0 };
            int32_t sjt_functionParam113;
            sji_model sjt_functionParam114 = { 0 };

#line 250 "lib/sj-lib-common/array.sj"
            sjt_functionParam113 = j;
#line 250
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam113, &sjt_functionParam112);
#line 250
            sjt_functionParam114 = pivot;
            if (sjt_functionParam114._parent != 0) {
                sjt_functionParam114._parent->_refCount++;
            }

#line 250
            cb._cb(cb._parent, sjt_functionParam112, sjt_functionParam114, &sjt_capture35);
#line 250
            shouldcontinue = sjt_capture35 > 0;
            if (shouldcontinue) {
#line 252 "lib/sj-lib-common/array.sj"
                j = j - 1;
            }

            if (j >= 0) {
#line 249 "lib/sj-lib-common/array.sj"
                sjt_while3 = shouldcontinue;
            } else {
#line 249 "lib/sj-lib-common/array.sj"
                sjt_while3 = false;
            }

            if (sjt_functionParam112._parent != 0) {
                sjt_functionParam112._parent->_refCount--;
                if (sjt_functionParam112._parent->_refCount <= 0) {
                    sjt_functionParam112._vtbl->destroy(sjt_functionParam112._parent);
                    free(sjt_functionParam112._parent);
                }
            }
            if (sjt_functionParam114._parent != 0) {
                sjt_functionParam114._parent->_refCount--;
                if (sjt_functionParam114._parent->_refCount <= 0) {
                    sjt_functionParam114._vtbl->destroy(sjt_functionParam114._parent);
                    free(sjt_functionParam114._parent);
                }
            }
        }

        if (i <= j) {
            int32_t sjt_functionParam115;
            int32_t sjt_functionParam116;
            sji_model sjt_functionParam117 = { 0 };
            int32_t sjt_functionParam118;
            int32_t sjt_functionParam119;
            sji_model sjt_functionParam120 = { 0 };
            sji_model tmp = { 0 };

#line 257 "lib/sj-lib-common/array.sj"
            sjt_functionParam115 = i;
#line 257
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam115, &tmp);
#line 258
            sjt_functionParam116 = i;
#line 258
            sjt_functionParam118 = j;
#line 258
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam118, &sjt_functionParam117);
#line 258
            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam116, sjt_functionParam117);
#line 259
            sjt_functionParam119 = j;
#line 259
            sjt_functionParam120 = tmp;
            if (sjt_functionParam120._parent != 0) {
                sjt_functionParam120._parent->_refCount++;
            }

#line 259
            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam119, sjt_functionParam120);
#line 260
            i = i + 1;
#line 261
            j = j - 1;

            if (sjt_functionParam117._parent != 0) {
                sjt_functionParam117._parent->_refCount--;
                if (sjt_functionParam117._parent->_refCount <= 0) {
                    sjt_functionParam117._vtbl->destroy(sjt_functionParam117._parent);
                    free(sjt_functionParam117._parent);
                }
            }
            if (sjt_functionParam120._parent != 0) {
                sjt_functionParam120._parent->_refCount--;
                if (sjt_functionParam120._parent->_refCount <= 0) {
                    sjt_functionParam120._vtbl->destroy(sjt_functionParam120._parent);
                    free(sjt_functionParam120._parent);
                }
            }
            if (tmp._parent != 0) {
                tmp._parent->_refCount--;
                if (tmp._parent->_refCount <= 0) {
                    tmp._vtbl->destroy(tmp._parent);
                    free(tmp._parent);
                }
            }
        }

#line 239
        sjt_while1 = i <= j;
    }

    if (left < j) {
        int32_t sjt_functionParam121;
        int32_t sjt_functionParam122;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam123;

#line 234 "lib/sj-lib-common/array.sj"
        sjt_functionParam121 = left;
#line 266
        sjt_functionParam122 = j;
#line 234
        sjt_functionParam123 = cb;
#line 234
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam121, sjt_functionParam122, sjt_functionParam123);
    }

    if (i < right) {
        int32_t sjt_functionParam124;
        int32_t sjt_functionParam125;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam126;

#line 269 "lib/sj-lib-common/array.sj"
        sjt_functionParam124 = i;
#line 234
        sjt_functionParam125 = right;
#line 234
        sjt_functionParam126 = cb;
#line 234
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam124, sjt_functionParam125, sjt_functionParam126);
    }

    if (pivot._parent != 0) {
        pivot._parent->_refCount--;
        if (pivot._parent->_refCount <= 0) {
            pivot._vtbl->destroy(pivot._parent);
            free(pivot._parent);
        }
    }
}

void sjf_array_heap_iface_model_clone(sjs_array_heap_iface_model* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_heap_iface_model* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sji_model), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sji_model* p = (sji_model*)arr->data + offset;
#line 187
    sji_model* newp = (sji_model*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sji_model) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
if (newp[i]._parent != 0) {
    newp[i]._parent->_refCount++;
}
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_heap_iface_model(_return);
}

void sjf_array_heap_iface_model_clone_heap(sjs_array_heap_iface_model* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_heap_iface_model** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sji_model), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sji_model* p = (sji_model*)arr->data + offset;
#line 187
    sji_model* newp = (sji_model*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sji_model) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
if (newp[i]._parent != 0) {
    newp[i]._parent->_refCount++;
}
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_heap_iface_model*)malloc(sizeof(sjs_array_heap_iface_model));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_heap_iface_model_heap((*_return));
}

void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !false
#line 381
        sji_model* p = (sji_model*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            if (p[i]._parent != 0) {
    p[i]._parent->_refCount--;
    if (p[i]._parent->_refCount <= 0) {
        p[i]._vtbl->destroy(p[i]._parent);
        free(p[i]._parent);
    }
}
;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_heap_iface_model_getat_heap(sjs_array_heap_iface_model* _parent, int32_t index, sji_model* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sji_model* p = (sji_model*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
if ((*_return)._parent != 0) {
    (*_return)._parent->_refCount++;
}
return;;       
}

void sjf_array_heap_iface_model_getcount(sjs_array_heap_iface_model* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_heap_iface_model_gettotalcount(sjs_array_heap_iface_model* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_heap_iface_model_initat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sji_model* p = (sji_model*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
#line 64
    arr->count = index + 1;
}

void sjf_array_heap_iface_model_setat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item) {
#line 70 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 71
    if (index >= arr->count || index < 0) {
#line 72
        halt("setAt: out of bounds %d:%d\n", index, arr->count);
#line 73
    }
#line 75
    sji_model* p = (sji_model*)arr->data;
#line 76
    if (p[index]._parent != 0) {
    p[index]._parent->_refCount--;
    if (p[index]._parent->_refCount <= 0) {
        p[index]._vtbl->destroy(p[index]._parent);
        free(p[index]._parent);
    }
}
;
#line 77
    #line 68 "lib/sj-lib-common/array.sj"
p[index] = item;
if (p[index]._parent != 0) {
    p[index]._parent->_refCount++;
}
;
}

void sjf_array_heap_iface_model_sortcb(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    int32_t sjt_capture31;

    sjf_array_heap_iface_model_getcount(_parent, &sjt_capture31);
    if (sjt_capture31 > 1) {
        int32_t sjt_capture36;
        int32_t sjt_functionParam127;
        int32_t sjt_functionParam128;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam129;

#line 281 "lib/sj-lib-common/array.sj"
        sjt_functionParam127 = 0;
#line 281
        sjf_array_heap_iface_model_getcount(_parent, &sjt_capture36);
#line 281
        sjt_functionParam128 = sjt_capture36 - 1;
#line 279
        sjt_functionParam129 = cb;
#line 279
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam127, sjt_functionParam128, sjt_functionParam129);
    }
}

void sjf_array_i32(sjs_array_i32* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_i32_clone(sjs_array_i32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_i32* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(int32_t), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    int32_t* p = (int32_t*)arr->data + offset;
#line 187
    int32_t* newp = (int32_t*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(int32_t) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_i32(_return);
}

void sjf_array_i32_clone_heap(sjs_array_i32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_i32** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(int32_t), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    int32_t* p = (int32_t*)arr->data + offset;
#line 187
    int32_t* newp = (int32_t*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(int32_t) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_i32*)malloc(sizeof(sjs_array_i32));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_i32_heap((*_return));
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        int32_t* p = (int32_t*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    int32_t* p = (int32_t*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_i32_getcount(sjs_array_i32* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_i32_gettotalcount(sjs_array_i32* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    int32_t* p = (int32_t*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_i32_setat(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 70 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 71
    if (index >= arr->count || index < 0) {
#line 72
        halt("setAt: out of bounds %d:%d\n", index, arr->count);
#line 73
    }
#line 75
    int32_t* p = (int32_t*)arr->data;
#line 76
    ;
#line 77
    #line 68 "lib/sj-lib-common/array.sj"
p[index] = item;
;
}

void sjf_array_rect(sjs_array_rect* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_rect_clone(sjs_array_rect* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_rect* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sjs_rect), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sjs_rect* p = (sjs_rect*)arr->data + offset;
#line 187
    sjs_rect* newp = (sjs_rect*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sjs_rect) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        newp[i]._refCount = 1;
#line 170 "lib/sj-lib-common/array.sj"
sjf_rect_copy(&newp[i], &p[i]);
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_rect(_return);
}

void sjf_array_rect_clone_heap(sjs_array_rect* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_rect** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sjs_rect), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sjs_rect* p = (sjs_rect*)arr->data + offset;
#line 187
    sjs_rect* newp = (sjs_rect*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sjs_rect) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        newp[i]._refCount = 1;
#line 170 "lib/sj-lib-common/array.sj"
sjf_rect_copy(&newp[i], &p[i]);
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_rect*)malloc(sizeof(sjs_array_rect));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_rect_heap((*_return));
}

void sjf_array_rect_copy(sjs_array_rect* _this, sjs_array_rect* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_rect_destroy(sjs_array_rect* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !true
#line 381
        sjs_rect* p = (sjs_rect*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_rect_getat(sjs_array_rect* _parent, int32_t index, sjs_rect* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_rect* p = (sjs_rect*)arr->data;
#line 48
    _return->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_rect_copy(_return, &p[index]);
return;;       
}

void sjf_array_rect_getat_heap(sjs_array_rect* _parent, int32_t index, sjs_rect** _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_rect* p = (sjs_rect*)arr->data;
#line 48
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
(*_return)->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_rect_copy((*_return), &p[index]);
return;;       
}

void sjf_array_rect_getcount(sjs_array_rect* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_rect_gettotalcount(sjs_array_rect* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_rect_heap(sjs_array_rect* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_rect_initat(sjs_array_rect* _parent, int32_t index, sjs_rect* item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sjs_rect* p = (sjs_rect*)arr->data;
#line 63
    p[index]._refCount = 1;
#line 52 "lib/sj-lib-common/array.sj"
sjf_rect_copy(&p[index], item);
;
#line 64
    arr->count = index + 1;
}

void sjf_array_u32(sjs_array_u32* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_u32_clone(sjs_array_u32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_u32* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(uint32_t), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    uint32_t* p = (uint32_t*)arr->data + offset;
#line 187
    uint32_t* newp = (uint32_t*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(uint32_t) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_u32(_return);
}

void sjf_array_u32_clone_heap(sjs_array_u32* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_u32** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(uint32_t), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    uint32_t* p = (uint32_t*)arr->data + offset;
#line 187
    uint32_t* newp = (uint32_t*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(uint32_t) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_u32*)malloc(sizeof(sjs_array_u32));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_u32_heap((*_return));
}

void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_u32_destroy(sjs_array_u32* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        uint32_t* p = (uint32_t*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_u32_getat(sjs_array_u32* _parent, int32_t index, uint32_t* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    uint32_t* p = (uint32_t*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_u32_getcount(sjs_array_u32* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_u32_gettotalcount(sjs_array_u32* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_u32_heap(sjs_array_u32* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_u32_initat(sjs_array_u32* _parent, int32_t index, uint32_t item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    uint32_t* p = (uint32_t*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_array_vec3(sjs_array_vec3* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_vec3_copy(sjs_array_vec3* _this, sjs_array_vec3* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_vec3_destroy(sjs_array_vec3* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !true
#line 381
        sjs_vec3* p = (sjs_vec3*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_vec3_getat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_vec3* p = (sjs_vec3*)arr->data;
#line 48
    _return->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_vec3_copy(_return, &p[index]);
return;;       
}

void sjf_array_vec3_getat_heap(sjs_array_vec3* _parent, int32_t index, sjs_vec3** _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_vec3* p = (sjs_vec3*)arr->data;
#line 48
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
(*_return)->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_vec3_copy((*_return), &p[index]);
return;;       
}

void sjf_array_vec3_heap(sjs_array_vec3* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_vec3_setat(sjs_array_vec3* _parent, int32_t index, sjs_vec3* item) {
#line 70 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 71
    if (index >= arr->count || index < 0) {
#line 72
        halt("setAt: out of bounds %d:%d\n", index, arr->count);
#line 73
    }
#line 75
    sjs_vec3* p = (sjs_vec3*)arr->data;
#line 76
    ;
#line 77
    p[index]._refCount = 1;
#line 68 "lib/sj-lib-common/array.sj"
sjf_vec3_copy(&p[index], item);
;
}

void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_vertex_location_texture_normal_clone(sjs_array_vertex_location_texture_normal* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_vertex_location_texture_normal* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sjs_vertex_location_texture_normal), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data + offset;
#line 187
    sjs_vertex_location_texture_normal* newp = (sjs_vertex_location_texture_normal*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sjs_vertex_location_texture_normal) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        newp[i]._refCount = 1;
#line 170 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(&newp[i], &p[i]);
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_vertex_location_texture_normal(_return);
}

void sjf_array_vertex_location_texture_normal_clone_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_vertex_location_texture_normal** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(sjs_vertex_location_texture_normal), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data + offset;
#line 187
    sjs_vertex_location_texture_normal* newp = (sjs_vertex_location_texture_normal*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if false
#line 193
    memcpy(newp, p, sizeof(sjs_vertex_location_texture_normal) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        newp[i]._refCount = 1;
#line 170 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(&newp[i], &p[i]);
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_vertex_location_texture_normal*)malloc(sizeof(sjs_array_vertex_location_texture_normal));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_vertex_location_texture_normal_heap((*_return));
}

void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !false && !true
#line 381
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
    }
}

void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 48
    _return->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(_return, &p[index]);
return;;       
}

void sjf_array_vertex_location_texture_normal_getat_heap(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal** _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 48
    (*_return) = (sjs_vertex_location_texture_normal*)malloc(sizeof(sjs_vertex_location_texture_normal));
(*_return)->_refCount = 1;
#line 42 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy((*_return), &p[index]);
return;;       
}

void sjf_array_vertex_location_texture_normal_getcount(sjs_array_vertex_location_texture_normal* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_vertex_location_texture_normal_gettotalcount(sjs_array_vertex_location_texture_normal* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 63
    p[index]._refCount = 1;
#line 52 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(&p[index], item);
;
#line 64
    arr->count = index + 1;
}

void sjf_array_vertex_location_texture_normal_setat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
#line 70 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 71
    if (index >= arr->count || index < 0) {
#line 72
        halt("setAt: out of bounds %d:%d\n", index, arr->count);
#line 73
    }
#line 75
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)arr->data;
#line 76
    ;
#line 77
    p[index]._refCount = 1;
#line 68 "lib/sj-lib-common/array.sj"
sjf_vertex_location_texture_normal_copy(&p[index], item);
;
}

void sjf_blureffect(sjs_blureffect* _this) {
}

void sjf_blureffect_as_sji_effect(sjs_blureffect* _this, sji_effect* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_blureffect_effect_vtbl;
}

void sjf_blureffect_asinterface(sjs_blureffect* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_effect_typeId:  {
            sjf_blureffect_as_sji_effect(_this, (sji_effect*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_blureffect_copy(sjs_blureffect* _this, sjs_blureffect* _from) {
#line 4 "lib/sj-lib-ui/blurEffect.sj"
    _this->radius = _from->radius;
#line 4
    _this->_rect._refCount = 1;
#line 4
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 4
    sjs_boxvertexbuffer* copyoption21 = (_from->_vertexbuffer1._refCount != -1 ? &_from->_vertexbuffer1 : 0);
    if (copyoption21 != 0) {
        _this->_vertexbuffer1._refCount = 1;
#line 4 "lib/sj-lib-ui/blurEffect.sj"
        sjf_boxvertexbuffer_copy(&_this->_vertexbuffer1, copyoption21);
    } else {
        _this->_vertexbuffer1._refCount = -1;
    }

#line 4
    sjs_boxvertexbuffer* copyoption22 = (_from->_vertexbuffer2._refCount != -1 ? &_from->_vertexbuffer2 : 0);
    if (copyoption22 != 0) {
        _this->_vertexbuffer2._refCount = 1;
#line 4 "lib/sj-lib-ui/blurEffect.sj"
        sjf_boxvertexbuffer_copy(&_this->_vertexbuffer2, copyoption22);
    } else {
        _this->_vertexbuffer2._refCount = -1;
    }

#line 4
    sjs_scenebuffer* copyoption23 = (_from->_scenebuffer1._refCount != -1 ? &_from->_scenebuffer1 : 0);
    if (copyoption23 != 0) {
        _this->_scenebuffer1._refCount = 1;
#line 4 "lib/sj-lib-ui/blurEffect.sj"
        sjf_scenebuffer_copy(&_this->_scenebuffer1, copyoption23);
    } else {
        _this->_scenebuffer1._refCount = -1;
    }

#line 4
    sjs_scenebuffer* copyoption24 = (_from->_scenebuffer2._refCount != -1 ? &_from->_scenebuffer2 : 0);
    if (copyoption24 != 0) {
        _this->_scenebuffer2._refCount = 1;
#line 4 "lib/sj-lib-ui/blurEffect.sj"
        sjf_scenebuffer_copy(&_this->_scenebuffer2, copyoption24);
    } else {
        _this->_scenebuffer2._refCount = -1;
    }

#line 4
    _this->_innerscene._refCount = 1;
#line 4
    sjf_scene2d_copy(&_this->_innerscene, &_from->_innerscene);
}

void sjf_blureffect_destroy(sjs_blureffect* _this) {
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_vertexbuffer1._refCount == 1) { sjf_boxvertexbuffer_destroy(&_this->_vertexbuffer1); }
;
    if (_this->_vertexbuffer2._refCount == 1) { sjf_boxvertexbuffer_destroy(&_this->_vertexbuffer2); }
;
    if (_this->_scenebuffer1._refCount == 1) { sjf_scenebuffer_destroy(&_this->_scenebuffer1); }
;
    if (_this->_scenebuffer2._refCount == 1) { sjf_scenebuffer_destroy(&_this->_scenebuffer2); }
;
    if (_this->_innerscene._refCount == 1) { sjf_scene2d_destroy(&_this->_innerscene); }
;
}

void sjf_blureffect_getclasstype(sjs_object* _this, int* _return) {
    *_return = 275;
}

void sjf_blureffect_getrect(sjs_blureffect* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 13 "lib/sj-lib-ui/blurEffect.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_blureffect_getrect_heap(sjs_blureffect* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-ui/blurEffect.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_blureffect_heap(sjs_blureffect* _this) {
}

void sjf_blureffect_render(sjs_blureffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_value5 = { -1 };
    sjs_boxvertexbuffer sjt_value6 = { -1 };
    sjs_scenebuffer sjt_value7 = { -1 };
    sjs_scenebuffer sjt_value8 = { -1 };

    if (_parent->radius == 0.0f) {
        sjs_scene2d* sjt_functionParam501 = 0;

#line 44 "lib/sj-lib-ui/blurEffect.sj"
        sjt_functionParam501 = scene;
#line 44
        cb._cb(cb._parent, sjt_functionParam501);
    } else {
        if ((_parent->_vertexbuffer1._refCount != -1 ? &_parent->_vertexbuffer1 : 0) == 0) {
            sjt_value5._refCount = 1;
            sjt_value5.rect._refCount = 1;
#line 50 "lib/sj-lib-ui/blurEffect.sj"
            sjt_value5.rect.x = 0;
#line 50
            sjt_value5.rect.y = 0;
#line 50
            sjt_value5.rect.w = (&_parent->_rect)->w;
#line 50
            sjt_value5.rect.h = (&_parent->_rect)->h;
#line 50
            sjf_rect(&sjt_value5.rect);
#line 50
            sjf_boxvertexbuffer(&sjt_value5);
#line 50
            if (_parent->_vertexbuffer1._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer1); }
;
#line 49
            sjs_boxvertexbuffer* copyoption25 = &sjt_value5;
            if (copyoption25 != 0) {
                _parent->_vertexbuffer1._refCount = 1;
#line 49 "lib/sj-lib-ui/blurEffect.sj"
                sjf_boxvertexbuffer_copy(&_parent->_vertexbuffer1, copyoption25);
            } else {
                _parent->_vertexbuffer1._refCount = -1;
            }
        }

        if ((_parent->_vertexbuffer2._refCount != -1 ? &_parent->_vertexbuffer2 : 0) == 0) {
            sjt_value6._refCount = 1;
            sjt_value6.rect._refCount = 1;
#line 56 "lib/sj-lib-ui/blurEffect.sj"
            sjf_rect_copy(&sjt_value6.rect, &_parent->_rect);
#line 56
            sjf_boxvertexbuffer(&sjt_value6);
#line 56
            if (_parent->_vertexbuffer2._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer2); }
;
#line 56
            sjs_boxvertexbuffer* copyoption26 = &sjt_value6;
            if (copyoption26 != 0) {
                _parent->_vertexbuffer2._refCount = 1;
#line 56 "lib/sj-lib-ui/blurEffect.sj"
                sjf_boxvertexbuffer_copy(&_parent->_vertexbuffer2, copyoption26);
            } else {
                _parent->_vertexbuffer2._refCount = -1;
            }
        }

        if ((_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0) == 0) {
            sjt_value7._refCount = 1;
            sjt_value7.size._refCount = 1;
#line 63 "lib/sj-lib-ui/blurEffect.sj"
            sjt_value7.size.w = (&_parent->_rect)->w;
#line 63
            sjt_value7.size.h = (&_parent->_rect)->h;
#line 63
            sjf_size(&sjt_value7.size);
#line 63
            sjt_value7.framebuffer._refCount = 1;
#line 63
            sjt_value7.framebuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
            sjt_value7.framebuffer.size.w = 0;
#line 3
            sjt_value7.framebuffer.size.h = 0;
#line 3
            sjf_size(&sjt_value7.framebuffer.size);
#line 3 "lib/sj-lib-ui/framebuffer.sj"
            sjt_value7.framebuffer.id = (uint32_t)0u;
#line 3
            sjf_framebuffer(&sjt_value7.framebuffer);
#line 3
            sjt_value7.texture._refCount = 1;
#line 3
            sjt_value7.texture.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
            sjt_value7.texture.size.w = 0;
#line 3
            sjt_value7.texture.size.h = 0;
#line 3
            sjf_size(&sjt_value7.texture.size);
#line 3 "lib/sj-lib-ui/texture.sj"
            sjt_value7.texture.id = (uint32_t)0u;
#line 3
            sjf_texture(&sjt_value7.texture);
#line 3
            sjt_value7.renderbuffer._refCount = 1;
#line 3
            sjt_value7.renderbuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
            sjt_value7.renderbuffer.size.w = 0;
#line 3
            sjt_value7.renderbuffer.size.h = 0;
#line 3
            sjf_size(&sjt_value7.renderbuffer.size);
#line 3 "lib/sj-lib-ui/renderbuffer.sj"
            sjt_value7.renderbuffer.id = (uint32_t)0u;
#line 3
            sjf_renderbuffer(&sjt_value7.renderbuffer);
#line 3
            sjf_scenebuffer(&sjt_value7);
#line 3
            if (_parent->_scenebuffer1._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer1); }
;
#line 63 "lib/sj-lib-ui/blurEffect.sj"
            sjs_scenebuffer* copyoption27 = &sjt_value7;
            if (copyoption27 != 0) {
                _parent->_scenebuffer1._refCount = 1;
#line 63 "lib/sj-lib-ui/blurEffect.sj"
                sjf_scenebuffer_copy(&_parent->_scenebuffer1, copyoption27);
            } else {
                _parent->_scenebuffer1._refCount = -1;
            }
        }

        if ((_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0) == 0) {
            sjt_value8._refCount = 1;
            sjt_value8.size._refCount = 1;
#line 67 "lib/sj-lib-ui/blurEffect.sj"
            sjt_value8.size.w = (&_parent->_rect)->w;
#line 67
            sjt_value8.size.h = (&_parent->_rect)->h;
#line 67
            sjf_size(&sjt_value8.size);
#line 67
            sjt_value8.framebuffer._refCount = 1;
#line 67
            sjt_value8.framebuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
            sjt_value8.framebuffer.size.w = 0;
#line 3
            sjt_value8.framebuffer.size.h = 0;
#line 3
            sjf_size(&sjt_value8.framebuffer.size);
#line 3 "lib/sj-lib-ui/framebuffer.sj"
            sjt_value8.framebuffer.id = (uint32_t)0u;
#line 3
            sjf_framebuffer(&sjt_value8.framebuffer);
#line 3
            sjt_value8.texture._refCount = 1;
#line 3
            sjt_value8.texture.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
            sjt_value8.texture.size.w = 0;
#line 3
            sjt_value8.texture.size.h = 0;
#line 3
            sjf_size(&sjt_value8.texture.size);
#line 3 "lib/sj-lib-ui/texture.sj"
            sjt_value8.texture.id = (uint32_t)0u;
#line 3
            sjf_texture(&sjt_value8.texture);
#line 3
            sjt_value8.renderbuffer._refCount = 1;
#line 3
            sjt_value8.renderbuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
            sjt_value8.renderbuffer.size.w = 0;
#line 3
            sjt_value8.renderbuffer.size.h = 0;
#line 3
            sjf_size(&sjt_value8.renderbuffer.size);
#line 3 "lib/sj-lib-ui/renderbuffer.sj"
            sjt_value8.renderbuffer.id = (uint32_t)0u;
#line 3
            sjf_renderbuffer(&sjt_value8.renderbuffer);
#line 3
            sjf_scenebuffer(&sjt_value8);
#line 3
            if (_parent->_scenebuffer2._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer2); }
;
#line 67 "lib/sj-lib-ui/blurEffect.sj"
            sjs_scenebuffer* copyoption28 = &sjt_value8;
            if (copyoption28 != 0) {
                _parent->_scenebuffer2._refCount = 1;
#line 67 "lib/sj-lib-ui/blurEffect.sj"
                sjf_scenebuffer_copy(&_parent->_scenebuffer2, copyoption28);
            } else {
                _parent->_scenebuffer2._refCount = -1;
            }
        }

        if (((_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0) != 0) && ((_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0) != 0) && ((_parent->_vertexbuffer1._refCount != -1 ? &_parent->_vertexbuffer1 : 0) != 0) && ((_parent->_vertexbuffer2._refCount != -1 ? &_parent->_vertexbuffer2 : 0) != 0)) {
            sjs_scenebuffer* ifValue19 = 0;
            sjs_scenebuffer* ifValue20 = 0;
            sjs_boxvertexbuffer* ifValue21 = 0;
            sjs_boxvertexbuffer* ifValue22 = 0;
            sjs_string sjt_call136 = { -1 };
            sjs_string sjt_call137 = { -1 };
            sjs_string sjt_call138 = { -1 };
            sjs_string sjt_call139 = { -1 };
            sjs_string sjt_call140 = { -1 };
            sjs_string sjt_call141 = { -1 };
            sjs_string sjt_call142 = { -1 };
            sjs_string sjt_call143 = { -1 };
            sjs_string sjt_call144 = { -1 };
            sjs_string sjt_call145 = { -1 };
            sjs_string sjt_call146 = { -1 };
            sjs_string sjt_call147 = { -1 };
            int32_t sjt_cast19;
            int32_t sjt_cast20;
            sjs_framebuffer* sjt_functionParam502 = 0;
            sjs_size* sjt_functionParam513 = 0;
            sjs_scene2d* sjt_functionParam516 = 0;
            sjs_framebuffer* sjt_functionParam519 = 0;
            sjs_framebuffer* sjt_functionParam520 = 0;
            sjs_size* sjt_functionParam521 = 0;
            int32_t sjt_functionParam522;
            sjs_texture* sjt_functionParam523 = 0;
            sjs_shader* sjt_functionParam524 = 0;
            int32_t sjt_functionParam525;
            int32_t sjt_functionParam526;
            int32_t sjt_functionParam527;
            sjs_shader* sjt_functionParam528 = 0;
            sjs_string* sjt_functionParam529 = 0;
            int32_t sjt_functionParam530;
            int32_t sjt_functionParam531;
            sjs_shader* sjt_functionParam532 = 0;
            sjs_string* sjt_functionParam533 = 0;
            float sjt_functionParam534;
            int32_t sjt_functionParam535;
            sjs_shader* sjt_functionParam536 = 0;
            sjs_string* sjt_functionParam537 = 0;
            float sjt_functionParam538;
            int32_t sjt_functionParam539;
            sjs_shader* sjt_functionParam540 = 0;
            sjs_string* sjt_functionParam541 = 0;
            sjs_mat4* sjt_functionParam542 = 0;
            int32_t sjt_functionParam543;
            sjs_shader* sjt_functionParam544 = 0;
            sjs_string* sjt_functionParam545 = 0;
            sjs_mat4* sjt_functionParam546 = 0;
            int32_t sjt_functionParam547;
            sjs_shader* sjt_functionParam548 = 0;
            sjs_string* sjt_functionParam549 = 0;
            sjs_mat4* sjt_functionParam550 = 0;
            sjs_scene2d* sjt_functionParam551 = 0;
            sjs_framebuffer* sjt_functionParam552 = 0;
            int32_t sjt_functionParam553;
            sjs_texture* sjt_functionParam554 = 0;
            sjs_shader* sjt_functionParam555 = 0;
            int32_t sjt_functionParam556;
            int32_t sjt_functionParam557;
            int32_t sjt_functionParam558;
            sjs_shader* sjt_functionParam559 = 0;
            sjs_string* sjt_functionParam560 = 0;
            int32_t sjt_functionParam561;
            int32_t sjt_functionParam562;
            sjs_shader* sjt_functionParam563 = 0;
            sjs_string* sjt_functionParam564 = 0;
            float sjt_functionParam565;
            int32_t sjt_functionParam566;
            sjs_shader* sjt_functionParam567 = 0;
            sjs_string* sjt_functionParam568 = 0;
            float sjt_functionParam569;
            int32_t sjt_functionParam570;
            sjs_shader* sjt_functionParam571 = 0;
            sjs_string* sjt_functionParam572 = 0;
            sjs_mat4* sjt_functionParam573 = 0;
            int32_t sjt_functionParam574;
            sjs_shader* sjt_functionParam575 = 0;
            sjs_string* sjt_functionParam576 = 0;
            sjs_mat4* sjt_functionParam577 = 0;
            int32_t sjt_functionParam578;
            sjs_shader* sjt_functionParam579 = 0;
            sjs_string* sjt_functionParam580 = 0;
            sjs_mat4* sjt_functionParam581 = 0;
            sjs_scene2d* sjt_functionParam582 = 0;
            sjs_scene2d* sjt_parent330 = 0;
            sjs_scene2d* sjt_parent331 = 0;
            sjs_scene2d* sjt_parent332 = 0;
            sjs_scene2d* sjt_parent333 = 0;
            sjs_scene2d* sjt_parent334 = 0;
            sjs_boxvertexbuffer* sjt_parent335 = 0;
            sjs_scene2d* sjt_parent336 = 0;
            sjs_boxvertexbuffer* sjt_parent337 = 0;

#line 70 "lib/sj-lib-ui/blurEffect.sj"
            ifValue19 = (_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0);
#line 70
            ifValue20 = (_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0);
#line 70
            ifValue21 = (_parent->_vertexbuffer1._refCount != -1 ? &_parent->_vertexbuffer1 : 0);
#line 70
            ifValue22 = (_parent->_vertexbuffer2._refCount != -1 ? &_parent->_vertexbuffer2 : 0);
#line 71
            sjt_functionParam502 = &ifValue19->framebuffer;
#line 71
            sjf_glpushframebuffer(sjt_functionParam502);
#line 27 "lib/sj-lib-ui/scene2d.sj"
            sjt_parent330 = &_parent->_innerscene;
#line 72 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam513 = &ifValue19->size;
#line 72
            sjf_scene2d_setsize(sjt_parent330, sjt_functionParam513);
#line 8 "lib/sj-lib-ui/scene2d.sj"
            sjt_parent331 = &_parent->_innerscene;
#line 8
            sjf_scene2d_start(sjt_parent331);
#line 75 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam516 = &_parent->_innerscene;
#line 75
            cb._cb(cb._parent, sjt_functionParam516);
#line 19 "lib/sj-lib-ui/scene2d.sj"
            sjt_parent332 = &_parent->_innerscene;
#line 19
            sjf_scene2d_end(sjt_parent332);
#line 78 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam519 = &ifValue19->framebuffer;
#line 78
            sjf_glpopframebuffer(sjt_functionParam519);
#line 80
            sjt_functionParam520 = &ifValue20->framebuffer;
#line 80
            sjf_glpushframebuffer(sjt_functionParam520);
#line 27 "lib/sj-lib-ui/scene2d.sj"
            sjt_parent333 = &_parent->_innerscene;
#line 81 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam521 = &ifValue20->size;
#line 81
            sjf_scene2d_setsize(sjt_parent333, sjt_functionParam521);
#line 8 "lib/sj-lib-ui/scene2d.sj"
            sjt_parent334 = &_parent->_innerscene;
#line 8
            sjf_scene2d_start(sjt_parent334);
#line 84 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam522 = g_gltexture_gl_texture_2d;
#line 84
            sjt_functionParam523 = &ifValue19->texture;
#line 84
            sjf_glbindtexture(sjt_functionParam522, sjt_functionParam523);
#line 85
            sjt_functionParam524 = &g_blurverticalshader;
#line 85
            sjf_gluseprogram(sjt_functionParam524);
#line 86
            sjt_functionParam525 = g_glblendfunctype_gl_one;
#line 86
            sjt_functionParam526 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 86
            sjf_glblendfunc(sjt_functionParam525, sjt_functionParam526);
#line 87
            sjt_functionParam528 = &g_blurverticalshader;
#line 87
            sjt_call136._refCount = 1;
#line 87
            sjt_call136.offset = 0;
#line 87
            sjt_call136.count = 7;
#line 87
            sjt_call136.data._refCount = 1;
#line 87
            sjt_call136.data.v = &sjg_string28;
#line 87
            sjf_array_char(&sjt_call136.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call136._isnullterminated = false;
#line 16
            sjf_string(&sjt_call136);
#line 87 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam529 = &sjt_call136;
#line 87
            sjf_glgetuniformlocation(sjt_functionParam528, sjt_functionParam529, &sjt_functionParam527);
#line 87
            sjt_functionParam530 = 0;
#line 87
            sjf_gluniformi32(sjt_functionParam527, sjt_functionParam530);
#line 88
            sjt_functionParam532 = &g_blurverticalshader;
#line 88
            sjt_call137._refCount = 1;
#line 88
            sjt_call137.offset = 0;
#line 88
            sjt_call137.count = 5;
#line 88
            sjt_call137.data._refCount = 1;
#line 88
            sjt_call137.data.v = &sjg_string34;
#line 88
            sjf_array_char(&sjt_call137.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call137._isnullterminated = false;
#line 16
            sjf_string(&sjt_call137);
#line 88 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam533 = &sjt_call137;
#line 88
            sjf_glgetuniformlocation(sjt_functionParam532, sjt_functionParam533, &sjt_functionParam531);
#line 88
            sjt_functionParam534 = _parent->radius;
#line 88
            sjf_gluniformf32(sjt_functionParam531, sjt_functionParam534);
#line 89
            sjt_functionParam536 = &g_blurverticalshader;
#line 89
            sjt_call138._refCount = 1;
#line 89
            sjt_call138.offset = 0;
#line 89
            sjt_call138.count = 8;
#line 89
            sjt_call138.data._refCount = 1;
#line 89
            sjt_call138.data.v = &sjg_string35;
#line 89
            sjf_array_char(&sjt_call138.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call138._isnullterminated = false;
#line 16
            sjf_string(&sjt_call138);
#line 89 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam537 = &sjt_call138;
#line 89
            sjf_glgetuniformlocation(sjt_functionParam536, sjt_functionParam537, &sjt_functionParam535);
#line 89
            sjt_cast19 = (&ifValue19->size)->h;
#line 89
            sjt_functionParam538 = 1.0f / (float)sjt_cast19;
#line 89
            sjf_gluniformf32(sjt_functionParam535, sjt_functionParam538);
#line 90
            sjt_functionParam540 = &g_blurverticalshader;
#line 90
            sjt_call139._refCount = 1;
#line 90
            sjt_call139.offset = 0;
#line 90
            sjt_call139.count = 5;
#line 90
            sjt_call139.data._refCount = 1;
#line 90
            sjt_call139.data.v = &sjg_string29;
#line 90
            sjf_array_char(&sjt_call139.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call139._isnullterminated = false;
#line 16
            sjf_string(&sjt_call139);
#line 90 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam541 = &sjt_call139;
#line 90
            sjf_glgetuniformlocation(sjt_functionParam540, sjt_functionParam541, &sjt_functionParam539);
#line 90
            sjt_functionParam542 = &(&_parent->_innerscene)->model;
#line 90
            sjf_gluniformmat4(sjt_functionParam539, sjt_functionParam542);
#line 91
            sjt_functionParam544 = &g_blurverticalshader;
#line 91
            sjt_call140._refCount = 1;
#line 91
            sjt_call140.offset = 0;
#line 91
            sjt_call140.count = 4;
#line 91
            sjt_call140.data._refCount = 1;
#line 91
            sjt_call140.data.v = &sjg_string30;
#line 91
            sjf_array_char(&sjt_call140.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call140._isnullterminated = false;
#line 16
            sjf_string(&sjt_call140);
#line 91 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam545 = &sjt_call140;
#line 91
            sjf_glgetuniformlocation(sjt_functionParam544, sjt_functionParam545, &sjt_functionParam543);
#line 91
            sjt_functionParam546 = &(&_parent->_innerscene)->view;
#line 91
            sjf_gluniformmat4(sjt_functionParam543, sjt_functionParam546);
#line 92
            sjt_functionParam548 = &g_blurverticalshader;
#line 92
            sjt_call141._refCount = 1;
#line 92
            sjt_call141.offset = 0;
#line 92
            sjt_call141.count = 10;
#line 92
            sjt_call141.data._refCount = 1;
#line 92
            sjt_call141.data.v = &sjg_string19;
#line 92
            sjf_array_char(&sjt_call141.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call141._isnullterminated = false;
#line 16
            sjf_string(&sjt_call141);
#line 92 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam549 = &sjt_call141;
#line 92
            sjf_glgetuniformlocation(sjt_functionParam548, sjt_functionParam549, &sjt_functionParam547);
#line 92
            sjt_functionParam550 = &(&_parent->_innerscene)->projection;
#line 92
            sjf_gluniformmat4(sjt_functionParam547, sjt_functionParam550);
#line 7 "lib/sj-lib-ui/boxVertexBuffer.sj"
            sjt_parent335 = ifValue21;
#line 93 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam551 = &_parent->_innerscene;
#line 93
            sjf_boxvertexbuffer_render(sjt_parent335, sjt_functionParam551);
#line 19 "lib/sj-lib-ui/scene2d.sj"
            sjt_parent336 = &_parent->_innerscene;
#line 19
            sjf_scene2d_end(sjt_parent336);
#line 96 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam552 = &ifValue20->framebuffer;
#line 96
            sjf_glpopframebuffer(sjt_functionParam552);
#line 98
            sjt_functionParam553 = g_gltexture_gl_texture_2d;
#line 98
            sjt_functionParam554 = &ifValue20->texture;
#line 98
            sjf_glbindtexture(sjt_functionParam553, sjt_functionParam554);
#line 99
            sjt_functionParam555 = &g_blurhorizontalshader;
#line 99
            sjf_gluseprogram(sjt_functionParam555);
#line 100
            sjt_functionParam556 = g_glblendfunctype_gl_one;
#line 100
            sjt_functionParam557 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 100
            sjf_glblendfunc(sjt_functionParam556, sjt_functionParam557);
#line 101
            sjt_functionParam559 = &g_blurhorizontalshader;
#line 101
            sjt_call142._refCount = 1;
#line 101
            sjt_call142.offset = 0;
#line 101
            sjt_call142.count = 7;
#line 101
            sjt_call142.data._refCount = 1;
#line 101
            sjt_call142.data.v = &sjg_string28;
#line 101
            sjf_array_char(&sjt_call142.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call142._isnullterminated = false;
#line 16
            sjf_string(&sjt_call142);
#line 101 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam560 = &sjt_call142;
#line 101
            sjf_glgetuniformlocation(sjt_functionParam559, sjt_functionParam560, &sjt_functionParam558);
#line 101
            sjt_functionParam561 = 0;
#line 101
            sjf_gluniformi32(sjt_functionParam558, sjt_functionParam561);
#line 102
            sjt_functionParam563 = &g_blurhorizontalshader;
#line 102
            sjt_call143._refCount = 1;
#line 102
            sjt_call143.offset = 0;
#line 102
            sjt_call143.count = 5;
#line 102
            sjt_call143.data._refCount = 1;
#line 102
            sjt_call143.data.v = &sjg_string34;
#line 102
            sjf_array_char(&sjt_call143.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call143._isnullterminated = false;
#line 16
            sjf_string(&sjt_call143);
#line 102 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam564 = &sjt_call143;
#line 102
            sjf_glgetuniformlocation(sjt_functionParam563, sjt_functionParam564, &sjt_functionParam562);
#line 102
            sjt_functionParam565 = _parent->radius;
#line 102
            sjf_gluniformf32(sjt_functionParam562, sjt_functionParam565);
#line 103
            sjt_functionParam567 = &g_blurhorizontalshader;
#line 103
            sjt_call144._refCount = 1;
#line 103
            sjt_call144.offset = 0;
#line 103
            sjt_call144.count = 8;
#line 103
            sjt_call144.data._refCount = 1;
#line 103
            sjt_call144.data.v = &sjg_string35;
#line 103
            sjf_array_char(&sjt_call144.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call144._isnullterminated = false;
#line 16
            sjf_string(&sjt_call144);
#line 103 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam568 = &sjt_call144;
#line 103
            sjf_glgetuniformlocation(sjt_functionParam567, sjt_functionParam568, &sjt_functionParam566);
#line 103
            sjt_cast20 = (&ifValue20->size)->w;
#line 103
            sjt_functionParam569 = 1.0f / (float)sjt_cast20;
#line 103
            sjf_gluniformf32(sjt_functionParam566, sjt_functionParam569);
#line 104
            sjt_functionParam571 = &g_blurhorizontalshader;
#line 104
            sjt_call145._refCount = 1;
#line 104
            sjt_call145.offset = 0;
#line 104
            sjt_call145.count = 5;
#line 104
            sjt_call145.data._refCount = 1;
#line 104
            sjt_call145.data.v = &sjg_string29;
#line 104
            sjf_array_char(&sjt_call145.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call145._isnullterminated = false;
#line 16
            sjf_string(&sjt_call145);
#line 104 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam572 = &sjt_call145;
#line 104
            sjf_glgetuniformlocation(sjt_functionParam571, sjt_functionParam572, &sjt_functionParam570);
#line 104
            sjt_functionParam573 = &scene->model;
#line 104
            sjf_gluniformmat4(sjt_functionParam570, sjt_functionParam573);
#line 105
            sjt_functionParam575 = &g_blurhorizontalshader;
#line 105
            sjt_call146._refCount = 1;
#line 105
            sjt_call146.offset = 0;
#line 105
            sjt_call146.count = 4;
#line 105
            sjt_call146.data._refCount = 1;
#line 105
            sjt_call146.data.v = &sjg_string30;
#line 105
            sjf_array_char(&sjt_call146.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call146._isnullterminated = false;
#line 16
            sjf_string(&sjt_call146);
#line 105 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam576 = &sjt_call146;
#line 105
            sjf_glgetuniformlocation(sjt_functionParam575, sjt_functionParam576, &sjt_functionParam574);
#line 105
            sjt_functionParam577 = &scene->view;
#line 105
            sjf_gluniformmat4(sjt_functionParam574, sjt_functionParam577);
#line 106
            sjt_functionParam579 = &g_blurhorizontalshader;
#line 106
            sjt_call147._refCount = 1;
#line 106
            sjt_call147.offset = 0;
#line 106
            sjt_call147.count = 10;
#line 106
            sjt_call147.data._refCount = 1;
#line 106
            sjt_call147.data.v = &sjg_string19;
#line 106
            sjf_array_char(&sjt_call147.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call147._isnullterminated = false;
#line 16
            sjf_string(&sjt_call147);
#line 106 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam580 = &sjt_call147;
#line 106
            sjf_glgetuniformlocation(sjt_functionParam579, sjt_functionParam580, &sjt_functionParam578);
#line 106
            sjt_functionParam581 = &scene->projection;
#line 106
            sjf_gluniformmat4(sjt_functionParam578, sjt_functionParam581);
#line 7 "lib/sj-lib-ui/boxVertexBuffer.sj"
            sjt_parent337 = ifValue22;
#line 44 "lib/sj-lib-ui/blurEffect.sj"
            sjt_functionParam582 = scene;
#line 44
            sjf_boxvertexbuffer_render(sjt_parent337, sjt_functionParam582);

            if (sjt_call136._refCount == 1) { sjf_string_destroy(&sjt_call136); }
;
            if (sjt_call137._refCount == 1) { sjf_string_destroy(&sjt_call137); }
;
            if (sjt_call138._refCount == 1) { sjf_string_destroy(&sjt_call138); }
;
            if (sjt_call139._refCount == 1) { sjf_string_destroy(&sjt_call139); }
;
            if (sjt_call140._refCount == 1) { sjf_string_destroy(&sjt_call140); }
;
            if (sjt_call141._refCount == 1) { sjf_string_destroy(&sjt_call141); }
;
            if (sjt_call142._refCount == 1) { sjf_string_destroy(&sjt_call142); }
;
            if (sjt_call143._refCount == 1) { sjf_string_destroy(&sjt_call143); }
;
            if (sjt_call144._refCount == 1) { sjf_string_destroy(&sjt_call144); }
;
            if (sjt_call145._refCount == 1) { sjf_string_destroy(&sjt_call145); }
;
            if (sjt_call146._refCount == 1) { sjf_string_destroy(&sjt_call146); }
;
            if (sjt_call147._refCount == 1) { sjf_string_destroy(&sjt_call147); }
;
        }
    }

    if (sjt_value5._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_value5); }
;
    if (sjt_value6._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_value6); }
;
    if (sjt_value7._refCount == 1) { sjf_scenebuffer_destroy(&sjt_value7); }
;
    if (sjt_value8._refCount == 1) { sjf_scenebuffer_destroy(&sjt_value8); }
;
}

void sjf_blureffect_setrect(sjs_blureffect* _parent, sjs_rect* rect_, cb_rect_void cb) {
    bool result13;
    sjs_rect sjt_call135 = { -1 };
    bool sjt_capture75;
    sjs_rect* sjt_functionParam496 = 0;
    sjs_rect* sjt_parent326 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent326 = &_parent->_rect;
#line 15 "lib/sj-lib-ui/blurEffect.sj"
    sjt_functionParam496 = rect_;
#line 15
    sjf_rect_isequal(sjt_parent326, sjt_functionParam496, &sjt_capture75);
#line 16
    result13 = !sjt_capture75;
    if (result13) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 15 "lib/sj-lib-ui/blurEffect.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
        if (((_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0) != 0)) {
            sjs_scenebuffer* ifValue15 = 0;
            bool result14;
            sjs_size sjt_call133 = { -1 };
            bool sjt_capture76;
            sjs_size* sjt_functionParam497 = 0;
            sjs_size* sjt_parent327 = 0;

#line 19 "lib/sj-lib-ui/blurEffect.sj"
            ifValue15 = (_parent->_scenebuffer1._refCount != -1 ? &_parent->_scenebuffer1 : 0);
#line 27 "lib/sj-lib-ui/size.sj"
            sjt_parent327 = &ifValue15->size;
#line 27
            sjt_call133._refCount = 1;
#line 20 "lib/sj-lib-ui/blurEffect.sj"
            sjt_call133.w = (&_parent->_rect)->w;
#line 20
            sjt_call133.h = (&_parent->_rect)->h;
#line 20
            sjf_size(&sjt_call133);
#line 20
            sjt_functionParam497 = &sjt_call133;
#line 20
            sjf_size_isequal(sjt_parent327, sjt_functionParam497, &sjt_capture76);
#line 20
            result14 = !sjt_capture76;
            if (result14) {
                if (_parent->_scenebuffer1._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer1); }
;
#line 21 "lib/sj-lib-ui/blurEffect.sj"
                _parent->_scenebuffer1._refCount = -1;
#line 21
                if (_parent->_vertexbuffer1._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer1); }
;
#line 22
                _parent->_vertexbuffer1._refCount = -1;
            }

            if (sjt_call133._refCount == 1) { sjf_size_destroy(&sjt_call133); }
;
        }

        if (((_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0) != 0)) {
            sjs_scenebuffer* ifValue16 = 0;
            bool result15;
            sjs_size sjt_call134 = { -1 };
            bool sjt_capture77;
            sjs_size* sjt_functionParam498 = 0;
            sjs_size* sjt_parent328 = 0;

#line 26 "lib/sj-lib-ui/blurEffect.sj"
            ifValue16 = (_parent->_scenebuffer2._refCount != -1 ? &_parent->_scenebuffer2 : 0);
#line 27 "lib/sj-lib-ui/size.sj"
            sjt_parent328 = &ifValue16->size;
#line 27
            sjt_call134._refCount = 1;
#line 27 "lib/sj-lib-ui/blurEffect.sj"
            sjt_call134.w = (&_parent->_rect)->w;
#line 27
            sjt_call134.h = (&_parent->_rect)->h;
#line 27
            sjf_size(&sjt_call134);
#line 27
            sjt_functionParam498 = &sjt_call134;
#line 27
            sjf_size_isequal(sjt_parent328, sjt_functionParam498, &sjt_capture77);
#line 27
            result15 = !sjt_capture77;
            if (result15) {
                if (_parent->_scenebuffer2._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer2); }
;
#line 28 "lib/sj-lib-ui/blurEffect.sj"
                _parent->_scenebuffer2._refCount = -1;
            }

            if (sjt_call134._refCount == 1) { sjf_size_destroy(&sjt_call134); }
;
        }

#line 15
        if (_parent->_vertexbuffer2._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer2); }
;
#line 32
        _parent->_vertexbuffer2._refCount = -1;
    }

    if (_parent->radius == 0.0f) {
        sjs_rect* sjt_functionParam499 = 0;

#line 36 "lib/sj-lib-ui/blurEffect.sj"
        sjt_functionParam499 = &_parent->_rect;
#line 36
        cb._cb(cb._parent, sjt_functionParam499);
    } else {
        sjs_rect* sjt_functionParam500 = 0;

        sjt_call135._refCount = 1;
#line 38 "lib/sj-lib-ui/blurEffect.sj"
        sjt_call135.x = 0;
#line 38
        sjt_call135.y = 0;
#line 38
        sjt_call135.w = (&_parent->_rect)->w;
#line 38
        sjt_call135.h = (&_parent->_rect)->h;
#line 38
        sjf_rect(&sjt_call135);
#line 38
        sjt_functionParam500 = &sjt_call135;
#line 38
        cb._cb(cb._parent, sjt_functionParam500);
    }

    if (sjt_call135._refCount == 1) { sjf_rect_destroy(&sjt_call135); }
;
}

void sjf_boxelement(sjs_boxelement* _this) {
}

void sjf_boxelement_as_sji_element(sjs_boxelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_boxelement_element_vtbl;
}

void sjf_boxelement_asinterface(sjs_boxelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_boxelement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_boxelement_copy(sjs_boxelement* _this, sjs_boxelement* _from) {
    _this->color._refCount = 1;
#line 1 "lib/sj-lib-ui/boxElement.sj"
    sjf_color_copy(&_this->color, &_from->color);
#line 1
    _this->idealsize._refCount = 1;
#line 1
    sjf_size_copy(&_this->idealsize, &_from->idealsize);
#line 1
    _this->rect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 1
    sjs_boxrenderer* copyoption14 = (_from->boxrenderer._refCount != -1 ? &_from->boxrenderer : 0);
    if (copyoption14 != 0) {
        _this->boxrenderer._refCount = 1;
#line 1 "lib/sj-lib-ui/boxElement.sj"
        sjf_boxrenderer_copy(&_this->boxrenderer, copyoption14);
    } else {
        _this->boxrenderer._refCount = -1;
    }
}

void sjf_boxelement_destroy(sjs_boxelement* _this) {
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
    if (_this->idealsize._refCount == 1) { sjf_size_destroy(&_this->idealsize); }
;
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
    if (_this->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_this->boxrenderer); }
;
}

void sjf_boxelement_firemouseevent(sjs_boxelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
}

void sjf_boxelement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 129;
}

void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 11 "lib/sj-lib-ui/boxElement.sj"
    sjf_rect_copy(_return, &_parent->rect);
}

void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 11 "lib/sj-lib-ui/boxElement.sj"
    sjf_rect_copy((*_return), &_parent->rect);
}

void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_functionParam65 = 0;
    sjs_size* sjt_parent66 = 0;

#line 5 "lib/sj-lib-ui/size.sj"
    sjt_parent66 = &_parent->idealsize;
#line 7 "lib/sj-lib-ui/boxElement.sj"
    sjt_functionParam65 = maxsize;
#line 7
    sjf_size_min(sjt_parent66, sjt_functionParam65, _return);
}

void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_functionParam66 = 0;
    sjs_size* sjt_parent67 = 0;

#line 5 "lib/sj-lib-ui/size.sj"
    sjt_parent67 = &_parent->idealsize;
#line 7 "lib/sj-lib-ui/boxElement.sj"
    sjt_functionParam66 = maxsize;
#line 7
    sjf_size_min_heap(sjt_parent67, sjt_functionParam66, _return);
}

void sjf_boxelement_heap(sjs_boxelement* _this) {
}

void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene) {
    sjs_boxrenderer sjt_value2 = { -1 };

    if ((_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0) == 0) {
        sjt_value2._refCount = 1;
        sjt_value2.rect._refCount = 1;
#line 23 "lib/sj-lib-ui/boxElement.sj"
        sjf_rect_copy(&sjt_value2.rect, &_parent->rect);
#line 23
        sjt_value2.color._refCount = 1;
#line 23
        sjf_color_copy(&sjt_value2.color, &_parent->color);
#line 23
        sjf_boxrenderer(&sjt_value2);
#line 23
        if (_parent->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->boxrenderer); }
;
#line 23
        sjs_boxrenderer* copyoption15 = &sjt_value2;
        if (copyoption15 != 0) {
            _parent->boxrenderer._refCount = 1;
#line 23 "lib/sj-lib-ui/boxElement.sj"
            sjf_boxrenderer_copy(&_parent->boxrenderer, copyoption15);
        } else {
            _parent->boxrenderer._refCount = -1;
        }
    }

    if ((_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam68 = 0;
        sjs_boxrenderer* sjt_parent69 = 0;

#line 8 "lib/sj-lib-ui/boxRenderer.sj"
        sjt_parent69 = (_parent->boxrenderer._refCount != -1 ? &_parent->boxrenderer : 0);
#line 21 "lib/sj-lib-ui/boxElement.sj"
        sjt_functionParam68 = scene;
#line 21
        sjf_boxrenderer_render(sjt_parent69, sjt_functionParam68);
    }

    if (sjt_value2._refCount == 1) { sjf_boxrenderer_destroy(&sjt_value2); }
;
}

void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_) {
    bool result3;
    bool sjt_capture18;
    sjs_rect* sjt_functionParam67 = 0;
    sjs_rect* sjt_parent68 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent68 = &_parent->rect;
#line 13 "lib/sj-lib-ui/boxElement.sj"
    sjt_functionParam67 = rect_;
#line 13
    sjf_rect_isequal(sjt_parent68, sjt_functionParam67, &sjt_capture18);
#line 14
    result3 = !sjt_capture18;
    if (result3) {
        if (_parent->rect._refCount == 1) { sjf_rect_destroy(&_parent->rect); }
;
#line 13 "lib/sj-lib-ui/boxElement.sj"
        sjf_rect_copy(&_parent->rect, rect_);
#line 13
        if (_parent->boxrenderer._refCount == 1) { sjf_boxrenderer_destroy(&_parent->boxrenderer); }
;
#line 16
        _parent->boxrenderer._refCount = -1;
    }
}

void sjf_boxrenderer(sjs_boxrenderer* _this) {
#line 20 "lib/sj-lib-ui/boxRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
#line 21
    float x0 = (float)_this->rect.x;
#line 22
    float y0 = (float)(_this->rect.y + _this->rect.h);
#line 23
    float x1 = (float)(_this->rect.x + _this->rect.w);
#line 24
    float y1 = (float)_this->rect.y;
#line 25
    GLuint index = (GLuint)_this->buffer->vertices->size;
#line 26
    GLuint indices[] = { //
#line 27
    index, index+1, index+2,
#line 28
    index, index+2, index+3 };
#line 29
    vertex3_color4_t vertices[] = { //
#line 30
    { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 31
    { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 32
    { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 33
    { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
#line 34
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 35
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxrenderer_copy(sjs_boxrenderer* _this, sjs_boxrenderer* _from) {
    _this->rect._refCount = 1;
#line 1 "lib/sj-lib-ui/boxRenderer.sj"
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 1
    _this->color._refCount = 1;
#line 1
    sjf_color_copy(&_this->color, &_from->color);
#line 40
    _this->buffer = _from->buffer;
#line 41
    ptr_retain(_this->buffer);
}

void sjf_boxrenderer_destroy(sjs_boxrenderer* _this) {
#line 45 "lib/sj-lib-ui/boxRenderer.sj"
    if (ptr_release(_this->buffer)) {
#line 46
        vertex_buffer_delete(_this->buffer);
#line 47
    }  
#line 47
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
#line 47
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
}

void sjf_boxrenderer_heap(sjs_boxrenderer* _this) {
#line 20 "lib/sj-lib-ui/boxRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
#line 21
    float x0 = (float)_this->rect.x;
#line 22
    float y0 = (float)(_this->rect.y + _this->rect.h);
#line 23
    float x1 = (float)(_this->rect.x + _this->rect.w);
#line 24
    float y1 = (float)_this->rect.y;
#line 25
    GLuint index = (GLuint)_this->buffer->vertices->size;
#line 26
    GLuint indices[] = { //
#line 27
    index, index+1, index+2,
#line 28
    index, index+2, index+3 };
#line 29
    vertex3_color4_t vertices[] = { //
#line 30
    { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 31
    { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 32
    { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 33
    { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
#line 34
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 35
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxrenderer_render(sjs_boxrenderer* _parent, sjs_scene2d* scene) {
#line 10 "lib/sj-lib-ui/boxRenderer.sj"
    glUseProgram(g_boxshader.id);
#line 11
    glUniformMatrix4fv(glGetUniformLocation(g_boxshader.id, "model" ), 1, 0, (GLfloat*)&scene->model.m00);
#line 12
    glUniformMatrix4fv(glGetUniformLocation(g_boxshader.id, "view" ), 1, 0, (GLfloat*)&scene->view.m00);
#line 13
    glUniformMatrix4fv(glGetUniformLocation(g_boxshader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection.m00);
#line 14
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_boxvertexbuffer(sjs_boxvertexbuffer* _this) {
#line 15 "lib/sj-lib-ui/boxVertexBuffer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
#line 16
    float x0 = (float)_this->rect.x;
#line 17
    float x1 = (float)(_this->rect.x + _this->rect.w);
#line 19
    float y0 = (float)_this->rect.y;
#line 20
    float y1 = (float)(_this->rect.y + _this->rect.h);
#line 22
    float s0 = 0.0f;
#line 23
    float s1 = 1.0f;
#line 25
    float t1 = 0.0f;
#line 26
    float t0 = 1.0f;
#line 28
    GLuint index = (GLuint)_this->buffer->vertices->size;
#line 29
    GLuint indices[] = { //
#line 30
    index, index+1, index+2,
#line 31
    index, index+2, index+3 };
#line 32
    vertex3_texture2_t vertices[] = { //
#line 33
    { x0, y0, 0.0f,  s0, t0 },
#line 34
    { x0, y1, 0.0f,  s0, t1 },
#line 35
    { x1, y1, 0.0f,  s1, t1 },
#line 36
    { x1, y0, 0.0f,  s1, t0 } };        
#line 37
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 38
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxvertexbuffer_copy(sjs_boxvertexbuffer* _this, sjs_boxvertexbuffer* _from) {
    _this->rect._refCount = 1;
#line 1 "lib/sj-lib-ui/boxVertexBuffer.sj"
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 43
    _this->buffer = _from->buffer;
#line 44
    ptr_retain(_this->buffer);
}

void sjf_boxvertexbuffer_destroy(sjs_boxvertexbuffer* _this) {
#line 48 "lib/sj-lib-ui/boxVertexBuffer.sj"
    if (ptr_release(_this->buffer)) {
#line 49
        vertex_buffer_delete(_this->buffer);
#line 50
    }  
#line 50
    if (_this->rect._refCount == 1) { sjf_rect_destroy(&_this->rect); }
;
}

void sjf_boxvertexbuffer_heap(sjs_boxvertexbuffer* _this) {
#line 15 "lib/sj-lib-ui/boxVertexBuffer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
#line 16
    float x0 = (float)_this->rect.x;
#line 17
    float x1 = (float)(_this->rect.x + _this->rect.w);
#line 19
    float y0 = (float)_this->rect.y;
#line 20
    float y1 = (float)(_this->rect.y + _this->rect.h);
#line 22
    float s0 = 0.0f;
#line 23
    float s1 = 1.0f;
#line 25
    float t1 = 0.0f;
#line 26
    float t0 = 1.0f;
#line 28
    GLuint index = (GLuint)_this->buffer->vertices->size;
#line 29
    GLuint indices[] = { //
#line 30
    index, index+1, index+2,
#line 31
    index, index+2, index+3 };
#line 32
    vertex3_texture2_t vertices[] = { //
#line 33
    { x0, y0, 0.0f,  s0, t0 },
#line 34
    { x0, y1, 0.0f,  s0, t1 },
#line 35
    { x1, y1, 0.0f,  s1, t1 },
#line 36
    { x1, y0, 0.0f,  s1, t0 } };        
#line 37
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 38
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxvertexbuffer_render(sjs_boxvertexbuffer* _parent, sjs_scene2d* scene) {
#line 9 "lib/sj-lib-ui/boxVertexBuffer.sj"
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 21 "lib/sj-lib-ui/color.sj"
    _return->x = _parent->r;
#line 21
    _return->y = _parent->g;
#line 21
    _return->z = _parent->b;
#line 21
    sjf_vec3(_return);
}

void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 21 "lib/sj-lib-ui/color.sj"
    (*_return)->x = _parent->r;
#line 21
    (*_return)->y = _parent->g;
#line 21
    (*_return)->z = _parent->b;
#line 21
    sjf_vec3_heap((*_return));
}

void sjf_color_copy(sjs_color* _this, sjs_color* _from) {
#line 10 "lib/sj-lib-ui/color.sj"
    _this->r = _from->r;
#line 10
    _this->g = _from->g;
#line 10
    _this->b = _from->b;
#line 10
    _this->a = _from->a;
}

void sjf_color_destroy(sjs_color* _this) {
}

void sjf_color_heap(sjs_color* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
#line 10 "lib/sj-lib-common/debug.sj"
    debugout("%s\n", string_char(data));
}

void sjf_f32_asstring(float val, sjs_string* _return) {
    int32_t count;
    void* v;

#line 94 "lib/sj-lib-common/f32.sj"
    v = 0;
#line 95
    count = 0;
#line 97
    sjs_array* arr = createarray(1, 256);
#line 98
    snprintf(arr->data, 256, "%f", val);
#line 99
    arr->count = (int)strlen(arr->data);
#line 100
    count = arr->count;
#line 101
    v = arr;
#line 101
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 103 "lib/sj-lib-common/f32.sj"
    _return->count = count;
#line 103
    _return->data._refCount = 1;
#line 103
    _return->data.v = v;
#line 103
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_f32_asstring_heap(float val, sjs_string** _return) {
    int32_t count;
    void* v;

#line 94 "lib/sj-lib-common/f32.sj"
    v = 0;
#line 95
    count = 0;
#line 97
    sjs_array* arr = createarray(1, 256);
#line 98
    snprintf(arr->data, 256, "%f", val);
#line 99
    arr->count = (int)strlen(arr->data);
#line 100
    count = arr->count;
#line 101
    v = arr;
#line 101
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 101
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 103 "lib/sj-lib-common/f32.sj"
    (*_return)->count = count;
#line 103
    (*_return)->data._refCount = 1;
#line 103
    (*_return)->data.v = v;
#line 103
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_f32_atan2(float y, float x, float* _return) {
    float result;

#line 36 "lib/sj-lib-common/f32.sj"
    result = 0.0f;
#line 38
    result = atan2f(y, x);
#line 35
    (*_return) = result;
}

void sjf_f32_compare(float l, float r, int32_t* _return) {
    if (l == r) {
#line 133 "lib/sj-lib-common/f32.sj"
        (*_return) = 0;
    } else {
        if (l < r) {
            int32_t result5;

#line 135 "lib/sj-lib-common/f32.sj"
            result5 = -1;
#line 135
            (*_return) = result5;
        } else {
#line 137 "lib/sj-lib-common/f32.sj"
            (*_return) = 1;
        }
    }
}

void sjf_f32_hash(float val, uint32_t* _return) {
    uint32_t result;

#line 123 "lib/sj-lib-common/f32.sj"
    result = (uint32_t)0u;
#line 125
    int32_t* p = (int32_t*)&val;
#line 126
    result = *p;
#line 122
    (*_return) = result;
}

void sjf_f32_max(float a, float b, float* _return) {
    if (a < b) {
#line 43 "lib/sj-lib-common/f32.sj"
        (*_return) = b;
    } else {
#line 43 "lib/sj-lib-common/f32.sj"
        (*_return) = a;
    }
}

void sjf_f32_min(float a, float b, float* _return) {
    if (a < b) {
#line 47 "lib/sj-lib-common/f32.sj"
        (*_return) = a;
    } else {
#line 47 "lib/sj-lib-common/f32.sj"
        (*_return) = b;
    }
}

void sjf_f32_random(float* _return) {
    float x;

#line 52 "lib/sj-lib-common/f32.sj"
    x = 0.0f;
#line 54
    x = (float)rand() / (float)RAND_MAX;
#line 51
    (*_return) = x;
}

void sjf_f32_sqrt(float v, float* _return) {
    float result;

#line 4 "lib/sj-lib-common/f32.sj"
    result = 0.0f;
#line 6
    result = sqrtf(v);
#line 3
    (*_return) = result;
}

void sjf_f32_tan(float v, float* _return) {
    float result;

#line 28 "lib/sj-lib-common/f32.sj"
    result = 0.0f;
#line 30
    result = tanf(v);
#line 27
    (*_return) = result;
}

void sjf_fadeeffect_as_sji_effect(sjs_fadeeffect* _this, sji_effect* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_fadeeffect_effect_vtbl;
}

void sjf_fadeeffect_asinterface(sjs_fadeeffect* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_effect_typeId:  {
            sjf_fadeeffect_as_sji_effect(_this, (sji_effect*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_fadeeffect_copy(sjs_fadeeffect* _this, sjs_fadeeffect* _from) {
#line 3 "lib/sj-lib-ui/fadeEffect.sj"
    _this->alpha = _from->alpha;
#line 3
    _this->_rect._refCount = 1;
#line 3
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 3
    sjs_boxvertexbuffer* copyoption29 = (_from->_vertexbuffer._refCount != -1 ? &_from->_vertexbuffer : 0);
    if (copyoption29 != 0) {
        _this->_vertexbuffer._refCount = 1;
#line 3 "lib/sj-lib-ui/fadeEffect.sj"
        sjf_boxvertexbuffer_copy(&_this->_vertexbuffer, copyoption29);
    } else {
        _this->_vertexbuffer._refCount = -1;
    }

#line 3
    sjs_scenebuffer* copyoption30 = (_from->_scenebuffer._refCount != -1 ? &_from->_scenebuffer : 0);
    if (copyoption30 != 0) {
        _this->_scenebuffer._refCount = 1;
#line 3 "lib/sj-lib-ui/fadeEffect.sj"
        sjf_scenebuffer_copy(&_this->_scenebuffer, copyoption30);
    } else {
        _this->_scenebuffer._refCount = -1;
    }

#line 3
    _this->_innerscene._refCount = 1;
#line 3
    sjf_scene2d_copy(&_this->_innerscene, &_from->_innerscene);
}

void sjf_fadeeffect_destroy(sjs_fadeeffect* _this) {
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_this->_vertexbuffer); }
;
    if (_this->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_this->_scenebuffer); }
;
    if (_this->_innerscene._refCount == 1) { sjf_scene2d_destroy(&_this->_innerscene); }
;
}

void sjf_fadeeffect_getclasstype(sjs_object* _this, int* _return) {
    *_return = 311;
}

void sjf_fadeeffect_getrect(sjs_fadeeffect* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 26 "lib/sj-lib-ui/fadeEffect.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_fadeeffect_getrect_heap(sjs_fadeeffect* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 26 "lib/sj-lib-ui/fadeEffect.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_fadeeffect_heap(sjs_fadeeffect* _this) {
}

void sjf_fadeeffect_render(sjs_fadeeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_value10 = { -1 };
    sjs_scenebuffer sjt_value11 = { -1 };

    if ((_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0) == 0) {
        sjt_value10._refCount = 1;
        sjt_value10.rect._refCount = 1;
#line 48 "lib/sj-lib-ui/fadeEffect.sj"
        sjf_rect_copy(&sjt_value10.rect, &_parent->_rect);
#line 48
        sjf_boxvertexbuffer(&sjt_value10);
#line 48
        if (_parent->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer); }
;
#line 48
        sjs_boxvertexbuffer* copyoption31 = &sjt_value10;
        if (copyoption31 != 0) {
            _parent->_vertexbuffer._refCount = 1;
#line 48 "lib/sj-lib-ui/fadeEffect.sj"
            sjf_boxvertexbuffer_copy(&_parent->_vertexbuffer, copyoption31);
        } else {
            _parent->_vertexbuffer._refCount = -1;
        }
    }

    if ((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) == 0) {
        sjt_value11._refCount = 1;
        sjt_value11.size._refCount = 1;
#line 55 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_value11.size.w = (&_parent->_rect)->w;
#line 55
        sjt_value11.size.h = (&_parent->_rect)->h;
#line 55
        sjf_size(&sjt_value11.size);
#line 55
        sjt_value11.framebuffer._refCount = 1;
#line 55
        sjt_value11.framebuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
        sjt_value11.framebuffer.size.w = 0;
#line 3
        sjt_value11.framebuffer.size.h = 0;
#line 3
        sjf_size(&sjt_value11.framebuffer.size);
#line 3 "lib/sj-lib-ui/framebuffer.sj"
        sjt_value11.framebuffer.id = (uint32_t)0u;
#line 3
        sjf_framebuffer(&sjt_value11.framebuffer);
#line 3
        sjt_value11.texture._refCount = 1;
#line 3
        sjt_value11.texture.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
        sjt_value11.texture.size.w = 0;
#line 3
        sjt_value11.texture.size.h = 0;
#line 3
        sjf_size(&sjt_value11.texture.size);
#line 3 "lib/sj-lib-ui/texture.sj"
        sjt_value11.texture.id = (uint32_t)0u;
#line 3
        sjf_texture(&sjt_value11.texture);
#line 3
        sjt_value11.renderbuffer._refCount = 1;
#line 3
        sjt_value11.renderbuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
        sjt_value11.renderbuffer.size.w = 0;
#line 3
        sjt_value11.renderbuffer.size.h = 0;
#line 3
        sjf_size(&sjt_value11.renderbuffer.size);
#line 3 "lib/sj-lib-ui/renderbuffer.sj"
        sjt_value11.renderbuffer.id = (uint32_t)0u;
#line 3
        sjf_renderbuffer(&sjt_value11.renderbuffer);
#line 3
        sjf_scenebuffer(&sjt_value11);
#line 3
        if (_parent->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer); }
;
#line 55 "lib/sj-lib-ui/fadeEffect.sj"
        sjs_scenebuffer* copyoption32 = &sjt_value11;
        if (copyoption32 != 0) {
            _parent->_scenebuffer._refCount = 1;
#line 55 "lib/sj-lib-ui/fadeEffect.sj"
            sjf_scenebuffer_copy(&_parent->_scenebuffer, copyoption32);
        } else {
            _parent->_scenebuffer._refCount = -1;
        }
    }

    if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) != 0) && ((_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0) != 0)) {
        sjs_scenebuffer* ifValue29 = 0;
        sjs_boxvertexbuffer* ifValue30 = 0;
        sjs_string sjt_call152 = { -1 };
        sjs_string sjt_call153 = { -1 };
        sjs_string sjt_call154 = { -1 };
        sjs_string sjt_call155 = { -1 };
        sjs_string sjt_call156 = { -1 };
        sjs_framebuffer* sjt_functionParam590 = 0;
        sjs_size* sjt_functionParam591 = 0;
        sjs_scene2d* sjt_functionParam592 = 0;
        sjs_framebuffer* sjt_functionParam593 = 0;
        int32_t sjt_functionParam594;
        sjs_texture* sjt_functionParam595 = 0;
        sjs_shader* sjt_functionParam596 = 0;
        int32_t sjt_functionParam597;
        int32_t sjt_functionParam598;
        int32_t sjt_functionParam599;
        sjs_shader* sjt_functionParam600 = 0;
        sjs_string* sjt_functionParam601 = 0;
        int32_t sjt_functionParam602;
        int32_t sjt_functionParam603;
        sjs_shader* sjt_functionParam604 = 0;
        sjs_string* sjt_functionParam605 = 0;
        float sjt_functionParam606;
        int32_t sjt_functionParam607;
        sjs_shader* sjt_functionParam608 = 0;
        sjs_string* sjt_functionParam609 = 0;
        sjs_mat4* sjt_functionParam610 = 0;
        int32_t sjt_functionParam611;
        sjs_shader* sjt_functionParam612 = 0;
        sjs_string* sjt_functionParam613 = 0;
        sjs_mat4* sjt_functionParam614 = 0;
        int32_t sjt_functionParam615;
        sjs_shader* sjt_functionParam616 = 0;
        sjs_string* sjt_functionParam617 = 0;
        sjs_mat4* sjt_functionParam618 = 0;
        sjs_scene2d* sjt_functionParam619 = 0;
        sjs_scene2d* sjt_parent342 = 0;
        sjs_scene2d* sjt_parent343 = 0;
        sjs_scene2d* sjt_parent344 = 0;
        sjs_boxvertexbuffer* sjt_parent345 = 0;

#line 58 "lib/sj-lib-ui/fadeEffect.sj"
        ifValue29 = (_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0);
#line 58
        ifValue30 = (_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0);
#line 59
        sjt_functionParam590 = &ifValue29->framebuffer;
#line 59
        sjf_glpushframebuffer(sjt_functionParam590);
#line 27 "lib/sj-lib-ui/scene2d.sj"
        sjt_parent342 = &_parent->_innerscene;
#line 61 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam591 = &ifValue29->size;
#line 61
        sjf_scene2d_setsize(sjt_parent342, sjt_functionParam591);
#line 8 "lib/sj-lib-ui/scene2d.sj"
        sjt_parent343 = &_parent->_innerscene;
#line 8
        sjf_scene2d_start(sjt_parent343);
#line 64 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam592 = &_parent->_innerscene;
#line 64
        cb._cb(cb._parent, sjt_functionParam592);
#line 19 "lib/sj-lib-ui/scene2d.sj"
        sjt_parent344 = &_parent->_innerscene;
#line 19
        sjf_scene2d_end(sjt_parent344);
#line 68 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam593 = &ifValue29->framebuffer;
#line 68
        sjf_glpopframebuffer(sjt_functionParam593);
#line 70
        sjt_functionParam594 = g_gltexture_gl_texture_2d;
#line 70
        sjt_functionParam595 = &ifValue29->texture;
#line 70
        sjf_glbindtexture(sjt_functionParam594, sjt_functionParam595);
#line 71
        sjt_functionParam596 = &g_fadeshader;
#line 71
        sjf_gluseprogram(sjt_functionParam596);
#line 72
        sjt_functionParam597 = g_glblendfunctype_gl_src_alpha;
#line 72
        sjt_functionParam598 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 72
        sjf_glblendfunc(sjt_functionParam597, sjt_functionParam598);
#line 73
        sjt_functionParam600 = &g_fadeshader;
#line 73
        sjt_call152._refCount = 1;
#line 73
        sjt_call152.offset = 0;
#line 73
        sjt_call152.count = 7;
#line 73
        sjt_call152.data._refCount = 1;
#line 73
        sjt_call152.data.v = &sjg_string28;
#line 73
        sjf_array_char(&sjt_call152.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call152._isnullterminated = false;
#line 16
        sjf_string(&sjt_call152);
#line 73 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam601 = &sjt_call152;
#line 73
        sjf_glgetuniformlocation(sjt_functionParam600, sjt_functionParam601, &sjt_functionParam599);
#line 73
        sjt_functionParam602 = 0;
#line 73
        sjf_gluniformi32(sjt_functionParam599, sjt_functionParam602);
#line 74
        sjt_functionParam604 = &g_fadeshader;
#line 74
        sjt_call153._refCount = 1;
#line 74
        sjt_call153.offset = 0;
#line 74
        sjt_call153.count = 5;
#line 74
        sjt_call153.data._refCount = 1;
#line 74
        sjt_call153.data.v = &sjg_string36;
#line 74
        sjf_array_char(&sjt_call153.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call153._isnullterminated = false;
#line 16
        sjf_string(&sjt_call153);
#line 74 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam605 = &sjt_call153;
#line 74
        sjf_glgetuniformlocation(sjt_functionParam604, sjt_functionParam605, &sjt_functionParam603);
#line 74
        sjt_functionParam606 = _parent->alpha;
#line 74
        sjf_gluniformf32(sjt_functionParam603, sjt_functionParam606);
#line 75
        sjt_functionParam608 = &g_fadeshader;
#line 75
        sjt_call154._refCount = 1;
#line 75
        sjt_call154.offset = 0;
#line 75
        sjt_call154.count = 5;
#line 75
        sjt_call154.data._refCount = 1;
#line 75
        sjt_call154.data.v = &sjg_string29;
#line 75
        sjf_array_char(&sjt_call154.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call154._isnullterminated = false;
#line 16
        sjf_string(&sjt_call154);
#line 75 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam609 = &sjt_call154;
#line 75
        sjf_glgetuniformlocation(sjt_functionParam608, sjt_functionParam609, &sjt_functionParam607);
#line 75
        sjt_functionParam610 = &scene->model;
#line 75
        sjf_gluniformmat4(sjt_functionParam607, sjt_functionParam610);
#line 76
        sjt_functionParam612 = &g_fadeshader;
#line 76
        sjt_call155._refCount = 1;
#line 76
        sjt_call155.offset = 0;
#line 76
        sjt_call155.count = 4;
#line 76
        sjt_call155.data._refCount = 1;
#line 76
        sjt_call155.data.v = &sjg_string30;
#line 76
        sjf_array_char(&sjt_call155.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call155._isnullterminated = false;
#line 16
        sjf_string(&sjt_call155);
#line 76 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam613 = &sjt_call155;
#line 76
        sjf_glgetuniformlocation(sjt_functionParam612, sjt_functionParam613, &sjt_functionParam611);
#line 76
        sjt_functionParam614 = &scene->view;
#line 76
        sjf_gluniformmat4(sjt_functionParam611, sjt_functionParam614);
#line 77
        sjt_functionParam616 = &g_fadeshader;
#line 77
        sjt_call156._refCount = 1;
#line 77
        sjt_call156.offset = 0;
#line 77
        sjt_call156.count = 10;
#line 77
        sjt_call156.data._refCount = 1;
#line 77
        sjt_call156.data.v = &sjg_string19;
#line 77
        sjf_array_char(&sjt_call156.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call156._isnullterminated = false;
#line 16
        sjf_string(&sjt_call156);
#line 77 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam617 = &sjt_call156;
#line 77
        sjf_glgetuniformlocation(sjt_functionParam616, sjt_functionParam617, &sjt_functionParam615);
#line 77
        sjt_functionParam618 = &scene->projection;
#line 77
        sjf_gluniformmat4(sjt_functionParam615, sjt_functionParam618);
#line 7 "lib/sj-lib-ui/boxVertexBuffer.sj"
        sjt_parent345 = ifValue30;
#line 46 "lib/sj-lib-ui/fadeEffect.sj"
        sjt_functionParam619 = scene;
#line 46
        sjf_boxvertexbuffer_render(sjt_parent345, sjt_functionParam619);

        if (sjt_call152._refCount == 1) { sjf_string_destroy(&sjt_call152); }
;
        if (sjt_call153._refCount == 1) { sjf_string_destroy(&sjt_call153); }
;
        if (sjt_call154._refCount == 1) { sjf_string_destroy(&sjt_call154); }
;
        if (sjt_call155._refCount == 1) { sjf_string_destroy(&sjt_call155); }
;
        if (sjt_call156._refCount == 1) { sjf_string_destroy(&sjt_call156); }
;
    }

    if (sjt_value10._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_value10); }
;
    if (sjt_value11._refCount == 1) { sjf_scenebuffer_destroy(&sjt_value11); }
;
}

void sjf_fadeeffect_setrect(sjs_fadeeffect* _parent, sjs_rect* rect_, cb_rect_void cb) {
    bool result21;
    sjs_rect sjt_call151 = { -1 };
    bool sjt_capture79;
    sjs_rect* sjt_functionParam587 = 0;
    sjs_rect* sjt_functionParam589 = 0;
    sjs_rect* sjt_parent340 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent340 = &_parent->_rect;
#line 28 "lib/sj-lib-ui/fadeEffect.sj"
    sjt_functionParam587 = rect_;
#line 28
    sjf_rect_isequal(sjt_parent340, sjt_functionParam587, &sjt_capture79);
#line 29
    result21 = !sjt_capture79;
    if (result21) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 28 "lib/sj-lib-ui/fadeEffect.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
        if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) != 0)) {
            sjs_scenebuffer* ifValue27 = 0;
            bool result22;
            sjs_size sjt_call150 = { -1 };
            bool sjt_capture80;
            sjs_size* sjt_functionParam588 = 0;
            sjs_size* sjt_parent341 = 0;

#line 32 "lib/sj-lib-ui/fadeEffect.sj"
            ifValue27 = (_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0);
#line 27 "lib/sj-lib-ui/size.sj"
            sjt_parent341 = &ifValue27->size;
#line 27
            sjt_call150._refCount = 1;
#line 33 "lib/sj-lib-ui/fadeEffect.sj"
            sjt_call150.w = (&_parent->_rect)->w;
#line 33
            sjt_call150.h = (&_parent->_rect)->h;
#line 33
            sjf_size(&sjt_call150);
#line 33
            sjt_functionParam588 = &sjt_call150;
#line 33
            sjf_size_isequal(sjt_parent341, sjt_functionParam588, &sjt_capture80);
#line 33
            result22 = !sjt_capture80;
            if (result22) {
                if (_parent->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer); }
;
#line 34 "lib/sj-lib-ui/fadeEffect.sj"
                _parent->_scenebuffer._refCount = -1;
            }

            if (sjt_call150._refCount == 1) { sjf_size_destroy(&sjt_call150); }
;
        }

#line 28
        if (_parent->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer); }
;
#line 38
        _parent->_vertexbuffer._refCount = -1;
    }

#line 29
    sjt_call151._refCount = 1;
#line 41
    sjt_call151.x = 0;
#line 41
    sjt_call151.y = 0;
#line 41
    sjt_call151.w = (&_parent->_rect)->w;
#line 41
    sjt_call151.h = (&_parent->_rect)->h;
#line 41
    sjf_rect(&sjt_call151);
#line 41
    sjt_functionParam589 = &sjt_call151;
#line 41
    cb._cb(cb._parent, sjt_functionParam589);

    if (sjt_call151._refCount == 1) { sjf_rect_destroy(&sjt_call151); }
;
}

void sjf_filllayout(sjs_filllayout* _this) {
}

void sjf_filllayout_as_sji_element(sjs_filllayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_filllayout_element_vtbl;
}

void sjf_filllayout_asinterface(sjs_filllayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_filllayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_filllayout_copy(sjs_filllayout* _this, sjs_filllayout* _from) {
    _this->children._refCount = 1;
#line 1 "lib/sj-lib-ui/fillLayout.sj"
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 1
    _this->margin._refCount = 1;
#line 1
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 1
    _this->effect = _from->effect;
    if (_this->effect._parent != 0) {
        _this->effect._parent->_refCount++;
    }

#line 1
    _this->_rect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_filllayout_destroy(sjs_filllayout* _this) {
    if (_this->effect._parent != 0) {
        _this->effect._parent->_refCount--;
        if (_this->effect._parent->_refCount <= 0) {
            _this->effect._vtbl->destroy(_this->effect._parent);
            free(_this->effect._parent);
        }
    }

    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_filllayout_firemouseevent(sjs_filllayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam60 = 0;
    sjs_mouseevent* sjt_parent63 = 0;

#line 55 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent63 = mouseevent;
#line 56
    sjt_functionParam60 = &_parent->children;
#line 56
    sjf_mouseevent_firechildren(sjt_parent63, sjt_functionParam60, _return);
}

void sjf_filllayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 114;
}

void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 17 "lib/sj-lib-ui/fillLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 17 "lib/sj-lib-ui/fillLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    sjs_size innersize = { -1 };
    sjs_size size = { -1 };
    int32_t sjt_forEnd8;
    int32_t sjt_forStart8;
    sjs_margin* sjt_functionParam47 = 0;
    sjs_margin* sjt_functionParam50 = 0;
    sjs_size* sjt_parent42 = 0;
    sjs_array_heap_iface_element* sjt_parent43 = 0;
    sjs_size* sjt_parent47 = 0;

    size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    size.w = 0;
#line 3
    size.h = 0;
#line 3
    sjf_size(&size);
#line 7 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent42 = maxsize;
#line 9
    sjt_functionParam47 = &_parent->margin;
#line 9
    sjf_size_subtractmargin(sjt_parent42, sjt_functionParam47, &innersize);
#line 10
    sjt_forStart8 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent43 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent43, &sjt_forEnd8);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart8;
    while (i < sjt_forEnd8) {
        sji_element child = { 0 };
        sjs_size sjt_call6 = { -1 };
        sjs_size sjt_funcold5 = { -1 };
        int32_t sjt_functionParam48;
        sjs_size* sjt_functionParam49 = 0;
        sjs_size* sjt_interfaceParam4 = 0;
        sjs_array_heap_iface_element* sjt_parent44 = 0;
        sjs_size* sjt_parent45 = 0;
        sji_element sjt_parent46 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent44 = &_parent->children;
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam48 = i;
#line 10
        sjf_array_heap_iface_element_getat_heap(sjt_parent44, sjt_functionParam48, &child);
#line 12 "lib/sj-lib-ui/size.sj"
        sjt_parent45 = &size;
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent46 = child;
#line 12 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam4 = &innersize;
#line 12
        sjt_parent46._vtbl->getsize(sjt_parent46._parent, sjt_interfaceParam4, &sjt_call6);
#line 12
        sjt_functionParam49 = &sjt_call6;
#line 12
        sjf_size_max(sjt_parent45, sjt_functionParam49, &sjt_funcold5);
#line 12
        if (size._refCount == 1) { sjf_size_destroy(&size); }
;
#line 12 "lib/sj-lib-ui/size.sj"
        sjf_size_copy(&size, &sjt_funcold5);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (sjt_call6._refCount == 1) { sjf_size_destroy(&sjt_call6); }
;
        if (sjt_funcold5._refCount == 1) { sjf_size_destroy(&sjt_funcold5); }
;
    }

#line 19 "lib/sj-lib-ui/size.sj"
    sjt_parent47 = &size;
#line 14 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam50 = &_parent->margin;
#line 14
    sjf_size_addmargin(sjt_parent47, sjt_functionParam50, _return);

    if (innersize._refCount == 1) { sjf_size_destroy(&innersize); }
;
    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
}

void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    sjs_size innersize = { -1 };
    sjs_size size = { -1 };
    int32_t sjt_forEnd9;
    int32_t sjt_forStart9;
    sjs_margin* sjt_functionParam51 = 0;
    sjs_margin* sjt_functionParam54 = 0;
    sjs_size* sjt_parent48 = 0;
    sjs_array_heap_iface_element* sjt_parent49 = 0;
    sjs_size* sjt_parent53 = 0;

    size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    size.w = 0;
#line 3
    size.h = 0;
#line 3
    sjf_size(&size);
#line 7 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent48 = maxsize;
#line 9
    sjt_functionParam51 = &_parent->margin;
#line 9
    sjf_size_subtractmargin(sjt_parent48, sjt_functionParam51, &innersize);
#line 10
    sjt_forStart9 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent49 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent49, &sjt_forEnd9);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sji_element child = { 0 };
        sjs_size sjt_call7 = { -1 };
        sjs_size sjt_funcold6 = { -1 };
        int32_t sjt_functionParam52;
        sjs_size* sjt_functionParam53 = 0;
        sjs_size* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent50 = 0;
        sjs_size* sjt_parent51 = 0;
        sji_element sjt_parent52 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent50 = &_parent->children;
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam52 = i;
#line 10
        sjf_array_heap_iface_element_getat_heap(sjt_parent50, sjt_functionParam52, &child);
#line 12 "lib/sj-lib-ui/size.sj"
        sjt_parent51 = &size;
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent52 = child;
#line 12 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam5 = &innersize;
#line 12
        sjt_parent52._vtbl->getsize(sjt_parent52._parent, sjt_interfaceParam5, &sjt_call7);
#line 12
        sjt_functionParam53 = &sjt_call7;
#line 12
        sjf_size_max(sjt_parent51, sjt_functionParam53, &sjt_funcold6);
#line 12
        if (size._refCount == 1) { sjf_size_destroy(&size); }
;
#line 12 "lib/sj-lib-ui/size.sj"
        sjf_size_copy(&size, &sjt_funcold6);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (sjt_call7._refCount == 1) { sjf_size_destroy(&sjt_call7); }
;
        if (sjt_funcold6._refCount == 1) { sjf_size_destroy(&sjt_funcold6); }
;
    }

#line 19 "lib/sj-lib-ui/size.sj"
    sjt_parent53 = &size;
#line 14 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam54 = &_parent->margin;
#line 14
    sjf_size_addmargin_heap(sjt_parent53, sjt_functionParam54, _return);

    if (innersize._refCount == 1) { sjf_size_destroy(&innersize); }
;
    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
}

void sjf_filllayout_heap(sjs_filllayout* _this) {
}

void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene) {
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue5 = { 0 };
        cb_scene2d_void sjt_interfaceParam10;
        sjs_scene2d* sjt_interfaceParam9 = 0;
        sji_effect sjt_parent59 = { 0 };

#line 41 "lib/sj-lib-ui/fillLayout.sj"
        ifValue5 = _parent->effect;
        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount++;
        }

#line 4 "lib/sj-lib-ui/effect.sj"
        sjt_parent59 = ifValue5;
#line 40 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam9 = scene;
#line 42
        sjt_interfaceParam10._parent = (sjs_object*)_parent;
#line 42
        sjt_interfaceParam10._cb = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_renderinner;
#line 42
        sjt_parent59._vtbl->render(sjt_parent59._parent, sjt_interfaceParam9, sjt_interfaceParam10);

        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount--;
            if (ifValue5._parent->_refCount <= 0) {
                ifValue5._vtbl->destroy(ifValue5._parent);
                free(ifValue5._parent);
            }
        }
    } else {
        sjs_scene2d* sjt_functionParam59 = 0;

#line 40 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam59 = scene;
#line 40
        sjf_filllayout_renderinner(_parent, sjt_functionParam59);
    }
}

void sjf_filllayout_renderinner(sjs_filllayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd11;
    int32_t sjt_forStart11;
    sjs_array_heap_iface_element* sjt_parent60 = 0;

#line 49 "lib/sj-lib-ui/fillLayout.sj"
    sjt_forStart11 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent60 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent60, &sjt_forEnd11);
#line 49 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        sji_element child = { 0 };
        int32_t sjt_functionParam58;
        sjs_scene2d* sjt_interfaceParam11 = 0;
        sjs_array_heap_iface_element* sjt_parent61 = 0;
        sji_element sjt_parent62 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent61 = &_parent->children;
#line 49 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam58 = i;
#line 49
        sjf_array_heap_iface_element_getat_heap(sjt_parent61, sjt_functionParam58, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent62 = child;
#line 48 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam11 = scene;
#line 51
        sjt_parent62._vtbl->render(sjt_parent62._parent, sjt_interfaceParam11);
#line 49
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }
}

void sjf_filllayout_setrect(sjs_filllayout* _parent, sjs_rect* rect_) {
    sjs_rect innerrect = { -1 };
    sjs_margin* sjt_functionParam55 = 0;
    sjs_rect* sjt_parent54 = 0;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 19 "lib/sj-lib-ui/fillLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 7 "lib/sj-lib-ui/rect.sj"
    sjt_parent54 = &_parent->_rect;
#line 21 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam55 = &_parent->margin;
#line 21
    sjf_rect_subtractmargin(sjt_parent54, sjt_functionParam55, &innerrect);
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue3 = { 0 };
        sjs_rect* sjt_interfaceParam6 = 0;
        cb_rect_void sjt_interfaceParam7;
        sji_effect sjt_parent55 = { 0 };

#line 23 "lib/sj-lib-ui/fillLayout.sj"
        ifValue3 = _parent->effect;
        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount++;
        }

#line 3 "lib/sj-lib-ui/effect.sj"
        sjt_parent55 = ifValue3;
#line 24 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam6 = &innerrect;
#line 24
        sjt_interfaceParam7._parent = (sjs_object*)_parent;
#line 24
        sjt_interfaceParam7._cb = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrectinner;
#line 24
        sjt_parent55._vtbl->setrect(sjt_parent55._parent, sjt_interfaceParam6, sjt_interfaceParam7);

        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount--;
            if (ifValue3._parent->_refCount <= 0) {
                ifValue3._vtbl->destroy(ifValue3._parent);
                free(ifValue3._parent);
            }
        }
    } else {
        sjs_rect* sjt_functionParam57 = 0;

#line 26 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam57 = &innerrect;
#line 26
        sjf_filllayout_setrectinner(_parent, sjt_functionParam57);
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
}

void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect) {
    int32_t i;
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;
    sjs_array_heap_iface_element* sjt_parent56 = 0;

#line 33 "lib/sj-lib-ui/fillLayout.sj"
    sjt_forStart10 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent56 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent56, &sjt_forEnd10);
#line 33 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart10;
    while (i < sjt_forEnd10) {
        sji_element child = { 0 };
        int32_t sjt_functionParam56;
        sjs_rect* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent57 = 0;
        sji_element sjt_parent58 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent57 = &_parent->children;
#line 33 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam56 = i;
#line 33
        sjf_array_heap_iface_element_getat_heap(sjt_parent57, sjt_functionParam56, &child);
#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent58 = child;
#line 32 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam8 = innerrect;
#line 35
        sjt_parent58._vtbl->setrect(sjt_parent58._parent, sjt_interfaceParam8);
#line 33
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }
}

void sjf_font(sjs_font* _this) {
#line 65 "lib/sj-lib-ui/font.sj"
    _this->atlas = texture_atlas_new( 512, 512, 3 );
#line 66
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, string_char(&_this->src));
#line 67
    if (_this->font == 0) {
#line 68
        printf("texture_font_new_from_file Error\n");
#line 69
    }   
#line 71
    glGenTextures( 1, &_this->atlas->id );
#line 72
    glBindTexture( GL_TEXTURE_2D, _this->atlas->id );
#line 73
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#line 74
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
#line 75
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#line 76
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
#line 77
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
#line 78
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
}

void sjf_font_copy(sjs_font* _this, sjs_font* _from) {
    _this->src._refCount = 1;
#line 33 "lib/sj-lib-ui/font.sj"
    sjf_string_copy(&_this->src, &_from->src);
#line 33
    _this->size = _from->size;
#line 83
    _this->atlas = _from->atlas;
#line 84
    ptr_retain(_this->atlas);
#line 86
    _this->font = _from->font;
#line 87
    ptr_retain(_this->font);
}

void sjf_font_destroy(sjs_font* _this) {
#line 91 "lib/sj-lib-ui/font.sj"
    if (ptr_release(_this->atlas)) {
#line 92
        texture_atlas_delete(_this->atlas);
#line 93
    }
#line 95
    if (ptr_release(_this->font)) {
#line 96
        texture_font_delete(_this->font);
#line 97
    }
#line 97
    if (_this->src._refCount == 1) { sjf_string_destroy(&_this->src); }
;
}

void sjf_font_gettextsize(sjs_font* _parent, sjs_string* str, sjs_size* _return) {
    int32_t h;
    int32_t w;

#line 54 "lib/sj-lib-ui/font.sj"
    w = 0;
#line 55
    h = 0;
#line 57
    vec2 size = get_text_size(_parent->font, string_char(str));
#line 58
    w = (int)size.x;
#line 59
    h = (int)size.y;
#line 59
    _return->_refCount = 1;
#line 61
    _return->w = w;
#line 61
    _return->h = h;
#line 61
    sjf_size(_return);
}

void sjf_font_gettextsize_heap(sjs_font* _parent, sjs_string* str, sjs_size** _return) {
    int32_t h;
    int32_t w;

#line 54 "lib/sj-lib-ui/font.sj"
    w = 0;
#line 55
    h = 0;
#line 57
    vec2 size = get_text_size(_parent->font, string_char(str));
#line 58
    w = (int)size.x;
#line 59
    h = (int)size.y;
#line 59
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
#line 59
    (*_return)->_refCount = 1;
#line 61
    (*_return)->w = w;
#line 61
    (*_return)->h = h;
#line 61
    sjf_size_heap((*_return));
}

void sjf_font_heap(sjs_font* _this) {
#line 65 "lib/sj-lib-ui/font.sj"
    _this->atlas = texture_atlas_new( 512, 512, 3 );
#line 66
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, string_char(&_this->src));
#line 67
    if (_this->font == 0) {
#line 68
        printf("texture_font_new_from_file Error\n");
#line 69
    }   
#line 71
    glGenTextures( 1, &_this->atlas->id );
#line 72
    glBindTexture( GL_TEXTURE_2D, _this->atlas->id );
#line 73
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#line 74
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
#line 75
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
#line 76
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
#line 77
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
#line 78
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
}

void sjf_font_load_heap(sjs_string* src, float size, sjs_font** _return) {
    sjs_font* h = 0;
    sjs_fontkey k = { -1 };
    sjs_fontkey* sjt_functionParam404 = 0;
    sjs_hash_fontkey_weak_font* sjt_parent304 = 0;
    sjs_font* w = 0;

    k._refCount = 1;
    k.src._refCount = 1;
#line 3 "lib/sj-lib-ui/font.sj"
    sjf_string_copy(&k.src, src);
#line 3
    k.size = size;
#line 3
    sjf_fontkey(&k);
#line 21 "lib/sj-lib-common/hash.sj"
    sjt_parent304 = &g_fonthash;
#line 7 "lib/sj-lib-ui/font.sj"
    sjt_functionParam404 = &k;
#line 7
    sjf_hash_fontkey_weak_font_getat(sjt_parent304, sjt_functionParam404, &w);
#line 8
    h = w;
    if (h != 0) {
        h->_refCount++;
    }

    if ((h != 0)) {
        sjs_font* ifValue11 = 0;

#line 9 "lib/sj-lib-ui/font.sj"
        ifValue11 = h;
        if (ifValue11 != 0) {
            ifValue11->_refCount++;
        }

#line 3
        (*_return) = ifValue11;
#line 3
        (*_return)->_refCount++;

        ifValue11->_refCount--;
        if (ifValue11->_refCount <= 0) {
            weakptr_release(ifValue11);
            sjf_font_destroy(ifValue11);
            free(ifValue11);
        }
    } else {
        sjs_font* result = 0;
        sjs_fontkey* sjt_functionParam405 = 0;
        sjs_font* sjt_functionParam406 = 0;
        sjs_hash_fontkey_weak_font* sjt_parent305 = 0;

        result = (sjs_font*)malloc(sizeof(sjs_font));
        result->_refCount = 1;
        result->src._refCount = 1;
#line 3 "lib/sj-lib-ui/font.sj"
        sjf_string_copy(&result->src, src);
#line 3
        result->size = size;
#line 3
        sjf_font_heap(result);
#line 38 "lib/sj-lib-common/hash.sj"
        sjt_parent305 = &g_fonthash;
#line 15 "lib/sj-lib-ui/font.sj"
        sjt_functionParam405 = &k;
#line 15
        sjt_functionParam406 = result;
#line 15
        delete_cb weakptrcb26 = { &sjt_functionParam406, weakptr_clear };
#line 15
        if (sjt_functionParam406 != 0) { weakptr_cb_add(sjt_functionParam406, weakptrcb26); }
#line 15
        sjf_hash_fontkey_weak_font_setat(sjt_parent305, sjt_functionParam405, sjt_functionParam406);
#line 3
        (*_return) = result;
#line 3
        (*_return)->_refCount++;

        result->_refCount--;
        if (result->_refCount <= 0) {
            weakptr_release(result);
            sjf_font_destroy(result);
            free(result);
        }
        delete_cb weakptrcb27 = { &sjt_functionParam406, weakptr_clear };
        if (sjt_functionParam406 != 0) { weakptr_cb_remove(sjt_functionParam406, weakptrcb27); }
    }

    if (h != 0) {
        h->_refCount--;
        if (h->_refCount <= 0) {
            weakptr_release(h);
            sjf_font_destroy(h);
            free(h);
        }
    }
    delete_cb weakptrcb28 = { &w, weakptr_clear };
    if (w != 0) { weakptr_cb_remove(w, weakptrcb28); }
    if (k._refCount == 1) { sjf_fontkey_destroy(&k); }
;
}

void sjf_fontkey(sjs_fontkey* _this) {
}

void sjf_fontkey_copy(sjs_fontkey* _this, sjs_fontkey* _from) {
    _this->src._refCount = 1;
#line 20 "lib/sj-lib-ui/font.sj"
    sjf_string_copy(&_this->src, &_from->src);
#line 20
    _this->size = _from->size;
}

void sjf_fontkey_destroy(sjs_fontkey* _this) {
    if (_this->src._refCount == 1) { sjf_string_destroy(&_this->src); }
;
}

void sjf_fontkey_hash(sjs_fontkey* _parent, uint32_t* _return) {
    uint32_t sjt_capture3;
    uint32_t sjt_capture4;
    float sjt_functionParam12;
    sjs_string* sjt_parent4 = 0;

#line 146 "lib/sj-lib-common/string.sj"
    sjt_parent4 = &_parent->src;
#line 146
    sjf_string_hash(sjt_parent4, &sjt_capture3);
#line 25 "lib/sj-lib-ui/font.sj"
    sjt_functionParam12 = _parent->size;
#line 25
    sjf_f32_hash(sjt_functionParam12, &sjt_capture4);
#line 25
    (*_return) = sjt_capture3 ^ sjt_capture4;
}

void sjf_fontkey_heap(sjs_fontkey* _this) {
}

void sjf_fontkey_isequal(sjs_fontkey* _parent, sjs_fontkey* x, bool* _return) {
    bool sjt_capture5;
    sjs_string* sjt_functionParam13 = 0;
    sjs_string* sjt_parent5 = 0;

#line 71 "lib/sj-lib-common/string.sj"
    sjt_parent5 = &_parent->src;
#line 29 "lib/sj-lib-ui/font.sj"
    sjt_functionParam13 = &x->src;
#line 29
    sjf_string_isequal(sjt_parent5, sjt_functionParam13, &sjt_capture5);
    if (sjt_capture5) {
#line 29 "lib/sj-lib-ui/font.sj"
        (*_return) = (_parent->size == x->size);
    } else {
#line 29 "lib/sj-lib-ui/font.sj"
        (*_return) = false;
    }
}

void sjf_framebuffer(sjs_framebuffer* _this) {
}

void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from) {
    _this->size._refCount = 1;
#line 1 "lib/sj-lib-ui/framebuffer.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 8
    _this->id = _from->id;
#line 9
    glid_retain(_this->id);
}

void sjf_framebuffer_destroy(sjs_framebuffer* _this) {
#line 13 "lib/sj-lib-ui/framebuffer.sj"
    if (glid_release(_this->id)) {
#line 14
        glDeleteFramebuffers(1, &_this->id);
#line 15
    }
#line 15
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
}

void sjf_framebuffer_heap(sjs_framebuffer* _this) {
}

void sjf_glbindrenderbuffer(sjs_renderbuffer* renderbuffer) {
#line 272 "lib/sj-lib-ui/gl.sj"
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glbindtexture(int32_t t, sjs_texture* texture) {
#line 173 "lib/sj-lib-ui/gl.sj"
    glBindTexture(t, texture->id);
}

void sjf_glblendfunc(int32_t sfactor, int32_t dfactor) {
#line 285 "lib/sj-lib-ui/gl.sj"
    glBlendFunc(sfactor, dfactor);
}

void sjf_glcheckframebufferstatus(int32_t* _return) {
    int32_t status;

#line 263 "lib/sj-lib-ui/gl.sj"
    status = g_glframebufferstatus_gl_framebuffer_unsupported;
#line 265
    status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
#line 262
    (*_return) = status;
}

void sjf_glclearcolor(sjs_color* color) {
#line 279 "lib/sj-lib-ui/gl.sj"
    glClearColor(color->r, color->g, color->b, color->a);
}

void sjf_gldisable(int32_t feature) {
#line 119 "lib/sj-lib-ui/gl.sj"
    glDisable(feature);
}

void sjf_glenable(int32_t feature) {
#line 113 "lib/sj-lib-ui/gl.sj"
    glEnable(feature);
}

void sjf_glframebufferrenderbuffer(int32_t attachment, sjs_renderbuffer* renderbuffer) {
#line 258 "lib/sj-lib-ui/gl.sj"
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glframebuffertexture2d(int32_t attachment, int32_t target, sjs_texture* texture, int32_t level) {
#line 238 "lib/sj-lib-ui/gl.sj"
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, target, texture->id, level);
}

void sjf_glgenframebuffer(sjs_size* size, sjs_framebuffer* _return) {
    uint32_t id;

#line 209 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 211
    glGenFramebuffers(1, &id);
#line 211
    _return->_refCount = 1;
#line 211
    _return->size._refCount = 1;
#line 208
    sjf_size_copy(&_return->size, size);
#line 213
    _return->id = id;
#line 213
    sjf_framebuffer(_return);
}

void sjf_glgenframebuffer_heap(sjs_size* size, sjs_framebuffer** _return) {
    uint32_t id;

#line 209 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 211
    glGenFramebuffers(1, &id);
#line 211
    (*_return) = (sjs_framebuffer*)malloc(sizeof(sjs_framebuffer));
#line 211
    (*_return)->_refCount = 1;
#line 211
    (*_return)->size._refCount = 1;
#line 208
    sjf_size_copy(&(*_return)->size, size);
#line 213
    (*_return)->id = id;
#line 213
    sjf_framebuffer_heap((*_return));
}

void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return) {
    uint32_t id;

#line 243 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 245
    glGenRenderbuffers(1, &id); 
#line 245
    _return->_refCount = 1;
#line 245
    _return->size._refCount = 1;
#line 242
    sjf_size_copy(&_return->size, size);
#line 247
    _return->id = id;
#line 247
    sjf_renderbuffer(_return);
}

void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return) {
    uint32_t id;

#line 243 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 245
    glGenRenderbuffers(1, &id); 
#line 245
    (*_return) = (sjs_renderbuffer*)malloc(sizeof(sjs_renderbuffer));
#line 245
    (*_return)->_refCount = 1;
#line 245
    (*_return)->size._refCount = 1;
#line 242
    sjf_size_copy(&(*_return)->size, size);
#line 247
    (*_return)->id = id;
#line 247
    sjf_renderbuffer_heap((*_return));
}

void sjf_glgentexture(sjs_size* size, sjs_texture* _return) {
    uint32_t id;

#line 217 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 219
    glGenTextures(1, &id);
#line 219
    _return->_refCount = 1;
#line 219
    _return->size._refCount = 1;
#line 216
    sjf_size_copy(&_return->size, size);
#line 221
    _return->id = id;
#line 221
    sjf_texture(_return);
}

void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return) {
    uint32_t id;

#line 217 "lib/sj-lib-ui/gl.sj"
    id = (uint32_t)0u;
#line 219
    glGenTextures(1, &id);
#line 219
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
#line 219
    (*_return)->_refCount = 1;
#line 219
    (*_return)->size._refCount = 1;
#line 216
    sjf_size_copy(&(*_return)->size, size);
#line 221
    (*_return)->id = id;
#line 221
    sjf_texture_heap((*_return));
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
#line 179 "lib/sj-lib-ui/gl.sj"
    int result = glGetUniformLocation(shader->id, string_char(name));
#line 180
    #line 178 "lib/sj-lib-ui/gl.sj"
(*_return) = result;
return;;
}

void sjf_glpopframebuffer(sjs_framebuffer* framebuffer) {
    uint32_t id;
    sjs_string sjt_call131 = { -1 };
    int32_t sjt_capture70;
    uint32_t sjt_capture71;
    int32_t sjt_capture72;
    int32_t sjt_capture73;
    int32_t sjt_functionParam456;
    int32_t sjt_functionParam458;
    sjs_list_u32* sjt_parent318 = 0;
    sjs_list_u32* sjt_parent320 = 0;
    sjs_list_u32* sjt_parent321 = 0;
    sjs_list_u32* sjt_parent322 = 0;
    sjs_list_u32* sjt_parent323 = 0;

#line 8 "lib/sj-lib-common/list.sj"
    sjt_parent318 = &g_glframebuffers;
#line 4
    sjt_parent320 = &g_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent320, &sjt_capture70);
#line 155 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam456 = sjt_capture70 - 1;
#line 155
    sjf_list_u32_getat(sjt_parent318, sjt_functionParam456, &sjt_capture71);
    if (sjt_capture71 != framebuffer->id) {
        sjs_string* sjt_functionParam457 = 0;

        sjt_call131._refCount = 1;
#line 156 "lib/sj-lib-ui/gl.sj"
        sjt_call131.offset = 0;
#line 156
        sjt_call131.count = 33;
#line 156
        sjt_call131.data._refCount = 1;
#line 156
        sjt_call131.data.v = &sjg_string33;
#line 156
        sjf_array_char(&sjt_call131.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call131._isnullterminated = false;
#line 16
        sjf_string(&sjt_call131);
#line 156 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam457 = &sjt_call131;
#line 156
        sjf_halt(sjt_functionParam457);
    }

#line 53 "lib/sj-lib-common/list.sj"
    sjt_parent321 = &g_glframebuffers;
#line 4
    sjt_parent322 = &g_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent322, &sjt_capture72);
#line 158 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam458 = sjt_capture72 - 1;
#line 158
    sjf_list_u32_removeat(sjt_parent321, sjt_functionParam458);
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent323 = &g_glframebuffers;
#line 4
    sjf_list_u32_getcount(sjt_parent323, &sjt_capture73);
    if (sjt_capture73 > 0) {
        int32_t sjt_capture74;
        int32_t sjt_functionParam459;
        sjs_list_u32* sjt_parent324 = 0;
        sjs_list_u32* sjt_parent325 = 0;

#line 8 "lib/sj-lib-common/list.sj"
        sjt_parent324 = &g_glframebuffers;
#line 4
        sjt_parent325 = &g_glframebuffers;
#line 4
        sjf_list_u32_getcount(sjt_parent325, &sjt_capture74);
#line 159 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam459 = sjt_capture74 - 1;
#line 159
        sjf_list_u32_getat(sjt_parent324, sjt_functionParam459, &id);
    } else {
#line 159 "lib/sj-lib-ui/gl.sj"
        id = (uint32_t)0u;
    }

#line 161 "lib/sj-lib-ui/gl.sj"
    glBindFramebuffer(GL_FRAMEBUFFER, id);

    if (sjt_call131._refCount == 1) { sjf_string_destroy(&sjt_call131); }
;
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect newrect = { -1 };
    sjs_rect oldrect = { -1 };
    bool result6;
    sjs_rect sjt_call13 = { -1 };
    sjs_string sjt_call14 = { -1 };
    int32_t sjt_capture37;
    bool sjt_capture38;
    int32_t sjt_capture39;
    int32_t sjt_capture40;
    int32_t sjt_functionParam138;
    sjs_rect* sjt_functionParam139 = 0;
    int32_t sjt_functionParam141;
    sjs_rect* sjt_parent111 = 0;
    sjs_list_rect* sjt_parent114 = 0;
    sjs_list_rect* sjt_parent116 = 0;
    sjs_list_rect* sjt_parent117 = 0;
    sjs_list_rect* sjt_parent118 = 0;
    sjs_list_rect* sjt_parent119 = 0;

    oldrect._refCount = 1;
#line 134 "lib/sj-lib-ui/gl.sj"
    oldrect.x = rect->x;
#line 134
    oldrect.y = scenerect->h - (rect->y + rect->h);
#line 134
    oldrect.w = rect->w;
#line 134
    oldrect.h = rect->h;
#line 134
    sjf_rect(&oldrect);
#line 8 "lib/sj-lib-common/list.sj"
    sjt_parent114 = &g_glviewports;
#line 4
    sjt_parent116 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent116, &sjt_capture37);
#line 135 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam138 = sjt_capture37 - 1;
#line 135
    sjf_list_rect_getat(sjt_parent114, sjt_functionParam138, &sjt_call13);
#line 135
    sjt_parent111 = &sjt_call13;
#line 135
    sjt_functionParam139 = &oldrect;
#line 135
    sjf_rect_isequal(sjt_parent111, sjt_functionParam139, &sjt_capture38);
#line 135
    result6 = !sjt_capture38;
    if (result6) {
        sjs_string* sjt_functionParam140 = 0;

        sjt_call14._refCount = 1;
#line 136 "lib/sj-lib-ui/gl.sj"
        sjt_call14.offset = 0;
#line 136
        sjt_call14.count = 30;
#line 136
        sjt_call14.data._refCount = 1;
#line 136
        sjt_call14.data.v = &sjg_string16;
#line 136
        sjf_array_char(&sjt_call14.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call14._isnullterminated = false;
#line 16
        sjf_string(&sjt_call14);
#line 136 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam140 = &sjt_call14;
#line 136
        sjf_halt(sjt_functionParam140);
    }

#line 53 "lib/sj-lib-common/list.sj"
    sjt_parent117 = &g_glviewports;
#line 4
    sjt_parent118 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent118, &sjt_capture39);
#line 138 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam141 = sjt_capture39 - 1;
#line 138
    sjf_list_rect_removeat(sjt_parent117, sjt_functionParam141);
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent119 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent119, &sjt_capture40);
    if (sjt_capture40 > 0) {
        int32_t sjt_capture41;
        int32_t sjt_functionParam142;
        sjs_list_rect* sjt_parent120 = 0;
        sjs_list_rect* sjt_parent121 = 0;

#line 8 "lib/sj-lib-common/list.sj"
        sjt_parent120 = &g_glviewports;
#line 4
        sjt_parent121 = &g_glviewports;
#line 4
        sjf_list_rect_getcount(sjt_parent121, &sjt_capture41);
#line 139 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam142 = sjt_capture41 - 1;
#line 139
        sjf_list_rect_getat(sjt_parent120, sjt_functionParam142, &newrect);
    } else {
        newrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
        newrect.x = 0;
#line 3
        newrect.y = 0;
#line 4
        newrect.w = 0;
#line 5
        newrect.h = 0;
#line 5
        sjf_rect(&newrect);
    }

#line 141 "lib/sj-lib-ui/gl.sj"
    glViewport(newrect.x, newrect.y, newrect.w, newrect.h);

    if (newrect._refCount == 1) { sjf_rect_destroy(&newrect); }
;
    if (oldrect._refCount == 1) { sjf_rect_destroy(&oldrect); }
;
    if (sjt_call13._refCount == 1) { sjf_rect_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
}

void sjf_glpushframebuffer(sjs_framebuffer* framebuffer) {
    uint32_t sjt_functionParam423;
    sjs_list_u32* sjt_parent316 = 0;

#line 44 "lib/sj-lib-common/list.sj"
    sjt_parent316 = &g_glframebuffers;
#line 148 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam423 = framebuffer->id;
#line 148
    sjf_list_u32_add(sjt_parent316, sjt_functionParam423);
#line 150
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect newrect = { -1 };
    sjs_rect* sjt_functionParam104 = 0;
    sjs_list_rect* sjt_parent98 = 0;

    newrect._refCount = 1;
#line 126 "lib/sj-lib-ui/gl.sj"
    newrect.x = rect->x;
#line 126
    newrect.y = scenerect->h - (rect->y + rect->h);
#line 126
    newrect.w = rect->w;
#line 126
    newrect.h = rect->h;
#line 126
    sjf_rect(&newrect);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_parent98 = &g_glviewports;
#line 127 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam104 = &newrect;
#line 127
    sjf_list_rect_add(sjt_parent98, sjt_functionParam104);
#line 129
    glViewport(newrect.x, newrect.y, newrect.w, newrect.h);

    if (newrect._refCount == 1) { sjf_rect_destroy(&newrect); }
;
}

void sjf_glrenderbufferstorage(int32_t format, sjs_size* size) {
#line 252 "lib/sj-lib-ui/gl.sj"
    glRenderbufferStorage(GL_RENDERBUFFER, format, size->w, size->h);
}

void sjf_glteximage2d(int32_t t, int32_t level, int32_t format, sjs_size* size, int32_t datatype, void* data) {
#line 232 "lib/sj-lib-ui/gl.sj"
    glTexImage2D(t, level, format, size->w, size->h, 0, format, datatype, data);
}

void sjf_gltexparameteri(int32_t t, int32_t attribute, int32_t val) {
#line 226 "lib/sj-lib-ui/gl.sj"
    glTexParameteri(t, attribute, val);
}

void sjf_gluniformf32(int32_t loc, float v) {
#line 204 "lib/sj-lib-ui/gl.sj"
    glUniform1f(loc, v);
}

void sjf_gluniformi32(int32_t loc, int32_t v) {
#line 198 "lib/sj-lib-ui/gl.sj"
    glUniform1i(loc, v);
}

void sjf_gluniformmat4(int32_t loc, sjs_mat4* m) {
#line 186 "lib/sj-lib-ui/gl.sj"
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
}

void sjf_gluniformvec3(int32_t loc, sjs_vec3* v) {
#line 192 "lib/sj-lib-ui/gl.sj"
    glUniform3fv(loc, 1, (GLfloat*)&v->x);
}

void sjf_gluseprogram(sjs_shader* shader) {
#line 167 "lib/sj-lib-ui/gl.sj"
    glUseProgram(shader->id);
}

void sjf_gridlayout(sjs_gridlayout* _this) {
}

void sjf_gridlayout_as_sji_element(sjs_gridlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_gridlayout_element_vtbl;
}

void sjf_gridlayout_asinterface(sjs_gridlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_gridlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_gridlayout_copy(sjs_gridlayout* _this, sjs_gridlayout* _from) {
    _this->children._refCount = 1;
#line 46 "lib/sj-lib-ui/gridLayout.sj"
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 46
    _this->margin._refCount = 1;
#line 46
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 46
    _this->cols._refCount = 1;
#line 46
    sjf_array_gridunit_copy(&_this->cols, &_from->cols);
#line 46
    _this->rows._refCount = 1;
#line 46
    sjf_array_gridunit_copy(&_this->rows, &_from->rows);
#line 46
    _this->_rect._refCount = 1;
#line 46
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_gridlayout_destroy(sjs_gridlayout* _this) {
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->cols._refCount == 1) { sjf_array_gridunit_destroy(&_this->cols); }
;
    if (_this->rows._refCount == 1) { sjf_array_gridunit_destroy(&_this->rows); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_gridlayout_firemouseevent(sjs_gridlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam44 = 0;
    sjs_mouseevent* sjt_parent40 = 0;

#line 164 "lib/sj-lib-ui/gridLayout.sj"
    sjt_parent40 = mouseevent;
#line 165
    sjt_functionParam44 = &_parent->children;
#line 165
    sjf_mouseevent_firechildren(sjt_parent40, sjt_functionParam44, _return);
}

void sjf_gridlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 91;
}

void sjf_gridlayout_getrect(sjs_gridlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 57 "lib/sj-lib-ui/gridLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_gridlayout_getrect_heap(sjs_gridlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 57 "lib/sj-lib-ui/gridLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_gridlayout_getsize(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 54 "lib/sj-lib-ui/gridLayout.sj"
    _return->w = maxsize->w;
#line 54
    _return->h = maxsize->h;
#line 54
    sjf_size(_return);
}

void sjf_gridlayout_getsize_heap(sjs_gridlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 54 "lib/sj-lib-ui/gridLayout.sj"
    (*_return)->w = maxsize->w;
#line 54
    (*_return)->h = maxsize->h;
#line 54
    sjf_size_heap((*_return));
}

void sjf_gridlayout_heap(sjs_gridlayout* _this) {
}

void sjf_gridlayout_render(sjs_gridlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;
    sjs_array_heap_iface_element* sjt_parent34 = 0;

#line 158 "lib/sj-lib-ui/gridLayout.sj"
    sjt_forStart6 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent34 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent34, &sjt_forEnd6);
#line 158 "lib/sj-lib-ui/gridLayout.sj"
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sji_element child = { 0 };
        int32_t sjt_functionParam42;
        sjs_scene2d* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent35 = 0;
        sji_element sjt_parent36 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent35 = &_parent->children;
#line 158 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam42 = i;
#line 158
        sjf_array_heap_iface_element_getat_heap(sjt_parent35, sjt_functionParam42, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent36 = child;
#line 157 "lib/sj-lib-ui/gridLayout.sj"
        sjt_interfaceParam2 = scene;
#line 160
        sjt_parent36._vtbl->render(sjt_parent36._parent, sjt_interfaceParam2);
#line 158
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }
}

void sjf_gridlayout_setrect(sjs_gridlayout* _parent, sjs_rect* rect_) {
    int32_t c;
    int32_t cnext;
    int32_t colfixed;
    int32_t colstarremainder;
    int32_t colstars;
    int32_t colstarunit;
    int32_t i;
    sjs_rect innerrect = { -1 };
    int32_t r;
    int32_t rnext;
    int32_t rowfixed;
    int32_t rowstarremainder;
    int32_t rowstars;
    int32_t rowstarunit;
    int32_t sjt_capture6;
    int32_t sjt_capture8;
    int32_t sjt_forEnd1;
    int32_t sjt_forEnd2;
    int32_t sjt_forEnd3;
    int32_t sjt_forEnd4;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart1;
    int32_t sjt_forStart2;
    int32_t sjt_forStart3;
    int32_t sjt_forStart4;
    int32_t sjt_forStart5;
    sjs_margin* sjt_functionParam14 = 0;
    int32_t sjt_functionParam16;
    int32_t sjt_functionParam17;
    int32_t sjt_functionParam18;
    int32_t sjt_functionParam19;
    int32_t sjt_functionParam26;
    int32_t sjt_functionParam27;
    int32_t sjt_functionParam28;
    int32_t sjt_functionParam29;
    sjs_array_i32* sjt_parent10 = 0;
    sjs_array_gridunit* sjt_parent11 = 0;
    sjs_array_gridunit* sjt_parent14 = 0;
    sjs_array_gridunit* sjt_parent16 = 0;
    sjs_array_i32* sjt_parent17 = 0;
    sjs_array_gridunit* sjt_parent18 = 0;
    sjs_array_heap_iface_element* sjt_parent21 = 0;
    sjs_rect* sjt_parent6 = 0;
    sjs_array_gridunit* sjt_parent7 = 0;
    sjs_array_gridunit* sjt_parent9 = 0;
    int32_t x;
    sjs_array_i32 xpos = { -1 };
    int32_t y;
    sjs_array_i32 ypos = { -1 };

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 59 "lib/sj-lib-ui/gridLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 59
    sjt_parent6 = rect_;
#line 61
    sjt_functionParam14 = &_parent->margin;
#line 61
    sjf_rect_subtractmargin(sjt_parent6, sjt_functionParam14, &innerrect);
#line 63
    rowfixed = 0;
#line 64
    rowstars = 0;
#line 65
    sjt_forStart1 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent7 = &_parent->rows;
#line 29
    sjf_array_gridunit_getcount(sjt_parent7, &sjt_forEnd1);
#line 65 "lib/sj-lib-ui/gridLayout.sj"
    r = sjt_forStart1;
    while (r < sjt_forEnd1) {
        sjs_gridunit row = { -1 };
        int32_t sjt_functionParam15;
        sjs_array_gridunit* sjt_parent8 = 0;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent8 = &_parent->rows;
#line 65 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam15 = r;
#line 65
        sjf_array_gridunit_getat(sjt_parent8, sjt_functionParam15, &row);
        if ((&row)->unittype == g_gridunittype_star) {
#line 68 "lib/sj-lib-ui/gridLayout.sj"
            rowstars = rowstars + (&row)->amount;
        } else {
#line 70 "lib/sj-lib-ui/gridLayout.sj"
            rowfixed = rowfixed + (&row)->amount;
        }

#line 65
        r++;

        if (row._refCount == 1) { sjf_gridunit_destroy(&row); }
;
    }

    if (rowstars > 0) {
#line 74 "lib/sj-lib-ui/gridLayout.sj"
        rowstarunit = ((&innerrect)->h - rowfixed) / rowstars;
    } else {
#line 74 "lib/sj-lib-ui/gridLayout.sj"
        rowstarunit = 0;
    }

    if (rowstars > 0) {
#line 75 "lib/sj-lib-ui/gridLayout.sj"
        rowstarremainder = ((&innerrect)->h - rowfixed) % rowstars;
    } else {
#line 75 "lib/sj-lib-ui/gridLayout.sj"
        rowstarremainder = 0;
    }

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent9 = &_parent->rows;
#line 29
    sjf_array_gridunit_getcount(sjt_parent9, &sjt_capture6);
#line 77 "lib/sj-lib-ui/gridLayout.sj"
    sjt_functionParam16 = sjt_capture6 + 1;
#line 77
    sjt_functionParam17 = 0;
#line 77
    sjf_array_create_i32(sjt_functionParam16, sjt_functionParam17, &ypos);
#line 78
    y = (&innerrect)->y;
#line 68 "lib/sj-lib-common/array.sj"
    sjt_parent10 = &ypos;
#line 79 "lib/sj-lib-ui/gridLayout.sj"
    sjt_functionParam18 = 0;
#line 79
    sjt_functionParam19 = y;
#line 79
    sjf_array_i32_setat(sjt_parent10, sjt_functionParam18, sjt_functionParam19);
#line 80
    sjt_forStart2 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent11 = &_parent->rows;
#line 29
    sjf_array_gridunit_getcount(sjt_parent11, &sjt_forEnd2);
#line 80 "lib/sj-lib-ui/gridLayout.sj"
    r = sjt_forStart2;
    while (r < sjt_forEnd2) {
        sjs_gridunit row = { -1 };
        int32_t sjt_functionParam20;
        int32_t sjt_functionParam23;
        int32_t sjt_functionParam24;
        sjs_array_gridunit* sjt_parent12 = 0;
        sjs_array_i32* sjt_parent13 = 0;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent12 = &_parent->rows;
#line 80 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam20 = r;
#line 80
        sjf_array_gridunit_getat(sjt_parent12, sjt_functionParam20, &row);
        if ((&row)->unittype == g_gridunittype_star) {
            int32_t sjt_capture7;
            int32_t sjt_functionParam21;
            int32_t sjt_functionParam22;

#line 83 "lib/sj-lib-ui/gridLayout.sj"
            y = y + (rowstarunit * (&row)->amount);
#line 84
            sjt_functionParam21 = 0;
#line 84
            sjt_functionParam22 = rowstarremainder;
#line 84
            sjf_i32_max(sjt_functionParam21, sjt_functionParam22, &sjt_capture7);
#line 84
            y = y + sjt_capture7;
#line 85
            rowstarremainder = rowstarremainder - (&row)->amount;
        } else {
#line 87 "lib/sj-lib-ui/gridLayout.sj"
            y = y + (&row)->amount;
        }

#line 68 "lib/sj-lib-common/array.sj"
        sjt_parent13 = &ypos;
#line 89 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam23 = r + 1;
#line 89
        sjt_functionParam24 = y;
#line 89
        sjf_array_i32_setat(sjt_parent13, sjt_functionParam23, sjt_functionParam24);
#line 80
        r++;

        if (row._refCount == 1) { sjf_gridunit_destroy(&row); }
;
    }

#line 92
    colfixed = 0;
#line 93
    colstars = 0;
#line 94
    sjt_forStart3 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent14 = &_parent->cols;
#line 29
    sjf_array_gridunit_getcount(sjt_parent14, &sjt_forEnd3);
#line 94 "lib/sj-lib-ui/gridLayout.sj"
    c = sjt_forStart3;
    while (c < sjt_forEnd3) {
        sjs_gridunit col = { -1 };
        int32_t sjt_functionParam25;
        sjs_array_gridunit* sjt_parent15 = 0;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent15 = &_parent->cols;
#line 94 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam25 = c;
#line 94
        sjf_array_gridunit_getat(sjt_parent15, sjt_functionParam25, &col);
        if ((&col)->unittype == g_gridunittype_star) {
#line 97 "lib/sj-lib-ui/gridLayout.sj"
            colstars = colstars + (&col)->amount;
        } else {
#line 99 "lib/sj-lib-ui/gridLayout.sj"
            colfixed = colfixed + (&col)->amount;
        }

#line 94
        c++;

        if (col._refCount == 1) { sjf_gridunit_destroy(&col); }
;
    }

    if (colstars > 0) {
#line 103 "lib/sj-lib-ui/gridLayout.sj"
        colstarunit = ((&innerrect)->w - colfixed) / colstars;
    } else {
#line 103 "lib/sj-lib-ui/gridLayout.sj"
        colstarunit = 0;
    }

    if (colstars > 0) {
#line 104 "lib/sj-lib-ui/gridLayout.sj"
        colstarremainder = ((&innerrect)->w - colfixed) % colstars;
    } else {
#line 104 "lib/sj-lib-ui/gridLayout.sj"
        colstarremainder = 0;
    }

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent16 = &_parent->cols;
#line 29
    sjf_array_gridunit_getcount(sjt_parent16, &sjt_capture8);
#line 106 "lib/sj-lib-ui/gridLayout.sj"
    sjt_functionParam26 = sjt_capture8 + 1;
#line 106
    sjt_functionParam27 = 0;
#line 106
    sjf_array_create_i32(sjt_functionParam26, sjt_functionParam27, &xpos);
#line 107
    x = (&innerrect)->x;
#line 68 "lib/sj-lib-common/array.sj"
    sjt_parent17 = &xpos;
#line 108 "lib/sj-lib-ui/gridLayout.sj"
    sjt_functionParam28 = 0;
#line 108
    sjt_functionParam29 = x;
#line 108
    sjf_array_i32_setat(sjt_parent17, sjt_functionParam28, sjt_functionParam29);
#line 109
    sjt_forStart4 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent18 = &_parent->cols;
#line 29
    sjf_array_gridunit_getcount(sjt_parent18, &sjt_forEnd4);
#line 109 "lib/sj-lib-ui/gridLayout.sj"
    c = sjt_forStart4;
    while (c < sjt_forEnd4) {
        sjs_gridunit col = { -1 };
        int32_t sjt_functionParam30;
        int32_t sjt_functionParam33;
        int32_t sjt_functionParam34;
        sjs_array_gridunit* sjt_parent19 = 0;
        sjs_array_i32* sjt_parent20 = 0;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent19 = &_parent->cols;
#line 109 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam30 = c;
#line 109
        sjf_array_gridunit_getat(sjt_parent19, sjt_functionParam30, &col);
        if ((&col)->unittype == g_gridunittype_star) {
            int32_t sjt_capture9;
            int32_t sjt_functionParam31;
            int32_t sjt_functionParam32;

#line 112 "lib/sj-lib-ui/gridLayout.sj"
            x = x + (colstarunit * (&col)->amount);
#line 113
            sjt_functionParam31 = 0;
#line 113
            sjt_functionParam32 = colstarremainder;
#line 113
            sjf_i32_max(sjt_functionParam31, sjt_functionParam32, &sjt_capture9);
#line 113
            x = x + sjt_capture9;
#line 114
            colstarremainder = colstarremainder - (&col)->amount;
        } else {
#line 116 "lib/sj-lib-ui/gridLayout.sj"
            x = x + (&col)->amount;
        }

#line 68 "lib/sj-lib-common/array.sj"
        sjt_parent20 = &xpos;
#line 118 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam33 = c + 1;
#line 118
        sjt_functionParam34 = x;
#line 118
        sjf_array_i32_setat(sjt_parent20, sjt_functionParam33, sjt_functionParam34);
#line 109
        c++;

        if (col._refCount == 1) { sjf_gridunit_destroy(&col); }
;
    }

#line 121
    rnext = 0;
#line 122
    cnext = 0;
#line 123
    sjt_forStart5 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent21 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent21, &sjt_forEnd5);
#line 123 "lib/sj-lib-ui/gridLayout.sj"
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        int32_t c;
        sji_element child = { 0 };
        sji_gridchild gridchild = { 0 };
        int32_t r;
        sjs_rect sjt_call4 = { -1 };
        int32_t sjt_capture12;
        int32_t sjt_capture13;
        int32_t sjt_capture14;
        int32_t sjt_capture15;
        sji_element sjt_cast3 = { 0 };
        int32_t sjt_functionParam35;
        int32_t sjt_functionParam36;
        int32_t sjt_functionParam37;
        int32_t sjt_functionParam38;
        int32_t sjt_functionParam39;
        int32_t sjt_functionParam40;
        int32_t sjt_functionParam41;
        sjs_rect* sjt_interfaceParam1 = 0;
        sjs_array_heap_iface_element* sjt_parent22 = 0;
        sji_element sjt_parent27 = { 0 };
        sjs_array_i32* sjt_parent28 = 0;
        sjs_array_i32* sjt_parent29 = 0;
        sjs_array_i32* sjt_parent30 = 0;
        sjs_array_i32* sjt_parent31 = 0;
        sjs_array_i32* sjt_parent32 = 0;
        sjs_array_i32* sjt_parent33 = 0;

#line 124 "lib/sj-lib-ui/gridLayout.sj"
        r = 0;
#line 125
        c = 0;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent22 = &_parent->children;
#line 123 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam35 = i;
#line 123
        sjf_array_heap_iface_element_getat_heap(sjt_parent22, sjt_functionParam35, &child);
#line 127
        sjt_cast3 = child;
#line 1
        sjt_cast3._vtbl->asinterface(sjt_cast3._parent, sji_gridchild_typeId, (sjs_interface*)&gridchild);
        if (gridchild._parent != 0) {
            gridchild._parent->_refCount++;
        }

        if ((gridchild._parent != 0)) {
            sji_gridchild ifValue1 = { 0 };
            int32_t sjt_funcold2;
            int32_t sjt_funcold3;
            sji_gridchild sjt_parent23 = { 0 };
            sji_gridchild sjt_parent24 = { 0 };

#line 128 "lib/sj-lib-ui/gridLayout.sj"
            ifValue1 = gridchild;
            if (ifValue1._parent != 0) {
                ifValue1._parent->_refCount++;
            }

#line 2
            sjt_parent23 = ifValue1;
#line 2
            sjt_funcold2 = r;
#line 129
            sjt_parent23._vtbl->getrow(sjt_parent23._parent, &sjt_funcold2);
#line 2
            r = sjt_funcold2;
#line 3
            sjt_parent24 = ifValue1;
#line 3
            sjt_funcold3 = c;
#line 130
            sjt_parent24._vtbl->getcol(sjt_parent24._parent, &sjt_funcold3);
#line 3
            c = sjt_funcold3;

            if (ifValue1._parent != 0) {
                ifValue1._parent->_refCount--;
                if (ifValue1._parent->_refCount <= 0) {
                    ifValue1._vtbl->destroy(ifValue1._parent);
                    free(ifValue1._parent);
                }
            }
        } else {
            int32_t sjt_capture10;
            sjs_array_gridunit* sjt_parent25 = 0;

#line 133 "lib/sj-lib-ui/gridLayout.sj"
            r = rnext;
#line 134
            c = cnext;
#line 135
            cnext = cnext + 1;
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent25 = &_parent->cols;
#line 29
            sjf_array_gridunit_getcount(sjt_parent25, &sjt_capture10);
            if (cnext >= sjt_capture10) {
                int32_t sjt_capture11;
                sjs_array_gridunit* sjt_parent26 = 0;

#line 137 "lib/sj-lib-ui/gridLayout.sj"
                cnext = 0;
#line 138
                rnext = rnext + 1;
#line 29 "lib/sj-lib-common/array.sj"
                sjt_parent26 = &_parent->rows;
#line 29
                sjf_array_gridunit_getcount(sjt_parent26, &sjt_capture11);
                if (rnext >= sjt_capture11) {
#line 140 "lib/sj-lib-ui/gridLayout.sj"
                    rnext = 0;
                }
            }
        }

#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent27 = child;
#line 4
        sjt_call4._refCount = 1;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent28 = &xpos;
#line 147 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam36 = c;
#line 147
        sjf_array_i32_getat(sjt_parent28, sjt_functionParam36, &sjt_call4.x);
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent29 = &ypos;
#line 148 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam37 = r;
#line 148
        sjf_array_i32_getat(sjt_parent29, sjt_functionParam37, &sjt_call4.y);
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent30 = &xpos;
#line 149 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam38 = c + 1;
#line 149
        sjf_array_i32_getat(sjt_parent30, sjt_functionParam38, &sjt_capture12);
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent31 = &xpos;
#line 149 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam39 = c;
#line 149
        sjf_array_i32_getat(sjt_parent31, sjt_functionParam39, &sjt_capture13);
#line 149
        sjt_call4.w = sjt_capture12 - sjt_capture13;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent32 = &ypos;
#line 150 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam40 = r + 1;
#line 150
        sjf_array_i32_getat(sjt_parent32, sjt_functionParam40, &sjt_capture14);
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent33 = &ypos;
#line 150 "lib/sj-lib-ui/gridLayout.sj"
        sjt_functionParam41 = r;
#line 150
        sjf_array_i32_getat(sjt_parent33, sjt_functionParam41, &sjt_capture15);
#line 150
        sjt_call4.h = sjt_capture14 - sjt_capture15;
#line 150
        sjf_rect(&sjt_call4);
#line 146
        sjt_interfaceParam1 = &sjt_call4;
#line 146
        sjt_parent27._vtbl->setrect(sjt_parent27._parent, sjt_interfaceParam1);
#line 123
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (gridchild._parent != 0) {
            gridchild._parent->_refCount--;
            if (gridchild._parent->_refCount <= 0) {
                gridchild._vtbl->destroy(gridchild._parent);
                free(gridchild._parent);
            }
        }
        if (sjt_call4._refCount == 1) { sjf_rect_destroy(&sjt_call4); }
;
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
    if (xpos._refCount == 1) { sjf_array_i32_destroy(&xpos); }
;
    if (ypos._refCount == 1) { sjf_array_i32_destroy(&ypos); }
;
}

void sjf_gridunit(sjs_gridunit* _this) {
}

void sjf_gridunit_copy(sjs_gridunit* _this, sjs_gridunit* _from) {
#line 41 "lib/sj-lib-ui/gridLayout.sj"
    _this->amount = _from->amount;
#line 41
    _this->unittype = _from->unittype;
}

void sjf_gridunit_destroy(sjs_gridunit* _this) {
}

void sjf_gridunit_heap(sjs_gridunit* _this) {
}

void sjf_halt(sjs_string* reason) {
#line 3 "lib/sj-lib-common/halt.sj"
    halt("%s\n", string_char(reason));
}

void sjf_hash_fontkey_weak_font(sjs_hash_fontkey_weak_font* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
}

void sjf_hash_fontkey_weak_font__weakptrremovekey(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(fontkey_weak_font_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_fontkey_weak_font__weakptrremovevalue(sjs_hash_fontkey_weak_font* _parent, sjs_font* val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if true
#line 201
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            sjs_font* t = kh_value(p, k);
#line 205
            if (t == val) {
#line 206
                kh_del(fontkey_weak_font_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_fontkey_weak_font_copy(sjs_hash_fontkey_weak_font* _this, sjs_hash_fontkey_weak_font* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_fontkey_weak_font_destroy(sjs_hash_fontkey_weak_font* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if true
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k), cb);
#line 260
                #else
#line 261
                delete_cb weakptrcb15 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb15); }
;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(fontkey_weak_font_hash_type, (khash_t(fontkey_weak_font_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_fontkey_weak_font_getat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font** _return) {
#line 23 "lib/sj-lib-common/hash.sj"
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
#line 25
    #if true
#line 26
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = 0;
#line 22
delete_cb weakptrcb22 = { &(*_return), weakptr_clear };
#line 22
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb22); }
return;
#line 33
    }
#line 34
    #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = kh_val(p, k);
#line 22
delete_cb weakptrcb23 = { &(*_return), weakptr_clear };
#line 22
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb23); }
return;;
}

void sjf_hash_fontkey_weak_font_getat_heap(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font** _return) {
#line 23 "lib/sj-lib-common/hash.sj"
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
#line 25
    #if true
#line 26
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = 0;
if ((*_return) != 0) {
    (*_return)->_refCount++;
}
return;
#line 33
    }
#line 34
    #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = kh_val(p, k);
if ((*_return) != 0) {
    (*_return)->_refCount++;
}
return;;
}

void sjf_hash_fontkey_weak_font_heap(sjs_hash_fontkey_weak_font* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(fontkey_weak_font_hash_type);
}

void sjf_hash_fontkey_weak_font_setat(sjs_hash_fontkey_weak_font* _parent, sjs_fontkey* key, sjs_font* val) {
#line 40 "lib/sj-lib-common/hash.sj"
    khash_t(fontkey_weak_font_hash_type)* p = (khash_t(fontkey_weak_font_hash_type)*)_parent->_hash;
#line 42
    #if true
#line 43
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(fontkey_weak_font_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    delete_cb weakptrcb24 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb24); }
;
#line 50
}
#line 52
int ret;
#line 53
#if true
#line 54
k = kh_put(fontkey_weak_font_hash_type, p, *key, &ret);
#line 55
#else
#line 56
k = kh_put(fontkey_weak_font_hash_type, p, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(fontkey_weak_font_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovekey };
#line 63
weakptr_cb_add(key, cb);
#line 64
#else
#line 65
sjs_fontkey t;
#line 66
t._refCount = 1;
#line 38 "lib/sj-lib-common/hash.sj"
sjf_fontkey_copy(&t, key);
;
#line 67
#endif
#line 69
#if true
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_fontkey_weak_font__weakptrremovevalue };
#line 71
weakptr_cb_add(val, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/sj-lib-common/hash.sj"
kh_val(p, k) = val;
#line 38
delete_cb weakptrcb25 = { &kh_val(p, k), weakptr_clear };
#line 38
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb25); }
;
#line 75
#endif
}

void sjf_hash_string_weak_iface_element(sjs_hash_string_weak_iface_element* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
}

void sjf_hash_string_weak_iface_element__weakptrremovekey(sjs_hash_string_weak_iface_element* _parent, sjs_string* key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(string_weak_iface_element_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_string_weak_iface_element__weakptrremovevalue(sjs_hash_string_weak_iface_element* _parent, sji_element val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if true
#line 201
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            sji_element t = kh_value(p, k);
#line 205
            if (t._parent == val._parent) {
#line 206
                kh_del(string_weak_iface_element_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_string_weak_iface_element_copy(sjs_hash_string_weak_iface_element* _this, sjs_hash_string_weak_iface_element* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_string_weak_iface_element_destroy(sjs_hash_string_weak_iface_element* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if true
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
#line 260
                #else
#line 261
                delete_cb weakptrcb14 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb14); }
;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(string_weak_iface_element_hash_type, (khash_t(string_weak_iface_element_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_string_weak_iface_element_heap(sjs_hash_string_weak_iface_element* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_element_hash_type);
}

void sjf_hash_string_weak_iface_element_setat(sjs_hash_string_weak_iface_element* _parent, sjs_string* key, sji_element val) {
#line 40 "lib/sj-lib-common/hash.sj"
    khash_t(string_weak_iface_element_hash_type)* p = (khash_t(string_weak_iface_element_hash_type)*)_parent->_hash;
#line 42
    #if true
#line 43
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(string_weak_iface_element_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    delete_cb weakptrcb19 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb19); }
;
#line 50
}
#line 52
int ret;
#line 53
#if true
#line 54
k = kh_put(string_weak_iface_element_hash_type, p, *key, &ret);
#line 55
#else
#line 56
k = kh_put(string_weak_iface_element_hash_type, p, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(string_weak_iface_element_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovekey };
#line 63
weakptr_cb_add(key, cb);
#line 64
#else
#line 65
sjs_string t;
#line 66
t._refCount = 1;
#line 38 "lib/sj-lib-common/hash.sj"
sjf_string_copy(&t, key);
;
#line 67
#endif
#line 69
#if true
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_element__weakptrremovevalue };
#line 71
weakptr_cb_add(val._parent, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/sj-lib-common/hash.sj"
kh_val(p, k) = val;
#line 38
delete_cb weakptrcb20 = { &kh_val(p, k)._parent, weakptr_clear };
#line 38
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb20); }
;
#line 75
#endif
}

void sjf_hash_string_weak_iface_model(sjs_hash_string_weak_iface_model* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_model_hash_type);
}

void sjf_hash_string_weak_iface_model__weakptrremovekey(sjs_hash_string_weak_iface_model* _parent, sjs_string* key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(string_weak_iface_model_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_string_weak_iface_model__weakptrremovevalue(sjs_hash_string_weak_iface_model* _parent, sji_model val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if true
#line 201
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            sji_model t = kh_value(p, k);
#line 205
            if (t._parent == val._parent) {
#line 206
                kh_del(string_weak_iface_model_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_string_weak_iface_model_copy(sjs_hash_string_weak_iface_model* _this, sjs_hash_string_weak_iface_model* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_string_weak_iface_model_destroy(sjs_hash_string_weak_iface_model* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if true
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k)._parent, cb);
#line 260
                #else
#line 261
                delete_cb weakptrcb13 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb13); }
;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(string_weak_iface_model_hash_type, (khash_t(string_weak_iface_model_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_string_weak_iface_model_heap(sjs_hash_string_weak_iface_model* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(string_weak_iface_model_hash_type);
}

void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val) {
#line 40 "lib/sj-lib-common/hash.sj"
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
#line 42
    #if true
#line 43
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    delete_cb weakptrcb16 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb16); }
;
#line 50
}
#line 52
int ret;
#line 53
#if true
#line 54
k = kh_put(string_weak_iface_model_hash_type, p, *key, &ret);
#line 55
#else
#line 56
k = kh_put(string_weak_iface_model_hash_type, p, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(string_weak_iface_model_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovekey };
#line 63
weakptr_cb_add(key, cb);
#line 64
#else
#line 65
sjs_string t;
#line 66
t._refCount = 1;
#line 38 "lib/sj-lib-common/hash.sj"
sjf_string_copy(&t, key);
;
#line 67
#endif
#line 69
#if true
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_string_weak_iface_model__weakptrremovevalue };
#line 71
weakptr_cb_add(val._parent, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/sj-lib-common/hash.sj"
kh_val(p, k) = val;
#line 38
delete_cb weakptrcb17 = { &kh_val(p, k)._parent, weakptr_clear };
#line 38
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb17); }
;
#line 75
#endif
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(type_bool_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if false
#line 201
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            bool t = kh_value(p, k);
#line 205
            if (t == val) {
#line 206
                kh_del(type_bool_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if false
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k), cb);
#line 260
                #else
#line 261
                ;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(type_bool_hash_type, (khash_t(type_bool_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    if (a < b) {
#line 6 "lib/sj-lib-common/i32.sj"
        (*_return) = b;
    } else {
#line 6 "lib/sj-lib-common/i32.sj"
        (*_return) = a;
    }
}

void sjf_light(sjs_light* _this) {
}

void sjf_light_copy(sjs_light* _this, sjs_light* _from) {
    _this->pos._refCount = 1;
#line 1 "lib/sj-lib-ui/scene3dElement.sj"
    sjf_vec3_copy(&_this->pos, &_from->pos);
#line 1
    _this->diffusecolor._refCount = 1;
#line 1
    sjf_color_copy(&_this->diffusecolor, &_from->diffusecolor);
#line 1
    _this->speccolor._refCount = 1;
#line 1
    sjf_color_copy(&_this->speccolor, &_from->speccolor);
}

void sjf_light_destroy(sjs_light* _this) {
    if (_this->pos._refCount == 1) { sjf_vec3_destroy(&_this->pos); }
;
    if (_this->diffusecolor._refCount == 1) { sjf_color_destroy(&_this->diffusecolor); }
;
    if (_this->speccolor._refCount == 1) { sjf_color_destroy(&_this->speccolor); }
;
}

void sjf_light_heap(sjs_light* _this) {
}

void sjf_list_heap_iface_animation(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_copy(sjs_list_heap_iface_animation* _this, sjs_list_heap_iface_animation* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_heap_iface_animation_copy(&_this->arr, &_from->arr);
}

void sjf_list_heap_iface_animation_destroy(sjs_list_heap_iface_animation* _this) {
    if (_this->arr._refCount == 1) { sjf_array_heap_iface_animation_destroy(&_this->arr); }
;
}

void sjf_list_heap_iface_animation_getat_heap(sjs_list_heap_iface_animation* _parent, int32_t index, sji_animation* _return) {
    int32_t sjt_functionParam665;
    sjs_array_heap_iface_animation* sjt_parent361 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent361 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam665 = index;
#line 8
    sjf_array_heap_iface_animation_getat_heap(sjt_parent361, sjt_functionParam665, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
    sjs_array_heap_iface_animation* sjt_parent358 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent358 = &_parent->arr;
#line 29
    sjf_array_heap_iface_animation_getcount(sjt_parent358, _return);
}

void sjf_list_heap_iface_animation_heap(sjs_list_heap_iface_animation* _this) {
}

void sjf_list_heap_iface_animation_removeat(sjs_list_heap_iface_animation* _parent, int32_t index) {
#line 55 "lib/sj-lib-common/list.sj"
    if (index < 0 || index >= ((sjs_array*)_parent->arr.v)->count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, ((sjs_array*)_parent->arr.v)->count);
#line 57
    }
#line 58
    sji_animation* p = (sji_animation*)((sjs_array*)_parent->arr.v)->data;
#line 59
    if (p[index]._parent != 0) {
    p[index]._parent->_refCount--;
    if (p[index]._parent->_refCount <= 0) {
        p[index]._vtbl->destroy(p[index]._parent);
        free(p[index]._parent);
    }
}
;
#line 60
    if (index != ((sjs_array*)_parent->arr.v)->count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (((sjs_array*)_parent->arr.v)->count - index - 1) * sizeof(sji_animation));
#line 62
    }
#line 63
    ((sjs_array*)_parent->arr.v)->count--;
}

void sjf_list_heap_iface_model(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_add(sjs_list_heap_iface_model* _parent, sji_model item) {
    int32_t sjt_capture45;
    int32_t sjt_capture46;
    sjs_array_heap_iface_model sjt_funcold14 = { -1 };
    int32_t sjt_functionParam167;
    sji_model sjt_functionParam168 = { 0 };
    sjs_array_heap_iface_model* sjt_parent132 = 0;
    sjs_array_heap_iface_model* sjt_parent133 = 0;
    sjs_array_heap_iface_model* sjt_parent137 = 0;
    sjs_array_heap_iface_model* sjt_parent138 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent132 = &_parent->arr;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent132, &sjt_capture45);
#line 35
    sjt_parent133 = &_parent->arr;
#line 35
    sjf_array_heap_iface_model_gettotalcount(sjt_parent133, &sjt_capture46);
    if (sjt_capture45 == sjt_capture46) {
        int32_t sjt_capture47;
        int32_t sjt_functionParam162;
        int32_t sjt_functionParam163;
        int32_t sjt_functionParam164;
        int32_t sjt_functionParam165;
        int32_t sjt_functionParam166;
        sjs_array_heap_iface_model* sjt_parent134 = 0;
        sjs_array_heap_iface_model* sjt_parent135 = 0;
        sjs_array_heap_iface_model* sjt_parent136 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent134 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam162 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent135 = &_parent->arr;
#line 29
        sjf_array_heap_iface_model_getcount(sjt_parent135, &sjt_functionParam163);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam165 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent136 = &_parent->arr;
#line 35
        sjf_array_heap_iface_model_gettotalcount(sjt_parent136, &sjt_capture47);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam166 = sjt_capture47 * 2;
#line 46
        sjf_i32_max(sjt_functionParam165, sjt_functionParam166, &sjt_functionParam164);
#line 46
        sjf_array_heap_iface_model_clone(sjt_parent134, sjt_functionParam162, sjt_functionParam163, sjt_functionParam164, &sjt_funcold14);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_heap_iface_model_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_heap_iface_model_copy(&_parent->arr, &sjt_funcold14);
    }

#line 52
    sjt_parent137 = &_parent->arr;
#line 29
    sjt_parent138 = &_parent->arr;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent138, &sjt_functionParam167);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam168 = item;
    if (sjt_functionParam168._parent != 0) {
        sjt_functionParam168._parent->_refCount++;
    }

#line 44
    sjf_array_heap_iface_model_initat(sjt_parent137, sjt_functionParam167, sjt_functionParam168);

    if (sjt_functionParam168._parent != 0) {
        sjt_functionParam168._parent->_refCount--;
        if (sjt_functionParam168._parent->_refCount <= 0) {
            sjt_functionParam168._vtbl->destroy(sjt_functionParam168._parent);
            free(sjt_functionParam168._parent);
        }
    }
    if (sjt_funcold14._refCount == 1) { sjf_array_heap_iface_model_destroy(&sjt_funcold14); }
;
}

void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_heap_iface_model_copy(&_this->arr, &_from->arr);
}

void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this) {
    if (_this->arr._refCount == 1) { sjf_array_heap_iface_model_destroy(&_this->arr); }
;
}

void sjf_list_heap_iface_model_getat_heap(sjs_list_heap_iface_model* _parent, int32_t index, sji_model* _return) {
    int32_t sjt_functionParam134;
    sjs_array_heap_iface_model* sjt_parent108 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent108 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam134 = index;
#line 8
    sjf_array_heap_iface_model_getat_heap(sjt_parent108, sjt_functionParam134, _return);
}

void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return) {
    sjs_array_heap_iface_model* sjt_parent106 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent106 = &_parent->arr;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent106, _return);
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam130;
    sjs_array_heap_iface_model* sjt_parent102 = 0;

#line 279 "lib/sj-lib-common/array.sj"
    sjt_parent102 = &_parent->arr;
#line 28 "lib/sj-lib-common/list.sj"
    sjt_functionParam130 = cb;
#line 28
    sjf_array_heap_iface_model_sortcb(sjt_parent102, sjt_functionParam130);
}

void sjf_list_i32(sjs_list_i32* _this) {
}

void sjf_list_i32_add(sjs_list_i32* _parent, int32_t item) {
    int32_t sjt_capture50;
    int32_t sjt_capture51;
    sjs_array_i32 sjt_funcold15 = { -1 };
    int32_t sjt_functionParam209;
    int32_t sjt_functionParam210;
    sjs_array_i32* sjt_parent149 = 0;
    sjs_array_i32* sjt_parent150 = 0;
    sjs_array_i32* sjt_parent154 = 0;
    sjs_array_i32* sjt_parent155 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent149 = &_parent->arr;
#line 29
    sjf_array_i32_getcount(sjt_parent149, &sjt_capture50);
#line 35
    sjt_parent150 = &_parent->arr;
#line 35
    sjf_array_i32_gettotalcount(sjt_parent150, &sjt_capture51);
    if (sjt_capture50 == sjt_capture51) {
        int32_t sjt_capture52;
        int32_t sjt_functionParam204;
        int32_t sjt_functionParam205;
        int32_t sjt_functionParam206;
        int32_t sjt_functionParam207;
        int32_t sjt_functionParam208;
        sjs_array_i32* sjt_parent151 = 0;
        sjs_array_i32* sjt_parent152 = 0;
        sjs_array_i32* sjt_parent153 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent151 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam204 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent152 = &_parent->arr;
#line 29
        sjf_array_i32_getcount(sjt_parent152, &sjt_functionParam205);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam207 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent153 = &_parent->arr;
#line 35
        sjf_array_i32_gettotalcount(sjt_parent153, &sjt_capture52);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam208 = sjt_capture52 * 2;
#line 46
        sjf_i32_max(sjt_functionParam207, sjt_functionParam208, &sjt_functionParam206);
#line 46
        sjf_array_i32_clone(sjt_parent151, sjt_functionParam204, sjt_functionParam205, sjt_functionParam206, &sjt_funcold15);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_i32_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_i32_copy(&_parent->arr, &sjt_funcold15);
    }

#line 52
    sjt_parent154 = &_parent->arr;
#line 29
    sjt_parent155 = &_parent->arr;
#line 29
    sjf_array_i32_getcount(sjt_parent155, &sjt_functionParam209);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam210 = item;
#line 44
    sjf_array_i32_initat(sjt_parent154, sjt_functionParam209, sjt_functionParam210);

    if (sjt_funcold15._refCount == 1) { sjf_array_i32_destroy(&sjt_funcold15); }
;
}

void sjf_list_i32_copy(sjs_list_i32* _this, sjs_list_i32* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_i32_copy(&_this->arr, &_from->arr);
}

void sjf_list_i32_destroy(sjs_list_i32* _this) {
    if (_this->arr._refCount == 1) { sjf_array_i32_destroy(&_this->arr); }
;
}

void sjf_list_i32_getat(sjs_list_i32* _parent, int32_t index, int32_t* _return) {
    int32_t sjt_functionParam268;
    sjs_array_i32* sjt_parent205 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent205 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam268 = index;
#line 8
    sjf_array_i32_getat(sjt_parent205, sjt_functionParam268, _return);
}

void sjf_list_i32_getcount(sjs_list_i32* _parent, int32_t* _return) {
    sjs_array_i32* sjt_parent203 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent203 = &_parent->arr;
#line 29
    sjf_array_i32_getcount(sjt_parent203, _return);
}

void sjf_list_i32_heap(sjs_list_i32* _this) {
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    int32_t sjt_capture28;
    int32_t sjt_capture29;
    sjs_array_rect sjt_funcold9 = { -1 };
    int32_t sjt_functionParam102;
    sjs_rect* sjt_functionParam103 = 0;
    sjs_array_rect* sjt_parent91 = 0;
    sjs_array_rect* sjt_parent92 = 0;
    sjs_array_rect* sjt_parent96 = 0;
    sjs_array_rect* sjt_parent97 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent91 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent91, &sjt_capture28);
#line 35
    sjt_parent92 = &_parent->arr;
#line 35
    sjf_array_rect_gettotalcount(sjt_parent92, &sjt_capture29);
    if (sjt_capture28 == sjt_capture29) {
        int32_t sjt_capture30;
        int32_t sjt_functionParam100;
        int32_t sjt_functionParam101;
        int32_t sjt_functionParam97;
        int32_t sjt_functionParam98;
        int32_t sjt_functionParam99;
        sjs_array_rect* sjt_parent93 = 0;
        sjs_array_rect* sjt_parent94 = 0;
        sjs_array_rect* sjt_parent95 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent93 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam97 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent94 = &_parent->arr;
#line 29
        sjf_array_rect_getcount(sjt_parent94, &sjt_functionParam98);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam100 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent95 = &_parent->arr;
#line 35
        sjf_array_rect_gettotalcount(sjt_parent95, &sjt_capture30);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam101 = sjt_capture30 * 2;
#line 46
        sjf_i32_max(sjt_functionParam100, sjt_functionParam101, &sjt_functionParam99);
#line 46
        sjf_array_rect_clone(sjt_parent93, sjt_functionParam97, sjt_functionParam98, sjt_functionParam99, &sjt_funcold9);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_rect_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_rect_copy(&_parent->arr, &sjt_funcold9);
    }

#line 52
    sjt_parent96 = &_parent->arr;
#line 29
    sjt_parent97 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent97, &sjt_functionParam102);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam103 = item;
#line 44
    sjf_array_rect_initat(sjt_parent96, sjt_functionParam102, sjt_functionParam103);

    if (sjt_funcold9._refCount == 1) { sjf_array_rect_destroy(&sjt_funcold9); }
;
}

void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_rect_copy(&_this->arr, &_from->arr);
}

void sjf_list_rect_destroy(sjs_list_rect* _this) {
    if (_this->arr._refCount == 1) { sjf_array_rect_destroy(&_this->arr); }
;
}

void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return) {
    int32_t sjt_functionParam136;
    sjs_array_rect* sjt_parent112 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent112 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam136 = index;
#line 8
    sjf_array_rect_getat(sjt_parent112, sjt_functionParam136, _return);
}

void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return) {
    int32_t sjt_functionParam137;
    sjs_array_rect* sjt_parent113 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent113 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam137 = index;
#line 8
    sjf_array_rect_getat_heap(sjt_parent113, sjt_functionParam137, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
    sjs_array_rect* sjt_parent115 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent115 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent115, _return);
}

void sjf_list_rect_heap(sjs_list_rect* _this) {
}

void sjf_list_rect_removeat(sjs_list_rect* _parent, int32_t index) {
#line 55 "lib/sj-lib-common/list.sj"
    if (index < 0 || index >= ((sjs_array*)_parent->arr.v)->count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, ((sjs_array*)_parent->arr.v)->count);
#line 57
    }
#line 58
    sjs_rect* p = (sjs_rect*)((sjs_array*)_parent->arr.v)->data;
#line 59
    ;
#line 60
    if (index != ((sjs_array*)_parent->arr.v)->count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (((sjs_array*)_parent->arr.v)->count - index - 1) * sizeof(sjs_rect));
#line 62
    }
#line 63
    ((sjs_array*)_parent->arr.v)->count--;
}

void sjf_list_u32(sjs_list_u32* _this) {
}

void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item) {
    int32_t sjt_capture67;
    int32_t sjt_capture68;
    sjs_array_u32 sjt_funcold24 = { -1 };
    int32_t sjt_functionParam421;
    uint32_t sjt_functionParam422;
    sjs_array_u32* sjt_parent309 = 0;
    sjs_array_u32* sjt_parent310 = 0;
    sjs_array_u32* sjt_parent314 = 0;
    sjs_array_u32* sjt_parent315 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent309 = &_parent->arr;
#line 29
    sjf_array_u32_getcount(sjt_parent309, &sjt_capture67);
#line 35
    sjt_parent310 = &_parent->arr;
#line 35
    sjf_array_u32_gettotalcount(sjt_parent310, &sjt_capture68);
    if (sjt_capture67 == sjt_capture68) {
        int32_t sjt_capture69;
        int32_t sjt_functionParam416;
        int32_t sjt_functionParam417;
        int32_t sjt_functionParam418;
        int32_t sjt_functionParam419;
        int32_t sjt_functionParam420;
        sjs_array_u32* sjt_parent311 = 0;
        sjs_array_u32* sjt_parent312 = 0;
        sjs_array_u32* sjt_parent313 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent311 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam416 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent312 = &_parent->arr;
#line 29
        sjf_array_u32_getcount(sjt_parent312, &sjt_functionParam417);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam419 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent313 = &_parent->arr;
#line 35
        sjf_array_u32_gettotalcount(sjt_parent313, &sjt_capture69);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam420 = sjt_capture69 * 2;
#line 46
        sjf_i32_max(sjt_functionParam419, sjt_functionParam420, &sjt_functionParam418);
#line 46
        sjf_array_u32_clone(sjt_parent311, sjt_functionParam416, sjt_functionParam417, sjt_functionParam418, &sjt_funcold24);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_u32_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_u32_copy(&_parent->arr, &sjt_funcold24);
    }

#line 52
    sjt_parent314 = &_parent->arr;
#line 29
    sjt_parent315 = &_parent->arr;
#line 29
    sjf_array_u32_getcount(sjt_parent315, &sjt_functionParam421);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam422 = item;
#line 44
    sjf_array_u32_initat(sjt_parent314, sjt_functionParam421, sjt_functionParam422);

    if (sjt_funcold24._refCount == 1) { sjf_array_u32_destroy(&sjt_funcold24); }
;
}

void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_u32_copy(&_this->arr, &_from->arr);
}

void sjf_list_u32_destroy(sjs_list_u32* _this) {
    if (_this->arr._refCount == 1) { sjf_array_u32_destroy(&_this->arr); }
;
}

void sjf_list_u32_getat(sjs_list_u32* _parent, int32_t index, uint32_t* _return) {
    int32_t sjt_functionParam455;
    sjs_array_u32* sjt_parent317 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent317 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam455 = index;
#line 8
    sjf_array_u32_getat(sjt_parent317, sjt_functionParam455, _return);
}

void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return) {
    sjs_array_u32* sjt_parent319 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent319 = &_parent->arr;
#line 29
    sjf_array_u32_getcount(sjt_parent319, _return);
}

void sjf_list_u32_heap(sjs_list_u32* _this) {
}

void sjf_list_u32_removeat(sjs_list_u32* _parent, int32_t index) {
#line 55 "lib/sj-lib-common/list.sj"
    if (index < 0 || index >= ((sjs_array*)_parent->arr.v)->count) {
#line 56
        halt("removeAt: out of bounds %d:%d\n", index, ((sjs_array*)_parent->arr.v)->count);
#line 57
    }
#line 58
    uint32_t* p = (uint32_t*)((sjs_array*)_parent->arr.v)->data;
#line 59
    ;
#line 60
    if (index != ((sjs_array*)_parent->arr.v)->count - 1) {
#line 61
        memcpy(p + index, p + index + 1, (((sjs_array*)_parent->arr.v)->count - index - 1) * sizeof(uint32_t));
#line 62
    }
#line 63
    ((sjs_array*)_parent->arr.v)->count--;
}

void sjf_list_vertex_location_texture_normal(sjs_list_vertex_location_texture_normal* _this) {
}

void sjf_list_vertex_location_texture_normal_add(sjs_list_vertex_location_texture_normal* _parent, sjs_vertex_location_texture_normal* item) {
    int32_t sjt_capture59;
    int32_t sjt_capture60;
    sjs_array_vertex_location_texture_normal sjt_funcold16 = { -1 };
    int32_t sjt_functionParam263;
    sjs_vertex_location_texture_normal* sjt_functionParam264 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent193 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent194 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent198 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent199 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent193 = &_parent->arr;
#line 29
    sjf_array_vertex_location_texture_normal_getcount(sjt_parent193, &sjt_capture59);
#line 35
    sjt_parent194 = &_parent->arr;
#line 35
    sjf_array_vertex_location_texture_normal_gettotalcount(sjt_parent194, &sjt_capture60);
    if (sjt_capture59 == sjt_capture60) {
        int32_t sjt_capture61;
        int32_t sjt_functionParam258;
        int32_t sjt_functionParam259;
        int32_t sjt_functionParam260;
        int32_t sjt_functionParam261;
        int32_t sjt_functionParam262;
        sjs_array_vertex_location_texture_normal* sjt_parent195 = 0;
        sjs_array_vertex_location_texture_normal* sjt_parent196 = 0;
        sjs_array_vertex_location_texture_normal* sjt_parent197 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent195 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam258 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent196 = &_parent->arr;
#line 29
        sjf_array_vertex_location_texture_normal_getcount(sjt_parent196, &sjt_functionParam259);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam261 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent197 = &_parent->arr;
#line 35
        sjf_array_vertex_location_texture_normal_gettotalcount(sjt_parent197, &sjt_capture61);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam262 = sjt_capture61 * 2;
#line 46
        sjf_i32_max(sjt_functionParam261, sjt_functionParam262, &sjt_functionParam260);
#line 46
        sjf_array_vertex_location_texture_normal_clone(sjt_parent195, sjt_functionParam258, sjt_functionParam259, sjt_functionParam260, &sjt_funcold16);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_vertex_location_texture_normal_copy(&_parent->arr, &sjt_funcold16);
    }

#line 52
    sjt_parent198 = &_parent->arr;
#line 29
    sjt_parent199 = &_parent->arr;
#line 29
    sjf_array_vertex_location_texture_normal_getcount(sjt_parent199, &sjt_functionParam263);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam264 = item;
#line 44
    sjf_array_vertex_location_texture_normal_initat(sjt_parent198, sjt_functionParam263, sjt_functionParam264);

    if (sjt_funcold16._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&sjt_funcold16); }
;
}

void sjf_list_vertex_location_texture_normal_copy(sjs_list_vertex_location_texture_normal* _this, sjs_list_vertex_location_texture_normal* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_vertex_location_texture_normal_copy(&_this->arr, &_from->arr);
}

void sjf_list_vertex_location_texture_normal_destroy(sjs_list_vertex_location_texture_normal* _this) {
    if (_this->arr._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&_this->arr); }
;
}

void sjf_list_vertex_location_texture_normal_getat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return) {
    int32_t sjt_functionParam272;
    sjs_array_vertex_location_texture_normal* sjt_parent209 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent209 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam272 = index;
#line 8
    sjf_array_vertex_location_texture_normal_getat(sjt_parent209, sjt_functionParam272, _return);
}

void sjf_list_vertex_location_texture_normal_getat_heap(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal** _return) {
    int32_t sjt_functionParam273;
    sjs_array_vertex_location_texture_normal* sjt_parent210 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent210 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam273 = index;
#line 8
    sjf_array_vertex_location_texture_normal_getat_heap(sjt_parent210, sjt_functionParam273, _return);
}

void sjf_list_vertex_location_texture_normal_getcount(sjs_list_vertex_location_texture_normal* _parent, int32_t* _return) {
    sjs_array_vertex_location_texture_normal* sjt_parent201 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent201 = &_parent->arr;
#line 29
    sjf_array_vertex_location_texture_normal_getcount(sjt_parent201, _return);
}

void sjf_list_vertex_location_texture_normal_heap(sjs_list_vertex_location_texture_normal* _this) {
}

void sjf_list_vertex_location_texture_normal_setat(sjs_list_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
    int32_t sjt_functionParam293;
    sjs_vertex_location_texture_normal* sjt_functionParam294 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent230 = 0;

#line 68 "lib/sj-lib-common/array.sj"
    sjt_parent230 = &_parent->arr;
#line 12 "lib/sj-lib-common/list.sj"
    sjt_functionParam293 = index;
#line 12
    sjt_functionParam294 = item;
#line 12
    sjf_array_vertex_location_texture_normal_setat(sjt_parent230, sjt_functionParam293, sjt_functionParam294);
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
#line 13 "lib/sj-lib-common/log.sj"
    _this->minlevel = _from->minlevel;
#line 13
    sjs_hash_type_bool* copyoption2 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption2 != 0) {
        _this->traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption2);
    } else {
        _this->traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption3 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption3 != 0) {
        _this->debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption3);
    } else {
        _this->debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption4 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption4 != 0) {
        _this->infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption4);
    } else {
        _this->infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption5 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption5 != 0) {
        _this->warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption5);
    } else {
        _this->warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption6 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption6 != 0) {
        _this->errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption6);
    } else {
        _this->errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption7 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption7 != 0) {
        _this->fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->fatalincludes, copyoption7);
    } else {
        _this->fatalincludes._refCount = -1;
    }
}

void sjf_log_destroy(sjs_log* _this) {
    if (_this->traceincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->traceincludes); }
;
    if (_this->debugincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->debugincludes); }
;
    if (_this->infoincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->infoincludes); }
;
    if (_this->warnincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->warnincludes); }
;
    if (_this->errorincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->errorincludes); }
;
    if (_this->fatalincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->fatalincludes); }
;
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_mainloop(void) {
    int32_option mouse_eventtype;
    bool mouse_isleftdown;
    int32_t mouse_x;
    int32_t mouse_y;
    sjs_rect rect = { -1 };
    bool result25;
    bool shouldappcontinue;
    bool shouldcontinue;
    sjs_size size = { -1 };
    sjs_string sjt_call170 = { -1 };
    sjs_string sjt_call171 = { -1 };
    sjs_string sjt_call172 = { -1 };
    bool sjt_capture85;
    int32_t sjt_functionParam668;
    sjs_size* sjt_functionParam672 = 0;
    sjs_rect* sjt_functionParam673 = 0;
    sjs_scene2d* sjt_interfaceParam21 = 0;
    sjs_animator* sjt_parent365 = 0;
    sjs_windowrenderer* sjt_parent367 = 0;
    sjs_scene2d* sjt_parent368 = 0;
    sjs_scene2d* sjt_parent369 = 0;
    sjs_rect* sjt_parent370 = 0;
    sji_element sjt_parent372 = { 0 };
    sjs_scene2d* sjt_parent373 = 0;
    sjs_windowrenderer* sjt_parent374 = 0;
    int32_t ticks;

#line 9 "lib/sj-lib-ui/loop.sj"
    shouldappcontinue = true;
#line 10
    ticks = 0;
#line 12
    ticks = SDL_GetTicks();
#line 31 "lib/sj-lib-ui/animation.sj"
    sjt_parent365 = &g_animator;
#line 14 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam668 = ticks;
#line 14
    sjf_animator_nextframe(sjt_parent365, sjt_functionParam668);
    if (g_mainloop_showfps) {
#line 17 "lib/sj-lib-ui/loop.sj"
        g_mainloop_frames = g_mainloop_frames + 1;
        if ((g_mainloop_lasttick + 1000) < ticks) {
            float fps;
            int32_t sjt_cast25;
            int32_t sjt_cast26;
            sjs_string* sjt_functionParam669 = 0;
            sjs_string* sjt_functionParam670 = 0;
            float sjt_functionParam671;
            sjs_string* sjt_parent366 = 0;

#line 19 "lib/sj-lib-ui/loop.sj"
            sjt_cast25 = g_mainloop_frames;
#line 19
            sjt_cast26 = ticks - g_mainloop_lasttick;
#line 19
            fps = ((float)sjt_cast25 * 1000.0f) / (float)sjt_cast26;
#line 19
            sjt_call171._refCount = 1;
#line 20
            sjt_call171.offset = 0;
#line 20
            sjt_call171.count = 5;
#line 20
            sjt_call171.data._refCount = 1;
#line 20
            sjt_call171.data.v = &sjg_string38;
#line 20
            sjf_array_char(&sjt_call171.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call171._isnullterminated = false;
#line 16
            sjf_string(&sjt_call171);
#line 20 "lib/sj-lib-ui/loop.sj"
            sjt_parent366 = &sjt_call171;
#line 20
            sjt_functionParam671 = fps;
#line 20
            sjf_f32_asstring(sjt_functionParam671, &sjt_call172);
#line 20
            sjt_functionParam670 = &sjt_call172;
#line 20
            sjf_string_add(sjt_parent366, sjt_functionParam670, &sjt_call170);
#line 20
            sjt_functionParam669 = &sjt_call170;
#line 20
            sjf_debug_writeline(sjt_functionParam669);
#line 21
            g_mainloop_lasttick = ticks;
#line 22
            g_mainloop_frames = 0;
        }
    }

#line 7 "lib/sj-lib-ui/windowRenderer.sj"
    sjt_parent367 = &g_rootwindowrenderer;
#line 7
    sjf_windowrenderer_getsize(sjt_parent367, &size);
#line 27 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent368 = &g_rootscene;
#line 27 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam672 = &size;
#line 27
    sjf_scene2d_setsize(sjt_parent368, sjt_functionParam672);
#line 8 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent369 = &g_rootscene;
#line 8
    sjf_scene2d_start(sjt_parent369);
#line 8
    rect._refCount = 1;
#line 29 "lib/sj-lib-ui/loop.sj"
    rect.x = 0;
#line 29
    rect.y = 0;
#line 29
    rect.w = (&size)->w;
#line 29
    rect.h = (&size)->h;
#line 29
    sjf_rect(&rect);
#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent370 = &g_looplastrect;
#line 30 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam673 = &rect;
#line 30
    sjf_rect_isequal(sjt_parent370, sjt_functionParam673, &sjt_capture85);
#line 30
    result25 = !sjt_capture85;
    if (result25) {
        sjs_rect* sjt_interfaceParam20 = 0;
        sji_element sjt_parent371 = { 0 };

#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent371 = g_root;
#line 31 "lib/sj-lib-ui/loop.sj"
        sjt_interfaceParam20 = &rect;
#line 31
        sjt_parent371._vtbl->setrect(sjt_parent371._parent, sjt_interfaceParam20);
    }

#line 5 "lib/sj-lib-ui/element.sj"
    sjt_parent372 = g_root;
#line 33 "lib/sj-lib-ui/loop.sj"
    sjt_interfaceParam21 = &g_rootscene;
#line 33
    sjt_parent372._vtbl->render(sjt_parent372._parent, sjt_interfaceParam21);
#line 19 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent373 = &g_rootscene;
#line 19
    sjf_scene2d_end(sjt_parent373);
#line 22 "lib/sj-lib-ui/windowRenderer.sj"
    sjt_parent374 = &g_rootwindowrenderer;
#line 22
    sjf_windowrenderer_present(sjt_parent374);
#line 38 "lib/sj-lib-ui/loop.sj"
    SDL_Event e;
#line 39
    while(SDL_PollEvent( &e ) != 0) {
#line 41
        mouse_eventtype = int32_empty;
#line 42
        mouse_x = 0;
#line 43
        mouse_y = 0;
#line 44
        mouse_isleftdown = false;
#line 47
        switch (e.type) {
#line 48
            case SDL_QUIT:
#line 49
            shouldappcontinue = false;
#line 50
            break;
#line 51
            case SDL_MOUSEBUTTONDOWN:
#line 52
            mouse_eventtype.isvalid = true;
#line 53
            mouse_eventtype.value = g_mouseeventtype_down;
#line 54
            mouse_x = e.button.x;
#line 55
            mouse_y = e.button.y;
#line 56
            mouse_isleftdown = e.button.state & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 57
            break;
#line 58
            case SDL_MOUSEBUTTONUP:
#line 59
            mouse_eventtype.isvalid = true;
#line 60
            mouse_eventtype.value = g_mouseeventtype_up;
#line 61
            mouse_x = e.button.x;
#line 62
            mouse_y = e.button.y;
#line 63
            mouse_isleftdown = e.button.state & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 64
            break;
#line 65
            case SDL_MOUSEMOTION:
#line 66
            mouse_eventtype.isvalid = true;
#line 67
            mouse_eventtype.value = g_mouseeventtype_move;
#line 68
            mouse_x = e.motion.x;
#line 69
            mouse_y = e.motion.y;
#line 70
            mouse_isleftdown = SDL_GetGlobalMouseState(0, 0) & SDL_BUTTON(SDL_BUTTON_LEFT);
#line 71
            break;
#line 72
        }
#line 75
        shouldcontinue = true;
        if (mouse_eventtype.isvalid) {
            int32_t ifValue39;
            int32_option sjt_getValue1;

#line 76 "lib/sj-lib-ui/loop.sj"
            sjt_getValue1 = mouse_eventtype;
#line 76
            ifValue39 = sjt_getValue1.value;
            if ((g_mouse_captureelement._parent != 0)) {
                sji_element ifValue40 = { 0 };
                sjs_mouseevent sjt_call173 = { -1 };
                bool sjt_funcold32;
                sjs_mouseevent* sjt_interfaceParam22 = 0;
                sji_element sjt_parent375 = { 0 };

#line 77 "lib/sj-lib-ui/loop.sj"
                ifValue40 = g_mouse_captureelement;
                if (ifValue40._parent != 0) {
                    ifValue40._parent->_refCount++;
                }

#line 6 "lib/sj-lib-ui/element.sj"
                sjt_parent375 = ifValue40;
#line 6
                sjt_funcold32 = shouldcontinue;
#line 6
                sjt_call173._refCount = 1;
#line 78 "lib/sj-lib-ui/loop.sj"
                sjt_call173.eventtype = ifValue39;
#line 78
                sjt_call173.point._refCount = 1;
#line 80
                sjt_call173.point.x = mouse_x;
#line 80
                sjt_call173.point.y = mouse_y;
#line 80
                sjf_point(&sjt_call173.point);
#line 81
                sjt_call173.iscaptured = true;
#line 78
                sjt_call173.isleftdown = mouse_isleftdown;
#line 78
                sjf_mouseevent(&sjt_call173);
#line 78
                sjt_interfaceParam22 = &sjt_call173;
#line 78
                sjt_parent375._vtbl->firemouseevent(sjt_parent375._parent, sjt_interfaceParam22, &sjt_funcold32);
#line 6 "lib/sj-lib-ui/element.sj"
                shouldcontinue = sjt_funcold32;

                if (ifValue40._parent != 0) {
                    ifValue40._parent->_refCount--;
                    if (ifValue40._parent->_refCount <= 0) {
                        ifValue40._vtbl->destroy(ifValue40._parent);
                        free(ifValue40._parent);
                    }
                }
                if (sjt_call173._refCount == 1) { sjf_mouseevent_destroy(&sjt_call173); }
;
            } else {
                sjs_mouseevent sjt_call174 = { -1 };
                bool sjt_funcold33;
                sjs_mouseevent* sjt_interfaceParam23 = 0;
                sji_element sjt_parent376 = { 0 };

#line 6 "lib/sj-lib-ui/element.sj"
                sjt_parent376 = g_root;
#line 6
                sjt_funcold33 = shouldcontinue;
#line 6
                sjt_call174._refCount = 1;
#line 86 "lib/sj-lib-ui/loop.sj"
                sjt_call174.eventtype = ifValue39;
#line 86
                sjt_call174.point._refCount = 1;
#line 88
                sjt_call174.point.x = mouse_x;
#line 88
                sjt_call174.point.y = mouse_y;
#line 88
                sjf_point(&sjt_call174.point);
#line 89
                sjt_call174.iscaptured = false;
#line 86
                sjt_call174.isleftdown = mouse_isleftdown;
#line 86
                sjf_mouseevent(&sjt_call174);
#line 86
                sjt_interfaceParam23 = &sjt_call174;
#line 86
                sjt_parent376._vtbl->firemouseevent(sjt_parent376._parent, sjt_interfaceParam23, &sjt_funcold33);
#line 6 "lib/sj-lib-ui/element.sj"
                shouldcontinue = sjt_funcold33;

                if (sjt_call174._refCount == 1) { sjf_mouseevent_destroy(&sjt_call174); }
;
            }
        }

#line 96
    }
#line 99
    g_mainloop_shouldcontinue = shouldappcontinue;

    if (rect._refCount == 1) { sjf_rect_destroy(&rect); }
;
    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
    if (sjt_call170._refCount == 1) { sjf_string_destroy(&sjt_call170); }
;
    if (sjt_call171._refCount == 1) { sjf_string_destroy(&sjt_call171); }
;
    if (sjt_call172._refCount == 1) { sjf_string_destroy(&sjt_call172); }
;
}

void sjf_margin(sjs_margin* _this) {
}

void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from) {
#line 1 "lib/sj-lib-ui/margin.sj"
    _this->l = _from->l;
#line 1
    _this->t = _from->t;
#line 1
    _this->r = _from->r;
#line 1
    _this->b = _from->b;
}

void sjf_margin_destroy(sjs_margin* _this) {
}

void sjf_margin_heap(sjs_margin* _this) {
}

void sjf_mat4(sjs_mat4* _this) {
}

void sjf_mat4_copy(sjs_mat4* _this, sjs_mat4* _from) {
#line 1 "lib/sj-lib-ui/mat4.sj"
    _this->m00 = _from->m00;
#line 1
    _this->m01 = _from->m01;
#line 1
    _this->m02 = _from->m02;
#line 1
    _this->m03 = _from->m03;
#line 1
    _this->m10 = _from->m10;
#line 1
    _this->m11 = _from->m11;
#line 1
    _this->m12 = _from->m12;
#line 1
    _this->m13 = _from->m13;
#line 1
    _this->m20 = _from->m20;
#line 1
    _this->m21 = _from->m21;
#line 1
    _this->m22 = _from->m22;
#line 1
    _this->m23 = _from->m23;
#line 1
    _this->m30 = _from->m30;
#line 1
    _this->m31 = _from->m31;
#line 1
    _this->m32 = _from->m32;
#line 1
    _this->m33 = _from->m33;
}

void sjf_mat4_destroy(sjs_mat4* _this) {
}

void sjf_mat4_determinant(sjs_mat4* _parent, float* _return) {
#line 95 "lib/sj-lib-ui/mat4.sj"
    (*_return) = (((((((((((((((((((((((((_parent->m03 * _parent->m12) * _parent->m21) * _parent->m30) - (((_parent->m02 * _parent->m13) * _parent->m21) * _parent->m30)) - (((_parent->m03 * _parent->m11) * _parent->m22) * _parent->m30)) + (((_parent->m01 * _parent->m13) * _parent->m22) * _parent->m30)) + (((_parent->m02 * _parent->m11) * _parent->m23) * _parent->m30)) - (((_parent->m01 * _parent->m12) * _parent->m23) * _parent->m30)) - (((_parent->m03 * _parent->m12) * _parent->m20) * _parent->m31)) + (((_parent->m02 * _parent->m13) * _parent->m20) * _parent->m31)) + (((_parent->m03 * _parent->m10) * _parent->m22) * _parent->m31)) - (((_parent->m00 * _parent->m13) * _parent->m22) * _parent->m31)) - (((_parent->m02 * _parent->m10) * _parent->m23) * _parent->m31)) + (((_parent->m00 * _parent->m12) * _parent->m23) * _parent->m31)) + (((_parent->m03 * _parent->m11) * _parent->m20) * _parent->m32)) - (((_parent->m01 * _parent->m13) * _parent->m20) * _parent->m32)) - (((_parent->m03 * _parent->m10) * _parent->m21) * _parent->m32)) + (((_parent->m00 * _parent->m13) * _parent->m21) * _parent->m32)) + (((_parent->m01 * _parent->m10) * _parent->m23) * _parent->m32)) - (((_parent->m00 * _parent->m11) * _parent->m23) * _parent->m32)) - (((_parent->m02 * _parent->m11) * _parent->m20) * _parent->m33)) + (((_parent->m01 * _parent->m12) * _parent->m20) * _parent->m33)) + (((_parent->m02 * _parent->m10) * _parent->m21) * _parent->m33)) - (((_parent->m00 * _parent->m12) * _parent->m21) * _parent->m33)) - (((_parent->m01 * _parent->m10) * _parent->m22) * _parent->m33)) + (((_parent->m00 * _parent->m11) * _parent->m22) * _parent->m33);
}

void sjf_mat4_heap(sjs_mat4* _this) {
}

void sjf_mat4_identity(sjs_mat4* _return) {
    _return->_refCount = 1;
#line 126 "lib/sj-lib-ui/mat4.sj"
    _return->m00 = 1.0f;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 127
    _return->m11 = 1.0f;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 128
    _return->m22 = 1.0f;
#line 13
    _return->m23 = 0.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 16
    _return->m32 = 0.0f;
#line 129
    _return->m33 = 1.0f;
#line 129
    sjf_mat4(_return);
}

void sjf_mat4_identity_heap(sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 126 "lib/sj-lib-ui/mat4.sj"
    (*_return)->m00 = 1.0f;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 127
    (*_return)->m11 = 1.0f;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 128
    (*_return)->m22 = 1.0f;
#line 13
    (*_return)->m23 = 0.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 16
    (*_return)->m32 = 0.0f;
#line 129
    (*_return)->m33 = 1.0f;
#line 129
    sjf_mat4_heap((*_return));
}

void sjf_mat4_invert(sjs_mat4* _parent, sjs_mat4* _return) {
    float sjt_capture48;
    float sjt_functionParam172;
    sjs_mat4* sjt_parent143 = 0;
    sjs_mat4 t = { -1 };

    t._refCount = 1;
#line 73 "lib/sj-lib-ui/mat4.sj"
    t.m00 = ((((((_parent->m12 * _parent->m23) * _parent->m31) - ((_parent->m13 * _parent->m22) * _parent->m31)) + ((_parent->m13 * _parent->m21) * _parent->m32)) - ((_parent->m11 * _parent->m23) * _parent->m32)) - ((_parent->m12 * _parent->m21) * _parent->m33)) + ((_parent->m11 * _parent->m22) * _parent->m33);
#line 74
    t.m01 = ((((((_parent->m03 * _parent->m22) * _parent->m31) - ((_parent->m02 * _parent->m23) * _parent->m31)) - ((_parent->m03 * _parent->m21) * _parent->m32)) + ((_parent->m01 * _parent->m23) * _parent->m32)) + ((_parent->m02 * _parent->m21) * _parent->m33)) - ((_parent->m01 * _parent->m22) * _parent->m33);
#line 75
    t.m02 = ((((((_parent->m02 * _parent->m13) * _parent->m31) - ((_parent->m03 * _parent->m12) * _parent->m31)) + ((_parent->m03 * _parent->m11) * _parent->m32)) - ((_parent->m01 * _parent->m13) * _parent->m32)) - ((_parent->m02 * _parent->m11) * _parent->m33)) + ((_parent->m01 * _parent->m12) * _parent->m33);
#line 76
    t.m03 = ((((((_parent->m03 * _parent->m12) * _parent->m21) - ((_parent->m02 * _parent->m13) * _parent->m21)) - ((_parent->m03 * _parent->m11) * _parent->m22)) + ((_parent->m01 * _parent->m13) * _parent->m22)) + ((_parent->m02 * _parent->m11) * _parent->m23)) - ((_parent->m01 * _parent->m12) * _parent->m23);
#line 77
    t.m10 = ((((((_parent->m13 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m23) * _parent->m30)) - ((_parent->m13 * _parent->m20) * _parent->m32)) + ((_parent->m10 * _parent->m23) * _parent->m32)) + ((_parent->m12 * _parent->m20) * _parent->m33)) - ((_parent->m10 * _parent->m22) * _parent->m33);
#line 78
    t.m11 = ((((((_parent->m02 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m22) * _parent->m30)) + ((_parent->m03 * _parent->m20) * _parent->m32)) - ((_parent->m00 * _parent->m23) * _parent->m32)) - ((_parent->m02 * _parent->m20) * _parent->m33)) + ((_parent->m00 * _parent->m22) * _parent->m33);
#line 79
    t.m12 = ((((((_parent->m03 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m13) * _parent->m30)) - ((_parent->m03 * _parent->m10) * _parent->m32)) + ((_parent->m00 * _parent->m13) * _parent->m32)) + ((_parent->m02 * _parent->m10) * _parent->m33)) - ((_parent->m00 * _parent->m12) * _parent->m33);
#line 80
    t.m13 = ((((((_parent->m02 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m12) * _parent->m20)) + ((_parent->m03 * _parent->m10) * _parent->m22)) - ((_parent->m00 * _parent->m13) * _parent->m22)) - ((_parent->m02 * _parent->m10) * _parent->m23)) + ((_parent->m00 * _parent->m12) * _parent->m23);
#line 81
    t.m20 = ((((((_parent->m11 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m21) * _parent->m30)) + ((_parent->m13 * _parent->m20) * _parent->m31)) - ((_parent->m10 * _parent->m23) * _parent->m31)) - ((_parent->m11 * _parent->m20) * _parent->m33)) + ((_parent->m10 * _parent->m21) * _parent->m33);
#line 82
    t.m21 = ((((((_parent->m03 * _parent->m21) * _parent->m30) - ((_parent->m01 * _parent->m23) * _parent->m30)) - ((_parent->m03 * _parent->m20) * _parent->m31)) + ((_parent->m00 * _parent->m23) * _parent->m31)) + ((_parent->m01 * _parent->m20) * _parent->m33)) - ((_parent->m00 * _parent->m21) * _parent->m33);
#line 83
    t.m22 = ((((((_parent->m01 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m11) * _parent->m30)) + ((_parent->m03 * _parent->m10) * _parent->m31)) - ((_parent->m00 * _parent->m13) * _parent->m31)) - ((_parent->m01 * _parent->m10) * _parent->m33)) + ((_parent->m00 * _parent->m11) * _parent->m33);
#line 84
    t.m23 = ((((((_parent->m03 * _parent->m11) * _parent->m20) - ((_parent->m01 * _parent->m13) * _parent->m20)) - ((_parent->m03 * _parent->m10) * _parent->m21)) + ((_parent->m00 * _parent->m13) * _parent->m21)) + ((_parent->m01 * _parent->m10) * _parent->m23)) - ((_parent->m00 * _parent->m11) * _parent->m23);
#line 85
    t.m30 = ((((((_parent->m12 * _parent->m21) * _parent->m30) - ((_parent->m11 * _parent->m22) * _parent->m30)) - ((_parent->m12 * _parent->m20) * _parent->m31)) + ((_parent->m10 * _parent->m22) * _parent->m31)) + ((_parent->m11 * _parent->m20) * _parent->m32)) - ((_parent->m10 * _parent->m21) * _parent->m32);
#line 86
    t.m31 = ((((((_parent->m01 * _parent->m22) * _parent->m30) - ((_parent->m02 * _parent->m21) * _parent->m30)) + ((_parent->m02 * _parent->m20) * _parent->m31)) - ((_parent->m00 * _parent->m22) * _parent->m31)) - ((_parent->m01 * _parent->m20) * _parent->m32)) + ((_parent->m00 * _parent->m21) * _parent->m32);
#line 87
    t.m32 = ((((((_parent->m02 * _parent->m11) * _parent->m30) - ((_parent->m01 * _parent->m12) * _parent->m30)) - ((_parent->m02 * _parent->m10) * _parent->m31)) + ((_parent->m00 * _parent->m12) * _parent->m31)) + ((_parent->m01 * _parent->m10) * _parent->m32)) - ((_parent->m00 * _parent->m11) * _parent->m32);
#line 88
    t.m33 = ((((((_parent->m01 * _parent->m12) * _parent->m20) - ((_parent->m02 * _parent->m11) * _parent->m20)) + ((_parent->m02 * _parent->m10) * _parent->m21)) - ((_parent->m00 * _parent->m12) * _parent->m21)) - ((_parent->m01 * _parent->m10) * _parent->m22)) + ((_parent->m00 * _parent->m11) * _parent->m22);
#line 88
    sjf_mat4(&t);
#line 40
    sjt_parent143 = &t;
#line 40
    sjf_mat4_determinant(_parent, &sjt_capture48);
#line 91
    sjt_functionParam172 = 1.0f / sjt_capture48;
#line 91
    sjf_mat4_multiplyf32(sjt_parent143, sjt_functionParam172, _return);

    if (t._refCount == 1) { sjf_mat4_destroy(&t); }
;
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    float sjt_capture49;
    float sjt_functionParam173;
    sjs_mat4* sjt_parent144 = 0;
    sjs_mat4 t = { -1 };

    t._refCount = 1;
#line 73 "lib/sj-lib-ui/mat4.sj"
    t.m00 = ((((((_parent->m12 * _parent->m23) * _parent->m31) - ((_parent->m13 * _parent->m22) * _parent->m31)) + ((_parent->m13 * _parent->m21) * _parent->m32)) - ((_parent->m11 * _parent->m23) * _parent->m32)) - ((_parent->m12 * _parent->m21) * _parent->m33)) + ((_parent->m11 * _parent->m22) * _parent->m33);
#line 74
    t.m01 = ((((((_parent->m03 * _parent->m22) * _parent->m31) - ((_parent->m02 * _parent->m23) * _parent->m31)) - ((_parent->m03 * _parent->m21) * _parent->m32)) + ((_parent->m01 * _parent->m23) * _parent->m32)) + ((_parent->m02 * _parent->m21) * _parent->m33)) - ((_parent->m01 * _parent->m22) * _parent->m33);
#line 75
    t.m02 = ((((((_parent->m02 * _parent->m13) * _parent->m31) - ((_parent->m03 * _parent->m12) * _parent->m31)) + ((_parent->m03 * _parent->m11) * _parent->m32)) - ((_parent->m01 * _parent->m13) * _parent->m32)) - ((_parent->m02 * _parent->m11) * _parent->m33)) + ((_parent->m01 * _parent->m12) * _parent->m33);
#line 76
    t.m03 = ((((((_parent->m03 * _parent->m12) * _parent->m21) - ((_parent->m02 * _parent->m13) * _parent->m21)) - ((_parent->m03 * _parent->m11) * _parent->m22)) + ((_parent->m01 * _parent->m13) * _parent->m22)) + ((_parent->m02 * _parent->m11) * _parent->m23)) - ((_parent->m01 * _parent->m12) * _parent->m23);
#line 77
    t.m10 = ((((((_parent->m13 * _parent->m22) * _parent->m30) - ((_parent->m12 * _parent->m23) * _parent->m30)) - ((_parent->m13 * _parent->m20) * _parent->m32)) + ((_parent->m10 * _parent->m23) * _parent->m32)) + ((_parent->m12 * _parent->m20) * _parent->m33)) - ((_parent->m10 * _parent->m22) * _parent->m33);
#line 78
    t.m11 = ((((((_parent->m02 * _parent->m23) * _parent->m30) - ((_parent->m03 * _parent->m22) * _parent->m30)) + ((_parent->m03 * _parent->m20) * _parent->m32)) - ((_parent->m00 * _parent->m23) * _parent->m32)) - ((_parent->m02 * _parent->m20) * _parent->m33)) + ((_parent->m00 * _parent->m22) * _parent->m33);
#line 79
    t.m12 = ((((((_parent->m03 * _parent->m12) * _parent->m30) - ((_parent->m02 * _parent->m13) * _parent->m30)) - ((_parent->m03 * _parent->m10) * _parent->m32)) + ((_parent->m00 * _parent->m13) * _parent->m32)) + ((_parent->m02 * _parent->m10) * _parent->m33)) - ((_parent->m00 * _parent->m12) * _parent->m33);
#line 80
    t.m13 = ((((((_parent->m02 * _parent->m13) * _parent->m20) - ((_parent->m03 * _parent->m12) * _parent->m20)) + ((_parent->m03 * _parent->m10) * _parent->m22)) - ((_parent->m00 * _parent->m13) * _parent->m22)) - ((_parent->m02 * _parent->m10) * _parent->m23)) + ((_parent->m00 * _parent->m12) * _parent->m23);
#line 81
    t.m20 = ((((((_parent->m11 * _parent->m23) * _parent->m30) - ((_parent->m13 * _parent->m21) * _parent->m30)) + ((_parent->m13 * _parent->m20) * _parent->m31)) - ((_parent->m10 * _parent->m23) * _parent->m31)) - ((_parent->m11 * _parent->m20) * _parent->m33)) + ((_parent->m10 * _parent->m21) * _parent->m33);
#line 82
    t.m21 = ((((((_parent->m03 * _parent->m21) * _parent->m30) - ((_parent->m01 * _parent->m23) * _parent->m30)) - ((_parent->m03 * _parent->m20) * _parent->m31)) + ((_parent->m00 * _parent->m23) * _parent->m31)) + ((_parent->m01 * _parent->m20) * _parent->m33)) - ((_parent->m00 * _parent->m21) * _parent->m33);
#line 83
    t.m22 = ((((((_parent->m01 * _parent->m13) * _parent->m30) - ((_parent->m03 * _parent->m11) * _parent->m30)) + ((_parent->m03 * _parent->m10) * _parent->m31)) - ((_parent->m00 * _parent->m13) * _parent->m31)) - ((_parent->m01 * _parent->m10) * _parent->m33)) + ((_parent->m00 * _parent->m11) * _parent->m33);
#line 84
    t.m23 = ((((((_parent->m03 * _parent->m11) * _parent->m20) - ((_parent->m01 * _parent->m13) * _parent->m20)) - ((_parent->m03 * _parent->m10) * _parent->m21)) + ((_parent->m00 * _parent->m13) * _parent->m21)) + ((_parent->m01 * _parent->m10) * _parent->m23)) - ((_parent->m00 * _parent->m11) * _parent->m23);
#line 85
    t.m30 = ((((((_parent->m12 * _parent->m21) * _parent->m30) - ((_parent->m11 * _parent->m22) * _parent->m30)) - ((_parent->m12 * _parent->m20) * _parent->m31)) + ((_parent->m10 * _parent->m22) * _parent->m31)) + ((_parent->m11 * _parent->m20) * _parent->m32)) - ((_parent->m10 * _parent->m21) * _parent->m32);
#line 86
    t.m31 = ((((((_parent->m01 * _parent->m22) * _parent->m30) - ((_parent->m02 * _parent->m21) * _parent->m30)) + ((_parent->m02 * _parent->m20) * _parent->m31)) - ((_parent->m00 * _parent->m22) * _parent->m31)) - ((_parent->m01 * _parent->m20) * _parent->m32)) + ((_parent->m00 * _parent->m21) * _parent->m32);
#line 87
    t.m32 = ((((((_parent->m02 * _parent->m11) * _parent->m30) - ((_parent->m01 * _parent->m12) * _parent->m30)) - ((_parent->m02 * _parent->m10) * _parent->m31)) + ((_parent->m00 * _parent->m12) * _parent->m31)) + ((_parent->m01 * _parent->m10) * _parent->m32)) - ((_parent->m00 * _parent->m11) * _parent->m32);
#line 88
    t.m33 = ((((((_parent->m01 * _parent->m12) * _parent->m20) - ((_parent->m02 * _parent->m11) * _parent->m20)) + ((_parent->m02 * _parent->m10) * _parent->m21)) - ((_parent->m00 * _parent->m12) * _parent->m21)) - ((_parent->m01 * _parent->m10) * _parent->m22)) + ((_parent->m00 * _parent->m11) * _parent->m22);
#line 88
    sjf_mat4(&t);
#line 40
    sjt_parent144 = &t;
#line 40
    sjf_mat4_determinant(_parent, &sjt_capture49);
#line 91
    sjt_functionParam173 = 1.0f / sjt_capture49;
#line 91
    sjf_mat4_multiplyf32_heap(sjt_parent144, sjt_functionParam173, _return);

    if (t._refCount == 1) { sjf_mat4_destroy(&t); }
;
}

void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call11 = { -1 };
    float sjt_capture22;
    float sjt_capture23;
    float sjt_capture24;
    sjs_vec3* sjt_functionParam78 = 0;
    sjs_vec3* sjt_functionParam81 = 0;
    sjs_vec3* sjt_functionParam82 = 0;
    sjs_vec3* sjt_functionParam83 = 0;
    sjs_vec3* sjt_functionParam84 = 0;
    sjs_vec3* sjt_functionParam85 = 0;
    sjs_vec3* sjt_parent72 = 0;
    sjs_vec3* sjt_parent73 = 0;
    sjs_vec3* sjt_parent74 = 0;
    sjs_vec3* sjt_parent75 = 0;
    sjs_vec3* sjt_parent76 = 0;
    sjs_vec3* sjt_parent77 = 0;
    sjs_vec3* sjt_parent78 = 0;
    sjs_vec3* sjt_parent79 = 0;
    sjs_vec3 temp = { -1 };
    sjs_vec3 xaxis = { -1 };
    sjs_vec3 yaxis = { -1 };
    sjs_vec3 zaxis = { -1 };

#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_parent72 = target;
#line 133
    sjt_functionParam78 = camera;
#line 133
    sjf_vec3_subtract(sjt_parent72, sjt_functionParam78, &temp);
#line 38 "lib/sj-lib-ui/vec3.sj"
    sjt_parent73 = &temp;
#line 38
    sjf_vec3_normalize(sjt_parent73, &zaxis);
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_parent75 = up;
#line 136
    sjt_functionParam81 = &zaxis;
#line 136
    sjf_vec3_cross(sjt_parent75, sjt_functionParam81, &sjt_call11);
#line 136
    sjt_parent74 = &sjt_call11;
#line 136
    sjf_vec3_normalize(sjt_parent74, &xaxis);
#line 47 "lib/sj-lib-ui/vec3.sj"
    sjt_parent76 = &zaxis;
#line 137 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam82 = &xaxis;
#line 137
    sjf_vec3_cross(sjt_parent76, sjt_functionParam82, &yaxis);
#line 137
    _return->_refCount = 1;
#line 138
    _return->m00 = (&xaxis)->x;
#line 138
    _return->m01 = (&yaxis)->x;
#line 138
    _return->m02 = (&zaxis)->x;
#line 142
    _return->m03 = 0.0f;
#line 138
    _return->m10 = (&xaxis)->y;
#line 138
    _return->m11 = (&yaxis)->y;
#line 138
    _return->m12 = (&zaxis)->y;
#line 146
    _return->m13 = 0.0f;
#line 138
    _return->m20 = (&xaxis)->z;
#line 138
    _return->m21 = (&yaxis)->z;
#line 138
    _return->m22 = (&zaxis)->z;
#line 150
    _return->m23 = 0.0f;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent77 = &xaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam83 = camera;
#line 133
    sjf_vec3_dot(sjt_parent77, sjt_functionParam83, &sjt_capture22);
#line 151
    _return->m30 = 0.0f - sjt_capture22;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent78 = &yaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam84 = camera;
#line 133
    sjf_vec3_dot(sjt_parent78, sjt_functionParam84, &sjt_capture23);
#line 152
    _return->m31 = 0.0f - sjt_capture23;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent79 = &zaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam85 = camera;
#line 133
    sjf_vec3_dot(sjt_parent79, sjt_functionParam85, &sjt_capture24);
#line 153
    _return->m32 = 0.0f - sjt_capture24;
#line 154
    _return->m33 = 1.0f;
#line 154
    sjf_mat4(_return);

    if (sjt_call11._refCount == 1) { sjf_vec3_destroy(&sjt_call11); }
;
    if (temp._refCount == 1) { sjf_vec3_destroy(&temp); }
;
    if (xaxis._refCount == 1) { sjf_vec3_destroy(&xaxis); }
;
    if (yaxis._refCount == 1) { sjf_vec3_destroy(&yaxis); }
;
    if (zaxis._refCount == 1) { sjf_vec3_destroy(&zaxis); }
;
}

void sjf_mat4_lookatlh_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4** _return) {
    sjs_vec3 sjt_call12 = { -1 };
    float sjt_capture25;
    float sjt_capture26;
    float sjt_capture27;
    sjs_vec3* sjt_functionParam86 = 0;
    sjs_vec3* sjt_functionParam87 = 0;
    sjs_vec3* sjt_functionParam88 = 0;
    sjs_vec3* sjt_functionParam89 = 0;
    sjs_vec3* sjt_functionParam90 = 0;
    sjs_vec3* sjt_functionParam91 = 0;
    sjs_vec3* sjt_parent80 = 0;
    sjs_vec3* sjt_parent81 = 0;
    sjs_vec3* sjt_parent82 = 0;
    sjs_vec3* sjt_parent83 = 0;
    sjs_vec3* sjt_parent84 = 0;
    sjs_vec3* sjt_parent85 = 0;
    sjs_vec3* sjt_parent86 = 0;
    sjs_vec3* sjt_parent87 = 0;
    sjs_vec3 temp = { -1 };
    sjs_vec3 xaxis = { -1 };
    sjs_vec3 yaxis = { -1 };
    sjs_vec3 zaxis = { -1 };

#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_parent80 = target;
#line 133
    sjt_functionParam86 = camera;
#line 133
    sjf_vec3_subtract(sjt_parent80, sjt_functionParam86, &temp);
#line 38 "lib/sj-lib-ui/vec3.sj"
    sjt_parent81 = &temp;
#line 38
    sjf_vec3_normalize(sjt_parent81, &zaxis);
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_parent83 = up;
#line 136
    sjt_functionParam87 = &zaxis;
#line 136
    sjf_vec3_cross(sjt_parent83, sjt_functionParam87, &sjt_call12);
#line 136
    sjt_parent82 = &sjt_call12;
#line 136
    sjf_vec3_normalize(sjt_parent82, &xaxis);
#line 47 "lib/sj-lib-ui/vec3.sj"
    sjt_parent84 = &zaxis;
#line 137 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam88 = &xaxis;
#line 137
    sjf_vec3_cross(sjt_parent84, sjt_functionParam88, &yaxis);
#line 137
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
#line 137
    (*_return)->_refCount = 1;
#line 138
    (*_return)->m00 = (&xaxis)->x;
#line 138
    (*_return)->m01 = (&yaxis)->x;
#line 138
    (*_return)->m02 = (&zaxis)->x;
#line 142
    (*_return)->m03 = 0.0f;
#line 138
    (*_return)->m10 = (&xaxis)->y;
#line 138
    (*_return)->m11 = (&yaxis)->y;
#line 138
    (*_return)->m12 = (&zaxis)->y;
#line 146
    (*_return)->m13 = 0.0f;
#line 138
    (*_return)->m20 = (&xaxis)->z;
#line 138
    (*_return)->m21 = (&yaxis)->z;
#line 138
    (*_return)->m22 = (&zaxis)->z;
#line 150
    (*_return)->m23 = 0.0f;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent85 = &xaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam89 = camera;
#line 133
    sjf_vec3_dot(sjt_parent85, sjt_functionParam89, &sjt_capture25);
#line 151
    (*_return)->m30 = 0.0f - sjt_capture25;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent86 = &yaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam90 = camera;
#line 133
    sjf_vec3_dot(sjt_parent86, sjt_functionParam90, &sjt_capture26);
#line 152
    (*_return)->m31 = 0.0f - sjt_capture26;
#line 55 "lib/sj-lib-ui/vec3.sj"
    sjt_parent87 = &zaxis;
#line 133 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam91 = camera;
#line 133
    sjf_vec3_dot(sjt_parent87, sjt_functionParam91, &sjt_capture27);
#line 153
    (*_return)->m32 = 0.0f - sjt_capture27;
#line 154
    (*_return)->m33 = 1.0f;
#line 154
    sjf_mat4_heap((*_return));

    if (sjt_call12._refCount == 1) { sjf_vec3_destroy(&sjt_call12); }
;
    if (temp._refCount == 1) { sjf_vec3_destroy(&temp); }
;
    if (xaxis._refCount == 1) { sjf_vec3_destroy(&xaxis); }
;
    if (yaxis._refCount == 1) { sjf_vec3_destroy(&yaxis); }
;
    if (zaxis._refCount == 1) { sjf_vec3_destroy(&zaxis); }
;
}

void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return) {
    _return->_refCount = 1;
#line 21 "lib/sj-lib-ui/mat4.sj"
    _return->m00 = (((m->m00 * _parent->m00) + (m->m01 * _parent->m10)) + (m->m02 * _parent->m20)) + (m->m03 * _parent->m30);
#line 22
    _return->m01 = (((m->m00 * _parent->m01) + (m->m01 * _parent->m11)) + (m->m02 * _parent->m21)) + (m->m03 * _parent->m31);
#line 23
    _return->m02 = (((m->m00 * _parent->m02) + (m->m01 * _parent->m12)) + (m->m02 * _parent->m22)) + (m->m03 * _parent->m32);
#line 24
    _return->m03 = (((m->m00 * _parent->m03) + (m->m01 * _parent->m13)) + (m->m02 * _parent->m23)) + (m->m03 * _parent->m33);
#line 25
    _return->m10 = (((m->m10 * _parent->m00) + (m->m11 * _parent->m10)) + (m->m12 * _parent->m20)) + (m->m13 * _parent->m30);
#line 26
    _return->m11 = (((m->m10 * _parent->m01) + (m->m11 * _parent->m11)) + (m->m12 * _parent->m21)) + (m->m13 * _parent->m31);
#line 27
    _return->m12 = (((m->m10 * _parent->m02) + (m->m11 * _parent->m12)) + (m->m12 * _parent->m22)) + (m->m13 * _parent->m32);
#line 28
    _return->m13 = (((m->m10 * _parent->m03) + (m->m11 * _parent->m13)) + (m->m12 * _parent->m23)) + (m->m13 * _parent->m33);
#line 29
    _return->m20 = (((m->m20 * _parent->m00) + (m->m21 * _parent->m10)) + (m->m22 * _parent->m20)) + (m->m23 * _parent->m30);
#line 30
    _return->m21 = (((m->m20 * _parent->m01) + (m->m21 * _parent->m11)) + (m->m22 * _parent->m21)) + (m->m23 * _parent->m31);
#line 31
    _return->m22 = (((m->m20 * _parent->m02) + (m->m21 * _parent->m12)) + (m->m22 * _parent->m22)) + (m->m23 * _parent->m32);
#line 32
    _return->m23 = (((m->m20 * _parent->m03) + (m->m21 * _parent->m13)) + (m->m22 * _parent->m23)) + (m->m23 * _parent->m33);
#line 33
    _return->m30 = (((m->m30 * _parent->m00) + (m->m31 * _parent->m10)) + (m->m32 * _parent->m20)) + (m->m33 * _parent->m30);
#line 34
    _return->m31 = (((m->m30 * _parent->m01) + (m->m31 * _parent->m11)) + (m->m32 * _parent->m21)) + (m->m33 * _parent->m31);
#line 35
    _return->m32 = (((m->m30 * _parent->m02) + (m->m31 * _parent->m12)) + (m->m32 * _parent->m22)) + (m->m33 * _parent->m32);
#line 36
    _return->m33 = (((m->m30 * _parent->m03) + (m->m31 * _parent->m13)) + (m->m32 * _parent->m23)) + (m->m33 * _parent->m33);
#line 36
    sjf_mat4(_return);
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 21 "lib/sj-lib-ui/mat4.sj"
    (*_return)->m00 = (((m->m00 * _parent->m00) + (m->m01 * _parent->m10)) + (m->m02 * _parent->m20)) + (m->m03 * _parent->m30);
#line 22
    (*_return)->m01 = (((m->m00 * _parent->m01) + (m->m01 * _parent->m11)) + (m->m02 * _parent->m21)) + (m->m03 * _parent->m31);
#line 23
    (*_return)->m02 = (((m->m00 * _parent->m02) + (m->m01 * _parent->m12)) + (m->m02 * _parent->m22)) + (m->m03 * _parent->m32);
#line 24
    (*_return)->m03 = (((m->m00 * _parent->m03) + (m->m01 * _parent->m13)) + (m->m02 * _parent->m23)) + (m->m03 * _parent->m33);
#line 25
    (*_return)->m10 = (((m->m10 * _parent->m00) + (m->m11 * _parent->m10)) + (m->m12 * _parent->m20)) + (m->m13 * _parent->m30);
#line 26
    (*_return)->m11 = (((m->m10 * _parent->m01) + (m->m11 * _parent->m11)) + (m->m12 * _parent->m21)) + (m->m13 * _parent->m31);
#line 27
    (*_return)->m12 = (((m->m10 * _parent->m02) + (m->m11 * _parent->m12)) + (m->m12 * _parent->m22)) + (m->m13 * _parent->m32);
#line 28
    (*_return)->m13 = (((m->m10 * _parent->m03) + (m->m11 * _parent->m13)) + (m->m12 * _parent->m23)) + (m->m13 * _parent->m33);
#line 29
    (*_return)->m20 = (((m->m20 * _parent->m00) + (m->m21 * _parent->m10)) + (m->m22 * _parent->m20)) + (m->m23 * _parent->m30);
#line 30
    (*_return)->m21 = (((m->m20 * _parent->m01) + (m->m21 * _parent->m11)) + (m->m22 * _parent->m21)) + (m->m23 * _parent->m31);
#line 31
    (*_return)->m22 = (((m->m20 * _parent->m02) + (m->m21 * _parent->m12)) + (m->m22 * _parent->m22)) + (m->m23 * _parent->m32);
#line 32
    (*_return)->m23 = (((m->m20 * _parent->m03) + (m->m21 * _parent->m13)) + (m->m22 * _parent->m23)) + (m->m23 * _parent->m33);
#line 33
    (*_return)->m30 = (((m->m30 * _parent->m00) + (m->m31 * _parent->m10)) + (m->m32 * _parent->m20)) + (m->m33 * _parent->m30);
#line 34
    (*_return)->m31 = (((m->m30 * _parent->m01) + (m->m31 * _parent->m11)) + (m->m32 * _parent->m21)) + (m->m33 * _parent->m31);
#line 35
    (*_return)->m32 = (((m->m30 * _parent->m02) + (m->m31 * _parent->m12)) + (m->m32 * _parent->m22)) + (m->m33 * _parent->m32);
#line 36
    (*_return)->m33 = (((m->m30 * _parent->m03) + (m->m31 * _parent->m13)) + (m->m32 * _parent->m23)) + (m->m33 * _parent->m33);
#line 36
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
    _return->_refCount = 1;
#line 42 "lib/sj-lib-ui/mat4.sj"
    _return->m00 = _parent->m00 * x;
#line 43
    _return->m01 = _parent->m01 * x;
#line 44
    _return->m02 = _parent->m02 * x;
#line 45
    _return->m03 = _parent->m03 * x;
#line 46
    _return->m10 = _parent->m10 * x;
#line 47
    _return->m11 = _parent->m11 * x;
#line 48
    _return->m12 = _parent->m12 * x;
#line 49
    _return->m13 = _parent->m13 * x;
#line 50
    _return->m20 = _parent->m20 * x;
#line 51
    _return->m21 = _parent->m21 * x;
#line 52
    _return->m22 = _parent->m22 * x;
#line 53
    _return->m23 = _parent->m23 * x;
#line 54
    _return->m30 = _parent->m30 * x;
#line 55
    _return->m31 = _parent->m31 * x;
#line 56
    _return->m32 = _parent->m32 * x;
#line 57
    _return->m33 = _parent->m33 * x;
#line 57
    sjf_mat4(_return);
}

void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 42 "lib/sj-lib-ui/mat4.sj"
    (*_return)->m00 = _parent->m00 * x;
#line 43
    (*_return)->m01 = _parent->m01 * x;
#line 44
    (*_return)->m02 = _parent->m02 * x;
#line 45
    (*_return)->m03 = _parent->m03 * x;
#line 46
    (*_return)->m10 = _parent->m10 * x;
#line 47
    (*_return)->m11 = _parent->m11 * x;
#line 48
    (*_return)->m12 = _parent->m12 * x;
#line 49
    (*_return)->m13 = _parent->m13 * x;
#line 50
    (*_return)->m20 = _parent->m20 * x;
#line 51
    (*_return)->m21 = _parent->m21 * x;
#line 52
    (*_return)->m22 = _parent->m22 * x;
#line 53
    (*_return)->m23 = _parent->m23 * x;
#line 54
    (*_return)->m30 = _parent->m30 * x;
#line 55
    (*_return)->m31 = _parent->m31 * x;
#line 56
    (*_return)->m32 = _parent->m32 * x;
#line 57
    (*_return)->m33 = _parent->m33 * x;
#line 57
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return) {
    _return->_refCount = 1;
#line 64 "lib/sj-lib-ui/mat4.sj"
    _return->x = (((_parent->m00 * v->x) + (_parent->m10 * v->y)) + (_parent->m20 * v->z)) + (_parent->m30 * v->w);
#line 65
    _return->y = (((_parent->m01 * v->x) + (_parent->m11 * v->y)) + (_parent->m21 * v->z)) + (_parent->m31 * v->w);
#line 66
    _return->z = (((_parent->m02 * v->x) + (_parent->m12 * v->y)) + (_parent->m22 * v->z)) + (_parent->m32 * v->w);
#line 67
    _return->w = (((_parent->m03 * v->x) + (_parent->m13 * v->y)) + (_parent->m23 * v->z)) + (_parent->m33 * v->w);
#line 67
    sjf_vec4(_return);
}

void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return) {
    (*_return) = (sjs_vec4*)malloc(sizeof(sjs_vec4));
    (*_return)->_refCount = 1;
#line 64 "lib/sj-lib-ui/mat4.sj"
    (*_return)->x = (((_parent->m00 * v->x) + (_parent->m10 * v->y)) + (_parent->m20 * v->z)) + (_parent->m30 * v->w);
#line 65
    (*_return)->y = (((_parent->m01 * v->x) + (_parent->m11 * v->y)) + (_parent->m21 * v->z)) + (_parent->m31 * v->w);
#line 66
    (*_return)->z = (((_parent->m02 * v->x) + (_parent->m12 * v->y)) + (_parent->m22 * v->z)) + (_parent->m32 * v->w);
#line 67
    (*_return)->w = (((_parent->m03 * v->x) + (_parent->m13 * v->y)) + (_parent->m23 * v->z)) + (_parent->m33 * v->w);
#line 67
    sjf_vec4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result17;

    _return->_refCount = 1;
#line 172 "lib/sj-lib-ui/mat4.sj"
    _return->m00 = 2.0f / (right - left);
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 174
    _return->m11 = 2.0f / (top - bottom);
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 176
    result17 = -2.0f;
#line 176
    _return->m22 = result17 / (zfar - znear);
#line 13
    _return->m23 = 0.0f;
#line 173
    _return->m30 = 0.0f - ((right + left) / (right - left));
#line 175
    _return->m31 = 0.0f - ((top + bottom) / (top - bottom));
#line 177
    _return->m32 = 0.0f - ((zfar + znear) / (zfar - znear));
#line 178
    _return->m33 = 1.0f;
#line 178
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result18;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 172 "lib/sj-lib-ui/mat4.sj"
    (*_return)->m00 = 2.0f / (right - left);
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 174
    (*_return)->m11 = 2.0f / (top - bottom);
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 176
    result18 = -2.0f;
#line 176
    (*_return)->m22 = result18 / (zfar - znear);
#line 13
    (*_return)->m23 = 0.0f;
#line 173
    (*_return)->m30 = 0.0f - ((right + left) / (right - left));
#line 175
    (*_return)->m31 = 0.0f - ((top + bottom) / (top - bottom));
#line 177
    (*_return)->m32 = 0.0f - ((zfar + znear) / (zfar - znear));
#line 178
    (*_return)->m33 = 1.0f;
#line 178
    sjf_mat4_heap((*_return));
}

void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return) {
    float sjt_capture20;
    float sjt_functionParam72;
    float xscale;
    float yscale;

#line 159 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam72 = (fovy / 180.0f) / 2.0f;
#line 159
    sjf_f32_tan(sjt_functionParam72, &sjt_capture20);
#line 159
    yscale = 1.0f / sjt_capture20;
#line 160
    xscale = yscale * aspect;
#line 160
    _return->_refCount = 1;
#line 161
    _return->m00 = xscale;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 161
    _return->m11 = yscale;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 164
    _return->m22 = zfar / (zfar - znear);
#line 165
    _return->m23 = 1.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 166
    _return->m32 = 0.0f - ((znear * zfar) / (zfar - znear));
#line 17
    _return->m33 = 0.0f;
#line 17
    sjf_mat4(_return);
}

void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4** _return) {
    float sjt_capture21;
    float sjt_functionParam73;
    float xscale;
    float yscale;

#line 159 "lib/sj-lib-ui/mat4.sj"
    sjt_functionParam73 = (fovy / 180.0f) / 2.0f;
#line 159
    sjf_f32_tan(sjt_functionParam73, &sjt_capture21);
#line 159
    yscale = 1.0f / sjt_capture21;
#line 160
    xscale = yscale * aspect;
#line 160
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
#line 160
    (*_return)->_refCount = 1;
#line 161
    (*_return)->m00 = xscale;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 161
    (*_return)->m11 = yscale;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 164
    (*_return)->m22 = zfar / (zfar - znear);
#line 165
    (*_return)->m23 = 1.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 166
    (*_return)->m32 = 0.0f - ((znear * zfar) / (zfar - znear));
#line 17
    (*_return)->m33 = 0.0f;
#line 17
    sjf_mat4_heap((*_return));
}

void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return) {
    _return->_refCount = 1;
#line 213 "lib/sj-lib-ui/mat4.sj"
    _return->m00 = x;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 213
    _return->m11 = y;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 213
    _return->m22 = z;
#line 13
    _return->m23 = 0.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 16
    _return->m32 = 0.0f;
#line 218
    _return->m33 = 1.0f;
#line 218
    sjf_mat4(_return);
}

void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 213 "lib/sj-lib-ui/mat4.sj"
    (*_return)->m00 = x;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 213
    (*_return)->m11 = y;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 213
    (*_return)->m22 = z;
#line 13
    (*_return)->m23 = 0.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 16
    (*_return)->m32 = 0.0f;
#line 218
    (*_return)->m33 = 1.0f;
#line 218
    sjf_mat4_heap((*_return));
}

void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return) {
    _return->_refCount = 1;
#line 99 "lib/sj-lib-ui/mat4.sj"
    _return->m00 = _parent->m00;
#line 99
    _return->m01 = _parent->m10;
#line 99
    _return->m02 = _parent->m20;
#line 99
    _return->m03 = _parent->m30;
#line 99
    _return->m10 = _parent->m01;
#line 99
    _return->m11 = _parent->m11;
#line 99
    _return->m12 = _parent->m21;
#line 99
    _return->m13 = _parent->m31;
#line 99
    _return->m20 = _parent->m02;
#line 99
    _return->m21 = _parent->m12;
#line 99
    _return->m22 = _parent->m22;
#line 99
    _return->m23 = _parent->m32;
#line 99
    _return->m30 = _parent->m03;
#line 99
    _return->m31 = _parent->m13;
#line 99
    _return->m32 = _parent->m23;
#line 99
    _return->m33 = _parent->m33;
#line 99
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
#line 99 "lib/sj-lib-ui/mat4.sj"
    (*_return)->m00 = _parent->m00;
#line 99
    (*_return)->m01 = _parent->m10;
#line 99
    (*_return)->m02 = _parent->m20;
#line 99
    (*_return)->m03 = _parent->m30;
#line 99
    (*_return)->m10 = _parent->m01;
#line 99
    (*_return)->m11 = _parent->m11;
#line 99
    (*_return)->m12 = _parent->m21;
#line 99
    (*_return)->m13 = _parent->m31;
#line 99
    (*_return)->m20 = _parent->m02;
#line 99
    (*_return)->m21 = _parent->m12;
#line 99
    (*_return)->m22 = _parent->m22;
#line 99
    (*_return)->m23 = _parent->m32;
#line 99
    (*_return)->m30 = _parent->m03;
#line 99
    (*_return)->m31 = _parent->m13;
#line 99
    (*_return)->m32 = _parent->m23;
#line 99
    (*_return)->m33 = _parent->m33;
#line 99
    sjf_mat4_heap((*_return));
}

void sjf_model_as_sji_model(sjs_model* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_model_model_vtbl;
}

void sjf_model_asinterface(sjs_model* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_model_as_sji_model(_this, (sji_model*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_model_copy(sjs_model* _this, sjs_model* _from) {
    _this->vertexbuffer._refCount = 1;
#line 15 "lib/sj-lib-ui/model.sj"
    sjf_vertexbuffer_vertex_location_texture_normal_copy(&_this->vertexbuffer, &_from->vertexbuffer);
#line 15
    _this->shader._refCount = 1;
#line 15
    sjf_shader_copy(&_this->shader, &_from->shader);
#line 15
    _this->texture._refCount = 1;
#line 15
    sjf_texture_copy(&_this->texture, &_from->texture);
#line 15
    _this->model._refCount = 1;
#line 15
    sjf_mat4_copy(&_this->model, &_from->model);
#line 15
    _this->center._refCount = 1;
#line 15
    sjf_vec3_copy(&_this->center, &_from->center);
#line 15
    _this->hasalpha = _from->hasalpha;
#line 15
    sjs_string* copyoption16 = (_from->id._refCount != -1 ? &_from->id : 0);
    if (copyoption16 != 0) {
        _this->id._refCount = 1;
#line 15 "lib/sj-lib-ui/model.sj"
        sjf_string_copy(&_this->id, copyoption16);
    } else {
        _this->id._refCount = -1;
    }

#line 15
    _this->_projection._refCount = 1;
#line 15
    sjf_mat4_copy(&_this->_projection, &_from->_projection);
#line 15
    _this->_view._refCount = 1;
#line 15
    sjf_mat4_copy(&_this->_view, &_from->_view);
#line 15
    _this->_world._refCount = 1;
#line 15
    sjf_mat4_copy(&_this->_world, &_from->_world);
#line 15
    _this->_light._refCount = 1;
#line 15
    sjf_light_copy(&_this->_light, &_from->_light);
#line 15
    _this->_projectedcenter._refCount = 1;
#line 15
    sjf_vec3_copy(&_this->_projectedcenter, &_from->_projectedcenter);
}

void sjf_model_destroy(sjs_model* _this) {
    if (_this->vertexbuffer._refCount == 1) { sjf_vertexbuffer_vertex_location_texture_normal_destroy(&_this->vertexbuffer); }
;
    if (_this->shader._refCount == 1) { sjf_shader_destroy(&_this->shader); }
;
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    if (_this->model._refCount == 1) { sjf_mat4_destroy(&_this->model); }
;
    if (_this->center._refCount == 1) { sjf_vec3_destroy(&_this->center); }
;
    if (_this->id._refCount == 1) { sjf_string_destroy(&_this->id); }
;
    if (_this->_projection._refCount == 1) { sjf_mat4_destroy(&_this->_projection); }
;
    if (_this->_view._refCount == 1) { sjf_mat4_destroy(&_this->_view); }
;
    if (_this->_world._refCount == 1) { sjf_mat4_destroy(&_this->_world); }
;
    if (_this->_light._refCount == 1) { sjf_light_destroy(&_this->_light); }
;
    if (_this->_projectedcenter._refCount == 1) { sjf_vec3_destroy(&_this->_projectedcenter); }
;
}

void sjf_model_firemouseevent(sjs_model* _parent, sjs_mouseevent* mouseevent) {
}

void sjf_model_getcenter(sjs_model* _parent, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 41 "lib/sj-lib-ui/model.sj"
    sjf_vec3_copy(_return, &_parent->center);
}

void sjf_model_getcenter_heap(sjs_model* _parent, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 41 "lib/sj-lib-ui/model.sj"
    sjf_vec3_copy((*_return), &_parent->center);
}

void sjf_model_getclasstype(sjs_object* _this, int* _return) {
    *_return = 182;
}

void sjf_model_getworld(sjs_model* _parent, sjs_mat4* _return) {
    sjs_mat4* sjt_functionParam160 = 0;
    sjs_mat4* sjt_parent130 = 0;

#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent130 = &_parent->_world;
#line 42 "lib/sj-lib-ui/model.sj"
    sjt_functionParam160 = &_parent->model;
#line 42
    sjf_mat4_multiply(sjt_parent130, sjt_functionParam160, _return);
}

void sjf_model_getworld_heap(sjs_model* _parent, sjs_mat4** _return) {
    sjs_mat4* sjt_functionParam161 = 0;
    sjs_mat4* sjt_parent131 = 0;

#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent131 = &_parent->_world;
#line 42 "lib/sj-lib-ui/model.sj"
    sjt_functionParam161 = &_parent->model;
#line 42
    sjf_mat4_multiply_heap(sjt_parent131, sjt_functionParam161, _return);
}

void sjf_model_getz(sjs_model* _parent, float* _return) {
#line 40 "lib/sj-lib-ui/model.sj"
    (*_return) = (&_parent->_projectedcenter)->z;
}

void sjf_model_heap(sjs_model* _this, sjs_model** _return) {
    if (((_this->id._refCount != -1 ? &_this->id : 0) != 0)) {
        sjs_string* ifValue8 = 0;
        sjs_model* sjt_cast11 = 0;
        sjs_string* sjt_functionParam149 = 0;
        sji_model sjt_functionParam150 = { 0 };
        sjs_hash_string_weak_iface_model* sjt_parent126 = 0;

#line 72 "lib/sj-lib-ui/model.sj"
        ifValue8 = (_this->id._refCount != -1 ? &_this->id : 0);
#line 38 "lib/sj-lib-common/hash.sj"
        sjt_parent126 = &g_modelsbyid;
#line 73 "lib/sj-lib-ui/model.sj"
        sjt_functionParam149 = ifValue8;
#line 15
        sjt_cast11 = _this;
#line 1
        sjf_model_as_sji_model(sjt_cast11, &sjt_functionParam150);
#line 1
        delete_cb weakptrcb18 = { &sjt_functionParam150._parent, weakptr_clear };
#line 1
        if (sjt_functionParam150._parent != 0) { weakptr_cb_add(sjt_functionParam150._parent, weakptrcb18); }
#line 1
        sjf_hash_string_weak_iface_model_setat(sjt_parent126, sjt_functionParam149, sjt_functionParam150);

        delete_cb weakptrcb29 = { &sjt_functionParam150._parent, weakptr_clear };
        if (sjt_functionParam150._parent != 0) { weakptr_cb_remove(sjt_functionParam150._parent, weakptrcb29); }
    }

#line 15 "lib/sj-lib-ui/model.sj"
    (*_return) = _this;
#line 15
    (*_return)->_refCount++;
}

void sjf_model_render(sjs_model* _parent) {
    sjs_mat4 normalmat = { -1 };
    sjs_mat4 sjt_call19 = { -1 };
    sjs_string sjt_call20 = { -1 };
    sjs_string sjt_call21 = { -1 };
    sjs_string sjt_call22 = { -1 };
    sjs_string sjt_call23 = { -1 };
    sjs_string sjt_call24 = { -1 };
    sjs_vec3 sjt_call25 = { -1 };
    sjs_string sjt_call26 = { -1 };
    sjs_vec3 sjt_call27 = { -1 };
    sjs_mat4* sjt_functionParam170 = 0;
    sjs_mat4* sjt_functionParam171 = 0;
    sjs_shader* sjt_functionParam174 = 0;
    int32_t sjt_functionParam175;
    int32_t sjt_functionParam176;
    int32_t sjt_functionParam177;
    sjs_texture* sjt_functionParam178 = 0;
    int32_t sjt_functionParam179;
    sjs_shader* sjt_functionParam180 = 0;
    sjs_string* sjt_functionParam181 = 0;
    sjs_mat4* sjt_functionParam182 = 0;
    int32_t sjt_functionParam183;
    sjs_shader* sjt_functionParam184 = 0;
    sjs_string* sjt_functionParam185 = 0;
    sjs_mat4* sjt_functionParam186 = 0;
    int32_t sjt_functionParam187;
    sjs_shader* sjt_functionParam188 = 0;
    sjs_string* sjt_functionParam189 = 0;
    sjs_mat4* sjt_functionParam190 = 0;
    int32_t sjt_functionParam191;
    sjs_shader* sjt_functionParam192 = 0;
    sjs_string* sjt_functionParam193 = 0;
    sjs_vec3* sjt_functionParam194 = 0;
    int32_t sjt_functionParam195;
    sjs_shader* sjt_functionParam196 = 0;
    sjs_string* sjt_functionParam197 = 0;
    sjs_vec3* sjt_functionParam198 = 0;
    int32_t sjt_functionParam199;
    sjs_shader* sjt_functionParam200 = 0;
    sjs_string* sjt_functionParam201 = 0;
    sjs_vec3* sjt_functionParam202 = 0;
    int32_t sjt_functionParam203;
    sjs_mat4* sjt_parent140 = 0;
    sjs_mat4* sjt_parent141 = 0;
    sjs_mat4* sjt_parent142 = 0;
    sjs_mat4* sjt_parent145 = 0;
    sjs_color* sjt_parent146 = 0;
    sjs_color* sjt_parent147 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent148 = 0;
    sjs_mat4 viewworld = { -1 };
    sjs_mat4 world = { -1 };

#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent140 = &_parent->_world;
#line 53 "lib/sj-lib-ui/model.sj"
    sjt_functionParam170 = &_parent->model;
#line 53
    sjf_mat4_multiply(sjt_parent140, sjt_functionParam170, &world);
#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent141 = &_parent->_view;
#line 54 "lib/sj-lib-ui/model.sj"
    sjt_functionParam171 = &world;
#line 54
    sjf_mat4_multiply(sjt_parent141, sjt_functionParam171, &viewworld);
#line 71 "lib/sj-lib-ui/mat4.sj"
    sjt_parent145 = &viewworld;
#line 71
    sjf_mat4_invert(sjt_parent145, &sjt_call19);
#line 55 "lib/sj-lib-ui/model.sj"
    sjt_parent142 = &sjt_call19;
#line 55
    sjf_mat4_transpose(sjt_parent142, &normalmat);
#line 56
    sjt_functionParam174 = &_parent->shader;
#line 56
    sjf_gluseprogram(sjt_functionParam174);
#line 57
    sjt_functionParam175 = g_glblendfunctype_gl_src_alpha;
#line 57
    sjt_functionParam176 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 57
    sjf_glblendfunc(sjt_functionParam175, sjt_functionParam176);
#line 58
    sjt_functionParam177 = g_gltexture_gl_texture_2d;
#line 58
    sjt_functionParam178 = &_parent->texture;
#line 58
    sjf_glbindtexture(sjt_functionParam177, sjt_functionParam178);
#line 59
    sjt_functionParam180 = &_parent->shader;
#line 59
    sjt_call20._refCount = 1;
#line 59
    sjt_call20.offset = 0;
#line 59
    sjt_call20.count = 9;
#line 59
    sjt_call20.data._refCount = 1;
#line 59
    sjt_call20.data.v = &sjg_string17;
#line 59
    sjf_array_char(&sjt_call20.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call20._isnullterminated = false;
#line 16
    sjf_string(&sjt_call20);
#line 59 "lib/sj-lib-ui/model.sj"
    sjt_functionParam181 = &sjt_call20;
#line 59
    sjf_glgetuniformlocation(sjt_functionParam180, sjt_functionParam181, &sjt_functionParam179);
#line 59
    sjt_functionParam182 = &viewworld;
#line 59
    sjf_gluniformmat4(sjt_functionParam179, sjt_functionParam182);
#line 60
    sjt_functionParam184 = &_parent->shader;
#line 60
    sjt_call21._refCount = 1;
#line 60
    sjt_call21.offset = 0;
#line 60
    sjt_call21.count = 9;
#line 60
    sjt_call21.data._refCount = 1;
#line 60
    sjt_call21.data.v = &sjg_string18;
#line 60
    sjf_array_char(&sjt_call21.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call21._isnullterminated = false;
#line 16
    sjf_string(&sjt_call21);
#line 60 "lib/sj-lib-ui/model.sj"
    sjt_functionParam185 = &sjt_call21;
#line 60
    sjf_glgetuniformlocation(sjt_functionParam184, sjt_functionParam185, &sjt_functionParam183);
#line 60
    sjt_functionParam186 = &normalmat;
#line 60
    sjf_gluniformmat4(sjt_functionParam183, sjt_functionParam186);
#line 61
    sjt_functionParam188 = &_parent->shader;
#line 61
    sjt_call22._refCount = 1;
#line 61
    sjt_call22.offset = 0;
#line 61
    sjt_call22.count = 10;
#line 61
    sjt_call22.data._refCount = 1;
#line 61
    sjt_call22.data.v = &sjg_string19;
#line 61
    sjf_array_char(&sjt_call22.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call22._isnullterminated = false;
#line 16
    sjf_string(&sjt_call22);
#line 61 "lib/sj-lib-ui/model.sj"
    sjt_functionParam189 = &sjt_call22;
#line 61
    sjf_glgetuniformlocation(sjt_functionParam188, sjt_functionParam189, &sjt_functionParam187);
#line 61
    sjt_functionParam190 = &_parent->_projection;
#line 61
    sjf_gluniformmat4(sjt_functionParam187, sjt_functionParam190);
#line 62
    sjt_functionParam192 = &_parent->shader;
#line 62
    sjt_call23._refCount = 1;
#line 62
    sjt_call23.offset = 0;
#line 62
    sjt_call23.count = 8;
#line 62
    sjt_call23.data._refCount = 1;
#line 62
    sjt_call23.data.v = &sjg_string20;
#line 62
    sjf_array_char(&sjt_call23.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call23._isnullterminated = false;
#line 16
    sjf_string(&sjt_call23);
#line 62 "lib/sj-lib-ui/model.sj"
    sjt_functionParam193 = &sjt_call23;
#line 62
    sjf_glgetuniformlocation(sjt_functionParam192, sjt_functionParam193, &sjt_functionParam191);
#line 62
    sjt_functionParam194 = &(&_parent->_light)->pos;
#line 62
    sjf_gluniformvec3(sjt_functionParam191, sjt_functionParam194);
#line 63
    sjt_functionParam196 = &_parent->shader;
#line 63
    sjt_call24._refCount = 1;
#line 63
    sjt_call24.offset = 0;
#line 63
    sjt_call24.count = 12;
#line 63
    sjt_call24.data._refCount = 1;
#line 63
    sjt_call24.data.v = &sjg_string21;
#line 63
    sjf_array_char(&sjt_call24.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call24._isnullterminated = false;
#line 16
    sjf_string(&sjt_call24);
#line 63 "lib/sj-lib-ui/model.sj"
    sjt_functionParam197 = &sjt_call24;
#line 63
    sjf_glgetuniformlocation(sjt_functionParam196, sjt_functionParam197, &sjt_functionParam195);
#line 20 "lib/sj-lib-ui/color.sj"
    sjt_parent146 = &(&_parent->_light)->diffusecolor;
#line 20
    sjf_color_asvec3(sjt_parent146, &sjt_call25);
#line 63 "lib/sj-lib-ui/model.sj"
    sjt_functionParam198 = &sjt_call25;
#line 63
    sjf_gluniformvec3(sjt_functionParam195, sjt_functionParam198);
#line 64
    sjt_functionParam200 = &_parent->shader;
#line 64
    sjt_call26._refCount = 1;
#line 64
    sjt_call26.offset = 0;
#line 64
    sjt_call26.count = 9;
#line 64
    sjt_call26.data._refCount = 1;
#line 64
    sjt_call26.data.v = &sjg_string22;
#line 64
    sjf_array_char(&sjt_call26.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call26._isnullterminated = false;
#line 16
    sjf_string(&sjt_call26);
#line 64 "lib/sj-lib-ui/model.sj"
    sjt_functionParam201 = &sjt_call26;
#line 64
    sjf_glgetuniformlocation(sjt_functionParam200, sjt_functionParam201, &sjt_functionParam199);
#line 20 "lib/sj-lib-ui/color.sj"
    sjt_parent147 = &(&_parent->_light)->speccolor;
#line 20
    sjf_color_asvec3(sjt_parent147, &sjt_call27);
#line 64 "lib/sj-lib-ui/model.sj"
    sjt_functionParam202 = &sjt_call27;
#line 64
    sjf_gluniformvec3(sjt_functionParam199, sjt_functionParam202);
#line 94 "lib/sj-lib-ui/vertexBuffer.sj"
    sjt_parent148 = &_parent->vertexbuffer;
#line 65 "lib/sj-lib-ui/model.sj"
    sjt_functionParam203 = g_gldrawmode_gl_triangles;
#line 65
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent148, sjt_functionParam203);

    if (normalmat._refCount == 1) { sjf_mat4_destroy(&normalmat); }
;
    if (sjt_call19._refCount == 1) { sjf_mat4_destroy(&sjt_call19); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_vec3_destroy(&sjt_call25); }
;
    if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
;
    if (sjt_call27._refCount == 1) { sjf_vec3_destroy(&sjt_call27); }
;
    if (viewworld._refCount == 1) { sjf_mat4_destroy(&viewworld); }
;
    if (world._refCount == 1) { sjf_mat4_destroy(&world); }
;
}

void sjf_model_renderorqueue(sjs_model* _parent, sjs_list_heap_iface_model* zqueue) {
    if (_parent->hasalpha) {
        sjs_model* sjt_cast12 = 0;
        sji_model sjt_functionParam169 = { 0 };
        sjs_list_heap_iface_model* sjt_parent139 = 0;

#line 44 "lib/sj-lib-ui/model.sj"
        sjt_parent139 = zqueue;
#line 46
        sjt_cast12 = _parent;
#line 1
        sjf_model_as_sji_model(sjt_cast12, &sjt_functionParam169);
        if (sjt_functionParam169._parent != 0) {
            sjt_functionParam169._parent->_refCount++;
        }

#line 1
        sjf_list_heap_iface_model_add(sjt_parent139, sjt_functionParam169);

        if (sjt_functionParam169._parent != 0) {
            sjt_functionParam169._parent->_refCount--;
            if (sjt_functionParam169._parent->_refCount <= 0) {
                sjt_functionParam169._vtbl->destroy(sjt_functionParam169._parent);
                free(sjt_functionParam169._parent);
            }
        }
    } else {
        sjf_model_render(_parent);
    }
}

void sjf_model_update(sjs_model* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    sjs_mat4 sjt_call16 = { -1 };
    sjs_mat4 sjt_call17 = { -1 };
    sjs_vec4 sjt_call18 = { -1 };
    sjs_vec3 sjt_funcold13 = { -1 };
    sjs_mat4* sjt_functionParam157 = 0;
    sjs_mat4* sjt_functionParam158 = 0;
    sjs_vec4* sjt_functionParam159 = 0;
    sjs_mat4* sjt_parent127 = 0;
    sjs_mat4* sjt_parent128 = 0;
    sjs_mat4* sjt_parent129 = 0;
    sjs_vec4 t2 = { -1 };

    if (_parent->_projection._refCount == 1) { sjf_mat4_destroy(&_parent->_projection); }
;
#line 30 "lib/sj-lib-ui/model.sj"
    sjf_mat4_copy(&_parent->_projection, projection);
#line 30
    if (_parent->_view._refCount == 1) { sjf_mat4_destroy(&_parent->_view); }
;
#line 30
    sjf_mat4_copy(&_parent->_view, view);
#line 30
    if (_parent->_world._refCount == 1) { sjf_mat4_destroy(&_parent->_world); }
;
#line 30
    sjf_mat4_copy(&_parent->_world, world);
#line 19 "lib/sj-lib-ui/mat4.sj"
    sjt_parent129 = &_parent->_view;
#line 34 "lib/sj-lib-ui/model.sj"
    sjt_functionParam157 = &_parent->_world;
#line 34
    sjf_mat4_multiply(sjt_parent129, sjt_functionParam157, &sjt_call17);
#line 34
    sjt_parent128 = &sjt_call17;
#line 34
    sjt_functionParam158 = &_parent->model;
#line 34
    sjf_mat4_multiply(sjt_parent128, sjt_functionParam158, &sjt_call16);
#line 34
    sjt_parent127 = &sjt_call16;
#line 34
    sjt_call18._refCount = 1;
#line 34
    sjt_call18.x = (&_parent->center)->x;
#line 34
    sjt_call18.y = (&_parent->center)->y;
#line 34
    sjt_call18.z = (&_parent->center)->z;
#line 34
    sjt_call18.w = 1.0f;
#line 34
    sjf_vec4(&sjt_call18);
#line 34
    sjt_functionParam159 = &sjt_call18;
#line 34
    sjf_mat4_multiplyvec4(sjt_parent127, sjt_functionParam159, &t2);
#line 34
    sjt_funcold13._refCount = 1;
#line 35
    sjt_funcold13.x = (&t2)->x / (&t2)->w;
#line 35
    sjt_funcold13.y = (&t2)->y / (&t2)->w;
#line 35
    sjt_funcold13.z = (&t2)->z / (&t2)->w;
#line 35
    sjf_vec3(&sjt_funcold13);
#line 35
    if (_parent->_projectedcenter._refCount == 1) { sjf_vec3_destroy(&_parent->_projectedcenter); }
;
#line 1 "lib/sj-lib-ui/vec3.sj"
    sjf_vec3_copy(&_parent->_projectedcenter, &sjt_funcold13);
#line 1
    if (_parent->_light._refCount == 1) { sjf_light_destroy(&_parent->_light); }
;
#line 30 "lib/sj-lib-ui/model.sj"
    sjf_light_copy(&_parent->_light, light);

    if (sjt_call16._refCount == 1) { sjf_mat4_destroy(&sjt_call16); }
;
    if (sjt_call17._refCount == 1) { sjf_mat4_destroy(&sjt_call17); }
;
    if (sjt_call18._refCount == 1) { sjf_vec4_destroy(&sjt_call18); }
;
    if (sjt_funcold13._refCount == 1) { sjf_vec3_destroy(&sjt_funcold13); }
;
    if (t2._refCount == 1) { sjf_vec4_destroy(&t2); }
;
}

void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return) {
    float sjt_functionParam132;
    float sjt_functionParam133;
    sji_model sjt_parent104 = { 0 };
    sji_model sjt_parent105 = { 0 };

#line 11 "lib/sj-lib-ui/model.sj"
    sjt_parent104 = l;
#line 12
    sjt_parent104._vtbl->getz(sjt_parent104._parent, &sjt_functionParam132);
#line 11
    sjt_parent105 = r;
#line 12
    sjt_parent105._vtbl->getz(sjt_parent105._parent, &sjt_functionParam133);
#line 12
    sjf_f32_compare(sjt_functionParam132, sjt_functionParam133, _return);
}

void sjf_model_zsort_callback(void * _parent, sji_model l, sji_model r, int32_t* _return) {
    sjf_model_zsort(l, r, _return);
}

void sjf_mouseevent(sjs_mouseevent* _this) {
}

void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from) {
#line 38 "lib/sj-lib-ui/mouse.sj"
    _this->eventtype = _from->eventtype;
#line 38
    _this->point._refCount = 1;
#line 38
    sjf_point_copy(&_this->point, &_from->point);
#line 38
    _this->iscaptured = _from->iscaptured;
#line 38
    _this->isleftdown = _from->isleftdown;
}

void sjf_mouseevent_destroy(sjs_mouseevent* _this) {
    if (_this->point._refCount == 1) { sjf_point_destroy(&_this->point); }
;
}

void sjf_mouseevent_firechildren(sjs_mouseevent* _parent, sjs_array_heap_iface_element* children, bool* _return) {
    int32_t i;
    bool shouldcontinue;
    int32_t sjt_forEnd7;
    int32_t sjt_forStart7;
    sjs_array_heap_iface_element* sjt_parent37 = 0;

#line 45 "lib/sj-lib-ui/mouse.sj"
    shouldcontinue = true;
#line 46
    sjt_forStart7 = 0;
#line 44
    sjt_parent37 = children;
#line 44
    sjf_array_heap_iface_element_getcount(sjt_parent37, &sjt_forEnd7);
#line 46
    i = sjt_forEnd7 - 1;
    while (i >= sjt_forStart7) {
        if (shouldcontinue) {
            sji_element child = { 0 };
            bool sjt_funcold4;
            int32_t sjt_functionParam43;
            sjs_mouseevent* sjt_interfaceParam3 = 0;
            sjs_array_heap_iface_element* sjt_parent38 = 0;
            sji_element sjt_parent39 = { 0 };

#line 44 "lib/sj-lib-ui/mouse.sj"
            sjt_parent38 = children;
#line 46
            sjt_functionParam43 = i;
#line 46
            sjf_array_heap_iface_element_getat_heap(sjt_parent38, sjt_functionParam43, &child);
#line 6 "lib/sj-lib-ui/element.sj"
            sjt_parent39 = child;
#line 6
            sjt_funcold4 = shouldcontinue;
#line 49 "lib/sj-lib-ui/mouse.sj"
            sjt_interfaceParam3 = _parent;
#line 49
            sjt_parent39._vtbl->firemouseevent(sjt_parent39._parent, sjt_interfaceParam3, &sjt_funcold4);
#line 6 "lib/sj-lib-ui/element.sj"
            shouldcontinue = sjt_funcold4;

            if (child._parent != 0) {
                child._parent->_refCount--;
                if (child._parent->_refCount <= 0) {
                    child._vtbl->destroy(child._parent);
                    free(child._parent);
                }
            }
        }

#line 46 "lib/sj-lib-ui/mouse.sj"
        i--;
    }

#line 44
    (*_return) = shouldcontinue;
}

void sjf_mouseevent_heap(sjs_mouseevent* _this) {
}

void sjf_point(sjs_point* _this) {
}

void sjf_point_copy(sjs_point* _this, sjs_point* _from) {
#line 1 "lib/sj-lib-ui/point.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
}

void sjf_point_destroy(sjs_point* _this) {
}

void sjf_point_heap(sjs_point* _this) {
}

void sjf_rect(sjs_rect* _this) {
}

void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from) {
#line 1 "lib/sj-lib-ui/rect.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->w = _from->w;
#line 1
    _this->h = _from->h;
}

void sjf_rect_destroy(sjs_rect* _this) {
}

void sjf_rect_heap(sjs_rect* _this) {
}

void sjf_rect_isequal(sjs_rect* _parent, sjs_rect* rect, bool* _return) {
    if (_parent->x == rect->x) {
        bool sjt_capture16;

        if (_parent->y == rect->y) {
            bool sjt_capture17;

            if (_parent->w == rect->w) {
#line 16 "lib/sj-lib-ui/rect.sj"
                sjt_capture17 = (_parent->h == rect->h);
            } else {
#line 16 "lib/sj-lib-ui/rect.sj"
                sjt_capture17 = false;
            }

#line 16 "lib/sj-lib-ui/rect.sj"
            sjt_capture16 = sjt_capture17;
        } else {
#line 16 "lib/sj-lib-ui/rect.sj"
            sjt_capture16 = false;
        }

#line 16 "lib/sj-lib-ui/rect.sj"
        (*_return) = sjt_capture16;
    } else {
#line 16 "lib/sj-lib-ui/rect.sj"
        (*_return) = false;
    }
}

void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    _return->_refCount = 1;
#line 8 "lib/sj-lib-ui/rect.sj"
    _return->x = _parent->x + margin->l;
#line 8
    _return->y = _parent->y + margin->t;
#line 8
    _return->w = (_parent->w - margin->l) - margin->r;
#line 8
    _return->h = (_parent->h - margin->t) - margin->b;
#line 8
    sjf_rect(_return);
}

void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 8 "lib/sj-lib-ui/rect.sj"
    (*_return)->x = _parent->x + margin->l;
#line 8
    (*_return)->y = _parent->y + margin->t;
#line 8
    (*_return)->w = (_parent->w - margin->l) - margin->r;
#line 8
    (*_return)->h = (_parent->h - margin->t) - margin->b;
#line 8
    sjf_rect_heap((*_return));
}

void sjf_renderbuffer(sjs_renderbuffer* _this) {
}

void sjf_renderbuffer_copy(sjs_renderbuffer* _this, sjs_renderbuffer* _from) {
    _this->size._refCount = 1;
#line 1 "lib/sj-lib-ui/renderbuffer.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 8
    _this->id = _from->id;
#line 9
    glid_retain(_this->id);
}

void sjf_renderbuffer_destroy(sjs_renderbuffer* _this) {
#line 13 "lib/sj-lib-ui/renderbuffer.sj"
    if (glid_release(_this->id)) {
#line 14
        glDeleteRenderbuffers(1, &_this->id);
#line 15
    }
#line 15
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
}

void sjf_renderbuffer_heap(sjs_renderbuffer* _this) {
}

void sjf_runloop(void) {
#line 105 "lib/sj-lib-ui/loop.sj"
    #ifdef EMSCRIPTEN
#line 106
    emscripten_set_main_loop((em_callback_func)sjf_mainloop, 0, 0);
#line 107
    exit(0);
#line 108
    #else
#line 109
    while (g_mainloop_shouldcontinue) {
#line 110
        sjf_mainloop();
#line 111
    }
#line 112
    #endif 
}

void sjf_saturateeffect(sjs_saturateeffect* _this) {
}

void sjf_saturateeffect_as_sji_effect(sjs_saturateeffect* _this, sji_effect* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_saturateeffect_effect_vtbl;
}

void sjf_saturateeffect_asinterface(sjs_saturateeffect* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_effect_typeId:  {
            sjf_saturateeffect_as_sji_effect(_this, (sji_effect*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_saturateeffect_copy(sjs_saturateeffect* _this, sjs_saturateeffect* _from) {
#line 3 "lib/sj-lib-ui/saturateEffect.sj"
    _this->amount = _from->amount;
#line 3
    _this->_rect._refCount = 1;
#line 3
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 3
    sjs_boxvertexbuffer* copyoption33 = (_from->_vertexbuffer._refCount != -1 ? &_from->_vertexbuffer : 0);
    if (copyoption33 != 0) {
        _this->_vertexbuffer._refCount = 1;
#line 3 "lib/sj-lib-ui/saturateEffect.sj"
        sjf_boxvertexbuffer_copy(&_this->_vertexbuffer, copyoption33);
    } else {
        _this->_vertexbuffer._refCount = -1;
    }

#line 3
    sjs_scenebuffer* copyoption34 = (_from->_scenebuffer._refCount != -1 ? &_from->_scenebuffer : 0);
    if (copyoption34 != 0) {
        _this->_scenebuffer._refCount = 1;
#line 3 "lib/sj-lib-ui/saturateEffect.sj"
        sjf_scenebuffer_copy(&_this->_scenebuffer, copyoption34);
    } else {
        _this->_scenebuffer._refCount = -1;
    }

#line 3
    _this->_innerscene._refCount = 1;
#line 3
    sjf_scene2d_copy(&_this->_innerscene, &_from->_innerscene);
}

void sjf_saturateeffect_destroy(sjs_saturateeffect* _this) {
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_this->_vertexbuffer); }
;
    if (_this->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_this->_scenebuffer); }
;
    if (_this->_innerscene._refCount == 1) { sjf_scene2d_destroy(&_this->_innerscene); }
;
}

void sjf_saturateeffect_getclasstype(sjs_object* _this, int* _return) {
    *_return = 315;
}

void sjf_saturateeffect_getrect(sjs_saturateeffect* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 10 "lib/sj-lib-ui/saturateEffect.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_saturateeffect_getrect_heap(sjs_saturateeffect* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 10 "lib/sj-lib-ui/saturateEffect.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_saturateeffect_heap(sjs_saturateeffect* _this) {
}

void sjf_saturateeffect_render(sjs_saturateeffect* _parent, sjs_scene2d* scene, cb_scene2d_void cb) {
    sjs_boxvertexbuffer sjt_value13 = { -1 };
    sjs_scenebuffer sjt_value14 = { -1 };

    if ((_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0) == 0) {
        sjt_value13._refCount = 1;
        sjt_value13.rect._refCount = 1;
#line 32 "lib/sj-lib-ui/saturateEffect.sj"
        sjf_rect_copy(&sjt_value13.rect, &_parent->_rect);
#line 32
        sjf_boxvertexbuffer(&sjt_value13);
#line 32
        if (_parent->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer); }
;
#line 32
        sjs_boxvertexbuffer* copyoption35 = &sjt_value13;
        if (copyoption35 != 0) {
            _parent->_vertexbuffer._refCount = 1;
#line 32 "lib/sj-lib-ui/saturateEffect.sj"
            sjf_boxvertexbuffer_copy(&_parent->_vertexbuffer, copyoption35);
        } else {
            _parent->_vertexbuffer._refCount = -1;
        }
    }

    if ((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) == 0) {
        sjt_value14._refCount = 1;
        sjt_value14.size._refCount = 1;
#line 39 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_value14.size.w = (&_parent->_rect)->w;
#line 39
        sjt_value14.size.h = (&_parent->_rect)->h;
#line 39
        sjf_size(&sjt_value14.size);
#line 39
        sjt_value14.framebuffer._refCount = 1;
#line 39
        sjt_value14.framebuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
        sjt_value14.framebuffer.size.w = 0;
#line 3
        sjt_value14.framebuffer.size.h = 0;
#line 3
        sjf_size(&sjt_value14.framebuffer.size);
#line 3 "lib/sj-lib-ui/framebuffer.sj"
        sjt_value14.framebuffer.id = (uint32_t)0u;
#line 3
        sjf_framebuffer(&sjt_value14.framebuffer);
#line 3
        sjt_value14.texture._refCount = 1;
#line 3
        sjt_value14.texture.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
        sjt_value14.texture.size.w = 0;
#line 3
        sjt_value14.texture.size.h = 0;
#line 3
        sjf_size(&sjt_value14.texture.size);
#line 3 "lib/sj-lib-ui/texture.sj"
        sjt_value14.texture.id = (uint32_t)0u;
#line 3
        sjf_texture(&sjt_value14.texture);
#line 3
        sjt_value14.renderbuffer._refCount = 1;
#line 3
        sjt_value14.renderbuffer.size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
        sjt_value14.renderbuffer.size.w = 0;
#line 3
        sjt_value14.renderbuffer.size.h = 0;
#line 3
        sjf_size(&sjt_value14.renderbuffer.size);
#line 3 "lib/sj-lib-ui/renderbuffer.sj"
        sjt_value14.renderbuffer.id = (uint32_t)0u;
#line 3
        sjf_renderbuffer(&sjt_value14.renderbuffer);
#line 3
        sjf_scenebuffer(&sjt_value14);
#line 3
        if (_parent->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer); }
;
#line 39 "lib/sj-lib-ui/saturateEffect.sj"
        sjs_scenebuffer* copyoption36 = &sjt_value14;
        if (copyoption36 != 0) {
            _parent->_scenebuffer._refCount = 1;
#line 39 "lib/sj-lib-ui/saturateEffect.sj"
            sjf_scenebuffer_copy(&_parent->_scenebuffer, copyoption36);
        } else {
            _parent->_scenebuffer._refCount = -1;
        }
    }

    if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) != 0) && ((_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0) != 0)) {
        sjs_scenebuffer* ifValue35 = 0;
        sjs_boxvertexbuffer* ifValue36 = 0;
        sjs_string sjt_call161 = { -1 };
        sjs_string sjt_call162 = { -1 };
        sjs_string sjt_call163 = { -1 };
        sjs_string sjt_call164 = { -1 };
        sjs_string sjt_call165 = { -1 };
        sjs_framebuffer* sjt_functionParam627 = 0;
        sjs_size* sjt_functionParam628 = 0;
        sjs_scene2d* sjt_functionParam629 = 0;
        sjs_framebuffer* sjt_functionParam630 = 0;
        int32_t sjt_functionParam631;
        sjs_texture* sjt_functionParam632 = 0;
        sjs_shader* sjt_functionParam633 = 0;
        int32_t sjt_functionParam634;
        int32_t sjt_functionParam635;
        int32_t sjt_functionParam636;
        sjs_shader* sjt_functionParam637 = 0;
        sjs_string* sjt_functionParam638 = 0;
        int32_t sjt_functionParam639;
        int32_t sjt_functionParam640;
        sjs_shader* sjt_functionParam641 = 0;
        sjs_string* sjt_functionParam642 = 0;
        float sjt_functionParam643;
        int32_t sjt_functionParam644;
        sjs_shader* sjt_functionParam645 = 0;
        sjs_string* sjt_functionParam646 = 0;
        sjs_mat4* sjt_functionParam647 = 0;
        int32_t sjt_functionParam648;
        sjs_shader* sjt_functionParam649 = 0;
        sjs_string* sjt_functionParam650 = 0;
        sjs_mat4* sjt_functionParam651 = 0;
        int32_t sjt_functionParam652;
        sjs_shader* sjt_functionParam653 = 0;
        sjs_string* sjt_functionParam654 = 0;
        sjs_mat4* sjt_functionParam655 = 0;
        sjs_scene2d* sjt_functionParam656 = 0;
        sjs_scene2d* sjt_parent350 = 0;
        sjs_scene2d* sjt_parent351 = 0;
        sjs_scene2d* sjt_parent352 = 0;
        sjs_boxvertexbuffer* sjt_parent353 = 0;

#line 42 "lib/sj-lib-ui/saturateEffect.sj"
        ifValue35 = (_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0);
#line 42
        ifValue36 = (_parent->_vertexbuffer._refCount != -1 ? &_parent->_vertexbuffer : 0);
#line 43
        sjt_functionParam627 = &ifValue35->framebuffer;
#line 43
        sjf_glpushframebuffer(sjt_functionParam627);
#line 27 "lib/sj-lib-ui/scene2d.sj"
        sjt_parent350 = &_parent->_innerscene;
#line 45 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam628 = &ifValue35->size;
#line 45
        sjf_scene2d_setsize(sjt_parent350, sjt_functionParam628);
#line 8 "lib/sj-lib-ui/scene2d.sj"
        sjt_parent351 = &_parent->_innerscene;
#line 8
        sjf_scene2d_start(sjt_parent351);
#line 48 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam629 = &_parent->_innerscene;
#line 48
        cb._cb(cb._parent, sjt_functionParam629);
#line 19 "lib/sj-lib-ui/scene2d.sj"
        sjt_parent352 = &_parent->_innerscene;
#line 19
        sjf_scene2d_end(sjt_parent352);
#line 52 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam630 = &ifValue35->framebuffer;
#line 52
        sjf_glpopframebuffer(sjt_functionParam630);
#line 54
        sjt_functionParam631 = g_gltexture_gl_texture_2d;
#line 54
        sjt_functionParam632 = &ifValue35->texture;
#line 54
        sjf_glbindtexture(sjt_functionParam631, sjt_functionParam632);
#line 55
        sjt_functionParam633 = &g_saturateshader;
#line 55
        sjf_gluseprogram(sjt_functionParam633);
#line 56
        sjt_functionParam634 = g_glblendfunctype_gl_src_alpha;
#line 56
        sjt_functionParam635 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 56
        sjf_glblendfunc(sjt_functionParam634, sjt_functionParam635);
#line 57
        sjt_functionParam637 = &g_saturateshader;
#line 57
        sjt_call161._refCount = 1;
#line 57
        sjt_call161.offset = 0;
#line 57
        sjt_call161.count = 7;
#line 57
        sjt_call161.data._refCount = 1;
#line 57
        sjt_call161.data.v = &sjg_string28;
#line 57
        sjf_array_char(&sjt_call161.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call161._isnullterminated = false;
#line 16
        sjf_string(&sjt_call161);
#line 57 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam638 = &sjt_call161;
#line 57
        sjf_glgetuniformlocation(sjt_functionParam637, sjt_functionParam638, &sjt_functionParam636);
#line 57
        sjt_functionParam639 = 0;
#line 57
        sjf_gluniformi32(sjt_functionParam636, sjt_functionParam639);
#line 58
        sjt_functionParam641 = &g_saturateshader;
#line 58
        sjt_call162._refCount = 1;
#line 58
        sjt_call162.offset = 0;
#line 58
        sjt_call162.count = 6;
#line 58
        sjt_call162.data._refCount = 1;
#line 58
        sjt_call162.data.v = &sjg_string37;
#line 58
        sjf_array_char(&sjt_call162.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call162._isnullterminated = false;
#line 16
        sjf_string(&sjt_call162);
#line 58 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam642 = &sjt_call162;
#line 58
        sjf_glgetuniformlocation(sjt_functionParam641, sjt_functionParam642, &sjt_functionParam640);
#line 58
        sjt_functionParam643 = _parent->amount;
#line 58
        sjf_gluniformf32(sjt_functionParam640, sjt_functionParam643);
#line 59
        sjt_functionParam645 = &g_saturateshader;
#line 59
        sjt_call163._refCount = 1;
#line 59
        sjt_call163.offset = 0;
#line 59
        sjt_call163.count = 5;
#line 59
        sjt_call163.data._refCount = 1;
#line 59
        sjt_call163.data.v = &sjg_string29;
#line 59
        sjf_array_char(&sjt_call163.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call163._isnullterminated = false;
#line 16
        sjf_string(&sjt_call163);
#line 59 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam646 = &sjt_call163;
#line 59
        sjf_glgetuniformlocation(sjt_functionParam645, sjt_functionParam646, &sjt_functionParam644);
#line 59
        sjt_functionParam647 = &scene->model;
#line 59
        sjf_gluniformmat4(sjt_functionParam644, sjt_functionParam647);
#line 60
        sjt_functionParam649 = &g_saturateshader;
#line 60
        sjt_call164._refCount = 1;
#line 60
        sjt_call164.offset = 0;
#line 60
        sjt_call164.count = 4;
#line 60
        sjt_call164.data._refCount = 1;
#line 60
        sjt_call164.data.v = &sjg_string30;
#line 60
        sjf_array_char(&sjt_call164.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call164._isnullterminated = false;
#line 16
        sjf_string(&sjt_call164);
#line 60 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam650 = &sjt_call164;
#line 60
        sjf_glgetuniformlocation(sjt_functionParam649, sjt_functionParam650, &sjt_functionParam648);
#line 60
        sjt_functionParam651 = &scene->view;
#line 60
        sjf_gluniformmat4(sjt_functionParam648, sjt_functionParam651);
#line 61
        sjt_functionParam653 = &g_saturateshader;
#line 61
        sjt_call165._refCount = 1;
#line 61
        sjt_call165.offset = 0;
#line 61
        sjt_call165.count = 10;
#line 61
        sjt_call165.data._refCount = 1;
#line 61
        sjt_call165.data.v = &sjg_string19;
#line 61
        sjf_array_char(&sjt_call165.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call165._isnullterminated = false;
#line 16
        sjf_string(&sjt_call165);
#line 61 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam654 = &sjt_call165;
#line 61
        sjf_glgetuniformlocation(sjt_functionParam653, sjt_functionParam654, &sjt_functionParam652);
#line 61
        sjt_functionParam655 = &scene->projection;
#line 61
        sjf_gluniformmat4(sjt_functionParam652, sjt_functionParam655);
#line 7 "lib/sj-lib-ui/boxVertexBuffer.sj"
        sjt_parent353 = ifValue36;
#line 30 "lib/sj-lib-ui/saturateEffect.sj"
        sjt_functionParam656 = scene;
#line 30
        sjf_boxvertexbuffer_render(sjt_parent353, sjt_functionParam656);

        if (sjt_call161._refCount == 1) { sjf_string_destroy(&sjt_call161); }
;
        if (sjt_call162._refCount == 1) { sjf_string_destroy(&sjt_call162); }
;
        if (sjt_call163._refCount == 1) { sjf_string_destroy(&sjt_call163); }
;
        if (sjt_call164._refCount == 1) { sjf_string_destroy(&sjt_call164); }
;
        if (sjt_call165._refCount == 1) { sjf_string_destroy(&sjt_call165); }
;
    }

    if (sjt_value13._refCount == 1) { sjf_boxvertexbuffer_destroy(&sjt_value13); }
;
    if (sjt_value14._refCount == 1) { sjf_scenebuffer_destroy(&sjt_value14); }
;
}

void sjf_saturateeffect_setrect(sjs_saturateeffect* _parent, sjs_rect* rect_, cb_rect_void cb) {
    bool result23;
    sjs_rect sjt_call160 = { -1 };
    bool sjt_capture81;
    sjs_rect* sjt_functionParam624 = 0;
    sjs_rect* sjt_functionParam626 = 0;
    sjs_rect* sjt_parent348 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent348 = &_parent->_rect;
#line 12 "lib/sj-lib-ui/saturateEffect.sj"
    sjt_functionParam624 = rect_;
#line 12
    sjf_rect_isequal(sjt_parent348, sjt_functionParam624, &sjt_capture81);
#line 13
    result23 = !sjt_capture81;
    if (result23) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 12 "lib/sj-lib-ui/saturateEffect.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
        if (((_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0) != 0)) {
            sjs_scenebuffer* ifValue33 = 0;
            bool result24;
            sjs_size sjt_call159 = { -1 };
            bool sjt_capture82;
            sjs_size* sjt_functionParam625 = 0;
            sjs_size* sjt_parent349 = 0;

#line 16 "lib/sj-lib-ui/saturateEffect.sj"
            ifValue33 = (_parent->_scenebuffer._refCount != -1 ? &_parent->_scenebuffer : 0);
#line 27 "lib/sj-lib-ui/size.sj"
            sjt_parent349 = &ifValue33->size;
#line 27
            sjt_call159._refCount = 1;
#line 17 "lib/sj-lib-ui/saturateEffect.sj"
            sjt_call159.w = (&_parent->_rect)->w;
#line 17
            sjt_call159.h = (&_parent->_rect)->h;
#line 17
            sjf_size(&sjt_call159);
#line 17
            sjt_functionParam625 = &sjt_call159;
#line 17
            sjf_size_isequal(sjt_parent349, sjt_functionParam625, &sjt_capture82);
#line 17
            result24 = !sjt_capture82;
            if (result24) {
                if (_parent->_scenebuffer._refCount == 1) { sjf_scenebuffer_destroy(&_parent->_scenebuffer); }
;
#line 18 "lib/sj-lib-ui/saturateEffect.sj"
                _parent->_scenebuffer._refCount = -1;
            }

            if (sjt_call159._refCount == 1) { sjf_size_destroy(&sjt_call159); }
;
        }

#line 12
        if (_parent->_vertexbuffer._refCount == 1) { sjf_boxvertexbuffer_destroy(&_parent->_vertexbuffer); }
;
#line 22
        _parent->_vertexbuffer._refCount = -1;
    }

#line 13
    sjt_call160._refCount = 1;
#line 25
    sjt_call160.x = 0;
#line 25
    sjt_call160.y = 0;
#line 25
    sjt_call160.w = (&_parent->_rect)->w;
#line 25
    sjt_call160.h = (&_parent->_rect)->h;
#line 25
    sjf_rect(&sjt_call160);
#line 25
    sjt_functionParam626 = &sjt_call160;
#line 25
    cb._cb(cb._parent, sjt_functionParam626);

    if (sjt_call160._refCount == 1) { sjf_rect_destroy(&sjt_call160); }
;
}

void sjf_scene2d(sjs_scene2d* _this) {
}

void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from) {
    _this->_size._refCount = 1;
#line 1 "lib/sj-lib-ui/scene2d.sj"
    sjf_size_copy(&_this->_size, &_from->_size);
#line 1
    _this->model._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->model, &_from->model);
#line 1
    _this->view._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->view, &_from->view);
#line 1
    _this->projection._refCount = 1;
#line 1
    sjf_mat4_copy(&_this->projection, &_from->projection);
#line 1
    _this->windowrect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->windowrect, &_from->windowrect);
}

void sjf_scene2d_destroy(sjs_scene2d* _this) {
    if (_this->_size._refCount == 1) { sjf_size_destroy(&_this->_size); }
;
    if (_this->model._refCount == 1) { sjf_mat4_destroy(&_this->model); }
;
    if (_this->view._refCount == 1) { sjf_mat4_destroy(&_this->view); }
;
    if (_this->projection._refCount == 1) { sjf_mat4_destroy(&_this->projection); }
;
    if (_this->windowrect._refCount == 1) { sjf_rect_destroy(&_this->windowrect); }
;
}

void sjf_scene2d_end(sjs_scene2d* _parent) {
    sjs_rect* sjt_functionParam517 = 0;
    sjs_rect* sjt_functionParam518 = 0;

#line 20 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam517 = &_parent->windowrect;
#line 20
    sjt_functionParam518 = &_parent->windowrect;
#line 20
    sjf_glpopviewport(sjt_functionParam517, sjt_functionParam518);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result16;
    bool sjt_capture78;
    sjs_mat4 sjt_funcold28 = { -1 };
    sjs_mat4 sjt_funcold29 = { -1 };
    sjs_mat4 sjt_funcold30 = { -1 };
    sjs_size* sjt_functionParam503 = 0;
    sjs_size* sjt_parent329 = 0;

#line 27 "lib/sj-lib-ui/size.sj"
    sjt_parent329 = &_parent->_size;
#line 27 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam503 = size;
#line 27
    sjf_size_isequal(sjt_parent329, sjt_functionParam503, &sjt_capture78);
#line 28
    result16 = !sjt_capture78;
    if (result16) {
        float result19;
        float result20;
        int32_t sjt_cast17;
        int32_t sjt_cast18;
        float sjt_functionParam504;
        float sjt_functionParam505;
        float sjt_functionParam506;
        float sjt_functionParam507;
        float sjt_functionParam508;
        float sjt_functionParam509;
        float sjt_functionParam510;
        float sjt_functionParam511;
        float sjt_functionParam512;

        if (_parent->_size._refCount == 1) { sjf_size_destroy(&_parent->_size); }
;
#line 27 "lib/sj-lib-ui/scene2d.sj"
        sjf_size_copy(&_parent->_size, size);
#line 30
        sjt_functionParam504 = 0.0f;
#line 30
        sjt_cast17 = (&_parent->_size)->w;
#line 30
        sjt_functionParam505 = (float)sjt_cast17;
#line 30
        sjt_cast18 = 0 - (&_parent->_size)->h;
#line 30
        sjt_functionParam506 = (float)sjt_cast18;
#line 30
        sjt_functionParam507 = 0.0f;
#line 30
        result19 = -1.0f;
#line 30
        sjt_functionParam508 = result19;
#line 30
        sjt_functionParam509 = 1.0f;
#line 30
        sjf_mat4_orthographic(sjt_functionParam504, sjt_functionParam505, sjt_functionParam506, sjt_functionParam507, sjt_functionParam508, sjt_functionParam509, &sjt_funcold28);
#line 30
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
#line 170 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->projection, &sjt_funcold28);
#line 31 "lib/sj-lib-ui/scene2d.sj"
        sjt_functionParam510 = 1.0f;
#line 31
        result20 = -1.0f;
#line 31
        sjt_functionParam511 = result20;
#line 31
        sjt_functionParam512 = 1.0f;
#line 31
        sjf_mat4_scale(sjt_functionParam510, sjt_functionParam511, sjt_functionParam512, &sjt_funcold29);
#line 31
        if (_parent->model._refCount == 1) { sjf_mat4_destroy(&_parent->model); }
;
#line 213 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->model, &sjt_funcold29);
#line 213
        sjf_mat4_identity(&sjt_funcold30);
#line 213
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
#line 124
        sjf_mat4_copy(&_parent->view, &sjt_funcold30);
    }

    if (sjt_funcold28._refCount == 1) { sjf_mat4_destroy(&sjt_funcold28); }
;
    if (sjt_funcold29._refCount == 1) { sjf_mat4_destroy(&sjt_funcold29); }
;
    if (sjt_funcold30._refCount == 1) { sjf_mat4_destroy(&sjt_funcold30); }
;
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_rect sjt_funcold31 = { -1 };
    sjs_rect* sjt_functionParam514 = 0;
    sjs_rect* sjt_functionParam515 = 0;

    sjt_funcold31._refCount = 1;
#line 9 "lib/sj-lib-ui/scene2d.sj"
    sjt_funcold31.x = 0;
#line 9
    sjt_funcold31.y = 0;
#line 9
    sjt_funcold31.w = (&_parent->_size)->w;
#line 9
    sjt_funcold31.h = (&_parent->_size)->h;
#line 9
    sjf_rect(&sjt_funcold31);
#line 9
    if (_parent->windowrect._refCount == 1) { sjf_rect_destroy(&_parent->windowrect); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
    sjf_rect_copy(&_parent->windowrect, &sjt_funcold31);
#line 10 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam514 = &_parent->windowrect;
#line 10
    sjt_functionParam515 = &_parent->windowrect;
#line 10
    sjf_glpushviewport(sjt_functionParam514, sjt_functionParam515);
#line 12
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
#line 13
    glEnable( GL_TEXTURE_2D );
#line 14
    glDisable( GL_DEPTH_TEST );

    if (sjt_funcold31._refCount == 1) { sjf_rect_destroy(&sjt_funcold31); }
;
}

void sjf_scene3delement(sjs_scene3delement* _this) {
}

void sjf_scene3delement_as_sji_element(sjs_scene3delement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_scene3delement_element_vtbl;
}

void sjf_scene3delement_asinterface(sjs_scene3delement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_scene3delement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_scene3delement_copy(sjs_scene3delement* _this, sjs_scene3delement* _from) {
    _this->children._refCount = 1;
#line 11 "lib/sj-lib-ui/scene3dElement.sj"
    sjf_array_heap_iface_model_copy(&_this->children, &_from->children);
#line 11
    _this->camera._refCount = 1;
#line 11
    sjf_vec3_copy(&_this->camera, &_from->camera);
#line 11
    _this->lookat._refCount = 1;
#line 11
    sjf_vec3_copy(&_this->lookat, &_from->lookat);
#line 11
    _this->up._refCount = 1;
#line 11
    sjf_vec3_copy(&_this->up, &_from->up);
#line 11
    _this->fieldofview = _from->fieldofview;
#line 11
    _this->znear = _from->znear;
#line 11
    _this->zfar = _from->zfar;
#line 11
    _this->light._refCount = 1;
#line 11
    sjf_light_copy(&_this->light, &_from->light);
#line 11
    _this->projection._refCount = 1;
#line 11
    sjf_mat4_copy(&_this->projection, &_from->projection);
#line 11
    _this->view._refCount = 1;
#line 11
    sjf_mat4_copy(&_this->view, &_from->view);
#line 11
    _this->world._refCount = 1;
#line 11
    sjf_mat4_copy(&_this->world, &_from->world);
#line 11
    _this->_rect._refCount = 1;
#line 11
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_scene3delement_destroy(sjs_scene3delement* _this) {
    if (_this->children._refCount == 1) { sjf_array_heap_iface_model_destroy(&_this->children); }
;
    if (_this->camera._refCount == 1) { sjf_vec3_destroy(&_this->camera); }
;
    if (_this->lookat._refCount == 1) { sjf_vec3_destroy(&_this->lookat); }
;
    if (_this->up._refCount == 1) { sjf_vec3_destroy(&_this->up); }
;
    if (_this->light._refCount == 1) { sjf_light_destroy(&_this->light); }
;
    if (_this->projection._refCount == 1) { sjf_mat4_destroy(&_this->projection); }
;
    if (_this->view._refCount == 1) { sjf_mat4_destroy(&_this->view); }
;
    if (_this->world._refCount == 1) { sjf_mat4_destroy(&_this->world); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_scene3delement_firemouseevent(sjs_scene3delement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    int32_t i;
    int32_t sjt_forEnd15;
    int32_t sjt_forStart15;
    sjs_array_heap_iface_model* sjt_parent122 = 0;

#line 67 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_forStart15 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent122 = &_parent->children;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent122, &sjt_forEnd15);
#line 67 "lib/sj-lib-ui/scene3dElement.sj"
    i = sjt_forStart15;
    while (i < sjt_forEnd15) {
        sji_model child = { 0 };
        int32_t sjt_functionParam146;
        sjs_mouseevent* sjt_interfaceParam18 = 0;
        sjs_array_heap_iface_model* sjt_parent123 = 0;
        sji_model sjt_parent124 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent123 = &_parent->children;
#line 67 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam146 = i;
#line 67
        sjf_array_heap_iface_model_getat_heap(sjt_parent123, sjt_functionParam146, &child);
#line 8 "lib/sj-lib-ui/model.sj"
        sjt_parent124 = child;
#line 66 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_interfaceParam18 = mouseevent;
#line 69
        sjt_parent124._vtbl->firemouseevent(sjt_parent124._parent, sjt_interfaceParam18);
#line 67
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 71
    (*_return) = true;
}

void sjf_scene3delement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 142;
}

void sjf_scene3delement_getrect(sjs_scene3delement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 29 "lib/sj-lib-ui/scene3dElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 29 "lib/sj-lib-ui/scene3dElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 26 "lib/sj-lib-ui/scene3dElement.sj"
    _return->w = maxsize->w;
#line 26
    _return->h = maxsize->h;
#line 26
    sjf_size(_return);
}

void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 26 "lib/sj-lib-ui/scene3dElement.sj"
    (*_return)->w = maxsize->w;
#line 26
    (*_return)->h = maxsize->h;
#line 26
    sjf_size_heap((*_return));
}

void sjf_scene3delement_heap(sjs_scene3delement* _this) {
}

void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene) {
    sjs_list_heap_iface_model a = { -1 };
    int32_t i;
    int32_t sjt_forEnd12;
    int32_t sjt_forEnd13;
    int32_t sjt_forEnd14;
    int32_t sjt_forStart12;
    int32_t sjt_forStart13;
    int32_t sjt_forStart14;
    sjs_rect* sjt_functionParam105 = 0;
    sjs_rect* sjt_functionParam106 = 0;
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam131;
    sjs_rect* sjt_functionParam143 = 0;
    sjs_rect* sjt_functionParam144 = 0;
    int32_t sjt_functionParam145;
    int32_t sjt_functionParam96;
    sjs_list_heap_iface_model* sjt_parent103 = 0;
    sjs_list_heap_iface_model* sjt_parent107 = 0;
    sjs_array_heap_iface_model* sjt_parent88 = 0;
    sjs_array_heap_iface_model* sjt_parent99 = 0;

#line 41 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_forStart12 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent88 = &_parent->children;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent88, &sjt_forEnd12);
#line 41 "lib/sj-lib-ui/scene3dElement.sj"
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sji_model child = { 0 };
        int32_t sjt_functionParam95;
        sjs_rect* sjt_interfaceParam12 = 0;
        sjs_mat4* sjt_interfaceParam13 = 0;
        sjs_mat4* sjt_interfaceParam14 = 0;
        sjs_mat4* sjt_interfaceParam15 = 0;
        sjs_light* sjt_interfaceParam16 = 0;
        sjs_array_heap_iface_model* sjt_parent89 = 0;
        sji_model sjt_parent90 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent89 = &_parent->children;
#line 41 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam95 = i;
#line 41
        sjf_array_heap_iface_model_getat_heap(sjt_parent89, sjt_functionParam95, &child);
#line 2 "lib/sj-lib-ui/model.sj"
        sjt_parent90 = child;
#line 43 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_interfaceParam12 = &_parent->_rect;
#line 43
        sjt_interfaceParam13 = &_parent->projection;
#line 43
        sjt_interfaceParam14 = &_parent->view;
#line 43
        sjt_interfaceParam15 = &_parent->world;
#line 43
        sjt_interfaceParam16 = &_parent->light;
#line 43
        sjt_parent90._vtbl->update(sjt_parent90._parent, sjt_interfaceParam12, sjt_interfaceParam13, sjt_interfaceParam14, sjt_interfaceParam15, sjt_interfaceParam16);
#line 41
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 46
    sjt_functionParam96 = g_glfeature_gl_depth_test;
#line 46
    sjf_glenable(sjt_functionParam96);
#line 47
    sjt_functionParam105 = &_parent->_rect;
#line 47
    sjt_functionParam106 = &scene->windowrect;
#line 47
    sjf_glpushviewport(sjt_functionParam105, sjt_functionParam106);
#line 47
    a._refCount = 1;
#line 47
    a.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    a.arr.v = 0;
#line 27
    sjf_array_heap_iface_model(&a.arr);
#line 27
    sjf_list_heap_iface_model(&a);
#line 51 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_forStart13 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent99 = &_parent->children;
#line 29
    sjf_array_heap_iface_model_getcount(sjt_parent99, &sjt_forEnd13);
#line 51 "lib/sj-lib-ui/scene3dElement.sj"
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sji_model child = { 0 };
        int32_t sjt_functionParam107;
        sjs_list_heap_iface_model* sjt_interfaceParam17 = 0;
        sjs_array_heap_iface_model* sjt_parent100 = 0;
        sji_model sjt_parent101 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent100 = &_parent->children;
#line 51 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam107 = i;
#line 51
        sjf_array_heap_iface_model_getat_heap(sjt_parent100, sjt_functionParam107, &child);
#line 6 "lib/sj-lib-ui/model.sj"
        sjt_parent101 = child;
#line 53 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_interfaceParam17 = &a;
#line 53
        sjt_parent101._vtbl->renderorqueue(sjt_parent101._parent, sjt_interfaceParam17);
#line 51
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 28 "lib/sj-lib-common/list.sj"
    sjt_parent103 = &a;
#line 56 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_functionParam131._parent = (sjs_object*)1;
#line 56
    sjt_functionParam131._cb = (void(*)(sjs_object*,sji_model,sji_model, int32_t*))sjf_model_zsort_callback;
#line 56
    sjf_list_heap_iface_model_sortcb(sjt_parent103, sjt_functionParam131);
#line 57
    sjt_forStart14 = 0;
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent107 = &a;
#line 4
    sjf_list_heap_iface_model_getcount(sjt_parent107, &sjt_forEnd14);
#line 57 "lib/sj-lib-ui/scene3dElement.sj"
    i = sjt_forEnd14 - 1;
    while (i >= sjt_forStart14) {
        sji_model child = { 0 };
        int32_t sjt_functionParam135;
        sjs_list_heap_iface_model* sjt_parent109 = 0;
        sji_model sjt_parent110 = { 0 };

#line 8 "lib/sj-lib-common/list.sj"
        sjt_parent109 = &a;
#line 57 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam135 = i;
#line 57
        sjf_list_heap_iface_model_getat_heap(sjt_parent109, sjt_functionParam135, &child);
#line 7 "lib/sj-lib-ui/model.sj"
        sjt_parent110 = child;
#line 59 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_parent110._vtbl->render(sjt_parent110._parent);
#line 57
        i--;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

#line 62
    sjt_functionParam143 = &_parent->_rect;
#line 62
    sjt_functionParam144 = &scene->windowrect;
#line 62
    sjf_glpopviewport(sjt_functionParam143, sjt_functionParam144);
#line 63
    sjt_functionParam145 = g_glfeature_gl_depth_test;
#line 63
    sjf_gldisable(sjt_functionParam145);

    if (a._refCount == 1) { sjf_list_heap_iface_model_destroy(&a); }
;
}

void sjf_scene3delement_setrect(sjs_scene3delement* _parent, sjs_rect* rect_) {
    bool result4;
    bool sjt_capture19;
    sjs_mat4 sjt_funcold7 = { -1 };
    sjs_mat4 sjt_funcold8 = { -1 };
    sjs_rect* sjt_functionParam71 = 0;
    sjs_rect* sjt_parent71 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent71 = &_parent->_rect;
#line 31 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_functionParam71 = rect_;
#line 31
    sjf_rect_isequal(sjt_parent71, sjt_functionParam71, &sjt_capture19);
#line 32
    result4 = !sjt_capture19;
    if (result4) {
        int32_t sjt_cast8;
        int32_t sjt_cast9;
        float sjt_functionParam74;
        float sjt_functionParam75;
        float sjt_functionParam76;
        float sjt_functionParam77;
        sjs_vec3* sjt_functionParam92 = 0;
        sjs_vec3* sjt_functionParam93 = 0;
        sjs_vec3* sjt_functionParam94 = 0;

        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 31 "lib/sj-lib-ui/scene3dElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 34
        sjt_functionParam74 = _parent->fieldofview;
#line 34
        sjt_cast8 = (&_parent->_rect)->h;
#line 34
        sjt_cast9 = (&_parent->_rect)->w;
#line 34
        sjt_functionParam75 = (float)sjt_cast8 / (float)sjt_cast9;
#line 34
        sjt_functionParam76 = _parent->znear;
#line 34
        sjt_functionParam77 = _parent->zfar;
#line 34
        sjf_mat4_perspective(sjt_functionParam74, sjt_functionParam75, sjt_functionParam76, sjt_functionParam77, &sjt_funcold7);
#line 34
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
#line 158 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->projection, &sjt_funcold7);
#line 35 "lib/sj-lib-ui/scene3dElement.sj"
        sjt_functionParam92 = &_parent->camera;
#line 35
        sjt_functionParam93 = &_parent->lookat;
#line 35
        sjt_functionParam94 = &_parent->up;
#line 35
        sjf_mat4_lookatlh(sjt_functionParam92, sjt_functionParam93, sjt_functionParam94, &sjt_funcold8);
#line 35
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
#line 133 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->view, &sjt_funcold8);
    }

    if (sjt_funcold7._refCount == 1) { sjf_mat4_destroy(&sjt_funcold7); }
;
    if (sjt_funcold8._refCount == 1) { sjf_mat4_destroy(&sjt_funcold8); }
;
}

void sjf_scenebuffer(sjs_scenebuffer* _this) {
    sjs_string sjt_call130 = { -1 };
    sjs_framebuffer sjt_funcold21 = { -1 };
    sjs_texture sjt_funcold22 = { -1 };
    sjs_renderbuffer sjt_funcold23 = { -1 };
    sjs_size* sjt_functionParam413 = 0;
    sjs_size* sjt_functionParam414 = 0;
    sjs_size* sjt_functionParam415 = 0;
    sjs_framebuffer* sjt_functionParam424 = 0;
    int32_t sjt_functionParam425;
    sjs_texture* sjt_functionParam426 = 0;
    int32_t sjt_functionParam427;
    int32_t sjt_functionParam428;
    int32_t sjt_functionParam429;
    int32_t sjt_functionParam430;
    int32_t sjt_functionParam431;
    int32_t sjt_functionParam432;
    int32_t sjt_functionParam433;
    int32_t sjt_functionParam434;
    int32_t sjt_functionParam435;
    int32_t sjt_functionParam436;
    int32_t sjt_functionParam437;
    int32_t sjt_functionParam438;
    int32_t sjt_functionParam439;
    int32_t sjt_functionParam440;
    int32_t sjt_functionParam441;
    sjs_size* sjt_functionParam442 = 0;
    int32_t sjt_functionParam443;
    void* sjt_functionParam444;
    int32_t sjt_functionParam445;
    int32_t sjt_functionParam446;
    sjs_texture* sjt_functionParam447 = 0;
    int32_t sjt_functionParam448;
    sjs_renderbuffer* sjt_functionParam449 = 0;
    int32_t sjt_functionParam450;
    sjs_size* sjt_functionParam451 = 0;
    int32_t sjt_functionParam452;
    sjs_renderbuffer* sjt_functionParam453 = 0;
    sjs_framebuffer* sjt_functionParam460 = 0;
    int32_t status;

#line 1 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam413 = &_this->size;
#line 1
    sjf_glgenframebuffer(sjt_functionParam413, &sjt_funcold21);
#line 1
    if (_this->framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->framebuffer); }
;
#line 208 "lib/sj-lib-ui/gl.sj"
    sjf_framebuffer_copy(&_this->framebuffer, &sjt_funcold21);
#line 1 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam414 = &_this->size;
#line 1
    sjf_glgentexture(sjt_functionParam414, &sjt_funcold22);
#line 1
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
#line 216 "lib/sj-lib-ui/gl.sj"
    sjf_texture_copy(&_this->texture, &sjt_funcold22);
#line 1 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam415 = &_this->size;
#line 1
    sjf_glgenrenderbuffer(sjt_functionParam415, &sjt_funcold23);
#line 1
    if (_this->renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->renderbuffer); }
;
#line 242 "lib/sj-lib-ui/gl.sj"
    sjf_renderbuffer_copy(&_this->renderbuffer, &sjt_funcold23);
#line 1 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam424 = &_this->framebuffer;
#line 1
    sjf_glpushframebuffer(sjt_functionParam424);
#line 12
    sjt_functionParam425 = g_gltexture_gl_texture_2d;
#line 1
    sjt_functionParam426 = &_this->texture;
#line 1
    sjf_glbindtexture(sjt_functionParam425, sjt_functionParam426);
#line 13
    sjt_functionParam427 = g_gltexture_gl_texture_2d;
#line 13
    sjt_functionParam428 = g_gltextureattribute_gl_texture_wrap_s;
#line 13
    sjt_functionParam429 = g_gltexturevalue_gl_clamp_to_edge;
#line 13
    sjf_gltexparameteri(sjt_functionParam427, sjt_functionParam428, sjt_functionParam429);
#line 14
    sjt_functionParam430 = g_gltexture_gl_texture_2d;
#line 14
    sjt_functionParam431 = g_gltextureattribute_gl_texture_wrap_t;
#line 14
    sjt_functionParam432 = g_gltexturevalue_gl_clamp_to_edge;
#line 14
    sjf_gltexparameteri(sjt_functionParam430, sjt_functionParam431, sjt_functionParam432);
#line 15
    sjt_functionParam433 = g_gltexture_gl_texture_2d;
#line 15
    sjt_functionParam434 = g_gltextureattribute_gl_texture_min_filter;
#line 15
    sjt_functionParam435 = g_gltexturevalue_gl_linear;
#line 15
    sjf_gltexparameteri(sjt_functionParam433, sjt_functionParam434, sjt_functionParam435);
#line 16
    sjt_functionParam436 = g_gltexture_gl_texture_2d;
#line 16
    sjt_functionParam437 = g_gltextureattribute_gl_texture_mag_filter;
#line 16
    sjt_functionParam438 = g_gltexturevalue_gl_linear;
#line 16
    sjf_gltexparameteri(sjt_functionParam436, sjt_functionParam437, sjt_functionParam438);
#line 17
    sjt_functionParam439 = g_gltexture_gl_texture_2d;
#line 17
    sjt_functionParam440 = 0;
#line 17
    sjt_functionParam441 = g_gltextureformat_gl_rgba;
#line 1
    sjt_functionParam442 = &_this->size;
#line 17
    sjt_functionParam443 = g_gltexturetype_gl_unsigned_byte;
#line 230 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam444 = 0;
#line 230
    sjf_glteximage2d(sjt_functionParam439, sjt_functionParam440, sjt_functionParam441, sjt_functionParam442, sjt_functionParam443, sjt_functionParam444);
#line 18 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam445 = g_glframebufferattachment_gl_color_attachment0;
#line 18
    sjt_functionParam446 = g_glframebuffertexture_gl_texture_2d;
#line 1
    sjt_functionParam447 = &_this->texture;
#line 18
    sjt_functionParam448 = 0;
#line 18
    sjf_glframebuffertexture2d(sjt_functionParam445, sjt_functionParam446, sjt_functionParam447, sjt_functionParam448);
#line 1
    sjt_functionParam449 = &_this->renderbuffer;
#line 1
    sjf_glbindrenderbuffer(sjt_functionParam449);
#line 21
    sjt_functionParam450 = g_glrenderbufferformat_gl_depth_component16;
#line 1
    sjt_functionParam451 = &_this->size;
#line 1
    sjf_glrenderbufferstorage(sjt_functionParam450, sjt_functionParam451);
#line 22
    sjt_functionParam452 = g_glframebufferattachment_gl_depth_attachment;
#line 1
    sjt_functionParam453 = &_this->renderbuffer;
#line 1
    sjf_glframebufferrenderbuffer(sjt_functionParam452, sjt_functionParam453);
#line 1
    sjf_glcheckframebufferstatus(&status);
    if (status != g_glframebufferstatus_gl_framebuffer_complete) {
        sjs_string* sjt_functionParam454 = 0;

        sjt_call130._refCount = 1;
#line 26 "lib/sj-lib-ui/scenebuffer.sj"
        sjt_call130.offset = 0;
#line 26
        sjt_call130.count = 18;
#line 26
        sjt_call130.data._refCount = 1;
#line 26
        sjt_call130.data.v = &sjg_string32;
#line 26
        sjf_array_char(&sjt_call130.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call130._isnullterminated = false;
#line 16
        sjf_string(&sjt_call130);
#line 26 "lib/sj-lib-ui/scenebuffer.sj"
        sjt_functionParam454 = &sjt_call130;
#line 26
        sjf_halt(sjt_functionParam454);
    }

#line 1
    sjt_functionParam460 = &_this->framebuffer;
#line 1
    sjf_glpopframebuffer(sjt_functionParam460);

    if (sjt_call130._refCount == 1) { sjf_string_destroy(&sjt_call130); }
;
    if (sjt_funcold21._refCount == 1) { sjf_framebuffer_destroy(&sjt_funcold21); }
;
    if (sjt_funcold22._refCount == 1) { sjf_texture_destroy(&sjt_funcold22); }
;
    if (sjt_funcold23._refCount == 1) { sjf_renderbuffer_destroy(&sjt_funcold23); }
;
}

void sjf_scenebuffer_copy(sjs_scenebuffer* _this, sjs_scenebuffer* _from) {
    _this->size._refCount = 1;
#line 1 "lib/sj-lib-ui/scenebuffer.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->framebuffer._refCount = 1;
#line 1
    sjf_framebuffer_copy(&_this->framebuffer, &_from->framebuffer);
#line 1
    _this->texture._refCount = 1;
#line 1
    sjf_texture_copy(&_this->texture, &_from->texture);
#line 1
    _this->renderbuffer._refCount = 1;
#line 1
    sjf_renderbuffer_copy(&_this->renderbuffer, &_from->renderbuffer);
}

void sjf_scenebuffer_destroy(sjs_scenebuffer* _this) {
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
    if (_this->framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->framebuffer); }
;
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
    if (_this->renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->renderbuffer); }
;
}

void sjf_scenebuffer_heap(sjs_scenebuffer* _this) {
    sjs_string sjt_call132 = { -1 };
    sjs_framebuffer sjt_funcold25 = { -1 };
    sjs_texture sjt_funcold26 = { -1 };
    sjs_renderbuffer sjt_funcold27 = { -1 };
    sjs_size* sjt_functionParam461 = 0;
    sjs_size* sjt_functionParam462 = 0;
    sjs_size* sjt_functionParam463 = 0;
    sjs_framebuffer* sjt_functionParam464 = 0;
    int32_t sjt_functionParam465;
    sjs_texture* sjt_functionParam466 = 0;
    int32_t sjt_functionParam467;
    int32_t sjt_functionParam468;
    int32_t sjt_functionParam469;
    int32_t sjt_functionParam470;
    int32_t sjt_functionParam471;
    int32_t sjt_functionParam472;
    int32_t sjt_functionParam473;
    int32_t sjt_functionParam474;
    int32_t sjt_functionParam475;
    int32_t sjt_functionParam476;
    int32_t sjt_functionParam477;
    int32_t sjt_functionParam478;
    int32_t sjt_functionParam479;
    int32_t sjt_functionParam480;
    int32_t sjt_functionParam481;
    sjs_size* sjt_functionParam482 = 0;
    int32_t sjt_functionParam483;
    void* sjt_functionParam484;
    int32_t sjt_functionParam485;
    int32_t sjt_functionParam486;
    sjs_texture* sjt_functionParam487 = 0;
    int32_t sjt_functionParam488;
    sjs_renderbuffer* sjt_functionParam489 = 0;
    int32_t sjt_functionParam490;
    sjs_size* sjt_functionParam491 = 0;
    int32_t sjt_functionParam492;
    sjs_renderbuffer* sjt_functionParam493 = 0;
    sjs_framebuffer* sjt_functionParam495 = 0;
    int32_t status;

#line 7 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam461 = &_this->size;
#line 7
    sjf_glgenframebuffer(sjt_functionParam461, &sjt_funcold25);
#line 7
    if (_this->framebuffer._refCount == 1) { sjf_framebuffer_destroy(&_this->framebuffer); }
;
#line 208 "lib/sj-lib-ui/gl.sj"
    sjf_framebuffer_copy(&_this->framebuffer, &sjt_funcold25);
#line 8 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam462 = &_this->size;
#line 8
    sjf_glgentexture(sjt_functionParam462, &sjt_funcold26);
#line 8
    if (_this->texture._refCount == 1) { sjf_texture_destroy(&_this->texture); }
;
#line 216 "lib/sj-lib-ui/gl.sj"
    sjf_texture_copy(&_this->texture, &sjt_funcold26);
#line 9 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam463 = &_this->size;
#line 9
    sjf_glgenrenderbuffer(sjt_functionParam463, &sjt_funcold27);
#line 9
    if (_this->renderbuffer._refCount == 1) { sjf_renderbuffer_destroy(&_this->renderbuffer); }
;
#line 242 "lib/sj-lib-ui/gl.sj"
    sjf_renderbuffer_copy(&_this->renderbuffer, &sjt_funcold27);
#line 11 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam464 = &_this->framebuffer;
#line 11
    sjf_glpushframebuffer(sjt_functionParam464);
#line 12
    sjt_functionParam465 = g_gltexture_gl_texture_2d;
#line 12
    sjt_functionParam466 = &_this->texture;
#line 12
    sjf_glbindtexture(sjt_functionParam465, sjt_functionParam466);
#line 13
    sjt_functionParam467 = g_gltexture_gl_texture_2d;
#line 13
    sjt_functionParam468 = g_gltextureattribute_gl_texture_wrap_s;
#line 13
    sjt_functionParam469 = g_gltexturevalue_gl_clamp_to_edge;
#line 13
    sjf_gltexparameteri(sjt_functionParam467, sjt_functionParam468, sjt_functionParam469);
#line 14
    sjt_functionParam470 = g_gltexture_gl_texture_2d;
#line 14
    sjt_functionParam471 = g_gltextureattribute_gl_texture_wrap_t;
#line 14
    sjt_functionParam472 = g_gltexturevalue_gl_clamp_to_edge;
#line 14
    sjf_gltexparameteri(sjt_functionParam470, sjt_functionParam471, sjt_functionParam472);
#line 15
    sjt_functionParam473 = g_gltexture_gl_texture_2d;
#line 15
    sjt_functionParam474 = g_gltextureattribute_gl_texture_min_filter;
#line 15
    sjt_functionParam475 = g_gltexturevalue_gl_linear;
#line 15
    sjf_gltexparameteri(sjt_functionParam473, sjt_functionParam474, sjt_functionParam475);
#line 16
    sjt_functionParam476 = g_gltexture_gl_texture_2d;
#line 16
    sjt_functionParam477 = g_gltextureattribute_gl_texture_mag_filter;
#line 16
    sjt_functionParam478 = g_gltexturevalue_gl_linear;
#line 16
    sjf_gltexparameteri(sjt_functionParam476, sjt_functionParam477, sjt_functionParam478);
#line 17
    sjt_functionParam479 = g_gltexture_gl_texture_2d;
#line 17
    sjt_functionParam480 = 0;
#line 17
    sjt_functionParam481 = g_gltextureformat_gl_rgba;
#line 17
    sjt_functionParam482 = &_this->size;
#line 17
    sjt_functionParam483 = g_gltexturetype_gl_unsigned_byte;
#line 230 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam484 = 0;
#line 230
    sjf_glteximage2d(sjt_functionParam479, sjt_functionParam480, sjt_functionParam481, sjt_functionParam482, sjt_functionParam483, sjt_functionParam484);
#line 18 "lib/sj-lib-ui/scenebuffer.sj"
    sjt_functionParam485 = g_glframebufferattachment_gl_color_attachment0;
#line 18
    sjt_functionParam486 = g_glframebuffertexture_gl_texture_2d;
#line 18
    sjt_functionParam487 = &_this->texture;
#line 18
    sjt_functionParam488 = 0;
#line 18
    sjf_glframebuffertexture2d(sjt_functionParam485, sjt_functionParam486, sjt_functionParam487, sjt_functionParam488);
#line 20
    sjt_functionParam489 = &_this->renderbuffer;
#line 20
    sjf_glbindrenderbuffer(sjt_functionParam489);
#line 21
    sjt_functionParam490 = g_glrenderbufferformat_gl_depth_component16;
#line 21
    sjt_functionParam491 = &_this->size;
#line 21
    sjf_glrenderbufferstorage(sjt_functionParam490, sjt_functionParam491);
#line 22
    sjt_functionParam492 = g_glframebufferattachment_gl_depth_attachment;
#line 22
    sjt_functionParam493 = &_this->renderbuffer;
#line 22
    sjf_glframebufferrenderbuffer(sjt_functionParam492, sjt_functionParam493);
#line 22
    sjf_glcheckframebufferstatus(&status);
    if (status != g_glframebufferstatus_gl_framebuffer_complete) {
        sjs_string* sjt_functionParam494 = 0;

        sjt_call132._refCount = 1;
#line 26 "lib/sj-lib-ui/scenebuffer.sj"
        sjt_call132.offset = 0;
#line 26
        sjt_call132.count = 18;
#line 26
        sjt_call132.data._refCount = 1;
#line 26
        sjt_call132.data.v = &sjg_string32;
#line 26
        sjf_array_char(&sjt_call132.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call132._isnullterminated = false;
#line 16
        sjf_string(&sjt_call132);
#line 26 "lib/sj-lib-ui/scenebuffer.sj"
        sjt_functionParam494 = &sjt_call132;
#line 26
        sjf_halt(sjt_functionParam494);
    }

#line 28
    sjt_functionParam495 = &_this->framebuffer;
#line 28
    sjf_glpopframebuffer(sjt_functionParam495);

    if (sjt_call132._refCount == 1) { sjf_string_destroy(&sjt_call132); }
;
    if (sjt_funcold25._refCount == 1) { sjf_framebuffer_destroy(&sjt_funcold25); }
;
    if (sjt_funcold26._refCount == 1) { sjf_texture_destroy(&sjt_funcold26); }
;
    if (sjt_funcold27._refCount == 1) { sjf_renderbuffer_destroy(&sjt_funcold27); }
;
}

void sjf_shader(sjs_shader* _this) {
#line 15 "lib/sj-lib-ui/shader.sj"
    _this->id = shader_load(string_char(&_this->vertex), string_char(&_this->pixel));
}

void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from) {
    _this->vertex._refCount = 1;
#line 7 "lib/sj-lib-ui/shader.sj"
    sjf_string_copy(&_this->vertex, &_from->vertex);
#line 7
    _this->pixel._refCount = 1;
#line 7
    sjf_string_copy(&_this->pixel, &_from->pixel);
#line 20
    _this->id = _from->id;
#line 21
    glid_retain(_this->id);
}

void sjf_shader_destroy(sjs_shader* _this) {
#line 25 "lib/sj-lib-ui/shader.sj"
    if (glid_release(_this->id)) {
#line 26
        glDeleteShader(_this->id);
#line 27
    }
#line 27
    if (_this->vertex._refCount == 1) { sjf_string_destroy(&_this->vertex); }
;
#line 27
    if (_this->pixel._refCount == 1) { sjf_string_destroy(&_this->pixel); }
;
}

void sjf_shader_heap(sjs_shader* _this) {
#line 15 "lib/sj-lib-ui/shader.sj"
    _this->id = shader_load(string_char(&_this->vertex), string_char(&_this->pixel));
}

void sjf_size(sjs_size* _this) {
}

void sjf_size_addmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    _return->_refCount = 1;
#line 20 "lib/sj-lib-ui/size.sj"
    _return->w = (_parent->w + margin->l) + margin->r;
#line 20
    _return->h = (_parent->h + margin->t) + margin->b;
#line 20
    sjf_size(_return);
}

void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 20 "lib/sj-lib-ui/size.sj"
    (*_return)->w = (_parent->w + margin->l) + margin->r;
#line 20
    (*_return)->h = (_parent->h + margin->t) + margin->b;
#line 20
    sjf_size_heap((*_return));
}

void sjf_size_copy(sjs_size* _this, sjs_size* _from) {
#line 1 "lib/sj-lib-ui/size.sj"
    _this->w = _from->w;
#line 1
    _this->h = _from->h;
}

void sjf_size_destroy(sjs_size* _this) {
}

void sjf_size_heap(sjs_size* _this) {
}

void sjf_size_isequal(sjs_size* _parent, sjs_size* size, bool* _return) {
    if (_parent->w == size->w) {
#line 28 "lib/sj-lib-ui/size.sj"
        (*_return) = (_parent->h == size->h);
    } else {
#line 28 "lib/sj-lib-ui/size.sj"
        (*_return) = false;
    }
}

void sjf_size_max(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if (_parent->w > maxsize->w) {
#line 13 "lib/sj-lib-ui/size.sj"
        _return->w = _parent->w;
    } else {
#line 13 "lib/sj-lib-ui/size.sj"
        _return->w = maxsize->w;
    }

    if (_parent->h > maxsize->h) {
#line 13 "lib/sj-lib-ui/size.sj"
        _return->h = _parent->h;
    } else {
#line 13 "lib/sj-lib-ui/size.sj"
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if (_parent->w > maxsize->w) {
#line 13 "lib/sj-lib-ui/size.sj"
        (*_return)->w = _parent->w;
    } else {
#line 13 "lib/sj-lib-ui/size.sj"
        (*_return)->w = maxsize->w;
    }

    if (_parent->h > maxsize->h) {
#line 13 "lib/sj-lib-ui/size.sj"
        (*_return)->h = _parent->h;
    } else {
#line 13 "lib/sj-lib-ui/size.sj"
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
    if (_parent->w < maxsize->w) {
#line 6 "lib/sj-lib-ui/size.sj"
        _return->w = _parent->w;
    } else {
#line 6 "lib/sj-lib-ui/size.sj"
        _return->w = maxsize->w;
    }

    if (_parent->h < maxsize->h) {
#line 6 "lib/sj-lib-ui/size.sj"
        _return->h = _parent->h;
    } else {
#line 6 "lib/sj-lib-ui/size.sj"
        _return->h = maxsize->h;
    }

    sjf_size(_return);
}

void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    if (_parent->w < maxsize->w) {
#line 6 "lib/sj-lib-ui/size.sj"
        (*_return)->w = _parent->w;
    } else {
#line 6 "lib/sj-lib-ui/size.sj"
        (*_return)->w = maxsize->w;
    }

    if (_parent->h < maxsize->h) {
#line 6 "lib/sj-lib-ui/size.sj"
        (*_return)->h = _parent->h;
    } else {
#line 6 "lib/sj-lib-ui/size.sj"
        (*_return)->h = maxsize->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_subtractmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    _return->_refCount = 1;
#line 24 "lib/sj-lib-ui/size.sj"
    _return->w = (_parent->w - margin->l) - margin->r;
#line 24
    _return->h = (_parent->h - margin->t) - margin->b;
#line 24
    sjf_size(_return);
}

void sjf_size_subtractmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 24 "lib/sj-lib-ui/size.sj"
    (*_return)->w = (_parent->w - margin->l) - margin->r;
#line 24
    (*_return)->h = (_parent->h - margin->t) - margin->b;
#line 24
    sjf_size_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy(_return, _parent);
    } else {
        bool sjt_capture53;
        int32_t sjt_capture54;
        sjs_array_char* sjt_parent157 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent157 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent157, &sjt_capture54);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture54) {
            int32_t sjt_capture55;
            sjs_array_char* sjt_parent158 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent158 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent158, &sjt_capture55);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture53 = ((_parent->offset + _parent->count) == sjt_capture55);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture53 = false;
        }

        if (sjt_capture53) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd16;
            int32_t sjt_forStart16;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart16 = 0;
#line 27
            sjt_forEnd16 = item->count;
#line 27
            i = sjt_forStart16;
            while (i < sjt_forEnd16) {
                int32_t sjt_functionParam213;
                char sjt_functionParam214;
                int32_t sjt_functionParam216;
                sjs_array_char* sjt_parent159 = 0;
                sjs_string* sjt_parent161 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent159 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam213 = newcount;
#line 18
                sjt_parent161 = item;
#line 27
                sjt_functionParam216 = i;
#line 27
                sjf_string_getat(sjt_parent161, sjt_functionParam216, &sjt_functionParam214);
#line 27
                sjf_array_char_initat(sjt_parent159, sjt_functionParam213, sjt_functionParam214);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            _return->_refCount = 1;
#line 32
            _return->offset = _parent->offset;
#line 32
            _return->count = newcount;
#line 32
            _return->data._refCount = 1;
#line 32
            sjf_array_char_copy(&_return->data, &_parent->data);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd17;
            int32_t sjt_forStart17;
            int32_t sjt_functionParam217;
            int32_t sjt_functionParam218;
            int32_t sjt_functionParam219;
            sjs_array_char* sjt_parent162 = 0;
            sjs_array_char* sjt_parent163 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent162 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam217 = _parent->offset;
#line 34
            sjt_functionParam218 = _parent->count;
#line 34
            sjt_functionParam219 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent162, sjt_functionParam217, sjt_functionParam218, sjt_functionParam219, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent163 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent163, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart17 = 0;
#line 37
            sjt_forEnd17 = item->count;
#line 37
            i = sjt_forStart17;
            while (i < sjt_forEnd17) {
                int32_t sjt_functionParam220;
                char sjt_functionParam221;
                int32_t sjt_functionParam222;
                sjs_array_char* sjt_parent164 = 0;
                sjs_string* sjt_parent165 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent164 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam220 = newcount;
#line 18
                sjt_parent165 = item;
#line 37
                sjt_functionParam222 = i;
#line 37
                sjf_string_getat(sjt_parent165, sjt_functionParam222, &sjt_functionParam221);
#line 37
                sjf_array_char_initat(sjt_parent164, sjt_functionParam220, sjt_functionParam221);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            _return->_refCount = 1;
#line 42
            _return->offset = 0;
#line 42
            _return->count = newcount;
#line 42
            _return->data._refCount = 1;
#line 42
            sjf_array_char_copy(&_return->data, &newdata);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy((*_return), _parent);
    } else {
        bool sjt_capture56;
        int32_t sjt_capture57;
        sjs_array_char* sjt_parent166 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent166 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent166, &sjt_capture57);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture57) {
            int32_t sjt_capture58;
            sjs_array_char* sjt_parent167 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent167 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent167, &sjt_capture58);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture56 = ((_parent->offset + _parent->count) == sjt_capture58);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture56 = false;
        }

        if (sjt_capture56) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd18;
            int32_t sjt_forStart18;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart18 = 0;
#line 27
            sjt_forEnd18 = item->count;
#line 27
            i = sjt_forStart18;
            while (i < sjt_forEnd18) {
                int32_t sjt_functionParam223;
                char sjt_functionParam224;
                int32_t sjt_functionParam225;
                sjs_array_char* sjt_parent168 = 0;
                sjs_string* sjt_parent169 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent168 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam223 = newcount;
#line 18
                sjt_parent169 = item;
#line 27
                sjt_functionParam225 = i;
#line 27
                sjf_string_getat(sjt_parent169, sjt_functionParam225, &sjt_functionParam224);
#line 27
                sjf_array_char_initat(sjt_parent168, sjt_functionParam223, sjt_functionParam224);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 27
            (*_return)->_refCount = 1;
#line 32
            (*_return)->offset = _parent->offset;
#line 32
            (*_return)->count = newcount;
#line 32
            (*_return)->data._refCount = 1;
#line 32
            sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd19;
            int32_t sjt_forStart19;
            int32_t sjt_functionParam226;
            int32_t sjt_functionParam227;
            int32_t sjt_functionParam228;
            sjs_array_char* sjt_parent170 = 0;
            sjs_array_char* sjt_parent171 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent170 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam226 = _parent->offset;
#line 34
            sjt_functionParam227 = _parent->count;
#line 34
            sjt_functionParam228 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent170, sjt_functionParam226, sjt_functionParam227, sjt_functionParam228, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent171 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent171, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart19 = 0;
#line 37
            sjt_forEnd19 = item->count;
#line 37
            i = sjt_forStart19;
            while (i < sjt_forEnd19) {
                int32_t sjt_functionParam229;
                char sjt_functionParam230;
                int32_t sjt_functionParam231;
                sjs_array_char* sjt_parent172 = 0;
                sjs_string* sjt_parent173 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent172 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam229 = newcount;
#line 18
                sjt_parent173 = item;
#line 37
                sjt_functionParam231 = i;
#line 37
                sjf_string_getat(sjt_parent173, sjt_functionParam231, &sjt_functionParam230);
#line 37
                sjf_array_char_initat(sjt_parent172, sjt_functionParam229, sjt_functionParam230);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 37
            (*_return)->_refCount = 1;
#line 42
            (*_return)->offset = 0;
#line 42
            (*_return)->count = newcount;
#line 42
            (*_return)->data._refCount = 1;
#line 42
            sjf_array_char_copy(&(*_return)->data, &newdata);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 12 "lib/sj-lib-common/string.sj"
    _this->offset = _from->offset;
#line 12
    _this->count = _from->count;
#line 12
    _this->data._refCount = 1;
#line 12
    sjf_array_char_copy(&_this->data, &_from->data);
#line 12
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam215;
    sjs_array_char* sjt_parent160 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent160 = &_parent->data;
#line 64 "lib/sj-lib-common/string.sj"
    sjt_functionParam215 = _parent->offset + index;
#line 64
    sjf_array_char_getat(sjt_parent160, sjt_functionParam215, _return);
}

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
#line 148 "lib/sj-lib-common/string.sj"
    #line 147 "lib/sj-lib-common/string.sj"
(*_return) = kh_str_hash_func(((sjs_array*)_parent->data.v)->data + _parent->offset, _parent->count);
return;;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
#line 73 "lib/sj-lib-common/string.sj"
    sjs_array* arr1 = (sjs_array*)_parent->data.v;
#line 74
    sjs_array* arr2 = (sjs_array*)test->data.v;
#line 75
    if (_parent->count != test->count) {
#line 76
        #line 72 "lib/sj-lib-common/string.sj"
(*_return) = false;
return;;      
#line 77
    }
#line 78
    bool result = memcmp(arr1->data + _parent->offset, arr2->data + test->offset, _parent->count) == 0;
#line 79
    #line 72 "lib/sj-lib-common/string.sj"
(*_return) = result;
return;;      
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    sjs_array_char sjt_funcold1 = { -1 };

#line 133 "lib/sj-lib-common/string.sj"
    result2 = !_parent->_isnullterminated;
    if (result2) {
        int32_t sjt_capture1;
        int32_t sjt_capture2;
        sjs_array_char* sjt_parent1 = 0;
        sjs_array_char* sjt_parent2 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent1 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent1, &sjt_capture1);
#line 29
        sjt_parent2 = &_parent->data;
#line 29
        sjf_array_char_getcount(sjt_parent2, &sjt_capture2);
        if ((((_parent->offset + _parent->count) + 1) > sjt_capture1) || ((_parent->offset + _parent->count) != sjt_capture2)) {
            int32_t sjt_functionParam1;
            int32_t sjt_functionParam2;
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent3 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent3 = &_parent->data;
#line 135 "lib/sj-lib-common/string.sj"
            sjt_functionParam1 = _parent->offset;
#line 135
            sjt_functionParam2 = _parent->count;
#line 135
            sjt_functionParam3 = _parent->count + 1;
#line 135
            sjf_array_char_clone(sjt_parent3, sjt_functionParam1, sjt_functionParam2, sjt_functionParam3, &sjt_funcold1);
#line 135
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 168 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
#line 136 "lib/sj-lib-common/string.sj"
            _parent->offset = 0;
        }

#line 139 "lib/sj-lib-common/string.sj"
        ((sjs_array*)_parent->data.v)->data[_parent->offset + _parent->count] = 0;
#line 141
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_style(sjs_style* _this) {
}

void sjf_style_copy(sjs_style* _this, sjs_style* _from) {
}

void sjf_style_destroy(sjs_style* _this) {
}

void sjf_style_getfont_heap(sjs_style* _parent, sjs_font** _return) {
    sjs_string sjt_call127 = { -1 };
    sjs_string* sjt_functionParam407 = 0;
    float sjt_functionParam408;

    sjt_call127._refCount = 1;
#line 3 "lib/sj-lib-ui/style.sj"
    sjt_call127.offset = 0;
#line 3
    sjt_call127.count = 32;
#line 3
    sjt_call127.data._refCount = 1;
#line 3
    sjt_call127.data.v = &sjg_string27;
#line 3
    sjf_array_char(&sjt_call127.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call127._isnullterminated = false;
#line 16
    sjf_string(&sjt_call127);
#line 3 "lib/sj-lib-ui/style.sj"
    sjt_functionParam407 = &sjt_call127;
#line 3
    sjt_functionParam408 = 24.0f;
#line 3
    sjf_font_load_heap(sjt_functionParam407, sjt_functionParam408, _return);

    if (sjt_call127._refCount == 1) { sjf_string_destroy(&sjt_call127); }
;
}

void sjf_style_heap(sjs_style* _this) {
}

void sjf_testscene_heap(sji_element* _return) {
    sjs_model* object1 = 0;
    float result11;
    sjs_scene3delement* sjt_call10 = 0;
    sjs_string sjt_call118 = { -1 };
    sjs_string sjt_call119 = { -1 };
    sjs_textelement* sjt_call120 = 0;
    sjs_model* sjt_call15 = 0;
    sjs_filllayout* sjt_call8 = 0;
    sjs_boxelement* sjt_call9 = 0;
    sjs_model* sjt_cast10 = 0;
    sjs_textelement* sjt_cast13 = 0;
    sjs_filllayout* sjt_cast5 = 0;
    sjs_boxelement* sjt_cast6 = 0;
    sjs_scene3delement* sjt_cast7 = 0;
    int32_t sjt_functionParam147;
    sji_model sjt_functionParam148 = { 0 };
    sjs_string* sjt_functionParam364 = 0;
    sjs_string* sjt_functionParam365 = 0;
    float sjt_functionParam366;
    float sjt_functionParam367;
    float sjt_functionParam368;
    int32_t sjt_functionParam369;
    sji_element sjt_functionParam370 = { 0 };
    int32_t sjt_functionParam63;
    sji_element sjt_functionParam64 = { 0 };
    int32_t sjt_functionParam69;
    sji_element sjt_functionParam70 = { 0 };
    sjs_array_heap_iface_model* sjt_parent125 = 0;
    sjs_array_heap_iface_element* sjt_parent290 = 0;
    sjs_style* sjt_parent306 = 0;
    sjs_array_heap_iface_element* sjt_parent65 = 0;
    sjs_array_heap_iface_element* sjt_parent70 = 0;

    sjt_call8 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call8->_refCount = 1;
    sjt_call8->children._refCount = 1;
#line 5 "effect.sj"
    sjt_call8->children.v = createarray(sizeof(sji_element), 3);
#line 5
    sjf_array_heap_iface_element(&sjt_call8->children);
#line 5
    sjs_array_heap_iface_element* array5;
#line 5
    array5 = &sjt_call8->children;
#line 5
    sjt_parent65 = array5;
#line 5
    sjt_functionParam63 = 0;
#line 5
    sjt_call9 = (sjs_boxelement*)malloc(sizeof(sjs_boxelement));
#line 5
    sjt_call9->_refCount = 1;
#line 5
    sjt_call9->color._refCount = 1;
#line 5
    sjf_f32_random(&sjt_call9->color.r);
#line 5
    sjf_f32_random(&sjt_call9->color.g);
#line 5
    sjf_f32_random(&sjt_call9->color.b);
#line 14 "lib/sj-lib-ui/color.sj"
    sjt_call9->color.a = 1.0f;
#line 14
    sjf_color(&sjt_call9->color);
#line 14
    sjt_call9->idealsize._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    sjt_call9->idealsize.w = 0;
#line 3
    sjt_call9->idealsize.h = 0;
#line 3
    sjf_size(&sjt_call9->idealsize);
#line 3
    sjt_call9->rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call9->rect.x = 0;
#line 3
    sjt_call9->rect.y = 0;
#line 4
    sjt_call9->rect.w = 0;
#line 5
    sjt_call9->rect.h = 0;
#line 5
    sjf_rect(&sjt_call9->rect);
#line 5 "lib/sj-lib-ui/boxElement.sj"
    sjt_call9->boxrenderer._refCount = -1;
#line 5
    sjf_boxelement_heap(sjt_call9);
#line 6 "effect.sj"
    sjt_cast6 = sjt_call9;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_boxelement_as_sji_element(sjt_cast6, &sjt_functionParam64);
    if (sjt_functionParam64._parent != 0) {
        sjt_functionParam64._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent65, sjt_functionParam63, sjt_functionParam64);
#line 5 "effect.sj"
    sjt_parent70 = array5;
#line 5
    sjt_functionParam69 = 1;
#line 5
    sjt_call10 = (sjs_scene3delement*)malloc(sizeof(sjs_scene3delement));
#line 5
    sjt_call10->_refCount = 1;
#line 5
    sjt_call10->children._refCount = 1;
#line 11
    sjt_call10->children.v = createarray(sizeof(sji_model), 1);
#line 11
    sjf_array_heap_iface_model(&sjt_call10->children);
#line 11
    sjs_array_heap_iface_model* array6;
#line 11
    array6 = &sjt_call10->children;
#line 11
    sjt_parent125 = array6;
#line 11
    sjt_functionParam147 = 0;
#line 11
    object1 = (sjs_model*)malloc(sizeof(sjs_model));
#line 11
    object1->_refCount = 1;
#line 11
    sjt_call118._refCount = 1;
#line 13
    sjt_call118.offset = 0;
#line 13
    sjt_call118.count = 17;
#line 13
    sjt_call118.data._refCount = 1;
#line 13
    sjt_call118.data.v = &sjg_string25;
#line 13
    sjf_array_char(&sjt_call118.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call118._isnullterminated = false;
#line 16
    sjf_string(&sjt_call118);
#line 13 "effect.sj"
    sjt_functionParam364 = &sjt_call118;
#line 13
    sjf_vertexbuffer_loadobj(sjt_functionParam364, &object1->vertexbuffer);
#line 13
    object1->shader._refCount = 1;
#line 12
    sjf_shader_copy(&object1->shader, &g_phongtextureshader);
#line 12
    sjt_call119._refCount = 1;
#line 15
    sjt_call119.offset = 0;
#line 15
    sjt_call119.count = 14;
#line 15
    sjt_call119.data._refCount = 1;
#line 15
    sjt_call119.data.v = &sjg_string26;
#line 15
    sjf_array_char(&sjt_call119.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call119._isnullterminated = false;
#line 16
    sjf_string(&sjt_call119);
#line 15 "effect.sj"
    sjt_functionParam365 = &sjt_call119;
#line 15
    sjf_texture_frompng(sjt_functionParam365, &object1->texture);
#line 16
    sjt_functionParam366 = 0.02f;
#line 16
    sjt_functionParam367 = 0.02f;
#line 16
    sjt_functionParam368 = 0.02f;
#line 16
    sjf_mat4_scale(sjt_functionParam366, sjt_functionParam367, sjt_functionParam368, &object1->model);
#line 16
    object1->center._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    object1->center.x = 0.0f;
#line 3
    object1->center.y = 0.0f;
#line 4
    object1->center.z = 0.0f;
#line 4
    sjf_vec3(&object1->center);
#line 22 "lib/sj-lib-ui/model.sj"
    object1->hasalpha = false;
#line 23
    object1->id._refCount = -1;
#line 23
    object1->_projection._refCount = 1;
#line 2 "lib/sj-lib-ui/mat4.sj"
    object1->_projection.m00 = 0.0f;
#line 3
    object1->_projection.m01 = 0.0f;
#line 4
    object1->_projection.m02 = 0.0f;
#line 5
    object1->_projection.m03 = 0.0f;
#line 6
    object1->_projection.m10 = 0.0f;
#line 7
    object1->_projection.m11 = 0.0f;
#line 8
    object1->_projection.m12 = 0.0f;
#line 9
    object1->_projection.m13 = 0.0f;
#line 10
    object1->_projection.m20 = 0.0f;
#line 11
    object1->_projection.m21 = 0.0f;
#line 12
    object1->_projection.m22 = 0.0f;
#line 13
    object1->_projection.m23 = 0.0f;
#line 14
    object1->_projection.m30 = 0.0f;
#line 15
    object1->_projection.m31 = 0.0f;
#line 16
    object1->_projection.m32 = 0.0f;
#line 17
    object1->_projection.m33 = 0.0f;
#line 17
    sjf_mat4(&object1->_projection);
#line 17
    object1->_view._refCount = 1;
#line 2
    object1->_view.m00 = 0.0f;
#line 3
    object1->_view.m01 = 0.0f;
#line 4
    object1->_view.m02 = 0.0f;
#line 5
    object1->_view.m03 = 0.0f;
#line 6
    object1->_view.m10 = 0.0f;
#line 7
    object1->_view.m11 = 0.0f;
#line 8
    object1->_view.m12 = 0.0f;
#line 9
    object1->_view.m13 = 0.0f;
#line 10
    object1->_view.m20 = 0.0f;
#line 11
    object1->_view.m21 = 0.0f;
#line 12
    object1->_view.m22 = 0.0f;
#line 13
    object1->_view.m23 = 0.0f;
#line 14
    object1->_view.m30 = 0.0f;
#line 15
    object1->_view.m31 = 0.0f;
#line 16
    object1->_view.m32 = 0.0f;
#line 17
    object1->_view.m33 = 0.0f;
#line 17
    sjf_mat4(&object1->_view);
#line 17
    object1->_world._refCount = 1;
#line 2
    object1->_world.m00 = 0.0f;
#line 3
    object1->_world.m01 = 0.0f;
#line 4
    object1->_world.m02 = 0.0f;
#line 5
    object1->_world.m03 = 0.0f;
#line 6
    object1->_world.m10 = 0.0f;
#line 7
    object1->_world.m11 = 0.0f;
#line 8
    object1->_world.m12 = 0.0f;
#line 9
    object1->_world.m13 = 0.0f;
#line 10
    object1->_world.m20 = 0.0f;
#line 11
    object1->_world.m21 = 0.0f;
#line 12
    object1->_world.m22 = 0.0f;
#line 13
    object1->_world.m23 = 0.0f;
#line 14
    object1->_world.m30 = 0.0f;
#line 15
    object1->_world.m31 = 0.0f;
#line 16
    object1->_world.m32 = 0.0f;
#line 17
    object1->_world.m33 = 0.0f;
#line 17
    sjf_mat4(&object1->_world);
#line 17
    object1->_light._refCount = 1;
#line 17
    object1->_light.pos._refCount = 1;
#line 2 "lib/sj-lib-ui/scene3dElement.sj"
    object1->_light.pos.x = 1.0f;
#line 2
    object1->_light.pos.y = 1.0f;
#line 2
    object1->_light.pos.z = 1.0f;
#line 2
    sjf_vec3(&object1->_light.pos);
#line 2
    object1->_light.diffusecolor._refCount = 1;
#line 3
    object1->_light.diffusecolor.r = 0.5f;
#line 3
    object1->_light.diffusecolor.g = 0.5f;
#line 3
    object1->_light.diffusecolor.b = 0.0f;
#line 3
    object1->_light.diffusecolor.a = 1.0f;
#line 3
    sjf_color(&object1->_light.diffusecolor);
#line 3
    object1->_light.speccolor._refCount = 1;
#line 4
    object1->_light.speccolor.r = 1.0f;
#line 4
    object1->_light.speccolor.g = 1.0f;
#line 4
    object1->_light.speccolor.b = 1.0f;
#line 4
    object1->_light.speccolor.a = 1.0f;
#line 4
    sjf_color(&object1->_light.speccolor);
#line 4
    sjf_light(&object1->_light);
#line 4
    object1->_projectedcenter._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    object1->_projectedcenter.x = 0.0f;
#line 3
    object1->_projectedcenter.y = 0.0f;
#line 4
    object1->_projectedcenter.z = 0.0f;
#line 4
    sjf_vec3(&object1->_projectedcenter);
#line 4
    sjf_model_heap(object1, &sjt_call15);
#line 12 "effect.sj"
    sjt_cast10 = sjt_call15;
#line 1 "lib/sj-lib-ui/model.sj"
    sjf_model_as_sji_model(sjt_cast10, &sjt_functionParam148);
    if (sjt_functionParam148._parent != 0) {
        sjt_functionParam148._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_model_initat(sjt_parent125, sjt_functionParam147, sjt_functionParam148);
#line 1
    sjt_call10->camera._refCount = 1;
#line 13 "lib/sj-lib-ui/scene3dElement.sj"
    sjt_call10->camera.x = 0.0f;
#line 13
    sjt_call10->camera.y = 0.0f;
#line 13
    result11 = -5.0f;
#line 13
    sjt_call10->camera.z = result11;
#line 13
    sjf_vec3(&sjt_call10->camera);
#line 13
    sjt_call10->lookat._refCount = 1;
#line 14
    sjt_call10->lookat.x = 0.0f;
#line 14
    sjt_call10->lookat.y = 0.0f;
#line 14
    sjt_call10->lookat.z = 0.0f;
#line 14
    sjf_vec3(&sjt_call10->lookat);
#line 14
    sjt_call10->up._refCount = 1;
#line 15
    sjt_call10->up.x = 0.0f;
#line 15
    sjt_call10->up.y = 1.0f;
#line 15
    sjt_call10->up.z = 0.0f;
#line 15
    sjf_vec3(&sjt_call10->up);
#line 16
    sjt_call10->fieldofview = 90.0f;
#line 17
    sjt_call10->znear = 1.0f;
#line 18
    sjt_call10->zfar = 100.0f;
#line 18
    sjt_call10->light._refCount = 1;
#line 18
    sjt_call10->light.pos._refCount = 1;
#line 2
    sjt_call10->light.pos.x = 1.0f;
#line 2
    sjt_call10->light.pos.y = 1.0f;
#line 2
    sjt_call10->light.pos.z = 1.0f;
#line 2
    sjf_vec3(&sjt_call10->light.pos);
#line 2
    sjt_call10->light.diffusecolor._refCount = 1;
#line 3
    sjt_call10->light.diffusecolor.r = 0.5f;
#line 3
    sjt_call10->light.diffusecolor.g = 0.5f;
#line 3
    sjt_call10->light.diffusecolor.b = 0.0f;
#line 3
    sjt_call10->light.diffusecolor.a = 1.0f;
#line 3
    sjf_color(&sjt_call10->light.diffusecolor);
#line 3
    sjt_call10->light.speccolor._refCount = 1;
#line 4
    sjt_call10->light.speccolor.r = 1.0f;
#line 4
    sjt_call10->light.speccolor.g = 1.0f;
#line 4
    sjt_call10->light.speccolor.b = 1.0f;
#line 4
    sjt_call10->light.speccolor.a = 1.0f;
#line 4
    sjf_color(&sjt_call10->light.speccolor);
#line 4
    sjf_light(&sjt_call10->light);
#line 4
    sjt_call10->projection._refCount = 1;
#line 2 "lib/sj-lib-ui/mat4.sj"
    sjt_call10->projection.m00 = 0.0f;
#line 3
    sjt_call10->projection.m01 = 0.0f;
#line 4
    sjt_call10->projection.m02 = 0.0f;
#line 5
    sjt_call10->projection.m03 = 0.0f;
#line 6
    sjt_call10->projection.m10 = 0.0f;
#line 7
    sjt_call10->projection.m11 = 0.0f;
#line 8
    sjt_call10->projection.m12 = 0.0f;
#line 9
    sjt_call10->projection.m13 = 0.0f;
#line 10
    sjt_call10->projection.m20 = 0.0f;
#line 11
    sjt_call10->projection.m21 = 0.0f;
#line 12
    sjt_call10->projection.m22 = 0.0f;
#line 13
    sjt_call10->projection.m23 = 0.0f;
#line 14
    sjt_call10->projection.m30 = 0.0f;
#line 15
    sjt_call10->projection.m31 = 0.0f;
#line 16
    sjt_call10->projection.m32 = 0.0f;
#line 17
    sjt_call10->projection.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call10->projection);
#line 17
    sjt_call10->view._refCount = 1;
#line 2
    sjt_call10->view.m00 = 0.0f;
#line 3
    sjt_call10->view.m01 = 0.0f;
#line 4
    sjt_call10->view.m02 = 0.0f;
#line 5
    sjt_call10->view.m03 = 0.0f;
#line 6
    sjt_call10->view.m10 = 0.0f;
#line 7
    sjt_call10->view.m11 = 0.0f;
#line 8
    sjt_call10->view.m12 = 0.0f;
#line 9
    sjt_call10->view.m13 = 0.0f;
#line 10
    sjt_call10->view.m20 = 0.0f;
#line 11
    sjt_call10->view.m21 = 0.0f;
#line 12
    sjt_call10->view.m22 = 0.0f;
#line 13
    sjt_call10->view.m23 = 0.0f;
#line 14
    sjt_call10->view.m30 = 0.0f;
#line 15
    sjt_call10->view.m31 = 0.0f;
#line 16
    sjt_call10->view.m32 = 0.0f;
#line 17
    sjt_call10->view.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call10->view);
#line 17
    sjf_mat4_identity(&sjt_call10->world);
#line 17
    sjt_call10->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call10->_rect.x = 0;
#line 3
    sjt_call10->_rect.y = 0;
#line 4
    sjt_call10->_rect.w = 0;
#line 5
    sjt_call10->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call10->_rect);
#line 5
    sjf_scene3delement_heap(sjt_call10);
#line 10 "effect.sj"
    sjt_cast7 = sjt_call10;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_scene3delement_as_sji_element(sjt_cast7, &sjt_functionParam70);
    if (sjt_functionParam70._parent != 0) {
        sjt_functionParam70._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent70, sjt_functionParam69, sjt_functionParam70);
#line 5 "effect.sj"
    sjt_parent290 = array5;
#line 5
    sjt_functionParam369 = 2;
#line 5
    sjt_call120 = (sjs_textelement*)malloc(sizeof(sjs_textelement));
#line 5
    sjt_call120->_refCount = 1;
#line 20 "lib/sj-lib-ui/textElement.sj"
    sjt_call120->id._refCount = -1;
#line 2 "lib/sj-lib-ui/style.sj"
    sjt_parent306 = &g_style;
#line 2
    sjf_style_getfont_heap(sjt_parent306, &sjt_call120->font);
#line 2
    sjt_call120->text._refCount = 1;
#line 22 "effect.sj"
    sjt_call120->text.offset = 0;
#line 22
    sjt_call120->text.count = 5;
#line 22
    sjt_call120->text.data._refCount = 1;
#line 22
    sjt_call120->text.data.v = &sjg_string31;
#line 22
    sjf_array_char(&sjt_call120->text.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call120->text._isnullterminated = false;
#line 16
    sjf_string(&sjt_call120->text);
#line 16
    sjt_call120->color._refCount = 1;
#line 21 "effect.sj"
    sjf_color_copy(&sjt_call120->color, &g_colors_white);
#line 21
    sjt_call120->margin._refCount = 1;
#line 2 "lib/sj-lib-ui/margin.sj"
    sjt_call120->margin.l = 0;
#line 3
    sjt_call120->margin.t = 0;
#line 4
    sjt_call120->margin.r = 0;
#line 5
    sjt_call120->margin.b = 0;
#line 5
    sjf_margin(&sjt_call120->margin);
#line 21 "effect.sj"
    sjt_call120->halign = g_texthorizontal_center;
#line 21
    sjt_call120->valign = g_textvertical_center;
#line 27 "lib/sj-lib-ui/textElement.sj"
    sjt_call120->idealsize._refCount = -1;
#line 27
    sjt_call120->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call120->_rect.x = 0;
#line 3
    sjt_call120->_rect.y = 0;
#line 4
    sjt_call120->_rect.w = 0;
#line 5
    sjt_call120->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call120->_rect);
#line 29 "lib/sj-lib-ui/textElement.sj"
    sjt_call120->_textrenderer._refCount = -1;
#line 29
    sjf_textelement_heap(sjt_call120);
#line 21 "effect.sj"
    sjt_cast13 = sjt_call120;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_textelement_as_sji_element(sjt_cast13, &sjt_functionParam370);
    if (sjt_functionParam370._parent != 0) {
        sjt_functionParam370._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent290, sjt_functionParam369, sjt_functionParam370);
#line 1
    sjt_call8->margin._refCount = 1;
#line 2 "lib/sj-lib-ui/margin.sj"
    sjt_call8->margin.l = 0;
#line 3
    sjt_call8->margin.t = 0;
#line 4
    sjt_call8->margin.r = 0;
#line 5
    sjt_call8->margin.b = 0;
#line 5
    sjf_margin(&sjt_call8->margin);
#line 4 "lib/sj-lib-ui/fillLayout.sj"
    sjt_call8->effect._parent = 0;
#line 4
    sjt_call8->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call8->_rect.x = 0;
#line 3
    sjt_call8->_rect.y = 0;
#line 4
    sjt_call8->_rect.w = 0;
#line 5
    sjt_call8->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call8->_rect);
#line 5
    sjf_filllayout_heap(sjt_call8);
#line 4 "effect.sj"
    sjt_cast5 = sjt_call8;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_filllayout_as_sji_element(sjt_cast5, &(*_return));
    if ((*_return)._parent != 0) {
        (*_return)._parent->_refCount++;
    }

    object1->_refCount--;
    if (object1->_refCount <= 0) {
        weakptr_release(object1);
        sjf_model_destroy(object1);
        free(object1);
    }
    sjt_call10->_refCount--;
    if (sjt_call10->_refCount <= 0) {
        weakptr_release(sjt_call10);
        sjf_scene3delement_destroy(sjt_call10);
        free(sjt_call10);
    }
    sjt_call120->_refCount--;
    if (sjt_call120->_refCount <= 0) {
        weakptr_release(sjt_call120);
        sjf_textelement_destroy(sjt_call120);
        free(sjt_call120);
    }
    sjt_call15->_refCount--;
    if (sjt_call15->_refCount <= 0) {
        weakptr_release(sjt_call15);
        sjf_model_destroy(sjt_call15);
        free(sjt_call15);
    }
    sjt_call8->_refCount--;
    if (sjt_call8->_refCount <= 0) {
        weakptr_release(sjt_call8);
        sjf_filllayout_destroy(sjt_call8);
        free(sjt_call8);
    }
    sjt_call9->_refCount--;
    if (sjt_call9->_refCount <= 0) {
        weakptr_release(sjt_call9);
        sjf_boxelement_destroy(sjt_call9);
        free(sjt_call9);
    }
    if (sjt_functionParam148._parent != 0) {
        sjt_functionParam148._parent->_refCount--;
        if (sjt_functionParam148._parent->_refCount <= 0) {
            sjt_functionParam148._vtbl->destroy(sjt_functionParam148._parent);
            free(sjt_functionParam148._parent);
        }
    }
    if (sjt_functionParam370._parent != 0) {
        sjt_functionParam370._parent->_refCount--;
        if (sjt_functionParam370._parent->_refCount <= 0) {
            sjt_functionParam370._vtbl->destroy(sjt_functionParam370._parent);
            free(sjt_functionParam370._parent);
        }
    }
    if (sjt_functionParam64._parent != 0) {
        sjt_functionParam64._parent->_refCount--;
        if (sjt_functionParam64._parent->_refCount <= 0) {
            sjt_functionParam64._vtbl->destroy(sjt_functionParam64._parent);
            free(sjt_functionParam64._parent);
        }
    }
    if (sjt_functionParam70._parent != 0) {
        sjt_functionParam70._parent->_refCount--;
        if (sjt_functionParam70._parent->_refCount <= 0) {
            sjt_functionParam70._vtbl->destroy(sjt_functionParam70._parent);
            free(sjt_functionParam70._parent);
        }
    }
    if (sjt_call118._refCount == 1) { sjf_string_destroy(&sjt_call118); }
;
    if (sjt_call119._refCount == 1) { sjf_string_destroy(&sjt_call119); }
;
}

void sjf_textelement_as_sji_element(sjs_textelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_textelement_element_vtbl;
}

void sjf_textelement_as_sji_textelement(sjs_textelement* _this, sji_textelement* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_textelement_textelement_vtbl;
}

void sjf_textelement_asinterface(sjs_textelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_textelement_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        case sji_textelement_typeId:  {
            sjf_textelement_as_sji_textelement(_this, (sji_textelement*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_textelement_copy(sjs_textelement* _this, sjs_textelement* _from) {
#line 18 "lib/sj-lib-ui/textElement.sj"
    sjs_string* copyoption17 = (_from->id._refCount != -1 ? &_from->id : 0);
    if (copyoption17 != 0) {
        _this->id._refCount = 1;
#line 18 "lib/sj-lib-ui/textElement.sj"
        sjf_string_copy(&_this->id, copyoption17);
    } else {
        _this->id._refCount = -1;
    }

#line 18
    _this->font = _from->font;
#line 18
    _this->font->_refCount++;
#line 18
    _this->text._refCount = 1;
#line 18
    sjf_string_copy(&_this->text, &_from->text);
#line 18
    _this->color._refCount = 1;
#line 18
    sjf_color_copy(&_this->color, &_from->color);
#line 18
    _this->margin._refCount = 1;
#line 18
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 18
    _this->halign = _from->halign;
#line 18
    _this->valign = _from->valign;
#line 18
    sjs_size* copyoption18 = (_from->idealsize._refCount != -1 ? &_from->idealsize : 0);
    if (copyoption18 != 0) {
        _this->idealsize._refCount = 1;
#line 18 "lib/sj-lib-ui/textElement.sj"
        sjf_size_copy(&_this->idealsize, copyoption18);
    } else {
        _this->idealsize._refCount = -1;
    }

#line 18
    _this->_rect._refCount = 1;
#line 18
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 18
    sjs_textrenderer* copyoption19 = (_from->_textrenderer._refCount != -1 ? &_from->_textrenderer : 0);
    if (copyoption19 != 0) {
        _this->_textrenderer._refCount = 1;
#line 18 "lib/sj-lib-ui/textElement.sj"
        sjf_textrenderer_copy(&_this->_textrenderer, copyoption19);
    } else {
        _this->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_destroy(sjs_textelement* _this) {
    _this->font->_refCount--;
    if (_this->font->_refCount <= 0) {
        weakptr_release(_this->font);
        sjf_font_destroy(_this->font);
        free(_this->font);
    }

    if (_this->id._refCount == 1) { sjf_string_destroy(&_this->id); }
;
    if (_this->text._refCount == 1) { sjf_string_destroy(&_this->text); }
;
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->idealsize._refCount == 1) { sjf_size_destroy(&_this->idealsize); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
    if (_this->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_this->_textrenderer); }
;
}

void sjf_textelement_firemouseevent(sjs_textelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
#line 87 "lib/sj-lib-ui/textElement.sj"
    (*_return) = true;
}

void sjf_textelement_getclasstype(sjs_object* _this, int* _return) {
    *_return = 258;
}

void sjf_textelement_getrect(sjs_textelement* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 40 "lib/sj-lib-ui/textElement.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_textelement_getrect_heap(sjs_textelement* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 40 "lib/sj-lib-ui/textElement.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_textelement_getsize(sjs_textelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue9 = 0;
        sjs_size* sjt_functionParam373 = 0;
        sjs_size* sjt_parent292 = 0;

#line 32 "lib/sj-lib-ui/textElement.sj"
        ifValue9 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
#line 5 "lib/sj-lib-ui/size.sj"
        sjt_parent292 = ifValue9;
#line 31 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam373 = maxsize;
#line 31
        sjf_size_min(sjt_parent292, sjt_functionParam373, _return);
    } else {
        sjs_size sjt_call121 = { -1 };
        sjs_string* sjt_functionParam374 = 0;
        sjs_margin* sjt_functionParam375 = 0;
        sjs_size* sjt_functionParam376 = 0;
        sjs_size* sjt_parent293 = 0;
        sjs_font* sjt_parent294 = 0;
        sjs_size* sjt_parent295 = 0;
        sjs_size textsize = { -1 };

#line 53 "lib/sj-lib-ui/font.sj"
        sjt_parent294 = _parent->font;
#line 35 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam374 = &_parent->text;
#line 35
        sjf_font_gettextsize(sjt_parent294, sjt_functionParam374, &sjt_call121);
#line 35
        sjt_parent293 = &sjt_call121;
#line 35
        sjt_functionParam375 = &_parent->margin;
#line 35
        sjf_size_addmargin(sjt_parent293, sjt_functionParam375, &textsize);
#line 5 "lib/sj-lib-ui/size.sj"
        sjt_parent295 = &textsize;
#line 31 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam376 = maxsize;
#line 31
        sjf_size_min(sjt_parent295, sjt_functionParam376, _return);

        if (sjt_call121._refCount == 1) { sjf_size_destroy(&sjt_call121); }
;
        if (textsize._refCount == 1) { sjf_size_destroy(&textsize); }
;
    }
}

void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue12 = 0;
        sjs_size* sjt_functionParam377 = 0;
        sjs_size* sjt_parent296 = 0;

#line 32 "lib/sj-lib-ui/textElement.sj"
        ifValue12 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
#line 5 "lib/sj-lib-ui/size.sj"
        sjt_parent296 = ifValue12;
#line 31 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam377 = maxsize;
#line 31
        sjf_size_min_heap(sjt_parent296, sjt_functionParam377, _return);
    } else {
        sjs_size sjt_call122 = { -1 };
        sjs_string* sjt_functionParam378 = 0;
        sjs_margin* sjt_functionParam379 = 0;
        sjs_size* sjt_functionParam380 = 0;
        sjs_size* sjt_parent297 = 0;
        sjs_font* sjt_parent298 = 0;
        sjs_size* sjt_parent299 = 0;
        sjs_size textsize = { -1 };

#line 53 "lib/sj-lib-ui/font.sj"
        sjt_parent298 = _parent->font;
#line 35 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam378 = &_parent->text;
#line 35
        sjf_font_gettextsize(sjt_parent298, sjt_functionParam378, &sjt_call122);
#line 35
        sjt_parent297 = &sjt_call122;
#line 35
        sjt_functionParam379 = &_parent->margin;
#line 35
        sjf_size_addmargin(sjt_parent297, sjt_functionParam379, &textsize);
#line 5 "lib/sj-lib-ui/size.sj"
        sjt_parent299 = &textsize;
#line 31 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam380 = maxsize;
#line 31
        sjf_size_min_heap(sjt_parent299, sjt_functionParam380, _return);

        if (sjt_call122._refCount == 1) { sjf_size_destroy(&sjt_call122); }
;
        if (textsize._refCount == 1) { sjf_size_destroy(&textsize); }
;
    }
}

void sjf_textelement_gettext(sjs_textelement* _parent, sjs_string* _return) {
    _return->_refCount = 1;
#line 49 "lib/sj-lib-ui/textElement.sj"
    sjf_string_copy(_return, &_parent->text);
}

void sjf_textelement_gettext_heap(sjs_textelement* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 49 "lib/sj-lib-ui/textElement.sj"
    sjf_string_copy((*_return), &_parent->text);
}

void sjf_textelement_heap(sjs_textelement* _this) {
    if (((_this->id._refCount != -1 ? &_this->id : 0) != 0)) {
        sjs_string* ifValue14 = 0;
        sjs_textelement* sjt_cast14 = 0;
        sjs_string* sjt_functionParam371 = 0;
        sji_element sjt_functionParam372 = { 0 };
        sjs_hash_string_weak_iface_element* sjt_parent291 = 0;

#line 90 "lib/sj-lib-ui/textElement.sj"
        ifValue14 = (_this->id._refCount != -1 ? &_this->id : 0);
#line 38 "lib/sj-lib-common/hash.sj"
        sjt_parent291 = &g_elementsbyid;
#line 91 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam371 = ifValue14;
#line 18
        sjt_cast14 = _this;
#line 1 "lib/sj-lib-ui/element.sj"
        sjf_textelement_as_sji_element(sjt_cast14, &sjt_functionParam372);
#line 1
        delete_cb weakptrcb21 = { &sjt_functionParam372._parent, weakptr_clear };
#line 1
        if (sjt_functionParam372._parent != 0) { weakptr_cb_add(sjt_functionParam372._parent, weakptrcb21); }
#line 1
        sjf_hash_string_weak_iface_element_setat(sjt_parent291, sjt_functionParam371, sjt_functionParam372);

        delete_cb weakptrcb30 = { &sjt_functionParam372._parent, weakptr_clear };
        if (sjt_functionParam372._parent != 0) { weakptr_cb_remove(sjt_functionParam372._parent, weakptrcb30); }
    }
}

void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene) {
    sjs_rect innerrect = { -1 };
    sjs_textrenderer sjt_value3 = { -1 };
    sjs_size textsize = { -1 };

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) == 0) {
        sjs_string* sjt_functionParam382 = 0;
        sjs_margin* sjt_functionParam383 = 0;
        sjs_font* sjt_parent301 = 0;
        sjs_rect* sjt_parent302 = 0;
        int32_t underscore1;
        int32_t underscore2;
        int32_t x;
        int32_t y;

#line 53 "lib/sj-lib-ui/font.sj"
        sjt_parent301 = _parent->font;
#line 58 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam382 = &_parent->text;
#line 58
        sjf_font_gettextsize(sjt_parent301, sjt_functionParam382, &textsize);
#line 7 "lib/sj-lib-ui/rect.sj"
        sjt_parent302 = &_parent->_rect;
#line 59 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam383 = &_parent->margin;
#line 59
        sjf_rect_subtractmargin(sjt_parent302, sjt_functionParam383, &innerrect);
#line 60
        underscore1 = _parent->halign;
        if (underscore1 == g_texthorizontal_left) {
#line 60 "lib/sj-lib-ui/textElement.sj"
            x = (&innerrect)->x;
        } else {
            if (underscore1 == g_texthorizontal_right) {
#line 62 "lib/sj-lib-ui/textElement.sj"
                x = ((&innerrect)->x + (&innerrect)->w) - (&textsize)->w;
            } else {
                if (underscore1 == g_texthorizontal_center) {
#line 63 "lib/sj-lib-ui/textElement.sj"
                    x = (&innerrect)->x + (((&innerrect)->w - (&textsize)->w) / 2);
                } else {
#line 64 "lib/sj-lib-ui/textElement.sj"
                    x = 0;
                }
            }
        }

#line 67
        underscore2 = _parent->valign;
        if (underscore2 == g_textvertical_top) {
#line 67 "lib/sj-lib-ui/textElement.sj"
            y = (&innerrect)->y;
        } else {
            if (underscore2 == g_textvertical_bottom) {
#line 69 "lib/sj-lib-ui/textElement.sj"
                y = ((&innerrect)->y + (&innerrect)->h) - (&textsize)->h;
            } else {
                if (underscore2 == g_textvertical_center) {
#line 70 "lib/sj-lib-ui/textElement.sj"
                    y = (&innerrect)->y + (((&innerrect)->h - (&textsize)->h) / 2);
                } else {
#line 71 "lib/sj-lib-ui/textElement.sj"
                    y = 0;
                }
            }
        }

#line 67
        sjt_value3._refCount = 1;
#line 67
        sjt_value3.text._refCount = 1;
#line 74
        sjf_string_copy(&sjt_value3.text, &_parent->text);
#line 74
        sjt_value3.point._refCount = 1;
#line 76
        sjt_value3.point.x = x;
#line 76
        sjt_value3.point.y = y;
#line 76
        sjf_point(&sjt_value3.point);
#line 76
        sjt_value3.color._refCount = 1;
#line 74
        sjf_color_copy(&sjt_value3.color, &_parent->color);
#line 74
        sjt_value3.font = _parent->font;
#line 74
        sjt_value3.font->_refCount++;
#line 74
        sjf_textrenderer(&sjt_value3);
#line 74
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
#line 74
        sjs_textrenderer* copyoption20 = &sjt_value3;
        if (copyoption20 != 0) {
            _parent->_textrenderer._refCount = 1;
#line 74 "lib/sj-lib-ui/textElement.sj"
            sjf_textrenderer_copy(&_parent->_textrenderer, copyoption20);
        } else {
            _parent->_textrenderer._refCount = -1;
        }
    }

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam403 = 0;
        sjs_textrenderer* sjt_parent303 = 0;

#line 10 "lib/sj-lib-ui/textRenderer.sj"
        sjt_parent303 = (_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0);
#line 56 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam403 = scene;
#line 56
        sjf_textrenderer_render(sjt_parent303, sjt_functionParam403);
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
    if (sjt_value3._refCount == 1) { sjf_textrenderer_destroy(&sjt_value3); }
;
    if (textsize._refCount == 1) { sjf_size_destroy(&textsize); }
;
}

void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_) {
    bool result12;
    bool sjt_capture66;
    sjs_rect* sjt_functionParam381 = 0;
    sjs_rect* sjt_parent300 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent300 = &_parent->_rect;
#line 41 "lib/sj-lib-ui/textElement.sj"
    sjt_functionParam381 = rect_;
#line 41
    sjf_rect_isequal(sjt_parent300, sjt_functionParam381, &sjt_capture66);
#line 42
    result12 = !sjt_capture66;
    if (result12) {
        if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 41 "lib/sj-lib-ui/textElement.sj"
        sjf_rect_copy(&_parent->_rect, rect_);
#line 41
        if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
#line 44
        _parent->_textrenderer._refCount = -1;
    }
}

void sjf_textelement_settext(sjs_textelement* _parent, sjs_string* text_) {
    if (_parent->text._refCount == 1) { sjf_string_destroy(&_parent->text); }
;
#line 50 "lib/sj-lib-ui/textElement.sj"
    sjf_string_copy(&_parent->text, text_);
#line 50
    if (_parent->_textrenderer._refCount == 1) { sjf_textrenderer_destroy(&_parent->_textrenderer); }
;
#line 52
    _parent->_textrenderer._refCount = -1;
}

void sjf_textrenderer(sjs_textrenderer* _this) {
#line 27 "lib/sj-lib-ui/textRenderer.sj"
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
#line 28
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};
#line 30
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
#line 31
    add_text(_this->buffer, _this->font->font, string_char(&_this->text), _this->text.count, &color, &pen);
#line 33
    glBindTexture(GL_TEXTURE_2D, _this->font->font->atlas->id);
#line 34
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font->font->atlas->width, (int)_this->font->font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font->font->atlas->data );
}

void sjf_textrenderer_copy(sjs_textrenderer* _this, sjs_textrenderer* _from) {
    _this->text._refCount = 1;
#line 1 "lib/sj-lib-ui/textRenderer.sj"
    sjf_string_copy(&_this->text, &_from->text);
#line 1
    _this->point._refCount = 1;
#line 1
    sjf_point_copy(&_this->point, &_from->point);
#line 1
    _this->color._refCount = 1;
#line 1
    sjf_color_copy(&_this->color, &_from->color);
#line 1
    _this->font = _from->font;
#line 1
    _this->font->_refCount++;
#line 39
    _this->buffer = _from->buffer;
#line 40
    ptr_retain(_this->buffer);
}

void sjf_textrenderer_destroy(sjs_textrenderer* _this) {
#line 44 "lib/sj-lib-ui/textRenderer.sj"
    if (ptr_release(_this->buffer)) {
#line 45
        vertex_buffer_delete(_this->buffer);
#line 46
    }  
#line 46
    _this->font->_refCount--;
    if (_this->font->_refCount <= 0) {
        weakptr_release(_this->font);
        sjf_font_destroy(_this->font);
        free(_this->font);
    }

#line 46
    if (_this->text._refCount == 1) { sjf_string_destroy(&_this->text); }
;
#line 46
    if (_this->point._refCount == 1) { sjf_point_destroy(&_this->point); }
;
#line 46
    if (_this->color._refCount == 1) { sjf_color_destroy(&_this->color); }
;
}

void sjf_textrenderer_heap(sjs_textrenderer* _this) {
#line 27 "lib/sj-lib-ui/textRenderer.sj"
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
#line 28
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};
#line 30
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
#line 31
    add_text(_this->buffer, _this->font->font, string_char(&_this->text), _this->text.count, &color, &pen);
#line 33
    glBindTexture(GL_TEXTURE_2D, _this->font->font->atlas->id);
#line 34
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font->font->atlas->width, (int)_this->font->font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font->font->atlas->data );
}

void sjf_textrenderer_render(sjs_textrenderer* _parent, sjs_scene2d* scene) {
    sjs_string sjt_call123 = { -1 };
    sjs_string sjt_call124 = { -1 };
    sjs_string sjt_call125 = { -1 };
    sjs_string sjt_call126 = { -1 };
    sjs_shader* sjt_functionParam384 = 0;
    int32_t sjt_functionParam385;
    int32_t sjt_functionParam386;
    int32_t sjt_functionParam387;
    sjs_shader* sjt_functionParam388 = 0;
    sjs_string* sjt_functionParam389 = 0;
    int32_t sjt_functionParam390;
    int32_t sjt_functionParam391;
    sjs_shader* sjt_functionParam392 = 0;
    sjs_string* sjt_functionParam393 = 0;
    sjs_mat4* sjt_functionParam394 = 0;
    int32_t sjt_functionParam395;
    sjs_shader* sjt_functionParam396 = 0;
    sjs_string* sjt_functionParam397 = 0;
    sjs_mat4* sjt_functionParam398 = 0;
    int32_t sjt_functionParam399;
    sjs_shader* sjt_functionParam400 = 0;
    sjs_string* sjt_functionParam401 = 0;
    sjs_mat4* sjt_functionParam402 = 0;

#line 12 "lib/sj-lib-ui/textRenderer.sj"
    glBindTexture(GL_TEXTURE_2D, _parent->font->atlas->id);
#line 14
    sjt_functionParam384 = &g_textshader;
#line 14
    sjf_gluseprogram(sjt_functionParam384);
#line 15
    sjt_functionParam385 = g_glblendfunctype_gl_src_alpha;
#line 15
    sjt_functionParam386 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 15
    sjf_glblendfunc(sjt_functionParam385, sjt_functionParam386);
#line 16
    sjt_functionParam388 = &g_textshader;
#line 16
    sjt_call123._refCount = 1;
#line 16
    sjt_call123.offset = 0;
#line 16
    sjt_call123.count = 7;
#line 16
    sjt_call123.data._refCount = 1;
#line 16
    sjt_call123.data.v = &sjg_string28;
#line 16
    sjf_array_char(&sjt_call123.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call123._isnullterminated = false;
#line 16
    sjf_string(&sjt_call123);
#line 16 "lib/sj-lib-ui/textRenderer.sj"
    sjt_functionParam389 = &sjt_call123;
#line 16
    sjf_glgetuniformlocation(sjt_functionParam388, sjt_functionParam389, &sjt_functionParam387);
#line 16
    sjt_functionParam390 = 0;
#line 16
    sjf_gluniformi32(sjt_functionParam387, sjt_functionParam390);
#line 17
    sjt_functionParam392 = &g_textshader;
#line 17
    sjt_call124._refCount = 1;
#line 17
    sjt_call124.offset = 0;
#line 17
    sjt_call124.count = 5;
#line 17
    sjt_call124.data._refCount = 1;
#line 17
    sjt_call124.data.v = &sjg_string29;
#line 17
    sjf_array_char(&sjt_call124.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call124._isnullterminated = false;
#line 16
    sjf_string(&sjt_call124);
#line 17 "lib/sj-lib-ui/textRenderer.sj"
    sjt_functionParam393 = &sjt_call124;
#line 17
    sjf_glgetuniformlocation(sjt_functionParam392, sjt_functionParam393, &sjt_functionParam391);
#line 17
    sjt_functionParam394 = &scene->model;
#line 17
    sjf_gluniformmat4(sjt_functionParam391, sjt_functionParam394);
#line 18
    sjt_functionParam396 = &g_textshader;
#line 18
    sjt_call125._refCount = 1;
#line 18
    sjt_call125.offset = 0;
#line 18
    sjt_call125.count = 4;
#line 18
    sjt_call125.data._refCount = 1;
#line 18
    sjt_call125.data.v = &sjg_string30;
#line 18
    sjf_array_char(&sjt_call125.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call125._isnullterminated = false;
#line 16
    sjf_string(&sjt_call125);
#line 18 "lib/sj-lib-ui/textRenderer.sj"
    sjt_functionParam397 = &sjt_call125;
#line 18
    sjf_glgetuniformlocation(sjt_functionParam396, sjt_functionParam397, &sjt_functionParam395);
#line 18
    sjt_functionParam398 = &scene->view;
#line 18
    sjf_gluniformmat4(sjt_functionParam395, sjt_functionParam398);
#line 19
    sjt_functionParam400 = &g_textshader;
#line 19
    sjt_call126._refCount = 1;
#line 19
    sjt_call126.offset = 0;
#line 19
    sjt_call126.count = 10;
#line 19
    sjt_call126.data._refCount = 1;
#line 19
    sjt_call126.data.v = &sjg_string19;
#line 19
    sjf_array_char(&sjt_call126.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call126._isnullterminated = false;
#line 16
    sjf_string(&sjt_call126);
#line 19 "lib/sj-lib-ui/textRenderer.sj"
    sjt_functionParam401 = &sjt_call126;
#line 19
    sjf_glgetuniformlocation(sjt_functionParam400, sjt_functionParam401, &sjt_functionParam399);
#line 19
    sjt_functionParam402 = &scene->projection;
#line 19
    sjf_gluniformmat4(sjt_functionParam399, sjt_functionParam402);
#line 21
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call123._refCount == 1) { sjf_string_destroy(&sjt_call123); }
;
    if (sjt_call124._refCount == 1) { sjf_string_destroy(&sjt_call124); }
;
    if (sjt_call125._refCount == 1) { sjf_string_destroy(&sjt_call125); }
;
    if (sjt_call126._refCount == 1) { sjf_string_destroy(&sjt_call126); }
;
}

void sjf_texture(sjs_texture* _this) {
}

void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from) {
    _this->size._refCount = 1;
#line 1 "lib/sj-lib-ui/texture.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 1
    _this->id = _from->id;
#line 10
    glid_retain(_this->id);
}

void sjf_texture_destroy(sjs_texture* _this) {
#line 14 "lib/sj-lib-ui/texture.sj"
    if (glid_release(_this->id)) {
#line 15
        glDeleteTextures(1, &_this->id);
#line 16
    }
#line 16
    if (_this->size._refCount == 1) { sjf_size_destroy(&_this->size); }
;
}

void sjf_texture_frompng(sjs_string* filename, sjs_texture* _return) {
    int32_t h;
    uint32_t id;
    int32_t w;

#line 37 "lib/sj-lib-ui/texture.sj"
    id = (uint32_t)0u;
#line 38
    w = 0;
#line 39
    h = 0;
#line 41
    id = png_texture_load(string_char(filename), &w, &h);
#line 41
    _return->_refCount = 1;
#line 41
    _return->size._refCount = 1;
#line 43
    _return->size.w = w;
#line 43
    _return->size.h = h;
#line 43
    sjf_size(&_return->size);
#line 43
    _return->id = id;
#line 43
    sjf_texture(_return);
}

void sjf_texture_frompng_heap(sjs_string* filename, sjs_texture** _return) {
    int32_t h;
    uint32_t id;
    int32_t w;

#line 37 "lib/sj-lib-ui/texture.sj"
    id = (uint32_t)0u;
#line 38
    w = 0;
#line 39
    h = 0;
#line 41
    id = png_texture_load(string_char(filename), &w, &h);
#line 41
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
#line 41
    (*_return)->_refCount = 1;
#line 41
    (*_return)->size._refCount = 1;
#line 43
    (*_return)->size.w = w;
#line 43
    (*_return)->size.h = h;
#line 43
    sjf_size(&(*_return)->size);
#line 43
    (*_return)->id = id;
#line 43
    sjf_texture_heap((*_return));
}

void sjf_texture_heap(sjs_texture* _this) {
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

#line 5 "lib/sj-lib-common/type.sj"
    sjt_cast1 = val;
#line 6
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
#line 10 "lib/sj-lib-common/type.sj"
    (*_return) = l == r;
}

void sjf_vec2(sjs_vec2* _this) {
}

void sjf_vec2_asstring(sjs_vec2* _parent, sjs_string* _return) {
    sjs_string sjt_call53 = { -1 };
    sjs_string sjt_call54 = { -1 };
    sjs_string sjt_call55 = { -1 };
    sjs_string sjt_call56 = { -1 };
    float sjt_functionParam250;
    sjs_string* sjt_functionParam251 = 0;
    sjs_string* sjt_functionParam252 = 0;
    float sjt_functionParam253;
    sjs_string* sjt_parent188 = 0;
    sjs_string* sjt_parent189 = 0;

#line 6 "lib/sj-lib-ui/vec2.sj"
    sjt_functionParam250 = _parent->x;
#line 6
    sjf_f32_asstring(sjt_functionParam250, &sjt_call54);
#line 6
    sjt_parent189 = &sjt_call54;
#line 6
    sjt_call55._refCount = 1;
#line 6
    sjt_call55.offset = 0;
#line 6
    sjt_call55.count = 2;
#line 6
    sjt_call55.data._refCount = 1;
#line 6
    sjt_call55.data.v = &sjg_string23;
#line 6
    sjf_array_char(&sjt_call55.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call55._isnullterminated = false;
#line 16
    sjf_string(&sjt_call55);
#line 6 "lib/sj-lib-ui/vec2.sj"
    sjt_functionParam251 = &sjt_call55;
#line 6
    sjf_string_add(sjt_parent189, sjt_functionParam251, &sjt_call53);
#line 6
    sjt_parent188 = &sjt_call53;
#line 6
    sjt_functionParam253 = _parent->y;
#line 6
    sjf_f32_asstring(sjt_functionParam253, &sjt_call56);
#line 6
    sjt_functionParam252 = &sjt_call56;
#line 6
    sjf_string_add(sjt_parent188, sjt_functionParam252, _return);

    if (sjt_call53._refCount == 1) { sjf_string_destroy(&sjt_call53); }
;
    if (sjt_call54._refCount == 1) { sjf_string_destroy(&sjt_call54); }
;
    if (sjt_call55._refCount == 1) { sjf_string_destroy(&sjt_call55); }
;
    if (sjt_call56._refCount == 1) { sjf_string_destroy(&sjt_call56); }
;
}

void sjf_vec2_asstring_heap(sjs_vec2* _parent, sjs_string** _return) {
    sjs_string sjt_call57 = { -1 };
    sjs_string sjt_call58 = { -1 };
    sjs_string sjt_call59 = { -1 };
    sjs_string sjt_call60 = { -1 };
    float sjt_functionParam254;
    sjs_string* sjt_functionParam255 = 0;
    sjs_string* sjt_functionParam256 = 0;
    float sjt_functionParam257;
    sjs_string* sjt_parent190 = 0;
    sjs_string* sjt_parent191 = 0;

#line 6 "lib/sj-lib-ui/vec2.sj"
    sjt_functionParam254 = _parent->x;
#line 6
    sjf_f32_asstring(sjt_functionParam254, &sjt_call58);
#line 6
    sjt_parent191 = &sjt_call58;
#line 6
    sjt_call59._refCount = 1;
#line 6
    sjt_call59.offset = 0;
#line 6
    sjt_call59.count = 2;
#line 6
    sjt_call59.data._refCount = 1;
#line 6
    sjt_call59.data.v = &sjg_string23;
#line 6
    sjf_array_char(&sjt_call59.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call59._isnullterminated = false;
#line 16
    sjf_string(&sjt_call59);
#line 6 "lib/sj-lib-ui/vec2.sj"
    sjt_functionParam255 = &sjt_call59;
#line 6
    sjf_string_add(sjt_parent191, sjt_functionParam255, &sjt_call57);
#line 6
    sjt_parent190 = &sjt_call57;
#line 6
    sjt_functionParam257 = _parent->y;
#line 6
    sjf_f32_asstring(sjt_functionParam257, &sjt_call60);
#line 6
    sjt_functionParam256 = &sjt_call60;
#line 6
    sjf_string_add_heap(sjt_parent190, sjt_functionParam256, _return);

    if (sjt_call57._refCount == 1) { sjf_string_destroy(&sjt_call57); }
;
    if (sjt_call58._refCount == 1) { sjf_string_destroy(&sjt_call58); }
;
    if (sjt_call59._refCount == 1) { sjf_string_destroy(&sjt_call59); }
;
    if (sjt_call60._refCount == 1) { sjf_string_destroy(&sjt_call60); }
;
}

void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from) {
#line 1 "lib/sj-lib-ui/vec2.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
}

void sjf_vec2_destroy(sjs_vec2* _this) {
}

void sjf_vec2_getrawsize(int32_t* _return) {
#line 12 "lib/sj-lib-ui/vec2.sj"
    int x = sizeof(float) * 2;
#line 13
    #line 11 "lib/sj-lib-ui/vec2.sj"
(*_return) = x;
return;;
}

void sjf_vec2_heap(sjs_vec2* _this) {
}

void sjf_vec2_rawcopy(sjs_vec2* v, void* p, void** _return) {
#line 19 "lib/sj-lib-ui/vec2.sj"
    float* f = (float*)p;
#line 20
    *f = v->x;
#line 21
    f++;
#line 22
    *f = v->y;
#line 23
    f++;
#line 24
    #line 18 "lib/sj-lib-ui/vec2.sj"
(*_return) = (void*)f;
return;;
}

void sjf_vec3(sjs_vec3* _this) {
}

void sjf_vec3_add(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 24 "lib/sj-lib-ui/vec3.sj"
    _return->x = _parent->x + v->x;
#line 25
    _return->y = _parent->y + v->y;
#line 26
    _return->z = _parent->z + v->z;
#line 26
    sjf_vec3(_return);
}

void sjf_vec3_add_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 24 "lib/sj-lib-ui/vec3.sj"
    (*_return)->x = _parent->x + v->x;
#line 25
    (*_return)->y = _parent->y + v->y;
#line 26
    (*_return)->z = _parent->z + v->z;
#line 26
    sjf_vec3_heap((*_return));
}

void sjf_vec3_asstring(sjs_vec3* _parent, sjs_string* _return) {
    sjs_string sjt_call33 = { -1 };
    sjs_string sjt_call34 = { -1 };
    sjs_string sjt_call35 = { -1 };
    sjs_string sjt_call36 = { -1 };
    sjs_string sjt_call37 = { -1 };
    sjs_string sjt_call38 = { -1 };
    sjs_string sjt_call39 = { -1 };
    sjs_string sjt_call40 = { -1 };
    float sjt_functionParam232;
    sjs_string* sjt_functionParam233 = 0;
    sjs_string* sjt_functionParam234 = 0;
    float sjt_functionParam235;
    sjs_string* sjt_functionParam236 = 0;
    sjs_string* sjt_functionParam237 = 0;
    float sjt_functionParam238;
    sjs_string* sjt_parent178 = 0;
    sjs_string* sjt_parent179 = 0;
    sjs_string* sjt_parent180 = 0;
    sjs_string* sjt_parent181 = 0;

#line 19 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam232 = _parent->x;
#line 19
    sjf_f32_asstring(sjt_functionParam232, &sjt_call36);
#line 19
    sjt_parent181 = &sjt_call36;
#line 19
    sjt_call37._refCount = 1;
#line 19
    sjt_call37.offset = 0;
#line 19
    sjt_call37.count = 2;
#line 19
    sjt_call37.data._refCount = 1;
#line 19
    sjt_call37.data.v = &sjg_string23;
#line 19
    sjf_array_char(&sjt_call37.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call37._isnullterminated = false;
#line 16
    sjf_string(&sjt_call37);
#line 19 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam233 = &sjt_call37;
#line 19
    sjf_string_add(sjt_parent181, sjt_functionParam233, &sjt_call35);
#line 19
    sjt_parent180 = &sjt_call35;
#line 19
    sjt_functionParam235 = _parent->y;
#line 19
    sjf_f32_asstring(sjt_functionParam235, &sjt_call38);
#line 19
    sjt_functionParam234 = &sjt_call38;
#line 19
    sjf_string_add(sjt_parent180, sjt_functionParam234, &sjt_call34);
#line 19
    sjt_parent179 = &sjt_call34;
#line 19
    sjt_call39._refCount = 1;
#line 19
    sjt_call39.offset = 0;
#line 19
    sjt_call39.count = 2;
#line 19
    sjt_call39.data._refCount = 1;
#line 19
    sjt_call39.data.v = &sjg_string23;
#line 19
    sjf_array_char(&sjt_call39.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call39._isnullterminated = false;
#line 16
    sjf_string(&sjt_call39);
#line 19 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam236 = &sjt_call39;
#line 19
    sjf_string_add(sjt_parent179, sjt_functionParam236, &sjt_call33);
#line 19
    sjt_parent178 = &sjt_call33;
#line 19
    sjt_functionParam238 = _parent->z;
#line 19
    sjf_f32_asstring(sjt_functionParam238, &sjt_call40);
#line 19
    sjt_functionParam237 = &sjt_call40;
#line 19
    sjf_string_add(sjt_parent178, sjt_functionParam237, _return);

    if (sjt_call33._refCount == 1) { sjf_string_destroy(&sjt_call33); }
;
    if (sjt_call34._refCount == 1) { sjf_string_destroy(&sjt_call34); }
;
    if (sjt_call35._refCount == 1) { sjf_string_destroy(&sjt_call35); }
;
    if (sjt_call36._refCount == 1) { sjf_string_destroy(&sjt_call36); }
;
    if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
;
    if (sjt_call38._refCount == 1) { sjf_string_destroy(&sjt_call38); }
;
    if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
;
    if (sjt_call40._refCount == 1) { sjf_string_destroy(&sjt_call40); }
;
}

void sjf_vec3_asstring_heap(sjs_vec3* _parent, sjs_string** _return) {
    sjs_string sjt_call41 = { -1 };
    sjs_string sjt_call42 = { -1 };
    sjs_string sjt_call43 = { -1 };
    sjs_string sjt_call44 = { -1 };
    sjs_string sjt_call45 = { -1 };
    sjs_string sjt_call46 = { -1 };
    sjs_string sjt_call47 = { -1 };
    sjs_string sjt_call48 = { -1 };
    float sjt_functionParam239;
    sjs_string* sjt_functionParam240 = 0;
    sjs_string* sjt_functionParam241 = 0;
    float sjt_functionParam242;
    sjs_string* sjt_functionParam243 = 0;
    sjs_string* sjt_functionParam244 = 0;
    float sjt_functionParam245;
    sjs_string* sjt_parent182 = 0;
    sjs_string* sjt_parent183 = 0;
    sjs_string* sjt_parent184 = 0;
    sjs_string* sjt_parent185 = 0;

#line 19 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam239 = _parent->x;
#line 19
    sjf_f32_asstring(sjt_functionParam239, &sjt_call44);
#line 19
    sjt_parent185 = &sjt_call44;
#line 19
    sjt_call45._refCount = 1;
#line 19
    sjt_call45.offset = 0;
#line 19
    sjt_call45.count = 2;
#line 19
    sjt_call45.data._refCount = 1;
#line 19
    sjt_call45.data.v = &sjg_string23;
#line 19
    sjf_array_char(&sjt_call45.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call45._isnullterminated = false;
#line 16
    sjf_string(&sjt_call45);
#line 19 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam240 = &sjt_call45;
#line 19
    sjf_string_add(sjt_parent185, sjt_functionParam240, &sjt_call43);
#line 19
    sjt_parent184 = &sjt_call43;
#line 19
    sjt_functionParam242 = _parent->y;
#line 19
    sjf_f32_asstring(sjt_functionParam242, &sjt_call46);
#line 19
    sjt_functionParam241 = &sjt_call46;
#line 19
    sjf_string_add(sjt_parent184, sjt_functionParam241, &sjt_call42);
#line 19
    sjt_parent183 = &sjt_call42;
#line 19
    sjt_call47._refCount = 1;
#line 19
    sjt_call47.offset = 0;
#line 19
    sjt_call47.count = 2;
#line 19
    sjt_call47.data._refCount = 1;
#line 19
    sjt_call47.data.v = &sjg_string23;
#line 19
    sjf_array_char(&sjt_call47.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call47._isnullterminated = false;
#line 16
    sjf_string(&sjt_call47);
#line 19 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam243 = &sjt_call47;
#line 19
    sjf_string_add(sjt_parent183, sjt_functionParam243, &sjt_call41);
#line 19
    sjt_parent182 = &sjt_call41;
#line 19
    sjt_functionParam245 = _parent->z;
#line 19
    sjf_f32_asstring(sjt_functionParam245, &sjt_call48);
#line 19
    sjt_functionParam244 = &sjt_call48;
#line 19
    sjf_string_add_heap(sjt_parent182, sjt_functionParam244, _return);

    if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
;
    if (sjt_call42._refCount == 1) { sjf_string_destroy(&sjt_call42); }
;
    if (sjt_call43._refCount == 1) { sjf_string_destroy(&sjt_call43); }
;
    if (sjt_call44._refCount == 1) { sjf_string_destroy(&sjt_call44); }
;
    if (sjt_call45._refCount == 1) { sjf_string_destroy(&sjt_call45); }
;
    if (sjt_call46._refCount == 1) { sjf_string_destroy(&sjt_call46); }
;
    if (sjt_call47._refCount == 1) { sjf_string_destroy(&sjt_call47); }
;
    if (sjt_call48._refCount == 1) { sjf_string_destroy(&sjt_call48); }
;
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
#line 1 "lib/sj-lib-ui/vec3.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->z = _from->z;
}

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 49 "lib/sj-lib-ui/vec3.sj"
    _return->x = (_parent->y * v->z) - (_parent->z * v->y);
#line 50
    _return->y = (_parent->z * v->x) - (_parent->x * v->z);
#line 51
    _return->z = (_parent->x * v->y) - (_parent->y * v->x);
#line 51
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 49 "lib/sj-lib-ui/vec3.sj"
    (*_return)->x = (_parent->y * v->z) - (_parent->z * v->y);
#line 50
    (*_return)->y = (_parent->z * v->x) - (_parent->x * v->z);
#line 51
    (*_return)->z = (_parent->x * v->y) - (_parent->y * v->x);
#line 51
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
#line 56 "lib/sj-lib-ui/vec3.sj"
    (*_return) = ((_parent->x * v->x) + (_parent->y * v->y)) + (_parent->z * v->z);
}

void sjf_vec3_getrawsize(int32_t* _return) {
#line 82 "lib/sj-lib-ui/vec3.sj"
    int x = sizeof(float) * 3;
#line 83
    #line 81 "lib/sj-lib-ui/vec3.sj"
(*_return) = x;
return;;
}

void sjf_vec3_heap(sjs_vec3* _this) {
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    float sjt_functionParam79;
    float t;

#line 39 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam79 = ((_parent->x * _parent->x) + (_parent->y * _parent->y)) + (_parent->z * _parent->z);
#line 39
    sjf_f32_sqrt(sjt_functionParam79, &t);
#line 39
    _return->_refCount = 1;
#line 41
    _return->x = _parent->x / t;
#line 42
    _return->y = _parent->y / t;
#line 43
    _return->z = _parent->z / t;
#line 43
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return) {
    float sjt_functionParam80;
    float t;

#line 39 "lib/sj-lib-ui/vec3.sj"
    sjt_functionParam80 = ((_parent->x * _parent->x) + (_parent->y * _parent->y)) + (_parent->z * _parent->z);
#line 39
    sjf_f32_sqrt(sjt_functionParam80, &t);
#line 39
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
#line 39
    (*_return)->_refCount = 1;
#line 41
    (*_return)->x = _parent->x / t;
#line 42
    (*_return)->y = _parent->y / t;
#line 43
    (*_return)->z = _parent->z / t;
#line 43
    sjf_vec3_heap((*_return));
}

void sjf_vec3_rawcopy(sjs_vec3* v, void* p, void** _return) {
#line 89 "lib/sj-lib-ui/vec3.sj"
    float* f = (float*)p;
#line 90
    *f = v->x;
#line 91
    f++;
#line 92
    *f = v->y;
#line 93
    f++;
#line 94
    *f = v->z;
#line 95
    f++;
#line 96
    #line 88 "lib/sj-lib-ui/vec3.sj"
(*_return) = (void*)f;
return;;
}

void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    _return->_refCount = 1;
#line 32 "lib/sj-lib-ui/vec3.sj"
    _return->x = _parent->x - v->x;
#line 33
    _return->y = _parent->y - v->y;
#line 34
    _return->z = _parent->z - v->z;
#line 34
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
#line 32 "lib/sj-lib-ui/vec3.sj"
    (*_return)->x = _parent->x - v->x;
#line 33
    (*_return)->y = _parent->y - v->y;
#line 34
    (*_return)->z = _parent->z - v->z;
#line 34
    sjf_vec3_heap((*_return));
}

void sjf_vec4(sjs_vec4* _this) {
}

void sjf_vec4_copy(sjs_vec4* _this, sjs_vec4* _from) {
#line 1 "lib/sj-lib-ui/vec4.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->z = _from->z;
#line 1
    _this->w = _from->w;
}

void sjf_vec4_destroy(sjs_vec4* _this) {
}

void sjf_vec4_heap(sjs_vec4* _this) {
}

void sjf_vertex_location_texture_normal(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_copy(sjs_vertex_location_texture_normal* _this, sjs_vertex_location_texture_normal* _from) {
    _this->location._refCount = 1;
#line 2 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjf_vec3_copy(&_this->location, &_from->location);
#line 2
    _this->texture._refCount = 1;
#line 2
    sjf_vec2_copy(&_this->texture, &_from->texture);
#line 2
    _this->normal._refCount = 1;
#line 2
    sjf_vec3_copy(&_this->normal, &_from->normal);
}

void sjf_vertex_location_texture_normal_destroy(sjs_vertex_location_texture_normal* _this) {
    if (_this->location._refCount == 1) { sjf_vec3_destroy(&_this->location); }
;
    if (_this->texture._refCount == 1) { sjf_vec2_destroy(&_this->texture); }
;
    if (_this->normal._refCount == 1) { sjf_vec3_destroy(&_this->normal); }
;
}

void sjf_vertex_location_texture_normal_getrawsize(int32_t* _return) {
    int32_t sjt_capture42;
    int32_t sjt_capture43;
    int32_t sjt_capture44;

    sjf_vec3_getrawsize(&sjt_capture42);
    sjf_vec2_getrawsize(&sjt_capture43);
    sjf_vec3_getrawsize(&sjt_capture44);
#line 9 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    (*_return) = (sjt_capture42 + sjt_capture43) + sjt_capture44;
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return) {
    void* sjt_funcold10;
    void* sjt_funcold11;
    void* sjt_funcold12;
    sjs_vec3* sjt_functionParam151 = 0;
    void* sjt_functionParam152;
    sjs_vec2* sjt_functionParam153 = 0;
    void* sjt_functionParam154;
    sjs_vec3* sjt_functionParam155 = 0;
    void* sjt_functionParam156;

#line 13 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam151 = &v->location;
#line 12
    sjt_functionParam152 = p;
#line 12
    sjf_vec3_rawcopy(sjt_functionParam151, sjt_functionParam152, &sjt_funcold10);
#line 87 "lib/sj-lib-ui/vec3.sj"
    p = sjt_funcold10;
#line 14 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam153 = &v->texture;
#line 12
    sjt_functionParam154 = p;
#line 12
    sjf_vec2_rawcopy(sjt_functionParam153, sjt_functionParam154, &sjt_funcold11);
#line 17 "lib/sj-lib-ui/vec2.sj"
    p = sjt_funcold11;
#line 15 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    sjt_functionParam155 = &v->normal;
#line 12
    sjt_functionParam156 = p;
#line 12
    sjf_vec3_rawcopy(sjt_functionParam155, sjt_functionParam156, &sjt_funcold12);
#line 87 "lib/sj-lib-ui/vec3.sj"
    p = sjt_funcold12;
#line 12 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    (*_return) = p;
}

void sjf_vertexbuffer_loadobj(sjs_string* filename, sjs_vertexbuffer_vertex_location_texture_normal* _return) {
    bool includenormals;
    bool includetextures;
    int32_t index;
    sjs_list_i32 indices = { -1 };
    sjs_vec3 location = { -1 };
    sjs_vec3 normal = { -1 };
    sjs_array_vec3 normals = { -1 };
    bool result7;
    bool result8;
    sjs_string sjt_call28 = { -1 };
    sjs_string sjt_call29 = { -1 };
    sjs_string sjt_call30 = { -1 };
    sjs_string sjt_call31 = { -1 };
    sjs_string sjt_call32 = { -1 };
    sjs_string sjt_call49 = { -1 };
    sjs_string sjt_call50 = { -1 };
    sjs_string sjt_call51 = { -1 };
    sjs_string sjt_call52 = { -1 };
    sjs_vertex_location_texture_normal sjt_call61 = { -1 };
    sjs_vec3 sjt_call62 = { -1 };
    int32_t sjt_functionParam211;
    sjs_string* sjt_functionParam212 = 0;
    sjs_string* sjt_functionParam246 = 0;
    sjs_string* sjt_functionParam247 = 0;
    sjs_string* sjt_functionParam248 = 0;
    sjs_string* sjt_functionParam249 = 0;
    sjs_vertex_location_texture_normal* sjt_functionParam265 = 0;
    sjs_list_i32* sjt_parent156 = 0;
    sjs_string* sjt_parent174 = 0;
    sjs_string* sjt_parent175 = 0;
    sjs_string* sjt_parent176 = 0;
    sjs_string* sjt_parent177 = 0;
    sjs_vec3* sjt_parent186 = 0;
    sjs_vec3* sjt_parent187 = 0;
    sjs_vec2* sjt_parent192 = 0;
    sjs_list_vertex_location_texture_normal* sjt_parent200 = 0;
    sjs_vec2 texture = { -1 };
    sjs_list_vertex_location_texture_normal vertices = { -1 };

    indices._refCount = 1;
    indices.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    indices.arr.v = 0;
#line 27
    sjf_array_i32(&indices.arr);
#line 27
    sjf_list_i32(&indices);
#line 27
    vertices._refCount = 1;
#line 27
    vertices.arr._refCount = 1;
#line 27
    vertices.arr.v = 0;
#line 27
    sjf_array_vertex_location_texture_normal(&vertices.arr);
#line 27
    sjf_list_vertex_location_texture_normal(&vertices);
#line 27
    location._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    location.x = 0.0f;
#line 3
    location.y = 0.0f;
#line 4
    location.z = 0.0f;
#line 4
    sjf_vec3(&location);
#line 4
    texture._refCount = 1;
#line 2 "lib/sj-lib-ui/vec2.sj"
    texture.x = 0.0f;
#line 3
    texture.y = 0.0f;
#line 3
    sjf_vec2(&texture);
#line 3
    normal._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    normal.x = 0.0f;
#line 3
    normal.y = 0.0f;
#line 4
    normal.z = 0.0f;
#line 4
    sjf_vec3(&normal);
#line 168 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    index = 0;
#line 169
    includenormals = true;
#line 170
    includetextures = true;
#line 172
    obj_scene_data data = { 0 };
#line 173
    if (parse_obj_scene(&data, string_char(filename))) {
#line 174
        for (int i = 0; i < data.face_count; i++) {
#line 175
            if (data.face_list[i]->vertex_count != 3) {
#line 176
                printf("warn: do not support obj with non-triangles\n");
#line 177
            }
#line 179
            for (int j = 0; j < 3; j++) {
#line 180
                index = data.face_list[i]->vertex_index[j];
#line 181
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->normal_index[j]) {
#line 182
                    includenormals = false;
#line 183
                }
#line 184
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->texture_index[j]) {
#line 185
                    includetextures = false;
#line 186
                }
#line 44 "lib/sj-lib-common/list.sj"
                sjt_parent156 = &indices;
#line 188 "lib/sj-lib-ui/vertexBufferBuilders.sj"
                sjt_functionParam211 = index;
#line 188
                sjf_list_i32_add(sjt_parent156, sjt_functionParam211);
#line 190
            }
#line 191
        }
#line 193
        if (data.vertex_count != data.vertex_normal_count) {
#line 194
            includenormals = false;
#line 195
        }
#line 197
        if (data.vertex_count != data.vertex_texture_count) {
#line 198
            includetextures = false;
#line 199
        }
#line 201
        for (int i = 0; i < data.vertex_count; i++) {
#line 202
            location.x = (float)data.vertex_list[i]->e[0];
#line 203
            location.y = (float)data.vertex_list[i]->e[1];
#line 204
            location.z = (float)data.vertex_list[i]->e[2];
#line 206
            if (includenormals) {
#line 207
                normal.x = (float)data.vertex_normal_list[i]->e[0];
#line 208
                normal.y = (float)data.vertex_normal_list[i]->e[1];
#line 209
                normal.z = (float)data.vertex_normal_list[i]->e[2];            
#line 210
            }
#line 212
            if (includetextures) {
#line 213
                texture.x = (float)data.vertex_texture_list[i]->e[0];
#line 214
                texture.y = (float)data.vertex_texture_list[i]->e[1];
#line 215
            }
#line 18 "lib/sj-lib-ui/vec3.sj"
            sjt_parent186 = &location;
#line 18
            sjf_vec3_asstring(sjt_parent186, &sjt_call32);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_parent177 = &sjt_call32;
#line 218
            sjt_call49._refCount = 1;
#line 218
            sjt_call49.offset = 0;
#line 218
            sjt_call49.count = 1;
#line 218
            sjt_call49.data._refCount = 1;
#line 218
            sjt_call49.data.v = &sjg_string24;
#line 218
            sjf_array_char(&sjt_call49.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call49._isnullterminated = false;
#line 16
            sjf_string(&sjt_call49);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam246 = &sjt_call49;
#line 218
            sjf_string_add(sjt_parent177, sjt_functionParam246, &sjt_call31);
#line 218
            sjt_parent176 = &sjt_call31;
#line 18 "lib/sj-lib-ui/vec3.sj"
            sjt_parent187 = &normal;
#line 18
            sjf_vec3_asstring(sjt_parent187, &sjt_call50);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam247 = &sjt_call50;
#line 218
            sjf_string_add(sjt_parent176, sjt_functionParam247, &sjt_call30);
#line 218
            sjt_parent175 = &sjt_call30;
#line 218
            sjt_call51._refCount = 1;
#line 218
            sjt_call51.offset = 0;
#line 218
            sjt_call51.count = 1;
#line 218
            sjt_call51.data._refCount = 1;
#line 218
            sjt_call51.data.v = &sjg_string24;
#line 218
            sjf_array_char(&sjt_call51.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call51._isnullterminated = false;
#line 16
            sjf_string(&sjt_call51);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam248 = &sjt_call51;
#line 218
            sjf_string_add(sjt_parent175, sjt_functionParam248, &sjt_call29);
#line 218
            sjt_parent174 = &sjt_call29;
#line 5 "lib/sj-lib-ui/vec2.sj"
            sjt_parent192 = &texture;
#line 5
            sjf_vec2_asstring(sjt_parent192, &sjt_call52);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam249 = &sjt_call52;
#line 218
            sjf_string_add(sjt_parent174, sjt_functionParam249, &sjt_call28);
#line 218
            sjt_functionParam212 = &sjt_call28;
#line 218
            sjf_debug_writeline(sjt_functionParam212);
#line 44 "lib/sj-lib-common/list.sj"
            sjt_parent200 = &vertices;
#line 44
            sjt_call61._refCount = 1;
#line 44
            sjt_call61.location._refCount = 1;
#line 219 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjf_vec3_copy(&sjt_call61.location, &location);
#line 219
            sjt_call61.texture._refCount = 1;
#line 219
            sjf_vec2_copy(&sjt_call61.texture, &texture);
#line 219
            sjt_call61.normal._refCount = 1;
#line 219
            sjf_vec3_copy(&sjt_call61.normal, &normal);
#line 219
            sjf_vertex_location_texture_normal(&sjt_call61);
#line 219
            sjt_functionParam265 = &sjt_call61;
#line 219
            sjf_list_vertex_location_texture_normal_add(sjt_parent200, sjt_functionParam265);
#line 225
        }
#line 227
    }
#line 228
    delete_obj_data(&data);
#line 232
    result7 = !includenormals;
    if (result7) {
        int32_t i;
        int32_t sjt_capture62;
        int32_t sjt_forEnd20;
        int32_t sjt_forEnd21;
        int32_t sjt_forStart20;
        int32_t sjt_forStart21;
        int32_t sjt_functionParam266;
        sjs_vec3* sjt_functionParam267 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent202 = 0;
        sjs_list_i32* sjt_parent204 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent227 = 0;

#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent202 = &vertices;
#line 4
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent202, &sjt_functionParam266);
#line 4
        sjt_call62._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
        sjt_call62.x = 0.0f;
#line 3
        sjt_call62.y = 0.0f;
#line 4
        sjt_call62.z = 0.0f;
#line 4
        sjf_vec3(&sjt_call62);
#line 233 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        sjt_functionParam267 = &sjt_call62;
#line 233
        sjf_array_create_vec3(sjt_functionParam266, sjt_functionParam267, &normals);
#line 234
        sjt_forStart20 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent204 = &indices;
#line 4
        sjf_list_i32_getcount(sjt_parent204, &sjt_capture62);
#line 234 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        sjt_forEnd20 = sjt_capture62 / 3;
#line 234
        i = sjt_forStart20;
        while (i < sjt_forEnd20) {
            int32_t i1;
            int32_t i2;
            int32_t i3;
            sjs_vec3 newnormal = { -1 };
            sjs_vec3 side1 = { -1 };
            sjs_vec3 side2 = { -1 };
            sjs_vertex_location_texture_normal sjt_call63 = { -1 };
            sjs_vertex_location_texture_normal sjt_call64 = { -1 };
            sjs_vertex_location_texture_normal sjt_call65 = { -1 };
            sjs_vec3 sjt_call66 = { -1 };
            sjs_vec3 sjt_call67 = { -1 };
            sjs_vec3 sjt_call68 = { -1 };
            sjs_vec3 sjt_call69 = { -1 };
            sjs_vec3 sjt_call70 = { -1 };
            sjs_vec3 sjt_call71 = { -1 };
            sjs_vec3 sjt_call72 = { -1 };
            int32_t sjt_functionParam269;
            int32_t sjt_functionParam270;
            int32_t sjt_functionParam271;
            int32_t sjt_functionParam274;
            int32_t sjt_functionParam275;
            int32_t sjt_functionParam276;
            sjs_vec3* sjt_functionParam277 = 0;
            sjs_vec3* sjt_functionParam278 = 0;
            sjs_vec3* sjt_functionParam279 = 0;
            int32_t sjt_functionParam280;
            sjs_vec3* sjt_functionParam281 = 0;
            int32_t sjt_functionParam282;
            sjs_vec3* sjt_functionParam283 = 0;
            int32_t sjt_functionParam284;
            sjs_vec3* sjt_functionParam285 = 0;
            int32_t sjt_functionParam286;
            sjs_vec3* sjt_functionParam287 = 0;
            int32_t sjt_functionParam288;
            sjs_vec3* sjt_functionParam289 = 0;
            int32_t sjt_functionParam290;
            sjs_vec3* sjt_functionParam291 = 0;
            sjs_list_i32* sjt_parent206 = 0;
            sjs_list_i32* sjt_parent207 = 0;
            sjs_list_i32* sjt_parent208 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent211 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent212 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent213 = 0;
            sjs_vec3* sjt_parent214 = 0;
            sjs_vec3* sjt_parent215 = 0;
            sjs_vec3* sjt_parent216 = 0;
            sjs_vec3* sjt_parent217 = 0;
            sjs_array_vec3* sjt_parent218 = 0;
            sjs_vec3* sjt_parent219 = 0;
            sjs_array_vec3* sjt_parent220 = 0;
            sjs_array_vec3* sjt_parent221 = 0;
            sjs_vec3* sjt_parent222 = 0;
            sjs_array_vec3* sjt_parent223 = 0;
            sjs_array_vec3* sjt_parent224 = 0;
            sjs_vec3* sjt_parent225 = 0;
            sjs_array_vec3* sjt_parent226 = 0;
            sjs_vec3 v1 = { -1 };
            sjs_vec3 v2 = { -1 };
            sjs_vec3 v3 = { -1 };

#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent206 = &indices;
#line 235 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam269 = (i * 3) + 0;
#line 235
            sjf_list_i32_getat(sjt_parent206, sjt_functionParam269, &i1);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent207 = &indices;
#line 236 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam270 = (i * 3) + 1;
#line 236
            sjf_list_i32_getat(sjt_parent207, sjt_functionParam270, &i2);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent208 = &indices;
#line 237 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam271 = (i * 3) + 2;
#line 237
            sjf_list_i32_getat(sjt_parent208, sjt_functionParam271, &i3);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent211 = &vertices;
#line 239 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam274 = i1;
#line 239
            sjf_list_vertex_location_texture_normal_getat(sjt_parent211, sjt_functionParam274, &sjt_call63);
#line 239
            v1._refCount = 1;
#line 239
            sjf_vec3_copy(&v1, &(&sjt_call63)->location);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent212 = &vertices;
#line 240 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam275 = i2;
#line 240
            sjf_list_vertex_location_texture_normal_getat(sjt_parent212, sjt_functionParam275, &sjt_call64);
#line 240
            v2._refCount = 1;
#line 240
            sjf_vec3_copy(&v2, &(&sjt_call64)->location);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent213 = &vertices;
#line 241 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam276 = i3;
#line 241
            sjf_list_vertex_location_texture_normal_getat(sjt_parent213, sjt_functionParam276, &sjt_call65);
#line 241
            v3._refCount = 1;
#line 241
            sjf_vec3_copy(&v3, &(&sjt_call65)->location);
#line 30 "lib/sj-lib-ui/vec3.sj"
            sjt_parent214 = &v2;
#line 243 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam277 = &v1;
#line 243
            sjf_vec3_subtract(sjt_parent214, sjt_functionParam277, &side1);
#line 30 "lib/sj-lib-ui/vec3.sj"
            sjt_parent215 = &v3;
#line 244 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam278 = &v1;
#line 244
            sjf_vec3_subtract(sjt_parent215, sjt_functionParam278, &side2);
#line 47 "lib/sj-lib-ui/vec3.sj"
            sjt_parent217 = &side2;
#line 246 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam279 = &side1;
#line 246
            sjf_vec3_cross(sjt_parent217, sjt_functionParam279, &sjt_call66);
#line 246
            sjt_parent216 = &sjt_call66;
#line 246
            sjf_vec3_normalize(sjt_parent216, &newnormal);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent218 = &normals;
#line 248 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam280 = i1;
#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent220 = &normals;
#line 248 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam282 = i1;
#line 248
            sjf_array_vec3_getat(sjt_parent220, sjt_functionParam282, &sjt_call68);
#line 248
            sjt_parent219 = &sjt_call68;
#line 248
            sjt_functionParam283 = &newnormal;
#line 248
            sjf_vec3_add(sjt_parent219, sjt_functionParam283, &sjt_call67);
#line 248
            sjt_functionParam281 = &sjt_call67;
#line 248
            sjf_array_vec3_setat(sjt_parent218, sjt_functionParam280, sjt_functionParam281);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent221 = &normals;
#line 249 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam284 = i2;
#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent223 = &normals;
#line 249 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam286 = i2;
#line 249
            sjf_array_vec3_getat(sjt_parent223, sjt_functionParam286, &sjt_call70);
#line 249
            sjt_parent222 = &sjt_call70;
#line 249
            sjt_functionParam287 = &newnormal;
#line 249
            sjf_vec3_add(sjt_parent222, sjt_functionParam287, &sjt_call69);
#line 249
            sjt_functionParam285 = &sjt_call69;
#line 249
            sjf_array_vec3_setat(sjt_parent221, sjt_functionParam284, sjt_functionParam285);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent224 = &normals;
#line 250 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam288 = i3;
#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent226 = &normals;
#line 250 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam290 = i3;
#line 250
            sjf_array_vec3_getat(sjt_parent226, sjt_functionParam290, &sjt_call72);
#line 250
            sjt_parent225 = &sjt_call72;
#line 250
            sjt_functionParam291 = &newnormal;
#line 250
            sjf_vec3_add(sjt_parent225, sjt_functionParam291, &sjt_call71);
#line 250
            sjt_functionParam289 = &sjt_call71;
#line 250
            sjf_array_vec3_setat(sjt_parent224, sjt_functionParam288, sjt_functionParam289);
#line 234
            i++;

            if (newnormal._refCount == 1) { sjf_vec3_destroy(&newnormal); }
;
            if (side1._refCount == 1) { sjf_vec3_destroy(&side1); }
;
            if (side2._refCount == 1) { sjf_vec3_destroy(&side2); }
;
            if (sjt_call63._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call63); }
;
            if (sjt_call64._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call64); }
;
            if (sjt_call65._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call65); }
;
            if (sjt_call66._refCount == 1) { sjf_vec3_destroy(&sjt_call66); }
;
            if (sjt_call67._refCount == 1) { sjf_vec3_destroy(&sjt_call67); }
;
            if (sjt_call68._refCount == 1) { sjf_vec3_destroy(&sjt_call68); }
;
            if (sjt_call69._refCount == 1) { sjf_vec3_destroy(&sjt_call69); }
;
            if (sjt_call70._refCount == 1) { sjf_vec3_destroy(&sjt_call70); }
;
            if (sjt_call71._refCount == 1) { sjf_vec3_destroy(&sjt_call71); }
;
            if (sjt_call72._refCount == 1) { sjf_vec3_destroy(&sjt_call72); }
;
            if (v1._refCount == 1) { sjf_vec3_destroy(&v1); }
;
            if (v2._refCount == 1) { sjf_vec3_destroy(&v2); }
;
            if (v3._refCount == 1) { sjf_vec3_destroy(&v3); }
;
        }

#line 253
        sjt_forStart21 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent227 = &vertices;
#line 4
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent227, &sjt_forEnd21);
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        i = sjt_forStart21;
        while (i < sjt_forEnd21) {
            sjs_vec3 newnormal = { -1 };
            sjs_vec3 sjt_call73 = { -1 };
            sjs_vertex_location_texture_normal sjt_call74 = { -1 };
            sjs_vertex_location_texture_normal sjt_call75 = { -1 };
            sjs_vertex_location_texture_normal sjt_call76 = { -1 };
            int32_t sjt_functionParam292;
            int32_t sjt_functionParam295;
            sjs_vertex_location_texture_normal* sjt_functionParam296 = 0;
            int32_t sjt_functionParam297;
            int32_t sjt_functionParam298;
            sjs_vec3* sjt_parent228 = 0;
            sjs_array_vec3* sjt_parent229 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent231 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent232 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent233 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent229 = &normals;
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam292 = i;
#line 253
            sjf_array_vec3_getat(sjt_parent229, sjt_functionParam292, &sjt_call73);
#line 254
            sjt_parent228 = &sjt_call73;
#line 254
            sjf_vec3_normalize(sjt_parent228, &newnormal);
#line 12 "lib/sj-lib-common/list.sj"
            sjt_parent231 = &vertices;
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam295 = i;
#line 253
            sjt_call74._refCount = 1;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent232 = &vertices;
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam297 = i;
#line 253
            sjf_list_vertex_location_texture_normal_getat(sjt_parent232, sjt_functionParam297, &sjt_call75);
#line 253
            sjt_call74.location._refCount = 1;
#line 255
            sjf_vec3_copy(&sjt_call74.location, &(&sjt_call75)->location);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent233 = &vertices;
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam298 = i;
#line 253
            sjf_list_vertex_location_texture_normal_getat(sjt_parent233, sjt_functionParam298, &sjt_call76);
#line 253
            sjt_call74.texture._refCount = 1;
#line 255
            sjf_vec2_copy(&sjt_call74.texture, &(&sjt_call76)->texture);
#line 255
            sjt_call74.normal._refCount = 1;
#line 255
            sjf_vec3_copy(&sjt_call74.normal, &newnormal);
#line 255
            sjf_vertex_location_texture_normal(&sjt_call74);
#line 255
            sjt_functionParam296 = &sjt_call74;
#line 255
            sjf_list_vertex_location_texture_normal_setat(sjt_parent231, sjt_functionParam295, sjt_functionParam296);
#line 253
            i++;

            if (newnormal._refCount == 1) { sjf_vec3_destroy(&newnormal); }
;
            if (sjt_call73._refCount == 1) { sjf_vec3_destroy(&sjt_call73); }
;
            if (sjt_call74._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call74); }
;
            if (sjt_call75._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call75); }
;
            if (sjt_call76._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call76); }
;
        }
    }

#line 264
    result8 = !includetextures;
    if (result8) {
        int32_t i;
        int32_t sjt_forEnd22;
        int32_t sjt_forEnd23;
        int32_t sjt_forStart22;
        int32_t sjt_forStart23;
        sjs_list_vertex_location_texture_normal* sjt_parent234 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent237 = 0;
        float ymax;
        float ymin;

#line 265 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        ymin = 0.0f;
#line 266
        ymax = 0.0f;
#line 267
        sjt_forStart22 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent234 = &vertices;
#line 4
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent234, &sjt_forEnd22);
#line 267 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        i = sjt_forStart22;
        while (i < sjt_forEnd22) {
            sjs_vertex_location_texture_normal sjt_call77 = { -1 };
            sjs_vertex_location_texture_normal sjt_call78 = { -1 };
            float sjt_funcold17;
            float sjt_funcold18;
            float sjt_functionParam299;
            float sjt_functionParam300;
            int32_t sjt_functionParam301;
            float sjt_functionParam302;
            float sjt_functionParam303;
            int32_t sjt_functionParam304;
            sjs_list_vertex_location_texture_normal* sjt_parent235 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent236 = 0;

#line 268 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam299 = ymin;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent235 = &vertices;
#line 267 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam301 = i;
#line 267
            sjf_list_vertex_location_texture_normal_getat(sjt_parent235, sjt_functionParam301, &sjt_call77);
#line 268
            sjt_functionParam300 = (&(&sjt_call77)->location)->y;
#line 268
            sjf_f32_min(sjt_functionParam299, sjt_functionParam300, &sjt_funcold17);
#line 47 "lib/sj-lib-common/f32.sj"
            ymin = sjt_funcold17;
#line 269 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam302 = ymax;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent236 = &vertices;
#line 267 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam304 = i;
#line 267
            sjf_list_vertex_location_texture_normal_getat(sjt_parent236, sjt_functionParam304, &sjt_call78);
#line 269
            sjt_functionParam303 = (&(&sjt_call78)->location)->y;
#line 269
            sjf_f32_max(sjt_functionParam302, sjt_functionParam303, &sjt_funcold18);
#line 43 "lib/sj-lib-common/f32.sj"
            ymax = sjt_funcold18;
#line 267 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            i++;

            if (sjt_call77._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call77); }
;
            if (sjt_call78._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call78); }
;
        }

#line 272
        sjt_forStart23 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent237 = &vertices;
#line 4
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent237, &sjt_forEnd23);
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        i = sjt_forStart23;
        while (i < sjt_forEnd23) {
            float s;
            sjs_vertex_location_texture_normal sjt_call79 = { -1 };
            sjs_vertex_location_texture_normal sjt_call80 = { -1 };
            sjs_vertex_location_texture_normal sjt_call81 = { -1 };
            sjs_vertex_location_texture_normal sjt_call82 = { -1 };
            sjs_vertex_location_texture_normal sjt_call83 = { -1 };
            sjs_vertex_location_texture_normal sjt_call84 = { -1 };
            float sjt_capture63;
            float sjt_functionParam305;
            int32_t sjt_functionParam306;
            float sjt_functionParam307;
            int32_t sjt_functionParam308;
            int32_t sjt_functionParam309;
            int32_t sjt_functionParam310;
            sjs_vertex_location_texture_normal* sjt_functionParam311 = 0;
            int32_t sjt_functionParam312;
            int32_t sjt_functionParam313;
            sjs_list_vertex_location_texture_normal* sjt_parent238 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent239 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent240 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent241 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent242 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent243 = 0;
            float t;

#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent238 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam306 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent238, sjt_functionParam306, &sjt_call79);
#line 273
            sjt_functionParam305 = (&(&sjt_call79)->location)->x;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent239 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam308 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent239, sjt_functionParam308, &sjt_call80);
#line 273
            sjt_functionParam307 = (&(&sjt_call80)->location)->z;
#line 273
            sjf_f32_atan2(sjt_functionParam305, sjt_functionParam307, &sjt_capture63);
#line 273
            s = (sjt_capture63 + g_f32_pi) / (2.0f * g_f32_pi);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent240 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam309 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent240, sjt_functionParam309, &sjt_call81);
#line 274
            t = ((&(&sjt_call81)->location)->y - ymin) / (ymax - ymin);
#line 12 "lib/sj-lib-common/list.sj"
            sjt_parent241 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam310 = i;
#line 272
            sjt_call82._refCount = 1;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent242 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam312 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent242, sjt_functionParam312, &sjt_call83);
#line 272
            sjt_call82.location._refCount = 1;
#line 275
            sjf_vec3_copy(&sjt_call82.location, &(&sjt_call83)->location);
#line 275
            sjt_call82.texture._refCount = 1;
#line 277
            sjt_call82.texture.x = s;
#line 277
            sjt_call82.texture.y = t;
#line 277
            sjf_vec2(&sjt_call82.texture);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent243 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam313 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent243, sjt_functionParam313, &sjt_call84);
#line 272
            sjt_call82.normal._refCount = 1;
#line 275
            sjf_vec3_copy(&sjt_call82.normal, &(&sjt_call84)->normal);
#line 275
            sjf_vertex_location_texture_normal(&sjt_call82);
#line 275
            sjt_functionParam311 = &sjt_call82;
#line 275
            sjf_list_vertex_location_texture_normal_setat(sjt_parent241, sjt_functionParam310, sjt_functionParam311);
#line 272
            i++;

            if (sjt_call79._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call79); }
;
            if (sjt_call80._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call80); }
;
            if (sjt_call81._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call81); }
;
            if (sjt_call82._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call82); }
;
            if (sjt_call83._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call83); }
;
            if (sjt_call84._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call84); }
;
        }
    }

#line 264
    _return->_refCount = 1;
#line 264
    _return->format._refCount = 1;
#line 283
    sjf_string_copy(&_return->format, &g_vertex_location_texture_normal_format);
#line 283
    _return->indices._refCount = 1;
#line 283
    sjf_array_i32_copy(&_return->indices, &(&indices)->arr);
#line 283
    _return->vertices._refCount = 1;
#line 283
    sjf_array_vertex_location_texture_normal_copy(&_return->vertices, &(&vertices)->arr);
#line 283
    sjf_vertexbuffer_vertex_location_texture_normal(_return);

    if (indices._refCount == 1) { sjf_list_i32_destroy(&indices); }
;
    if (location._refCount == 1) { sjf_vec3_destroy(&location); }
;
    if (normal._refCount == 1) { sjf_vec3_destroy(&normal); }
;
    if (normals._refCount == 1) { sjf_array_vec3_destroy(&normals); }
;
    if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
;
    if (sjt_call29._refCount == 1) { sjf_string_destroy(&sjt_call29); }
;
    if (sjt_call30._refCount == 1) { sjf_string_destroy(&sjt_call30); }
;
    if (sjt_call31._refCount == 1) { sjf_string_destroy(&sjt_call31); }
;
    if (sjt_call32._refCount == 1) { sjf_string_destroy(&sjt_call32); }
;
    if (sjt_call49._refCount == 1) { sjf_string_destroy(&sjt_call49); }
;
    if (sjt_call50._refCount == 1) { sjf_string_destroy(&sjt_call50); }
;
    if (sjt_call51._refCount == 1) { sjf_string_destroy(&sjt_call51); }
;
    if (sjt_call52._refCount == 1) { sjf_string_destroy(&sjt_call52); }
;
    if (sjt_call61._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call61); }
;
    if (sjt_call62._refCount == 1) { sjf_vec3_destroy(&sjt_call62); }
;
    if (texture._refCount == 1) { sjf_vec2_destroy(&texture); }
;
    if (vertices._refCount == 1) { sjf_list_vertex_location_texture_normal_destroy(&vertices); }
;
}

void sjf_vertexbuffer_loadobj_heap(sjs_string* filename, sjs_vertexbuffer_vertex_location_texture_normal** _return) {
    bool includenormals;
    bool includetextures;
    int32_t index;
    sjs_list_i32 indices = { -1 };
    sjs_vec3 location = { -1 };
    sjs_vec3 normal = { -1 };
    sjs_array_vec3 normals = { -1 };
    bool result10;
    bool result9;
    sjs_string sjt_call85 = { -1 };
    sjs_string sjt_call86 = { -1 };
    sjs_string sjt_call87 = { -1 };
    sjs_string sjt_call88 = { -1 };
    sjs_string sjt_call89 = { -1 };
    sjs_string sjt_call90 = { -1 };
    sjs_string sjt_call91 = { -1 };
    sjs_string sjt_call92 = { -1 };
    sjs_string sjt_call93 = { -1 };
    sjs_vertex_location_texture_normal sjt_call94 = { -1 };
    sjs_vec3 sjt_call95 = { -1 };
    int32_t sjt_functionParam314;
    sjs_string* sjt_functionParam315 = 0;
    sjs_string* sjt_functionParam316 = 0;
    sjs_string* sjt_functionParam317 = 0;
    sjs_string* sjt_functionParam318 = 0;
    sjs_string* sjt_functionParam319 = 0;
    sjs_vertex_location_texture_normal* sjt_functionParam320 = 0;
    sjs_list_i32* sjt_parent244 = 0;
    sjs_string* sjt_parent245 = 0;
    sjs_string* sjt_parent246 = 0;
    sjs_string* sjt_parent247 = 0;
    sjs_string* sjt_parent248 = 0;
    sjs_vec3* sjt_parent249 = 0;
    sjs_vec3* sjt_parent250 = 0;
    sjs_vec2* sjt_parent251 = 0;
    sjs_list_vertex_location_texture_normal* sjt_parent252 = 0;
    sjs_vec2 texture = { -1 };
    sjs_list_vertex_location_texture_normal vertices = { -1 };

    indices._refCount = 1;
    indices.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    indices.arr.v = 0;
#line 27
    sjf_array_i32(&indices.arr);
#line 27
    sjf_list_i32(&indices);
#line 27
    vertices._refCount = 1;
#line 27
    vertices.arr._refCount = 1;
#line 27
    vertices.arr.v = 0;
#line 27
    sjf_array_vertex_location_texture_normal(&vertices.arr);
#line 27
    sjf_list_vertex_location_texture_normal(&vertices);
#line 27
    location._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    location.x = 0.0f;
#line 3
    location.y = 0.0f;
#line 4
    location.z = 0.0f;
#line 4
    sjf_vec3(&location);
#line 4
    texture._refCount = 1;
#line 2 "lib/sj-lib-ui/vec2.sj"
    texture.x = 0.0f;
#line 3
    texture.y = 0.0f;
#line 3
    sjf_vec2(&texture);
#line 3
    normal._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
    normal.x = 0.0f;
#line 3
    normal.y = 0.0f;
#line 4
    normal.z = 0.0f;
#line 4
    sjf_vec3(&normal);
#line 168 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    index = 0;
#line 169
    includenormals = true;
#line 170
    includetextures = true;
#line 172
    obj_scene_data data = { 0 };
#line 173
    if (parse_obj_scene(&data, string_char(filename))) {
#line 174
        for (int i = 0; i < data.face_count; i++) {
#line 175
            if (data.face_list[i]->vertex_count != 3) {
#line 176
                printf("warn: do not support obj with non-triangles\n");
#line 177
            }
#line 179
            for (int j = 0; j < 3; j++) {
#line 180
                index = data.face_list[i]->vertex_index[j];
#line 181
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->normal_index[j]) {
#line 182
                    includenormals = false;
#line 183
                }
#line 184
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->texture_index[j]) {
#line 185
                    includetextures = false;
#line 186
                }
#line 44 "lib/sj-lib-common/list.sj"
                sjt_parent244 = &indices;
#line 188 "lib/sj-lib-ui/vertexBufferBuilders.sj"
                sjt_functionParam314 = index;
#line 188
                sjf_list_i32_add(sjt_parent244, sjt_functionParam314);
#line 190
            }
#line 191
        }
#line 193
        if (data.vertex_count != data.vertex_normal_count) {
#line 194
            includenormals = false;
#line 195
        }
#line 197
        if (data.vertex_count != data.vertex_texture_count) {
#line 198
            includetextures = false;
#line 199
        }
#line 201
        for (int i = 0; i < data.vertex_count; i++) {
#line 202
            location.x = (float)data.vertex_list[i]->e[0];
#line 203
            location.y = (float)data.vertex_list[i]->e[1];
#line 204
            location.z = (float)data.vertex_list[i]->e[2];
#line 206
            if (includenormals) {
#line 207
                normal.x = (float)data.vertex_normal_list[i]->e[0];
#line 208
                normal.y = (float)data.vertex_normal_list[i]->e[1];
#line 209
                normal.z = (float)data.vertex_normal_list[i]->e[2];            
#line 210
            }
#line 212
            if (includetextures) {
#line 213
                texture.x = (float)data.vertex_texture_list[i]->e[0];
#line 214
                texture.y = (float)data.vertex_texture_list[i]->e[1];
#line 215
            }
#line 18 "lib/sj-lib-ui/vec3.sj"
            sjt_parent249 = &location;
#line 18
            sjf_vec3_asstring(sjt_parent249, &sjt_call89);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_parent248 = &sjt_call89;
#line 218
            sjt_call90._refCount = 1;
#line 218
            sjt_call90.offset = 0;
#line 218
            sjt_call90.count = 1;
#line 218
            sjt_call90.data._refCount = 1;
#line 218
            sjt_call90.data.v = &sjg_string24;
#line 218
            sjf_array_char(&sjt_call90.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call90._isnullterminated = false;
#line 16
            sjf_string(&sjt_call90);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam316 = &sjt_call90;
#line 218
            sjf_string_add(sjt_parent248, sjt_functionParam316, &sjt_call88);
#line 218
            sjt_parent247 = &sjt_call88;
#line 18 "lib/sj-lib-ui/vec3.sj"
            sjt_parent250 = &normal;
#line 18
            sjf_vec3_asstring(sjt_parent250, &sjt_call91);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam317 = &sjt_call91;
#line 218
            sjf_string_add(sjt_parent247, sjt_functionParam317, &sjt_call87);
#line 218
            sjt_parent246 = &sjt_call87;
#line 218
            sjt_call92._refCount = 1;
#line 218
            sjt_call92.offset = 0;
#line 218
            sjt_call92.count = 1;
#line 218
            sjt_call92.data._refCount = 1;
#line 218
            sjt_call92.data.v = &sjg_string24;
#line 218
            sjf_array_char(&sjt_call92.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call92._isnullterminated = false;
#line 16
            sjf_string(&sjt_call92);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam318 = &sjt_call92;
#line 218
            sjf_string_add(sjt_parent246, sjt_functionParam318, &sjt_call86);
#line 218
            sjt_parent245 = &sjt_call86;
#line 5 "lib/sj-lib-ui/vec2.sj"
            sjt_parent251 = &texture;
#line 5
            sjf_vec2_asstring(sjt_parent251, &sjt_call93);
#line 218 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam319 = &sjt_call93;
#line 218
            sjf_string_add(sjt_parent245, sjt_functionParam319, &sjt_call85);
#line 218
            sjt_functionParam315 = &sjt_call85;
#line 218
            sjf_debug_writeline(sjt_functionParam315);
#line 44 "lib/sj-lib-common/list.sj"
            sjt_parent252 = &vertices;
#line 44
            sjt_call94._refCount = 1;
#line 44
            sjt_call94.location._refCount = 1;
#line 219 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjf_vec3_copy(&sjt_call94.location, &location);
#line 219
            sjt_call94.texture._refCount = 1;
#line 219
            sjf_vec2_copy(&sjt_call94.texture, &texture);
#line 219
            sjt_call94.normal._refCount = 1;
#line 219
            sjf_vec3_copy(&sjt_call94.normal, &normal);
#line 219
            sjf_vertex_location_texture_normal(&sjt_call94);
#line 219
            sjt_functionParam320 = &sjt_call94;
#line 219
            sjf_list_vertex_location_texture_normal_add(sjt_parent252, sjt_functionParam320);
#line 225
        }
#line 227
    }
#line 228
    delete_obj_data(&data);
#line 232
    result9 = !includenormals;
    if (result9) {
        int32_t i;
        int32_t sjt_capture64;
        int32_t sjt_forEnd24;
        int32_t sjt_forEnd25;
        int32_t sjt_forStart24;
        int32_t sjt_forStart25;
        int32_t sjt_functionParam321;
        sjs_vec3* sjt_functionParam322 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent253 = 0;
        sjs_list_i32* sjt_parent254 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent274 = 0;

#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent253 = &vertices;
#line 4
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent253, &sjt_functionParam321);
#line 4
        sjt_call95._refCount = 1;
#line 2 "lib/sj-lib-ui/vec3.sj"
        sjt_call95.x = 0.0f;
#line 3
        sjt_call95.y = 0.0f;
#line 4
        sjt_call95.z = 0.0f;
#line 4
        sjf_vec3(&sjt_call95);
#line 233 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        sjt_functionParam322 = &sjt_call95;
#line 233
        sjf_array_create_vec3(sjt_functionParam321, sjt_functionParam322, &normals);
#line 234
        sjt_forStart24 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent254 = &indices;
#line 4
        sjf_list_i32_getcount(sjt_parent254, &sjt_capture64);
#line 234 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        sjt_forEnd24 = sjt_capture64 / 3;
#line 234
        i = sjt_forStart24;
        while (i < sjt_forEnd24) {
            int32_t i1;
            int32_t i2;
            int32_t i3;
            sjs_vec3 newnormal = { -1 };
            sjs_vec3 side1 = { -1 };
            sjs_vec3 side2 = { -1 };
            sjs_vec3 sjt_call100 = { -1 };
            sjs_vec3 sjt_call101 = { -1 };
            sjs_vec3 sjt_call102 = { -1 };
            sjs_vec3 sjt_call103 = { -1 };
            sjs_vec3 sjt_call104 = { -1 };
            sjs_vec3 sjt_call105 = { -1 };
            sjs_vertex_location_texture_normal sjt_call96 = { -1 };
            sjs_vertex_location_texture_normal sjt_call97 = { -1 };
            sjs_vertex_location_texture_normal sjt_call98 = { -1 };
            sjs_vec3 sjt_call99 = { -1 };
            int32_t sjt_functionParam323;
            int32_t sjt_functionParam324;
            int32_t sjt_functionParam325;
            int32_t sjt_functionParam326;
            int32_t sjt_functionParam327;
            int32_t sjt_functionParam328;
            sjs_vec3* sjt_functionParam329 = 0;
            sjs_vec3* sjt_functionParam330 = 0;
            sjs_vec3* sjt_functionParam331 = 0;
            int32_t sjt_functionParam332;
            sjs_vec3* sjt_functionParam333 = 0;
            int32_t sjt_functionParam334;
            sjs_vec3* sjt_functionParam335 = 0;
            int32_t sjt_functionParam336;
            sjs_vec3* sjt_functionParam337 = 0;
            int32_t sjt_functionParam338;
            sjs_vec3* sjt_functionParam339 = 0;
            int32_t sjt_functionParam340;
            sjs_vec3* sjt_functionParam341 = 0;
            int32_t sjt_functionParam342;
            sjs_vec3* sjt_functionParam343 = 0;
            sjs_list_i32* sjt_parent255 = 0;
            sjs_list_i32* sjt_parent256 = 0;
            sjs_list_i32* sjt_parent257 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent258 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent259 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent260 = 0;
            sjs_vec3* sjt_parent261 = 0;
            sjs_vec3* sjt_parent262 = 0;
            sjs_vec3* sjt_parent263 = 0;
            sjs_vec3* sjt_parent264 = 0;
            sjs_array_vec3* sjt_parent265 = 0;
            sjs_vec3* sjt_parent266 = 0;
            sjs_array_vec3* sjt_parent267 = 0;
            sjs_array_vec3* sjt_parent268 = 0;
            sjs_vec3* sjt_parent269 = 0;
            sjs_array_vec3* sjt_parent270 = 0;
            sjs_array_vec3* sjt_parent271 = 0;
            sjs_vec3* sjt_parent272 = 0;
            sjs_array_vec3* sjt_parent273 = 0;
            sjs_vec3 v1 = { -1 };
            sjs_vec3 v2 = { -1 };
            sjs_vec3 v3 = { -1 };

#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent255 = &indices;
#line 235 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam323 = (i * 3) + 0;
#line 235
            sjf_list_i32_getat(sjt_parent255, sjt_functionParam323, &i1);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent256 = &indices;
#line 236 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam324 = (i * 3) + 1;
#line 236
            sjf_list_i32_getat(sjt_parent256, sjt_functionParam324, &i2);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent257 = &indices;
#line 237 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam325 = (i * 3) + 2;
#line 237
            sjf_list_i32_getat(sjt_parent257, sjt_functionParam325, &i3);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent258 = &vertices;
#line 239 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam326 = i1;
#line 239
            sjf_list_vertex_location_texture_normal_getat(sjt_parent258, sjt_functionParam326, &sjt_call96);
#line 239
            v1._refCount = 1;
#line 239
            sjf_vec3_copy(&v1, &(&sjt_call96)->location);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent259 = &vertices;
#line 240 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam327 = i2;
#line 240
            sjf_list_vertex_location_texture_normal_getat(sjt_parent259, sjt_functionParam327, &sjt_call97);
#line 240
            v2._refCount = 1;
#line 240
            sjf_vec3_copy(&v2, &(&sjt_call97)->location);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent260 = &vertices;
#line 241 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam328 = i3;
#line 241
            sjf_list_vertex_location_texture_normal_getat(sjt_parent260, sjt_functionParam328, &sjt_call98);
#line 241
            v3._refCount = 1;
#line 241
            sjf_vec3_copy(&v3, &(&sjt_call98)->location);
#line 30 "lib/sj-lib-ui/vec3.sj"
            sjt_parent261 = &v2;
#line 243 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam329 = &v1;
#line 243
            sjf_vec3_subtract(sjt_parent261, sjt_functionParam329, &side1);
#line 30 "lib/sj-lib-ui/vec3.sj"
            sjt_parent262 = &v3;
#line 244 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam330 = &v1;
#line 244
            sjf_vec3_subtract(sjt_parent262, sjt_functionParam330, &side2);
#line 47 "lib/sj-lib-ui/vec3.sj"
            sjt_parent264 = &side2;
#line 246 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam331 = &side1;
#line 246
            sjf_vec3_cross(sjt_parent264, sjt_functionParam331, &sjt_call99);
#line 246
            sjt_parent263 = &sjt_call99;
#line 246
            sjf_vec3_normalize(sjt_parent263, &newnormal);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent265 = &normals;
#line 248 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam332 = i1;
#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent267 = &normals;
#line 248 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam334 = i1;
#line 248
            sjf_array_vec3_getat(sjt_parent267, sjt_functionParam334, &sjt_call101);
#line 248
            sjt_parent266 = &sjt_call101;
#line 248
            sjt_functionParam335 = &newnormal;
#line 248
            sjf_vec3_add(sjt_parent266, sjt_functionParam335, &sjt_call100);
#line 248
            sjt_functionParam333 = &sjt_call100;
#line 248
            sjf_array_vec3_setat(sjt_parent265, sjt_functionParam332, sjt_functionParam333);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent268 = &normals;
#line 249 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam336 = i2;
#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent270 = &normals;
#line 249 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam338 = i2;
#line 249
            sjf_array_vec3_getat(sjt_parent270, sjt_functionParam338, &sjt_call103);
#line 249
            sjt_parent269 = &sjt_call103;
#line 249
            sjt_functionParam339 = &newnormal;
#line 249
            sjf_vec3_add(sjt_parent269, sjt_functionParam339, &sjt_call102);
#line 249
            sjt_functionParam337 = &sjt_call102;
#line 249
            sjf_array_vec3_setat(sjt_parent268, sjt_functionParam336, sjt_functionParam337);
#line 68 "lib/sj-lib-common/array.sj"
            sjt_parent271 = &normals;
#line 250 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam340 = i3;
#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent273 = &normals;
#line 250 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam342 = i3;
#line 250
            sjf_array_vec3_getat(sjt_parent273, sjt_functionParam342, &sjt_call105);
#line 250
            sjt_parent272 = &sjt_call105;
#line 250
            sjt_functionParam343 = &newnormal;
#line 250
            sjf_vec3_add(sjt_parent272, sjt_functionParam343, &sjt_call104);
#line 250
            sjt_functionParam341 = &sjt_call104;
#line 250
            sjf_array_vec3_setat(sjt_parent271, sjt_functionParam340, sjt_functionParam341);
#line 234
            i++;

            if (newnormal._refCount == 1) { sjf_vec3_destroy(&newnormal); }
;
            if (side1._refCount == 1) { sjf_vec3_destroy(&side1); }
;
            if (side2._refCount == 1) { sjf_vec3_destroy(&side2); }
;
            if (sjt_call100._refCount == 1) { sjf_vec3_destroy(&sjt_call100); }
;
            if (sjt_call101._refCount == 1) { sjf_vec3_destroy(&sjt_call101); }
;
            if (sjt_call102._refCount == 1) { sjf_vec3_destroy(&sjt_call102); }
;
            if (sjt_call103._refCount == 1) { sjf_vec3_destroy(&sjt_call103); }
;
            if (sjt_call104._refCount == 1) { sjf_vec3_destroy(&sjt_call104); }
;
            if (sjt_call105._refCount == 1) { sjf_vec3_destroy(&sjt_call105); }
;
            if (sjt_call96._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call96); }
;
            if (sjt_call97._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call97); }
;
            if (sjt_call98._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call98); }
;
            if (sjt_call99._refCount == 1) { sjf_vec3_destroy(&sjt_call99); }
;
            if (v1._refCount == 1) { sjf_vec3_destroy(&v1); }
;
            if (v2._refCount == 1) { sjf_vec3_destroy(&v2); }
;
            if (v3._refCount == 1) { sjf_vec3_destroy(&v3); }
;
        }

#line 253
        sjt_forStart25 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent274 = &vertices;
#line 4
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent274, &sjt_forEnd25);
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        i = sjt_forStart25;
        while (i < sjt_forEnd25) {
            sjs_vec3 newnormal = { -1 };
            sjs_vec3 sjt_call106 = { -1 };
            sjs_vertex_location_texture_normal sjt_call107 = { -1 };
            sjs_vertex_location_texture_normal sjt_call108 = { -1 };
            sjs_vertex_location_texture_normal sjt_call109 = { -1 };
            int32_t sjt_functionParam344;
            int32_t sjt_functionParam345;
            sjs_vertex_location_texture_normal* sjt_functionParam346 = 0;
            int32_t sjt_functionParam347;
            int32_t sjt_functionParam348;
            sjs_vec3* sjt_parent275 = 0;
            sjs_array_vec3* sjt_parent276 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent277 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent278 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent279 = 0;

#line 41 "lib/sj-lib-common/array.sj"
            sjt_parent276 = &normals;
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam344 = i;
#line 253
            sjf_array_vec3_getat(sjt_parent276, sjt_functionParam344, &sjt_call106);
#line 254
            sjt_parent275 = &sjt_call106;
#line 254
            sjf_vec3_normalize(sjt_parent275, &newnormal);
#line 12 "lib/sj-lib-common/list.sj"
            sjt_parent277 = &vertices;
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam345 = i;
#line 253
            sjt_call107._refCount = 1;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent278 = &vertices;
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam347 = i;
#line 253
            sjf_list_vertex_location_texture_normal_getat(sjt_parent278, sjt_functionParam347, &sjt_call108);
#line 253
            sjt_call107.location._refCount = 1;
#line 255
            sjf_vec3_copy(&sjt_call107.location, &(&sjt_call108)->location);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent279 = &vertices;
#line 253 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam348 = i;
#line 253
            sjf_list_vertex_location_texture_normal_getat(sjt_parent279, sjt_functionParam348, &sjt_call109);
#line 253
            sjt_call107.texture._refCount = 1;
#line 255
            sjf_vec2_copy(&sjt_call107.texture, &(&sjt_call109)->texture);
#line 255
            sjt_call107.normal._refCount = 1;
#line 255
            sjf_vec3_copy(&sjt_call107.normal, &newnormal);
#line 255
            sjf_vertex_location_texture_normal(&sjt_call107);
#line 255
            sjt_functionParam346 = &sjt_call107;
#line 255
            sjf_list_vertex_location_texture_normal_setat(sjt_parent277, sjt_functionParam345, sjt_functionParam346);
#line 253
            i++;

            if (newnormal._refCount == 1) { sjf_vec3_destroy(&newnormal); }
;
            if (sjt_call106._refCount == 1) { sjf_vec3_destroy(&sjt_call106); }
;
            if (sjt_call107._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call107); }
;
            if (sjt_call108._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call108); }
;
            if (sjt_call109._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call109); }
;
        }
    }

#line 264
    result10 = !includetextures;
    if (result10) {
        int32_t i;
        int32_t sjt_forEnd26;
        int32_t sjt_forEnd27;
        int32_t sjt_forStart26;
        int32_t sjt_forStart27;
        sjs_list_vertex_location_texture_normal* sjt_parent280 = 0;
        sjs_list_vertex_location_texture_normal* sjt_parent283 = 0;
        float ymax;
        float ymin;

#line 265 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        ymin = 0.0f;
#line 266
        ymax = 0.0f;
#line 267
        sjt_forStart26 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent280 = &vertices;
#line 4
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent280, &sjt_forEnd26);
#line 267 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        i = sjt_forStart26;
        while (i < sjt_forEnd26) {
            sjs_vertex_location_texture_normal sjt_call110 = { -1 };
            sjs_vertex_location_texture_normal sjt_call111 = { -1 };
            float sjt_funcold19;
            float sjt_funcold20;
            float sjt_functionParam349;
            float sjt_functionParam350;
            int32_t sjt_functionParam351;
            float sjt_functionParam352;
            float sjt_functionParam353;
            int32_t sjt_functionParam354;
            sjs_list_vertex_location_texture_normal* sjt_parent281 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent282 = 0;

#line 268 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam349 = ymin;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent281 = &vertices;
#line 267 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam351 = i;
#line 267
            sjf_list_vertex_location_texture_normal_getat(sjt_parent281, sjt_functionParam351, &sjt_call110);
#line 268
            sjt_functionParam350 = (&(&sjt_call110)->location)->y;
#line 268
            sjf_f32_min(sjt_functionParam349, sjt_functionParam350, &sjt_funcold19);
#line 47 "lib/sj-lib-common/f32.sj"
            ymin = sjt_funcold19;
#line 269 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam352 = ymax;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent282 = &vertices;
#line 267 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam354 = i;
#line 267
            sjf_list_vertex_location_texture_normal_getat(sjt_parent282, sjt_functionParam354, &sjt_call111);
#line 269
            sjt_functionParam353 = (&(&sjt_call111)->location)->y;
#line 269
            sjf_f32_max(sjt_functionParam352, sjt_functionParam353, &sjt_funcold20);
#line 43 "lib/sj-lib-common/f32.sj"
            ymax = sjt_funcold20;
#line 267 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            i++;

            if (sjt_call110._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call110); }
;
            if (sjt_call111._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call111); }
;
        }

#line 272
        sjt_forStart27 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent283 = &vertices;
#line 4
        sjf_list_vertex_location_texture_normal_getcount(sjt_parent283, &sjt_forEnd27);
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
        i = sjt_forStart27;
        while (i < sjt_forEnd27) {
            float s;
            sjs_vertex_location_texture_normal sjt_call112 = { -1 };
            sjs_vertex_location_texture_normal sjt_call113 = { -1 };
            sjs_vertex_location_texture_normal sjt_call114 = { -1 };
            sjs_vertex_location_texture_normal sjt_call115 = { -1 };
            sjs_vertex_location_texture_normal sjt_call116 = { -1 };
            sjs_vertex_location_texture_normal sjt_call117 = { -1 };
            float sjt_capture65;
            float sjt_functionParam355;
            int32_t sjt_functionParam356;
            float sjt_functionParam357;
            int32_t sjt_functionParam358;
            int32_t sjt_functionParam359;
            int32_t sjt_functionParam360;
            sjs_vertex_location_texture_normal* sjt_functionParam361 = 0;
            int32_t sjt_functionParam362;
            int32_t sjt_functionParam363;
            sjs_list_vertex_location_texture_normal* sjt_parent284 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent285 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent286 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent287 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent288 = 0;
            sjs_list_vertex_location_texture_normal* sjt_parent289 = 0;
            float t;

#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent284 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam356 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent284, sjt_functionParam356, &sjt_call112);
#line 273
            sjt_functionParam355 = (&(&sjt_call112)->location)->x;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent285 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam358 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent285, sjt_functionParam358, &sjt_call113);
#line 273
            sjt_functionParam357 = (&(&sjt_call113)->location)->z;
#line 273
            sjf_f32_atan2(sjt_functionParam355, sjt_functionParam357, &sjt_capture65);
#line 273
            s = (sjt_capture65 + g_f32_pi) / (2.0f * g_f32_pi);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent286 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam359 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent286, sjt_functionParam359, &sjt_call114);
#line 274
            t = ((&(&sjt_call114)->location)->y - ymin) / (ymax - ymin);
#line 12 "lib/sj-lib-common/list.sj"
            sjt_parent287 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam360 = i;
#line 272
            sjt_call115._refCount = 1;
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent288 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam362 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent288, sjt_functionParam362, &sjt_call116);
#line 272
            sjt_call115.location._refCount = 1;
#line 275
            sjf_vec3_copy(&sjt_call115.location, &(&sjt_call116)->location);
#line 275
            sjt_call115.texture._refCount = 1;
#line 277
            sjt_call115.texture.x = s;
#line 277
            sjt_call115.texture.y = t;
#line 277
            sjf_vec2(&sjt_call115.texture);
#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent289 = &vertices;
#line 272 "lib/sj-lib-ui/vertexBufferBuilders.sj"
            sjt_functionParam363 = i;
#line 272
            sjf_list_vertex_location_texture_normal_getat(sjt_parent289, sjt_functionParam363, &sjt_call117);
#line 272
            sjt_call115.normal._refCount = 1;
#line 275
            sjf_vec3_copy(&sjt_call115.normal, &(&sjt_call117)->normal);
#line 275
            sjf_vertex_location_texture_normal(&sjt_call115);
#line 275
            sjt_functionParam361 = &sjt_call115;
#line 275
            sjf_list_vertex_location_texture_normal_setat(sjt_parent287, sjt_functionParam360, sjt_functionParam361);
#line 272
            i++;

            if (sjt_call112._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call112); }
;
            if (sjt_call113._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call113); }
;
            if (sjt_call114._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call114); }
;
            if (sjt_call115._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call115); }
;
            if (sjt_call116._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call116); }
;
            if (sjt_call117._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call117); }
;
        }
    }

#line 264
    (*_return) = (sjs_vertexbuffer_vertex_location_texture_normal*)malloc(sizeof(sjs_vertexbuffer_vertex_location_texture_normal));
#line 264
    (*_return)->_refCount = 1;
#line 264
    (*_return)->format._refCount = 1;
#line 283
    sjf_string_copy(&(*_return)->format, &g_vertex_location_texture_normal_format);
#line 283
    (*_return)->indices._refCount = 1;
#line 283
    sjf_array_i32_copy(&(*_return)->indices, &(&indices)->arr);
#line 283
    (*_return)->vertices._refCount = 1;
#line 283
    sjf_array_vertex_location_texture_normal_copy(&(*_return)->vertices, &(&vertices)->arr);
#line 283
    sjf_vertexbuffer_vertex_location_texture_normal_heap((*_return));

    if (indices._refCount == 1) { sjf_list_i32_destroy(&indices); }
;
    if (location._refCount == 1) { sjf_vec3_destroy(&location); }
;
    if (normal._refCount == 1) { sjf_vec3_destroy(&normal); }
;
    if (normals._refCount == 1) { sjf_array_vec3_destroy(&normals); }
;
    if (sjt_call85._refCount == 1) { sjf_string_destroy(&sjt_call85); }
;
    if (sjt_call86._refCount == 1) { sjf_string_destroy(&sjt_call86); }
;
    if (sjt_call87._refCount == 1) { sjf_string_destroy(&sjt_call87); }
;
    if (sjt_call88._refCount == 1) { sjf_string_destroy(&sjt_call88); }
;
    if (sjt_call89._refCount == 1) { sjf_string_destroy(&sjt_call89); }
;
    if (sjt_call90._refCount == 1) { sjf_string_destroy(&sjt_call90); }
;
    if (sjt_call91._refCount == 1) { sjf_string_destroy(&sjt_call91); }
;
    if (sjt_call92._refCount == 1) { sjf_string_destroy(&sjt_call92); }
;
    if (sjt_call93._refCount == 1) { sjf_string_destroy(&sjt_call93); }
;
    if (sjt_call94._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call94); }
;
    if (sjt_call95._refCount == 1) { sjf_vec3_destroy(&sjt_call95); }
;
    if (texture._refCount == 1) { sjf_vec2_destroy(&texture); }
;
    if (vertices._refCount == 1) { sjf_list_vertex_location_texture_normal_destroy(&vertices); }
;
}

void sjf_vertexbuffer_vertex_location_texture_normal(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
#line 102 "lib/sj-lib-ui/vertexBuffer.sj"
    _this->buffer = vertex_buffer_new(string_char(&_this->format));
#line 103
    if (((sjs_array*)_this->indices.v)->count > 0) {
#line 104
        vertex_buffer_push_back_indices(_this->buffer, (GLuint*)((sjs_array*)_this->indices.v)->data, ((sjs_array*)_this->indices.v)->count);
#line 105
    }
#line 107
    if (((sjs_array*)_this->vertices.v)->count > 0) {
#line 108
        int vertexSize;
#line 109
        sjf_vertex_location_texture_normal_getrawsize(&vertexSize);
#line 110
        int verticesSize = ((sjs_array*)_this->vertices.v)->count * vertexSize;
#line 111
        char* t = (char*)malloc(verticesSize);
#line 112
        char* buffer = t;
#line 113
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)((sjs_array*)_this->vertices.v)->data;
#line 114
        for (int i = 0; i < ((sjs_array*)_this->vertices.v)->count; i++) {
#line 115
            sjf_vertex_location_texture_normal_rawcopy(&p[i], buffer, (void**)&buffer);
#line 116
        }
#line 117
        vertex_buffer_push_back_vertices(_this->buffer, t, ((sjs_array*)_this->vertices.v)->count);
#line 118
        free(t);
#line 119
    }
}

void sjf_vertexbuffer_vertex_location_texture_normal_copy(sjs_vertexbuffer_vertex_location_texture_normal* _this, sjs_vertexbuffer_vertex_location_texture_normal* _from) {
    _this->format._refCount = 1;
#line 7 "lib/sj-lib-ui/vertexBuffer.sj"
    sjf_string_copy(&_this->format, &_from->format);
#line 7
    _this->indices._refCount = 1;
#line 7
    sjf_array_i32_copy(&_this->indices, &_from->indices);
#line 7
    _this->vertices._refCount = 1;
#line 7
    sjf_array_vertex_location_texture_normal_copy(&_this->vertices, &_from->vertices);
#line 124
    _this->buffer = _from->buffer;
#line 125
    ptr_retain(_this->buffer);
}

void sjf_vertexbuffer_vertex_location_texture_normal_destroy(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
#line 129 "lib/sj-lib-ui/vertexBuffer.sj"
    if (ptr_release(_this->buffer)) {
#line 130
        vertex_buffer_delete(_this->buffer);  
#line 131
    }
#line 131
    if (_this->format._refCount == 1) { sjf_string_destroy(&_this->format); }
;
#line 131
    if (_this->indices._refCount == 1) { sjf_array_i32_destroy(&_this->indices); }
;
#line 131
    if (_this->vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&_this->vertices); }
;
}

void sjf_vertexbuffer_vertex_location_texture_normal_heap(sjs_vertexbuffer_vertex_location_texture_normal* _this) {
#line 102 "lib/sj-lib-ui/vertexBuffer.sj"
    _this->buffer = vertex_buffer_new(string_char(&_this->format));
#line 103
    if (((sjs_array*)_this->indices.v)->count > 0) {
#line 104
        vertex_buffer_push_back_indices(_this->buffer, (GLuint*)((sjs_array*)_this->indices.v)->data, ((sjs_array*)_this->indices.v)->count);
#line 105
    }
#line 107
    if (((sjs_array*)_this->vertices.v)->count > 0) {
#line 108
        int vertexSize;
#line 109
        sjf_vertex_location_texture_normal_getrawsize(&vertexSize);
#line 110
        int verticesSize = ((sjs_array*)_this->vertices.v)->count * vertexSize;
#line 111
        char* t = (char*)malloc(verticesSize);
#line 112
        char* buffer = t;
#line 113
        sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)((sjs_array*)_this->vertices.v)->data;
#line 114
        for (int i = 0; i < ((sjs_array*)_this->vertices.v)->count; i++) {
#line 115
            sjf_vertex_location_texture_normal_rawcopy(&p[i], buffer, (void**)&buffer);
#line 116
        }
#line 117
        vertex_buffer_push_back_vertices(_this->buffer, t, ((sjs_array*)_this->vertices.v)->count);
#line 118
        free(t);
#line 119
    }
}

void sjf_vertexbuffer_vertex_location_texture_normal_render(sjs_vertexbuffer_vertex_location_texture_normal* _parent, int32_t gldrawmode) {
#line 96 "lib/sj-lib-ui/vertexBuffer.sj"
    vertex_buffer_render(_parent->buffer, gldrawmode);
}

void sjf_windowrenderer(sjs_windowrenderer* _this) {
    sjs_color sjt_call1 = { -1 };
    sjs_color* sjt_functionParam4 = 0;
    int32_t sjt_functionParam5;
    int32_t sjt_functionParam6;
    int32_t sjt_functionParam7;

#line 30 "lib/sj-lib-ui/windowRenderer.sj"
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
#line 31
        halt("SDL_Init Error: %s\n", SDL_GetError());
#line 32
    }
#line 34
    #ifdef __APPLE__
#line 35
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 36
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#line 37
    #else
#line 38
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#line 39
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 40
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#line 41
    #endif
#line 42
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#line 43
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
#line 45
    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
#line 46
    if (_this->win == 0) {
#line 47
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
#line 48
    }
#line 50
    SDL_GL_CreateContext((SDL_Window*)_this->win);
#line 51
    #ifdef WIN32
#line 52
    GLint GlewInitResult = glewInit();
#line 53
    if (GLEW_OK != GlewInitResult) 
#line 54
    {
#line 55
        halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
#line 56
    }
#line 57
    #endif
#line 59
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED);
#line 60
    if (_this->ren == 0) {
#line 61
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
#line 62
    }
#line 62
    sjt_call1._refCount = 1;
#line 65
    sjt_call1.r = 0.0f;
#line 65
    sjt_call1.g = 0.0f;
#line 65
    sjt_call1.b = 0.0f;
#line 65
    sjt_call1.a = 0.0f;
#line 65
    sjf_color(&sjt_call1);
#line 65
    sjt_functionParam4 = &sjt_call1;
#line 65
    sjf_glclearcolor(sjt_functionParam4);
#line 66
    sjt_functionParam5 = g_glblendfunctype_gl_src_alpha;
#line 66
    sjt_functionParam6 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 66
    sjf_glblendfunc(sjt_functionParam5, sjt_functionParam6);
#line 67
    sjt_functionParam7 = g_glfeature_gl_blend;
#line 67
    sjf_glenable(sjt_functionParam7);

    if (sjt_call1._refCount == 1) { sjf_color_destroy(&sjt_call1); }
;
}

void sjf_windowrenderer_copy(sjs_windowrenderer* _this, sjs_windowrenderer* _from) {
#line 71 "lib/sj-lib-ui/windowRenderer.sj"
    _this->ren = _from->ren;
#line 72
    ptr_retain(_this->ren);
#line 73
    _this->win = _from->win;
#line 74
    ptr_retain(_this->win);
}

void sjf_windowrenderer_destroy(sjs_windowrenderer* _this) {
#line 78 "lib/sj-lib-ui/windowRenderer.sj"
    if (ptr_release(_this->ren)) {
#line 79
        SDL_DestroyRenderer(_this->ren);
#line 80
    }
#line 81
    if (ptr_release(_this->win)) {
#line 82
        SDL_DestroyWindow(_this->win);
#line 83
    }
}

void sjf_windowrenderer_getsize(sjs_windowrenderer* _parent, sjs_size* _return) {
    int32_t h;
    int32_t w;

#line 8 "lib/sj-lib-ui/windowRenderer.sj"
    w = 0;
#line 9
    h = 0;
#line 11
    SDL_GetRendererOutputSize(_parent->ren, &w, &h);
#line 11
    _return->_refCount = 1;
#line 13
    _return->w = w;
#line 13
    _return->h = h;
#line 13
    sjf_size(_return);
}

void sjf_windowrenderer_getsize_heap(sjs_windowrenderer* _parent, sjs_size** _return) {
    int32_t h;
    int32_t w;

#line 8 "lib/sj-lib-ui/windowRenderer.sj"
    w = 0;
#line 9
    h = 0;
#line 11
    SDL_GetRendererOutputSize(_parent->ren, &w, &h);
#line 11
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
#line 11
    (*_return)->_refCount = 1;
#line 13
    (*_return)->w = w;
#line 13
    (*_return)->h = h;
#line 13
    sjf_size_heap((*_return));
}

void sjf_windowrenderer_heap(sjs_windowrenderer* _this) {
    sjs_color sjt_call2 = { -1 };
    int32_t sjt_functionParam10;
    int32_t sjt_functionParam11;
    sjs_color* sjt_functionParam8 = 0;
    int32_t sjt_functionParam9;

#line 30 "lib/sj-lib-ui/windowRenderer.sj"
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
#line 31
        halt("SDL_Init Error: %s\n", SDL_GetError());
#line 32
    }
#line 34
    #ifdef __APPLE__
#line 35
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 36
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#line 37
    #else
#line 38
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#line 39
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 40
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#line 41
    #endif
#line 42
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#line 43
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
#line 45
    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
#line 46
    if (_this->win == 0) {
#line 47
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
#line 48
    }
#line 50
    SDL_GL_CreateContext((SDL_Window*)_this->win);
#line 51
    #ifdef WIN32
#line 52
    GLint GlewInitResult = glewInit();
#line 53
    if (GLEW_OK != GlewInitResult) 
#line 54
    {
#line 55
        halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
#line 56
    }
#line 57
    #endif
#line 59
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED);
#line 60
    if (_this->ren == 0) {
#line 61
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
#line 62
    }
#line 62
    sjt_call2._refCount = 1;
#line 65
    sjt_call2.r = 0.0f;
#line 65
    sjt_call2.g = 0.0f;
#line 65
    sjt_call2.b = 0.0f;
#line 65
    sjt_call2.a = 0.0f;
#line 65
    sjf_color(&sjt_call2);
#line 65
    sjt_functionParam8 = &sjt_call2;
#line 65
    sjf_glclearcolor(sjt_functionParam8);
#line 66
    sjt_functionParam9 = g_glblendfunctype_gl_src_alpha;
#line 66
    sjt_functionParam10 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 66
    sjf_glblendfunc(sjt_functionParam9, sjt_functionParam10);
#line 67
    sjt_functionParam11 = g_glfeature_gl_blend;
#line 67
    sjf_glenable(sjt_functionParam11);

    if (sjt_call2._refCount == 1) { sjf_color_destroy(&sjt_call2); }
;
}

void sjf_windowrenderer_present(sjs_windowrenderer* _parent) {
#line 24 "lib/sj-lib-ui/windowRenderer.sj"
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
}

int main(int argc, char** argv) {
    sjs_blureffect_effect_vtbl.destroy = (void(*)(void*))sjf_blureffect_destroy;
    sjs_blureffect_effect_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_blureffect_asinterface;
    sjs_blureffect_effect_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_blureffect_getclasstype;
    sjs_blureffect_effect_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_blureffect_getrect;
    sjs_blureffect_effect_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_blureffect_getrect_heap;
    sjs_blureffect_effect_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*,cb_rect_void))sjf_blureffect_setrect;
    sjs_blureffect_effect_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*,cb_scene2d_void))sjf_blureffect_render;
    sjs_boxelement_element_vtbl.destroy = (void(*)(void*))sjf_boxelement_destroy;
    sjs_boxelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_boxelement_asinterface;
    sjs_boxelement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_boxelement_getclasstype;
    sjs_boxelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_boxelement_getsize;
    sjs_boxelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_boxelement_getsize_heap;
    sjs_boxelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_boxelement_getrect;
    sjs_boxelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_boxelement_getrect_heap;
    sjs_boxelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_boxelement_setrect;
    sjs_boxelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_boxelement_render;
    sjs_boxelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_boxelement_firemouseevent;
    sjs_fadeeffect_effect_vtbl.destroy = (void(*)(void*))sjf_fadeeffect_destroy;
    sjs_fadeeffect_effect_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_fadeeffect_asinterface;
    sjs_fadeeffect_effect_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_fadeeffect_getclasstype;
    sjs_fadeeffect_effect_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_fadeeffect_getrect;
    sjs_fadeeffect_effect_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_fadeeffect_getrect_heap;
    sjs_fadeeffect_effect_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*,cb_rect_void))sjf_fadeeffect_setrect;
    sjs_fadeeffect_effect_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*,cb_scene2d_void))sjf_fadeeffect_render;
    sjs_filllayout_element_vtbl.destroy = (void(*)(void*))sjf_filllayout_destroy;
    sjs_filllayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_filllayout_asinterface;
    sjs_filllayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_filllayout_getclasstype;
    sjs_filllayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_filllayout_getsize;
    sjs_filllayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_filllayout_getsize_heap;
    sjs_filllayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_filllayout_getrect;
    sjs_filllayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_filllayout_getrect_heap;
    sjs_filllayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrect;
    sjs_filllayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_render;
    sjs_filllayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_filllayout_firemouseevent;
    sjs_gridlayout_element_vtbl.destroy = (void(*)(void*))sjf_gridlayout_destroy;
    sjs_gridlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_gridlayout_asinterface;
    sjs_gridlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_gridlayout_getclasstype;
    sjs_gridlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_gridlayout_getsize;
    sjs_gridlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_gridlayout_getsize_heap;
    sjs_gridlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_gridlayout_getrect;
    sjs_gridlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_gridlayout_getrect_heap;
    sjs_gridlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_gridlayout_setrect;
    sjs_gridlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_gridlayout_render;
    sjs_gridlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_gridlayout_firemouseevent;
    sjs_model_model_vtbl.destroy = (void(*)(void*))sjf_model_destroy;
    sjs_model_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_model_asinterface;
    sjs_model_model_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_model_getclasstype;
    sjs_model_model_vtbl.update = (void(*)(sjs_object*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_model_update;
    sjs_model_model_vtbl.getz = (void(*)(sjs_object*, float*))sjf_model_getz;
    sjs_model_model_vtbl.getcenter = (void(*)(sjs_object*, sjs_vec3*))sjf_model_getcenter;
    sjs_model_model_vtbl.getcenter_heap = (void(*)(sjs_object*, sjs_vec3**))sjf_model_getcenter_heap;
    sjs_model_model_vtbl.getworld = (void(*)(sjs_object*, sjs_mat4*))sjf_model_getworld;
    sjs_model_model_vtbl.getworld_heap = (void(*)(sjs_object*, sjs_mat4**))sjf_model_getworld_heap;
    sjs_model_model_vtbl.renderorqueue = (void(*)(sjs_object*,sjs_list_heap_iface_model*))sjf_model_renderorqueue;
    sjs_model_model_vtbl.render = (void(*)(sjs_object*))sjf_model_render;
    sjs_model_model_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_model_firemouseevent;
    sjs_saturateeffect_effect_vtbl.destroy = (void(*)(void*))sjf_saturateeffect_destroy;
    sjs_saturateeffect_effect_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_saturateeffect_asinterface;
    sjs_saturateeffect_effect_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_saturateeffect_getclasstype;
    sjs_saturateeffect_effect_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_saturateeffect_getrect;
    sjs_saturateeffect_effect_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_saturateeffect_getrect_heap;
    sjs_saturateeffect_effect_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*,cb_rect_void))sjf_saturateeffect_setrect;
    sjs_saturateeffect_effect_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*,cb_scene2d_void))sjf_saturateeffect_render;
    sjs_scene3delement_element_vtbl.destroy = (void(*)(void*))sjf_scene3delement_destroy;
    sjs_scene3delement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_scene3delement_asinterface;
    sjs_scene3delement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_scene3delement_getclasstype;
    sjs_scene3delement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_scene3delement_getsize;
    sjs_scene3delement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_scene3delement_getsize_heap;
    sjs_scene3delement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_scene3delement_getrect;
    sjs_scene3delement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_scene3delement_getrect_heap;
    sjs_scene3delement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_scene3delement_setrect;
    sjs_scene3delement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_scene3delement_render;
    sjs_scene3delement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_scene3delement_firemouseevent;
    sjs_textelement_element_vtbl.destroy = (void(*)(void*))sjf_textelement_destroy;
    sjs_textelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_textelement_asinterface;
    sjs_textelement_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_textelement_getclasstype;
    sjs_textelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_textelement_getsize;
    sjs_textelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_textelement_getsize_heap;
    sjs_textelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_textelement_getrect;
    sjs_textelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_textelement_getrect_heap;
    sjs_textelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_textelement_setrect;
    sjs_textelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_textelement_render;
    sjs_textelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_textelement_firemouseevent;
    sjs_textelement_textelement_vtbl.destroy = (void(*)(void*))sjf_textelement_destroy;
    sjs_textelement_textelement_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_textelement_asinterface;
    sjs_textelement_textelement_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_textelement_getclasstype;
    sjs_textelement_textelement_vtbl.gettext = (void(*)(sjs_object*, sjs_string*))sjf_textelement_gettext;
    sjs_textelement_textelement_vtbl.gettext_heap = (void(*)(sjs_object*, sjs_string**))sjf_textelement_gettext_heap;
    sjs_textelement_textelement_vtbl.settext = (void(*)(sjs_object*,sjs_string*))sjf_textelement_settext;
#line 1 "lib/sj-lib-common/log.sj"
    g_loglevel_trace = 0;
#line 1
    g_loglevel_debug = 1;
#line 1
    g_loglevel_info = 2;
#line 1
    g_loglevel_warn = 3;
#line 1
    g_loglevel_error = 4;
#line 1
    g_loglevel_fatal = 5;
#line 1 "lib/sj-lib-ui/borderLayout.sj"
    g_borderposition_fill = 0;
#line 1
    g_borderposition_left = 1;
#line 1
    g_borderposition_right = 2;
#line 1
    g_borderposition_top = 3;
#line 1
    g_borderposition_bottom = 4;
#line 1 "lib/sj-lib-ui/clickGesture.sj"
    g_clickstate_none = 0;
#line 1
    g_clickstate_entered = 1;
#line 1
    g_clickstate_pressed = 2;
#line 1 "lib/sj-lib-ui/flowLayout.sj"
    g_flowlayoutorientation_topbottom = 0;
#line 1
    g_flowlayoutorientation_leftright = 1;
#line 1
    g_flowlayoutorientation_bottomtop = 2;
#line 1
    g_flowlayoutorientation_rightleft = 3;
#line 1 "lib/sj-lib-ui/gl.sj"
    g_glfeature_gl_blend = 0x0BE2;
#line 1
    g_glfeature_gl_cull_face = 0x0B44;
#line 1
    g_glfeature_gl_depth_test = 0x0B71;
#line 1
    g_glfeature_gl_dither = 0x0BD0;
#line 1
    g_glfeature_gl_polygon_offset_fill = 0x8037;
#line 1
    g_glfeature_gl_sample_alpha_to_coverage = 0x809E;
#line 1
    g_glfeature_gl_sample_coverage = 0x80A0;
#line 1
    g_glfeature_gl_scissor_test = 0x0C11;
#line 1
    g_glfeature_gl_stencil_test = 0x0B90;
#line 13
    g_gltexture_gl_texture_2d = 0x0DE1;
#line 13
    g_gltexture_gl_texture_cube_map = 0x8513;
#line 18
    g_gltextureattribute_gl_texture_min_filter = 0x2801;
#line 18
    g_gltextureattribute_gl_texture_mag_filter = 0x2800;
#line 18
    g_gltextureattribute_gl_texture_wrap_s = 0x2802;
#line 18
    g_gltextureattribute_gl_texture_wrap_t = 0x2803;
#line 25
    g_gltexturevalue_gl_clamp_to_edge = 0x812F;
#line 25
    g_gltexturevalue_gl_mirrored_repeat = 0x8370;
#line 25
    g_gltexturevalue_gl_repeat = 0x2901;
#line 25
    g_gltexturevalue_gl_nearest = 0x2600;
#line 25
    g_gltexturevalue_gl_linear = 0x2601;
#line 25
    g_gltexturevalue_gl_nearest_mipmap_nearest = 0x2700;
#line 25
    g_gltexturevalue_gl_linear_mipmap_nearest = 0x2701;
#line 25
    g_gltexturevalue_gl_nearest_mipmap_linear = 0x2702;
#line 25
    g_gltexturevalue_gl_linear_mipmap_linear = 0x2703;
#line 37
    g_gltextureformat_gl_alpha = 0x1906;
#line 37
    g_gltextureformat_gl_luminance = 0x1909;
#line 37
    g_gltextureformat_gl_luminance_alpha = 0x190A;
#line 37
    g_gltextureformat_gl_rgb = 0x1907;
#line 37
    g_gltextureformat_gl_rgba = 0x1908;
#line 45
    g_gltexturetype_gl_unsigned_byte = 0x1401;
#line 45
    g_gltexturetype_gl_unsigned_short_5_6_5 = 0x8363;
#line 45
    g_gltexturetype_gl_unsigned_short_4_4_4_4 = 0x8033;
#line 45
    g_gltexturetype_gl_unsigned_short_5_5_5_1 = 0x8034;
#line 52
    g_glframebufferattachment_gl_color_attachment0 = 0x8CE0;
#line 52
    g_glframebufferattachment_gl_depth_attachment = 0x8D00;
#line 52
    g_glframebufferattachment_gl_stencil_attachment = 0x8D20;
#line 58
    g_glframebuffertexture_gl_texture_2d = 0x0DE1;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_positive_x = 0x8515;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_negative_x = 0x8516;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_positive_y = 0x8517;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_negative_y = 0x8518;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_positive_z = 0x8519;
#line 58
    g_glframebuffertexture_gl_texture_cube_map_negative_z = 0x851A;
#line 68
    g_glrenderbufferformat_gl_rgba4 = 0x8056;
#line 68
    g_glrenderbufferformat_gl_rgb565 = 0x8D62;
#line 68
    g_glrenderbufferformat_gl_rgb5_a1 = 0x8057;
#line 68
    g_glrenderbufferformat_gl_depth_component16 = 0x81A5;
#line 68
    g_glrenderbufferformat_gl_stencil_index8 = 0x8D48;
#line 76
    g_glframebufferstatus_gl_framebuffer_complete = 0x8CD5;
#line 76
    g_glframebufferstatus_gl_framebuffer_incomplete_attachment = 0x8CD6;
#line 76
    g_glframebufferstatus_gl_framebuffer_incomplete_missing_attachment = 0x8CD7;
#line 76
    g_glframebufferstatus_gl_framebuffer_unsupported = 0x8CDD;
#line 83
    g_glblendfunctype_gl_zero = 0;
#line 83
    g_glblendfunctype_gl_one = 1;
#line 83
    g_glblendfunctype_gl_src_color = 0x0300;
#line 83
    g_glblendfunctype_gl_one_minus_src_color = 0x0301;
#line 83
    g_glblendfunctype_gl_dst_color = 0x0306;
#line 83
    g_glblendfunctype_gl_one_minus_dst_color = 0x0307;
#line 83
    g_glblendfunctype_gl_src_alpha = 0x0302;
#line 83
    g_glblendfunctype_gl_one_minus_src_alpha = 0x0303;
#line 83
    g_glblendfunctype_gl_dst_alpha = 0x0304;
#line 83
    g_glblendfunctype_gl_one_minus_dst_alpha = 0x0305;
#line 83
    g_glblendfunctype_gl_constant_color = 0x8001;
#line 83
    g_glblendfunctype_gl_one_minus_constant_color = 0x8002;
#line 83
    g_glblendfunctype_gl_constant_alpha = 0x8003;
#line 83
    g_glblendfunctype_gl_one_minus_constant_alpha = 0x8004;
#line 83
    g_glblendfunctype_gl_src_alpha_saturate = 0x0308;
#line 101
    g_gldrawmode_gl_points = 0x0000;
#line 101
    g_gldrawmode_gl_line_strip = 0x0003;
#line 101
    g_gldrawmode_gl_line_loop = 0x0002;
#line 101
    g_gldrawmode_gl_lines = 0x0001;
#line 101
    g_gldrawmode_gl_triangle_strip = 0x0005;
#line 101
    g_gldrawmode_gl_triangle_fan = 0x0006;
#line 101
    g_gldrawmode_gl_triangles = 0x0004;
#line 36 "lib/sj-lib-ui/gridLayout.sj"
    g_gridunittype_fixed = 0;
#line 36
    g_gridunittype_star = 1;
#line 1 "lib/sj-lib-ui/imageElement.sj"
    g_imagestretch_fill = 0;
#line 1
    g_imagestretch_center = 1;
#line 1
    g_imagestretch_aspectratio = 2;
#line 1 "lib/sj-lib-ui/listLayout.sj"
    g_listlayoutorientation_topbottom = 0;
#line 1
    g_listlayoutorientation_leftright = 1;
#line 1
    g_listlayoutorientation_bottomtop = 2;
#line 1
    g_listlayoutorientation_rightleft = 3;
#line 32 "lib/sj-lib-ui/mouse.sj"
    g_mouseeventtype_move = 0;
#line 32
    g_mouseeventtype_up = 1;
#line 32
    g_mouseeventtype_down = 2;
#line 1 "lib/sj-lib-ui/textElement.sj"
    g_texthorizontal_left = 0;
#line 1
    g_texthorizontal_right = 1;
#line 1
    g_texthorizontal_center = 2;
#line 7
    g_textvertical_top = 0;
#line 7
    g_textvertical_bottom = 1;
#line 7
    g_textvertical_center = 2;
#line 1 "lib/sj-lib-common/f32.sj"
    g_f32_pi = 3.14159265358979323846f;
#line 1 "lib/sj-lib-common/i32.sj"
    g_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    g_i32_maxvalue = result1 - 2147483647;
#line 4
    g_i32_minvalue = 2147483647;
#line 10 "lib/sj-lib-common/log.sj"
    g_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        g_log_excludeall._refCount = 1;
#line 11 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log_excludeall, copyoption1);
    } else {
        g_log_excludeall._refCount = -1;
    }

#line 11
    g_log._refCount = 1;
#line 13
    g_log.minlevel = g_loglevel_warn;
#line 13
    sjs_hash_type_bool* copyoption8 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption8 != 0) {
        g_log.traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.traceincludes, copyoption8);
    } else {
        g_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption9 != 0) {
        g_log.debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.debugincludes, copyoption9);
    } else {
        g_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption10 != 0) {
        g_log.infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.infoincludes, copyoption10);
    } else {
        g_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption11 != 0) {
        g_log.warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.warnincludes, copyoption11);
    } else {
        g_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption12 != 0) {
        g_log.errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.errorincludes, copyoption12);
    } else {
        g_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption13 != 0) {
        g_log.fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.fatalincludes, copyoption13);
    } else {
        g_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&g_log);
#line 2 "lib/sj-lib-common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/sj-lib-common/clock.sj"
    g_clocks_per_sec = 0;
#line 9
    g_clocks_per_sec = CLOCKS_PER_SEC;
#line 9
    g_rootwindowrenderer._refCount = 1;
#line 9
    sjf_windowrenderer(&g_rootwindowrenderer);
#line 9
    g_rootscene._refCount = 1;
#line 9
    g_rootscene._size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    g_rootscene._size.w = 0;
#line 3
    g_rootscene._size.h = 0;
#line 3
    sjf_size(&g_rootscene._size);
#line 3
    g_rootscene.model._refCount = 1;
#line 2 "lib/sj-lib-ui/mat4.sj"
    g_rootscene.model.m00 = 0.0f;
#line 3
    g_rootscene.model.m01 = 0.0f;
#line 4
    g_rootscene.model.m02 = 0.0f;
#line 5
    g_rootscene.model.m03 = 0.0f;
#line 6
    g_rootscene.model.m10 = 0.0f;
#line 7
    g_rootscene.model.m11 = 0.0f;
#line 8
    g_rootscene.model.m12 = 0.0f;
#line 9
    g_rootscene.model.m13 = 0.0f;
#line 10
    g_rootscene.model.m20 = 0.0f;
#line 11
    g_rootscene.model.m21 = 0.0f;
#line 12
    g_rootscene.model.m22 = 0.0f;
#line 13
    g_rootscene.model.m23 = 0.0f;
#line 14
    g_rootscene.model.m30 = 0.0f;
#line 15
    g_rootscene.model.m31 = 0.0f;
#line 16
    g_rootscene.model.m32 = 0.0f;
#line 17
    g_rootscene.model.m33 = 0.0f;
#line 17
    sjf_mat4(&g_rootscene.model);
#line 17
    g_rootscene.view._refCount = 1;
#line 2
    g_rootscene.view.m00 = 0.0f;
#line 3
    g_rootscene.view.m01 = 0.0f;
#line 4
    g_rootscene.view.m02 = 0.0f;
#line 5
    g_rootscene.view.m03 = 0.0f;
#line 6
    g_rootscene.view.m10 = 0.0f;
#line 7
    g_rootscene.view.m11 = 0.0f;
#line 8
    g_rootscene.view.m12 = 0.0f;
#line 9
    g_rootscene.view.m13 = 0.0f;
#line 10
    g_rootscene.view.m20 = 0.0f;
#line 11
    g_rootscene.view.m21 = 0.0f;
#line 12
    g_rootscene.view.m22 = 0.0f;
#line 13
    g_rootscene.view.m23 = 0.0f;
#line 14
    g_rootscene.view.m30 = 0.0f;
#line 15
    g_rootscene.view.m31 = 0.0f;
#line 16
    g_rootscene.view.m32 = 0.0f;
#line 17
    g_rootscene.view.m33 = 0.0f;
#line 17
    sjf_mat4(&g_rootscene.view);
#line 17
    g_rootscene.projection._refCount = 1;
#line 2
    g_rootscene.projection.m00 = 0.0f;
#line 3
    g_rootscene.projection.m01 = 0.0f;
#line 4
    g_rootscene.projection.m02 = 0.0f;
#line 5
    g_rootscene.projection.m03 = 0.0f;
#line 6
    g_rootscene.projection.m10 = 0.0f;
#line 7
    g_rootscene.projection.m11 = 0.0f;
#line 8
    g_rootscene.projection.m12 = 0.0f;
#line 9
    g_rootscene.projection.m13 = 0.0f;
#line 10
    g_rootscene.projection.m20 = 0.0f;
#line 11
    g_rootscene.projection.m21 = 0.0f;
#line 12
    g_rootscene.projection.m22 = 0.0f;
#line 13
    g_rootscene.projection.m23 = 0.0f;
#line 14
    g_rootscene.projection.m30 = 0.0f;
#line 15
    g_rootscene.projection.m31 = 0.0f;
#line 16
    g_rootscene.projection.m32 = 0.0f;
#line 17
    g_rootscene.projection.m33 = 0.0f;
#line 17
    sjf_mat4(&g_rootscene.projection);
#line 17
    g_rootscene.windowrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    g_rootscene.windowrect.x = 0;
#line 3
    g_rootscene.windowrect.y = 0;
#line 4
    g_rootscene.windowrect.w = 0;
#line 5
    g_rootscene.windowrect.h = 0;
#line 5
    sjf_rect(&g_rootscene.windowrect);
#line 5
    sjf_scene2d(&g_rootscene);
#line 5
    g_modelsbyid._refCount = 1;
#line 5
    sjf_hash_string_weak_iface_model(&g_modelsbyid);
#line 5
    g_elementsbyid._refCount = 1;
#line 5
    sjf_hash_string_weak_iface_element(&g_elementsbyid);
#line 5
    g_animator._refCount = 1;
#line 5
    g_animator.animations._refCount = 1;
#line 5
    g_animator.animations.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    g_animator.animations.arr.v = 0;
#line 27
    sjf_array_heap_iface_animation(&g_animator.animations.arr);
#line 27
    sjf_list_heap_iface_animation(&g_animator.animations);
#line 29 "lib/sj-lib-ui/animation.sj"
    g_animator.current = 0;
#line 29
    sjf_animator(&g_animator);
#line 29
    g_blurhorizontalshader._refCount = 1;
#line 29
    g_blurhorizontalshader.vertex._refCount = 1;
#line 1 "lib/sj-lib-ui/blurEffect.sj"
    g_blurhorizontalshader.vertex.offset = 0;
#line 1
    g_blurhorizontalshader.vertex.count = 37;
#line 1
    g_blurhorizontalshader.vertex.data._refCount = 1;
#line 1
    g_blurhorizontalshader.vertex.data.v = &sjg_string1;
#line 1
    sjf_array_char(&g_blurhorizontalshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_blurhorizontalshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_blurhorizontalshader.vertex);
#line 16
    g_blurhorizontalshader.pixel._refCount = 1;
#line 1 "lib/sj-lib-ui/blurEffect.sj"
    g_blurhorizontalshader.pixel.offset = 0;
#line 1
    g_blurhorizontalshader.pixel.count = 45;
#line 1
    g_blurhorizontalshader.pixel.data._refCount = 1;
#line 1
    g_blurhorizontalshader.pixel.data.v = &sjg_string2;
#line 1
    sjf_array_char(&g_blurhorizontalshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_blurhorizontalshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_blurhorizontalshader.pixel);
#line 16
    sjf_shader(&g_blurhorizontalshader);
#line 16
    g_blurverticalshader._refCount = 1;
#line 16
    g_blurverticalshader.vertex._refCount = 1;
#line 2 "lib/sj-lib-ui/blurEffect.sj"
    g_blurverticalshader.vertex.offset = 0;
#line 2
    g_blurverticalshader.vertex.count = 37;
#line 2
    g_blurverticalshader.vertex.data._refCount = 1;
#line 2
    g_blurverticalshader.vertex.data.v = &sjg_string1;
#line 2
    sjf_array_char(&g_blurverticalshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_blurverticalshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_blurverticalshader.vertex);
#line 16
    g_blurverticalshader.pixel._refCount = 1;
#line 2 "lib/sj-lib-ui/blurEffect.sj"
    g_blurverticalshader.pixel.offset = 0;
#line 2
    g_blurverticalshader.pixel.count = 43;
#line 2
    g_blurverticalshader.pixel.data._refCount = 1;
#line 2
    g_blurverticalshader.pixel.data.v = &sjg_string3;
#line 2
    sjf_array_char(&g_blurverticalshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_blurverticalshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_blurverticalshader.pixel);
#line 16
    sjf_shader(&g_blurverticalshader);
#line 16
    g_colors_red._refCount = 1;
#line 2 "lib/sj-lib-ui/color.sj"
    g_colors_red.r = 1.0f;
#line 2
    g_colors_red.g = 0.0f;
#line 2
    g_colors_red.b = 0.0f;
#line 14
    g_colors_red.a = 1.0f;
#line 14
    sjf_color(&g_colors_red);
#line 14
    g_colors_green._refCount = 1;
#line 3
    g_colors_green.r = 0.0f;
#line 3
    g_colors_green.g = 1.0f;
#line 3
    g_colors_green.b = 0.0f;
#line 14
    g_colors_green.a = 1.0f;
#line 14
    sjf_color(&g_colors_green);
#line 14
    g_colors_blue._refCount = 1;
#line 4
    g_colors_blue.r = 0.0f;
#line 4
    g_colors_blue.g = 0.0f;
#line 4
    g_colors_blue.b = 1.0f;
#line 14
    g_colors_blue.a = 1.0f;
#line 14
    sjf_color(&g_colors_blue);
#line 14
    g_colors_black._refCount = 1;
#line 5
    g_colors_black.r = 0.0f;
#line 5
    g_colors_black.g = 0.0f;
#line 5
    g_colors_black.b = 0.0f;
#line 14
    g_colors_black.a = 1.0f;
#line 14
    sjf_color(&g_colors_black);
#line 14
    g_colors_white._refCount = 1;
#line 6
    g_colors_white.r = 1.0f;
#line 6
    g_colors_white.g = 1.0f;
#line 6
    g_colors_white.b = 1.0f;
#line 14
    g_colors_white.a = 1.0f;
#line 14
    sjf_color(&g_colors_white);
#line 14
    g_colors_gray._refCount = 1;
#line 7
    g_colors_gray.r = 0.5f;
#line 7
    g_colors_gray.g = 0.5f;
#line 7
    g_colors_gray.b = 0.5f;
#line 14
    g_colors_gray.a = 1.0f;
#line 14
    sjf_color(&g_colors_gray);
#line 14
    g_fadeshader._refCount = 1;
#line 14
    g_fadeshader.vertex._refCount = 1;
#line 1 "lib/sj-lib-ui/fadeEffect.sj"
    g_fadeshader.vertex.offset = 0;
#line 1
    g_fadeshader.vertex.count = 37;
#line 1
    g_fadeshader.vertex.data._refCount = 1;
#line 1
    g_fadeshader.vertex.data.v = &sjg_string1;
#line 1
    sjf_array_char(&g_fadeshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_fadeshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_fadeshader.vertex);
#line 16
    g_fadeshader.pixel._refCount = 1;
#line 1 "lib/sj-lib-ui/fadeEffect.sj"
    g_fadeshader.pixel.offset = 0;
#line 1
    g_fadeshader.pixel.count = 34;
#line 1
    g_fadeshader.pixel.data._refCount = 1;
#line 1
    g_fadeshader.pixel.data.v = &sjg_string4;
#line 1
    sjf_array_char(&g_fadeshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_fadeshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_fadeshader.pixel);
#line 16
    sjf_shader(&g_fadeshader);
#line 16
    g_fonthash._refCount = 1;
#line 16
    sjf_hash_fontkey_weak_font(&g_fonthash);
#line 16
    g_glviewports._refCount = 1;
#line 16
    g_glviewports.arr._refCount = 1;
#line 27 "lib/sj-lib-common/array.sj"
    g_glviewports.arr.v = 0;
#line 27
    sjf_array_rect(&g_glviewports.arr);
#line 27
    sjf_list_rect(&g_glviewports);
#line 27
    g_glframebuffers._refCount = 1;
#line 27
    g_glframebuffers.arr._refCount = 1;
#line 27
    g_glframebuffers.arr.v = 0;
#line 27
    sjf_array_u32(&g_glframebuffers.arr);
#line 27
    sjf_list_u32(&g_glframebuffers);
#line 340 "lib/sj-lib-ui/gl.sj"
    glid_init();
#line 340
    g_looplastrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    g_looplastrect.x = 0;
#line 3
    g_looplastrect.y = 0;
#line 4
    g_looplastrect.w = 0;
#line 5
    g_looplastrect.h = 0;
#line 5
    sjf_rect(&g_looplastrect);
#line 3 "lib/sj-lib-ui/loop.sj"
    g_mainloop_lasttick = 0;
#line 4
    g_mainloop_frames = 0;
#line 5
    g_mainloop_showfps = false;
#line 6
    g_mainloop_shouldcontinue = true;
#line 1 "lib/sj-lib-ui/mouse.sj"
    g_mouse_captureelement._parent = 0;
#line 1
    g_boxshader._refCount = 1;
#line 1
    g_boxshader.vertex._refCount = 1;
#line 1 "lib/sj-lib-ui/shader.sj"
    g_boxshader.vertex.offset = 0;
#line 1
    g_boxshader.vertex.count = 37;
#line 1
    g_boxshader.vertex.data._refCount = 1;
#line 1
    g_boxshader.vertex.data.v = &sjg_string5;
#line 1
    sjf_array_char(&g_boxshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_boxshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_boxshader.vertex);
#line 16
    g_boxshader.pixel._refCount = 1;
#line 1 "lib/sj-lib-ui/shader.sj"
    g_boxshader.pixel.offset = 0;
#line 1
    g_boxshader.pixel.count = 37;
#line 1
    g_boxshader.pixel.data._refCount = 1;
#line 1
    g_boxshader.pixel.data.v = &sjg_string6;
#line 1
    sjf_array_char(&g_boxshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_boxshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_boxshader.pixel);
#line 16
    sjf_shader(&g_boxshader);
#line 16
    g_imageshader._refCount = 1;
#line 16
    g_imageshader.vertex._refCount = 1;
#line 2 "lib/sj-lib-ui/shader.sj"
    g_imageshader.vertex.offset = 0;
#line 2
    g_imageshader.vertex.count = 37;
#line 2
    g_imageshader.vertex.data._refCount = 1;
#line 2
    g_imageshader.vertex.data.v = &sjg_string1;
#line 2
    sjf_array_char(&g_imageshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_imageshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_imageshader.vertex);
#line 16
    g_imageshader.pixel._refCount = 1;
#line 2 "lib/sj-lib-ui/shader.sj"
    g_imageshader.pixel.offset = 0;
#line 2
    g_imageshader.pixel.count = 37;
#line 2
    g_imageshader.pixel.data._refCount = 1;
#line 2
    g_imageshader.pixel.data.v = &sjg_string7;
#line 2
    sjf_array_char(&g_imageshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_imageshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_imageshader.pixel);
#line 16
    sjf_shader(&g_imageshader);
#line 16
    g_phongcolorshader._refCount = 1;
#line 16
    g_phongcolorshader.vertex._refCount = 1;
#line 3 "lib/sj-lib-ui/shader.sj"
    g_phongcolorshader.vertex.offset = 0;
#line 3
    g_phongcolorshader.vertex.count = 43;
#line 3
    g_phongcolorshader.vertex.data._refCount = 1;
#line 3
    g_phongcolorshader.vertex.data.v = &sjg_string8;
#line 3
    sjf_array_char(&g_phongcolorshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_phongcolorshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_phongcolorshader.vertex);
#line 16
    g_phongcolorshader.pixel._refCount = 1;
#line 3 "lib/sj-lib-ui/shader.sj"
    g_phongcolorshader.pixel.offset = 0;
#line 3
    g_phongcolorshader.pixel.count = 43;
#line 3
    g_phongcolorshader.pixel.data._refCount = 1;
#line 3
    g_phongcolorshader.pixel.data.v = &sjg_string9;
#line 3
    sjf_array_char(&g_phongcolorshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_phongcolorshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_phongcolorshader.pixel);
#line 16
    sjf_shader(&g_phongcolorshader);
#line 16
    g_phongtextureshader._refCount = 1;
#line 16
    g_phongtextureshader.vertex._refCount = 1;
#line 4 "lib/sj-lib-ui/shader.sj"
    g_phongtextureshader.vertex.offset = 0;
#line 4
    g_phongtextureshader.vertex.count = 47;
#line 4
    g_phongtextureshader.vertex.data._refCount = 1;
#line 4
    g_phongtextureshader.vertex.data.v = &sjg_string10;
#line 4
    sjf_array_char(&g_phongtextureshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_phongtextureshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_phongtextureshader.vertex);
#line 16
    g_phongtextureshader.pixel._refCount = 1;
#line 4 "lib/sj-lib-ui/shader.sj"
    g_phongtextureshader.pixel.offset = 0;
#line 4
    g_phongtextureshader.pixel.count = 47;
#line 4
    g_phongtextureshader.pixel.data._refCount = 1;
#line 4
    g_phongtextureshader.pixel.data.v = &sjg_string11;
#line 4
    sjf_array_char(&g_phongtextureshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_phongtextureshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_phongtextureshader.pixel);
#line 16
    sjf_shader(&g_phongtextureshader);
#line 16
    g_textshader._refCount = 1;
#line 16
    g_textshader.vertex._refCount = 1;
#line 5 "lib/sj-lib-ui/shader.sj"
    g_textshader.vertex.offset = 0;
#line 5
    g_textshader.vertex.count = 41;
#line 5
    g_textshader.vertex.data._refCount = 1;
#line 5
    g_textshader.vertex.data.v = &sjg_string12;
#line 5
    sjf_array_char(&g_textshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_textshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_textshader.vertex);
#line 16
    g_textshader.pixel._refCount = 1;
#line 5 "lib/sj-lib-ui/shader.sj"
    g_textshader.pixel.offset = 0;
#line 5
    g_textshader.pixel.count = 41;
#line 5
    g_textshader.pixel.data._refCount = 1;
#line 5
    g_textshader.pixel.data.v = &sjg_string13;
#line 5
    sjf_array_char(&g_textshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_textshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_textshader.pixel);
#line 16
    sjf_shader(&g_textshader);
#line 16
    g_style._refCount = 1;
#line 16
    sjf_style(&g_style);
#line 16
    g_vertex_location_texture_normal_format._refCount = 1;
#line 1 "lib/sj-lib-ui/vertexBufferBuilders.sj"
    g_vertex_location_texture_normal_format.offset = 0;
#line 1
    g_vertex_location_texture_normal_format.count = 32;
#line 1
    g_vertex_location_texture_normal_format.data._refCount = 1;
#line 1
    g_vertex_location_texture_normal_format.data.v = &sjg_string14;
#line 1
    sjf_array_char(&g_vertex_location_texture_normal_format.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_vertex_location_texture_normal_format._isnullterminated = false;
#line 16
    sjf_string(&g_vertex_location_texture_normal_format);
#line 16
    g_saturateshader._refCount = 1;
#line 16
    g_saturateshader.vertex._refCount = 1;
#line 1 "lib/sj-lib-ui/saturateEffect.sj"
    g_saturateshader.vertex.offset = 0;
#line 1
    g_saturateshader.vertex.count = 37;
#line 1
    g_saturateshader.vertex.data._refCount = 1;
#line 1
    g_saturateshader.vertex.data.v = &sjg_string1;
#line 1
    sjf_array_char(&g_saturateshader.vertex.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_saturateshader.vertex._isnullterminated = false;
#line 16
    sjf_string(&g_saturateshader.vertex);
#line 16
    g_saturateshader.pixel._refCount = 1;
#line 1 "lib/sj-lib-ui/saturateEffect.sj"
    g_saturateshader.pixel.offset = 0;
#line 1
    g_saturateshader.pixel.count = 38;
#line 1
    g_saturateshader.pixel.data._refCount = 1;
#line 1
    g_saturateshader.pixel.data.v = &sjg_string15;
#line 1
    sjf_array_char(&g_saturateshader.pixel.data);
#line 16 "lib/sj-lib-common/string.sj"
    g_saturateshader.pixel._isnullterminated = false;
#line 16
    sjf_string(&g_saturateshader.pixel);
#line 16
    sjf_shader(&g_saturateshader);
#line 16
    sjt_call3 = (sjs_gridlayout*)malloc(sizeof(sjs_gridlayout));
#line 16
    sjt_call3->_refCount = 1;
#line 16
    sjt_call3->children._refCount = 1;
#line 40 "effect.sj"
    sjt_call3->children.v = createarray(sizeof(sji_element), 4);
#line 40
    sjf_array_heap_iface_element(&sjt_call3->children);
#line 40
    sjs_array_heap_iface_element* array8;
#line 40
    array8 = &sjt_call3->children;
#line 40
    sjt_parent41 = array8;
#line 40
    sjt_functionParam45 = 0;
#line 40
    sjt_call5 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
#line 40
    sjt_call5->_refCount = 1;
#line 40
    sjt_call5->children._refCount = 1;
#line 44
    sjt_call5->children.v = createarray(sizeof(sji_element), 1);
#line 44
    sjf_array_heap_iface_element(&sjt_call5->children);
#line 44
    sjs_array_heap_iface_element* array7;
#line 44
    array7 = &sjt_call5->children;
#line 44
    sjt_parent64 = array7;
#line 44
    sjt_functionParam61 = 0;
#line 44
    sjf_testscene_heap(&sjt_functionParam62);
#line 44
    sjf_array_heap_iface_element_initat(sjt_parent64, sjt_functionParam61, sjt_functionParam62);
#line 44
    sjt_call5->margin._refCount = 1;
#line 43
    sjt_call5->margin.l = 10;
#line 43
    sjt_call5->margin.t = 10;
#line 43
    sjt_call5->margin.r = 10;
#line 43
    sjt_call5->margin.b = 10;
#line 43
    sjf_margin(&sjt_call5->margin);
#line 4 "lib/sj-lib-ui/fillLayout.sj"
    sjt_call5->effect._parent = 0;
#line 4
    sjt_call5->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call5->_rect.x = 0;
#line 3
    sjt_call5->_rect.y = 0;
#line 4
    sjt_call5->_rect.w = 0;
#line 5
    sjt_call5->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call5->_rect);
#line 5
    sjf_filllayout_heap(sjt_call5);
#line 42 "effect.sj"
    sjt_cast4 = sjt_call5;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_filllayout_as_sji_element(sjt_cast4, &sjt_functionParam46);
    if (sjt_functionParam46._parent != 0) {
        sjt_functionParam46._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent41, sjt_functionParam45, sjt_functionParam46);
#line 40 "effect.sj"
    sjt_parent307 = array8;
#line 40
    sjt_functionParam409 = 1;
#line 40
    sjt_call128 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
#line 40
    sjt_call128->_refCount = 1;
#line 40
    sjt_call128->children._refCount = 1;
#line 52
    sjt_call128->children.v = createarray(sizeof(sji_element), 1);
#line 52
    sjf_array_heap_iface_element(&sjt_call128->children);
#line 52
    sjs_array_heap_iface_element* array9;
#line 52
    array9 = &sjt_call128->children;
#line 52
    sjt_parent308 = array9;
#line 52
    sjt_functionParam411 = 0;
#line 52
    sjf_testscene_heap(&sjt_functionParam412);
#line 52
    sjf_array_heap_iface_element_initat(sjt_parent308, sjt_functionParam411, sjt_functionParam412);
#line 52
    sjt_call128->margin._refCount = 1;
#line 50
    sjt_call128->margin.l = 10;
#line 50
    sjt_call128->margin.t = 10;
#line 50
    sjt_call128->margin.r = 10;
#line 50
    sjt_call128->margin.b = 10;
#line 50
    sjf_margin(&sjt_call128->margin);
#line 50
    sjt_call129 = (sjs_blureffect*)malloc(sizeof(sjs_blureffect));
#line 50
    sjt_call129->_refCount = 1;
#line 51
    sjt_call129->radius = 5.0f;
#line 51
    sjt_call129->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call129->_rect.x = 0;
#line 3
    sjt_call129->_rect.y = 0;
#line 4
    sjt_call129->_rect.w = 0;
#line 5
    sjt_call129->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call129->_rect);
#line 7 "lib/sj-lib-ui/blurEffect.sj"
    sjt_call129->_vertexbuffer1._refCount = -1;
#line 8
    sjt_call129->_vertexbuffer2._refCount = -1;
#line 9
    sjt_call129->_scenebuffer1._refCount = -1;
#line 10
    sjt_call129->_scenebuffer2._refCount = -1;
#line 10
    sjt_call129->_innerscene._refCount = 1;
#line 10
    sjt_call129->_innerscene._size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    sjt_call129->_innerscene._size.w = 0;
#line 3
    sjt_call129->_innerscene._size.h = 0;
#line 3
    sjf_size(&sjt_call129->_innerscene._size);
#line 3
    sjt_call129->_innerscene.model._refCount = 1;
#line 2 "lib/sj-lib-ui/mat4.sj"
    sjt_call129->_innerscene.model.m00 = 0.0f;
#line 3
    sjt_call129->_innerscene.model.m01 = 0.0f;
#line 4
    sjt_call129->_innerscene.model.m02 = 0.0f;
#line 5
    sjt_call129->_innerscene.model.m03 = 0.0f;
#line 6
    sjt_call129->_innerscene.model.m10 = 0.0f;
#line 7
    sjt_call129->_innerscene.model.m11 = 0.0f;
#line 8
    sjt_call129->_innerscene.model.m12 = 0.0f;
#line 9
    sjt_call129->_innerscene.model.m13 = 0.0f;
#line 10
    sjt_call129->_innerscene.model.m20 = 0.0f;
#line 11
    sjt_call129->_innerscene.model.m21 = 0.0f;
#line 12
    sjt_call129->_innerscene.model.m22 = 0.0f;
#line 13
    sjt_call129->_innerscene.model.m23 = 0.0f;
#line 14
    sjt_call129->_innerscene.model.m30 = 0.0f;
#line 15
    sjt_call129->_innerscene.model.m31 = 0.0f;
#line 16
    sjt_call129->_innerscene.model.m32 = 0.0f;
#line 17
    sjt_call129->_innerscene.model.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call129->_innerscene.model);
#line 17
    sjt_call129->_innerscene.view._refCount = 1;
#line 2
    sjt_call129->_innerscene.view.m00 = 0.0f;
#line 3
    sjt_call129->_innerscene.view.m01 = 0.0f;
#line 4
    sjt_call129->_innerscene.view.m02 = 0.0f;
#line 5
    sjt_call129->_innerscene.view.m03 = 0.0f;
#line 6
    sjt_call129->_innerscene.view.m10 = 0.0f;
#line 7
    sjt_call129->_innerscene.view.m11 = 0.0f;
#line 8
    sjt_call129->_innerscene.view.m12 = 0.0f;
#line 9
    sjt_call129->_innerscene.view.m13 = 0.0f;
#line 10
    sjt_call129->_innerscene.view.m20 = 0.0f;
#line 11
    sjt_call129->_innerscene.view.m21 = 0.0f;
#line 12
    sjt_call129->_innerscene.view.m22 = 0.0f;
#line 13
    sjt_call129->_innerscene.view.m23 = 0.0f;
#line 14
    sjt_call129->_innerscene.view.m30 = 0.0f;
#line 15
    sjt_call129->_innerscene.view.m31 = 0.0f;
#line 16
    sjt_call129->_innerscene.view.m32 = 0.0f;
#line 17
    sjt_call129->_innerscene.view.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call129->_innerscene.view);
#line 17
    sjt_call129->_innerscene.projection._refCount = 1;
#line 2
    sjt_call129->_innerscene.projection.m00 = 0.0f;
#line 3
    sjt_call129->_innerscene.projection.m01 = 0.0f;
#line 4
    sjt_call129->_innerscene.projection.m02 = 0.0f;
#line 5
    sjt_call129->_innerscene.projection.m03 = 0.0f;
#line 6
    sjt_call129->_innerscene.projection.m10 = 0.0f;
#line 7
    sjt_call129->_innerscene.projection.m11 = 0.0f;
#line 8
    sjt_call129->_innerscene.projection.m12 = 0.0f;
#line 9
    sjt_call129->_innerscene.projection.m13 = 0.0f;
#line 10
    sjt_call129->_innerscene.projection.m20 = 0.0f;
#line 11
    sjt_call129->_innerscene.projection.m21 = 0.0f;
#line 12
    sjt_call129->_innerscene.projection.m22 = 0.0f;
#line 13
    sjt_call129->_innerscene.projection.m23 = 0.0f;
#line 14
    sjt_call129->_innerscene.projection.m30 = 0.0f;
#line 15
    sjt_call129->_innerscene.projection.m31 = 0.0f;
#line 16
    sjt_call129->_innerscene.projection.m32 = 0.0f;
#line 17
    sjt_call129->_innerscene.projection.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call129->_innerscene.projection);
#line 17
    sjt_call129->_innerscene.windowrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call129->_innerscene.windowrect.x = 0;
#line 3
    sjt_call129->_innerscene.windowrect.y = 0;
#line 4
    sjt_call129->_innerscene.windowrect.w = 0;
#line 5
    sjt_call129->_innerscene.windowrect.h = 0;
#line 5
    sjf_rect(&sjt_call129->_innerscene.windowrect);
#line 5
    sjf_scene2d(&sjt_call129->_innerscene);
#line 5
    sjf_blureffect_heap(sjt_call129);
#line 51 "effect.sj"
    sjt_cast16 = sjt_call129;
#line 1 "lib/sj-lib-ui/effect.sj"
    sjf_blureffect_as_sji_effect(sjt_cast16, &sjt_value4);
    if (sjt_value4._parent != 0) {
        sjt_value4._parent->_refCount++;
    }

#line 51 "effect.sj"
    sjt_call128->effect = sjt_value4;
    if (sjt_call128->effect._parent != 0) {
        sjt_call128->effect._parent->_refCount++;
    }

#line 51
    sjt_call128->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call128->_rect.x = 0;
#line 3
    sjt_call128->_rect.y = 0;
#line 4
    sjt_call128->_rect.w = 0;
#line 5
    sjt_call128->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call128->_rect);
#line 5
    sjf_filllayout_heap(sjt_call128);
#line 49 "effect.sj"
    sjt_cast15 = sjt_call128;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_filllayout_as_sji_element(sjt_cast15, &sjt_functionParam410);
    if (sjt_functionParam410._parent != 0) {
        sjt_functionParam410._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent307, sjt_functionParam409, sjt_functionParam410);
#line 40 "effect.sj"
    sjt_parent338 = array8;
#line 40
    sjt_functionParam583 = 2;
#line 40
    sjt_call148 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
#line 40
    sjt_call148->_refCount = 1;
#line 40
    sjt_call148->children._refCount = 1;
#line 60
    sjt_call148->children.v = createarray(sizeof(sji_element), 1);
#line 60
    sjf_array_heap_iface_element(&sjt_call148->children);
#line 60
    sjs_array_heap_iface_element* array10;
#line 60
    array10 = &sjt_call148->children;
#line 60
    sjt_parent339 = array10;
#line 60
    sjt_functionParam585 = 0;
#line 60
    sjf_testscene_heap(&sjt_functionParam586);
#line 60
    sjf_array_heap_iface_element_initat(sjt_parent339, sjt_functionParam585, sjt_functionParam586);
#line 60
    sjt_call148->margin._refCount = 1;
#line 58
    sjt_call148->margin.l = 10;
#line 58
    sjt_call148->margin.t = 10;
#line 58
    sjt_call148->margin.r = 10;
#line 58
    sjt_call148->margin.b = 10;
#line 58
    sjf_margin(&sjt_call148->margin);
#line 58
    sjt_call149 = (sjs_fadeeffect*)malloc(sizeof(sjs_fadeeffect));
#line 58
    sjt_call149->_refCount = 1;
#line 59
    sjt_call149->alpha = 0.5f;
#line 59
    sjt_call149->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call149->_rect.x = 0;
#line 3
    sjt_call149->_rect.y = 0;
#line 4
    sjt_call149->_rect.w = 0;
#line 5
    sjt_call149->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call149->_rect);
#line 7 "lib/sj-lib-ui/fadeEffect.sj"
    sjt_call149->_vertexbuffer._refCount = -1;
#line 8
    sjt_call149->_scenebuffer._refCount = -1;
#line 8
    sjt_call149->_innerscene._refCount = 1;
#line 8
    sjt_call149->_innerscene._size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    sjt_call149->_innerscene._size.w = 0;
#line 3
    sjt_call149->_innerscene._size.h = 0;
#line 3
    sjf_size(&sjt_call149->_innerscene._size);
#line 3
    sjt_call149->_innerscene.model._refCount = 1;
#line 2 "lib/sj-lib-ui/mat4.sj"
    sjt_call149->_innerscene.model.m00 = 0.0f;
#line 3
    sjt_call149->_innerscene.model.m01 = 0.0f;
#line 4
    sjt_call149->_innerscene.model.m02 = 0.0f;
#line 5
    sjt_call149->_innerscene.model.m03 = 0.0f;
#line 6
    sjt_call149->_innerscene.model.m10 = 0.0f;
#line 7
    sjt_call149->_innerscene.model.m11 = 0.0f;
#line 8
    sjt_call149->_innerscene.model.m12 = 0.0f;
#line 9
    sjt_call149->_innerscene.model.m13 = 0.0f;
#line 10
    sjt_call149->_innerscene.model.m20 = 0.0f;
#line 11
    sjt_call149->_innerscene.model.m21 = 0.0f;
#line 12
    sjt_call149->_innerscene.model.m22 = 0.0f;
#line 13
    sjt_call149->_innerscene.model.m23 = 0.0f;
#line 14
    sjt_call149->_innerscene.model.m30 = 0.0f;
#line 15
    sjt_call149->_innerscene.model.m31 = 0.0f;
#line 16
    sjt_call149->_innerscene.model.m32 = 0.0f;
#line 17
    sjt_call149->_innerscene.model.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call149->_innerscene.model);
#line 17
    sjt_call149->_innerscene.view._refCount = 1;
#line 2
    sjt_call149->_innerscene.view.m00 = 0.0f;
#line 3
    sjt_call149->_innerscene.view.m01 = 0.0f;
#line 4
    sjt_call149->_innerscene.view.m02 = 0.0f;
#line 5
    sjt_call149->_innerscene.view.m03 = 0.0f;
#line 6
    sjt_call149->_innerscene.view.m10 = 0.0f;
#line 7
    sjt_call149->_innerscene.view.m11 = 0.0f;
#line 8
    sjt_call149->_innerscene.view.m12 = 0.0f;
#line 9
    sjt_call149->_innerscene.view.m13 = 0.0f;
#line 10
    sjt_call149->_innerscene.view.m20 = 0.0f;
#line 11
    sjt_call149->_innerscene.view.m21 = 0.0f;
#line 12
    sjt_call149->_innerscene.view.m22 = 0.0f;
#line 13
    sjt_call149->_innerscene.view.m23 = 0.0f;
#line 14
    sjt_call149->_innerscene.view.m30 = 0.0f;
#line 15
    sjt_call149->_innerscene.view.m31 = 0.0f;
#line 16
    sjt_call149->_innerscene.view.m32 = 0.0f;
#line 17
    sjt_call149->_innerscene.view.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call149->_innerscene.view);
#line 17
    sjt_call149->_innerscene.projection._refCount = 1;
#line 2
    sjt_call149->_innerscene.projection.m00 = 0.0f;
#line 3
    sjt_call149->_innerscene.projection.m01 = 0.0f;
#line 4
    sjt_call149->_innerscene.projection.m02 = 0.0f;
#line 5
    sjt_call149->_innerscene.projection.m03 = 0.0f;
#line 6
    sjt_call149->_innerscene.projection.m10 = 0.0f;
#line 7
    sjt_call149->_innerscene.projection.m11 = 0.0f;
#line 8
    sjt_call149->_innerscene.projection.m12 = 0.0f;
#line 9
    sjt_call149->_innerscene.projection.m13 = 0.0f;
#line 10
    sjt_call149->_innerscene.projection.m20 = 0.0f;
#line 11
    sjt_call149->_innerscene.projection.m21 = 0.0f;
#line 12
    sjt_call149->_innerscene.projection.m22 = 0.0f;
#line 13
    sjt_call149->_innerscene.projection.m23 = 0.0f;
#line 14
    sjt_call149->_innerscene.projection.m30 = 0.0f;
#line 15
    sjt_call149->_innerscene.projection.m31 = 0.0f;
#line 16
    sjt_call149->_innerscene.projection.m32 = 0.0f;
#line 17
    sjt_call149->_innerscene.projection.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call149->_innerscene.projection);
#line 17
    sjt_call149->_innerscene.windowrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call149->_innerscene.windowrect.x = 0;
#line 3
    sjt_call149->_innerscene.windowrect.y = 0;
#line 4
    sjt_call149->_innerscene.windowrect.w = 0;
#line 5
    sjt_call149->_innerscene.windowrect.h = 0;
#line 5
    sjf_rect(&sjt_call149->_innerscene.windowrect);
#line 5
    sjf_scene2d(&sjt_call149->_innerscene);
#line 5
    sjf_fadeeffect_heap(sjt_call149);
#line 59 "effect.sj"
    sjt_cast22 = sjt_call149;
#line 1 "lib/sj-lib-ui/effect.sj"
    sjf_fadeeffect_as_sji_effect(sjt_cast22, &sjt_value9);
    if (sjt_value9._parent != 0) {
        sjt_value9._parent->_refCount++;
    }

#line 59 "effect.sj"
    sjt_call148->effect = sjt_value9;
    if (sjt_call148->effect._parent != 0) {
        sjt_call148->effect._parent->_refCount++;
    }

#line 59
    sjt_call148->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call148->_rect.x = 0;
#line 3
    sjt_call148->_rect.y = 0;
#line 4
    sjt_call148->_rect.w = 0;
#line 5
    sjt_call148->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call148->_rect);
#line 5
    sjf_filllayout_heap(sjt_call148);
#line 57 "effect.sj"
    sjt_cast21 = sjt_call148;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_filllayout_as_sji_element(sjt_cast21, &sjt_functionParam584);
    if (sjt_functionParam584._parent != 0) {
        sjt_functionParam584._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent338, sjt_functionParam583, sjt_functionParam584);
#line 40 "effect.sj"
    sjt_parent346 = array8;
#line 40
    sjt_functionParam620 = 3;
#line 40
    sjt_call157 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
#line 40
    sjt_call157->_refCount = 1;
#line 40
    sjt_call157->children._refCount = 1;
#line 68
    sjt_call157->children.v = createarray(sizeof(sji_element), 1);
#line 68
    sjf_array_heap_iface_element(&sjt_call157->children);
#line 68
    sjs_array_heap_iface_element* array11;
#line 68
    array11 = &sjt_call157->children;
#line 68
    sjt_parent347 = array11;
#line 68
    sjt_functionParam622 = 0;
#line 68
    sjf_testscene_heap(&sjt_functionParam623);
#line 68
    sjf_array_heap_iface_element_initat(sjt_parent347, sjt_functionParam622, sjt_functionParam623);
#line 68
    sjt_call157->margin._refCount = 1;
#line 66
    sjt_call157->margin.l = 10;
#line 66
    sjt_call157->margin.t = 10;
#line 66
    sjt_call157->margin.r = 10;
#line 66
    sjt_call157->margin.b = 10;
#line 66
    sjf_margin(&sjt_call157->margin);
#line 66
    sjt_call158 = (sjs_saturateeffect*)malloc(sizeof(sjs_saturateeffect));
#line 66
    sjt_call158->_refCount = 1;
#line 67
    sjt_call158->amount = 0.2f;
#line 67
    sjt_call158->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call158->_rect.x = 0;
#line 3
    sjt_call158->_rect.y = 0;
#line 4
    sjt_call158->_rect.w = 0;
#line 5
    sjt_call158->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call158->_rect);
#line 6 "lib/sj-lib-ui/saturateEffect.sj"
    sjt_call158->_vertexbuffer._refCount = -1;
#line 7
    sjt_call158->_scenebuffer._refCount = -1;
#line 7
    sjt_call158->_innerscene._refCount = 1;
#line 7
    sjt_call158->_innerscene._size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    sjt_call158->_innerscene._size.w = 0;
#line 3
    sjt_call158->_innerscene._size.h = 0;
#line 3
    sjf_size(&sjt_call158->_innerscene._size);
#line 3
    sjt_call158->_innerscene.model._refCount = 1;
#line 2 "lib/sj-lib-ui/mat4.sj"
    sjt_call158->_innerscene.model.m00 = 0.0f;
#line 3
    sjt_call158->_innerscene.model.m01 = 0.0f;
#line 4
    sjt_call158->_innerscene.model.m02 = 0.0f;
#line 5
    sjt_call158->_innerscene.model.m03 = 0.0f;
#line 6
    sjt_call158->_innerscene.model.m10 = 0.0f;
#line 7
    sjt_call158->_innerscene.model.m11 = 0.0f;
#line 8
    sjt_call158->_innerscene.model.m12 = 0.0f;
#line 9
    sjt_call158->_innerscene.model.m13 = 0.0f;
#line 10
    sjt_call158->_innerscene.model.m20 = 0.0f;
#line 11
    sjt_call158->_innerscene.model.m21 = 0.0f;
#line 12
    sjt_call158->_innerscene.model.m22 = 0.0f;
#line 13
    sjt_call158->_innerscene.model.m23 = 0.0f;
#line 14
    sjt_call158->_innerscene.model.m30 = 0.0f;
#line 15
    sjt_call158->_innerscene.model.m31 = 0.0f;
#line 16
    sjt_call158->_innerscene.model.m32 = 0.0f;
#line 17
    sjt_call158->_innerscene.model.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call158->_innerscene.model);
#line 17
    sjt_call158->_innerscene.view._refCount = 1;
#line 2
    sjt_call158->_innerscene.view.m00 = 0.0f;
#line 3
    sjt_call158->_innerscene.view.m01 = 0.0f;
#line 4
    sjt_call158->_innerscene.view.m02 = 0.0f;
#line 5
    sjt_call158->_innerscene.view.m03 = 0.0f;
#line 6
    sjt_call158->_innerscene.view.m10 = 0.0f;
#line 7
    sjt_call158->_innerscene.view.m11 = 0.0f;
#line 8
    sjt_call158->_innerscene.view.m12 = 0.0f;
#line 9
    sjt_call158->_innerscene.view.m13 = 0.0f;
#line 10
    sjt_call158->_innerscene.view.m20 = 0.0f;
#line 11
    sjt_call158->_innerscene.view.m21 = 0.0f;
#line 12
    sjt_call158->_innerscene.view.m22 = 0.0f;
#line 13
    sjt_call158->_innerscene.view.m23 = 0.0f;
#line 14
    sjt_call158->_innerscene.view.m30 = 0.0f;
#line 15
    sjt_call158->_innerscene.view.m31 = 0.0f;
#line 16
    sjt_call158->_innerscene.view.m32 = 0.0f;
#line 17
    sjt_call158->_innerscene.view.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call158->_innerscene.view);
#line 17
    sjt_call158->_innerscene.projection._refCount = 1;
#line 2
    sjt_call158->_innerscene.projection.m00 = 0.0f;
#line 3
    sjt_call158->_innerscene.projection.m01 = 0.0f;
#line 4
    sjt_call158->_innerscene.projection.m02 = 0.0f;
#line 5
    sjt_call158->_innerscene.projection.m03 = 0.0f;
#line 6
    sjt_call158->_innerscene.projection.m10 = 0.0f;
#line 7
    sjt_call158->_innerscene.projection.m11 = 0.0f;
#line 8
    sjt_call158->_innerscene.projection.m12 = 0.0f;
#line 9
    sjt_call158->_innerscene.projection.m13 = 0.0f;
#line 10
    sjt_call158->_innerscene.projection.m20 = 0.0f;
#line 11
    sjt_call158->_innerscene.projection.m21 = 0.0f;
#line 12
    sjt_call158->_innerscene.projection.m22 = 0.0f;
#line 13
    sjt_call158->_innerscene.projection.m23 = 0.0f;
#line 14
    sjt_call158->_innerscene.projection.m30 = 0.0f;
#line 15
    sjt_call158->_innerscene.projection.m31 = 0.0f;
#line 16
    sjt_call158->_innerscene.projection.m32 = 0.0f;
#line 17
    sjt_call158->_innerscene.projection.m33 = 0.0f;
#line 17
    sjf_mat4(&sjt_call158->_innerscene.projection);
#line 17
    sjt_call158->_innerscene.windowrect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call158->_innerscene.windowrect.x = 0;
#line 3
    sjt_call158->_innerscene.windowrect.y = 0;
#line 4
    sjt_call158->_innerscene.windowrect.w = 0;
#line 5
    sjt_call158->_innerscene.windowrect.h = 0;
#line 5
    sjf_rect(&sjt_call158->_innerscene.windowrect);
#line 5
    sjf_scene2d(&sjt_call158->_innerscene);
#line 5
    sjf_saturateeffect_heap(sjt_call158);
#line 67 "effect.sj"
    sjt_cast24 = sjt_call158;
#line 1 "lib/sj-lib-ui/effect.sj"
    sjf_saturateeffect_as_sji_effect(sjt_cast24, &sjt_value12);
    if (sjt_value12._parent != 0) {
        sjt_value12._parent->_refCount++;
    }

#line 67 "effect.sj"
    sjt_call157->effect = sjt_value12;
    if (sjt_call157->effect._parent != 0) {
        sjt_call157->effect._parent->_refCount++;
    }

#line 67
    sjt_call157->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call157->_rect.x = 0;
#line 3
    sjt_call157->_rect.y = 0;
#line 4
    sjt_call157->_rect.w = 0;
#line 5
    sjt_call157->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call157->_rect);
#line 5
    sjf_filllayout_heap(sjt_call157);
#line 65 "effect.sj"
    sjt_cast23 = sjt_call157;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_filllayout_as_sji_element(sjt_cast23, &sjt_functionParam621);
    if (sjt_functionParam621._parent != 0) {
        sjt_functionParam621._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent346, sjt_functionParam620, sjt_functionParam621);
#line 1
    sjt_call3->margin._refCount = 1;
#line 2 "lib/sj-lib-ui/margin.sj"
    sjt_call3->margin.l = 0;
#line 3
    sjt_call3->margin.t = 0;
#line 4
    sjt_call3->margin.r = 0;
#line 5
    sjt_call3->margin.b = 0;
#line 5
    sjf_margin(&sjt_call3->margin);
#line 5
    sjt_call3->cols._refCount = 1;
#line 32 "effect.sj"
    sjt_call3->cols.v = createarray(sizeof(sjs_gridunit), 2);
#line 32
    sjf_array_gridunit(&sjt_call3->cols);
#line 32
    sjs_array_gridunit* array1;
#line 32
    array1 = &sjt_call3->cols;
#line 32
    sjt_parent354 = array1;
#line 32
    sjt_functionParam657 = 0;
#line 32
    sjt_call166._refCount = 1;
#line 33
    sjt_call166.amount = 1;
#line 33
    sjt_call166.unittype = g_gridunittype_star;
#line 33
    sjf_gridunit(&sjt_call166);
#line 33
    sjt_functionParam658 = &sjt_call166;
#line 33
    sjf_array_gridunit_initat(sjt_parent354, sjt_functionParam657, sjt_functionParam658);
#line 32
    sjt_parent355 = array1;
#line 32
    sjt_functionParam659 = 1;
#line 32
    sjt_call167._refCount = 1;
#line 34
    sjt_call167.amount = 1;
#line 34
    sjt_call167.unittype = g_gridunittype_star;
#line 34
    sjf_gridunit(&sjt_call167);
#line 34
    sjt_functionParam660 = &sjt_call167;
#line 34
    sjf_array_gridunit_initat(sjt_parent355, sjt_functionParam659, sjt_functionParam660);
#line 34
    sjt_call3->rows._refCount = 1;
#line 36
    sjt_call3->rows.v = createarray(sizeof(sjs_gridunit), 2);
#line 36
    sjf_array_gridunit(&sjt_call3->rows);
#line 36
    sjs_array_gridunit* array2;
#line 36
    array2 = &sjt_call3->rows;
#line 36
    sjt_parent356 = array2;
#line 36
    sjt_functionParam661 = 0;
#line 36
    sjt_call168._refCount = 1;
#line 37
    sjt_call168.amount = 1;
#line 37
    sjt_call168.unittype = g_gridunittype_star;
#line 37
    sjf_gridunit(&sjt_call168);
#line 37
    sjt_functionParam662 = &sjt_call168;
#line 37
    sjf_array_gridunit_initat(sjt_parent356, sjt_functionParam661, sjt_functionParam662);
#line 36
    sjt_parent357 = array2;
#line 36
    sjt_functionParam663 = 1;
#line 36
    sjt_call169._refCount = 1;
#line 38
    sjt_call169.amount = 1;
#line 38
    sjt_call169.unittype = g_gridunittype_star;
#line 38
    sjf_gridunit(&sjt_call169);
#line 38
    sjt_functionParam664 = &sjt_call169;
#line 38
    sjf_array_gridunit_initat(sjt_parent357, sjt_functionParam663, sjt_functionParam664);
#line 38
    sjt_call3->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call3->_rect.x = 0;
#line 3
    sjt_call3->_rect.y = 0;
#line 4
    sjt_call3->_rect.w = 0;
#line 5
    sjt_call3->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call3->_rect);
#line 5
    sjf_gridlayout_heap(sjt_call3);
#line 31 "effect.sj"
    sjt_cast2 = sjt_call3;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_gridlayout_as_sji_element(sjt_cast2, &g_root);
    if (g_root._parent != 0) {
        g_root._parent->_refCount++;
    }

#line 1
    sjf_runloop();
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_mouse_captureelement._parent != 0) {
        g_mouse_captureelement._parent->_refCount--;
        if (g_mouse_captureelement._parent->_refCount <= 0) {
            g_mouse_captureelement._vtbl->destroy(g_mouse_captureelement._parent);
            free(g_mouse_captureelement._parent);
        }
    }
    if (g_root._parent != 0) {
        g_root._parent->_refCount--;
        if (g_root._parent->_refCount <= 0) {
            g_root._vtbl->destroy(g_root._parent);
            free(g_root._parent);
        }
    }
    sjt_call128->_refCount--;
    if (sjt_call128->_refCount <= 0) {
        weakptr_release(sjt_call128);
        sjf_filllayout_destroy(sjt_call128);
        free(sjt_call128);
    }
    sjt_call129->_refCount--;
    if (sjt_call129->_refCount <= 0) {
        weakptr_release(sjt_call129);
        sjf_blureffect_destroy(sjt_call129);
        free(sjt_call129);
    }
    sjt_call148->_refCount--;
    if (sjt_call148->_refCount <= 0) {
        weakptr_release(sjt_call148);
        sjf_filllayout_destroy(sjt_call148);
        free(sjt_call148);
    }
    sjt_call149->_refCount--;
    if (sjt_call149->_refCount <= 0) {
        weakptr_release(sjt_call149);
        sjf_fadeeffect_destroy(sjt_call149);
        free(sjt_call149);
    }
    sjt_call157->_refCount--;
    if (sjt_call157->_refCount <= 0) {
        weakptr_release(sjt_call157);
        sjf_filllayout_destroy(sjt_call157);
        free(sjt_call157);
    }
    sjt_call158->_refCount--;
    if (sjt_call158->_refCount <= 0) {
        weakptr_release(sjt_call158);
        sjf_saturateeffect_destroy(sjt_call158);
        free(sjt_call158);
    }
    sjt_call3->_refCount--;
    if (sjt_call3->_refCount <= 0) {
        weakptr_release(sjt_call3);
        sjf_gridlayout_destroy(sjt_call3);
        free(sjt_call3);
    }
    sjt_call5->_refCount--;
    if (sjt_call5->_refCount <= 0) {
        weakptr_release(sjt_call5);
        sjf_filllayout_destroy(sjt_call5);
        free(sjt_call5);
    }
    if (sjt_functionParam410._parent != 0) {
        sjt_functionParam410._parent->_refCount--;
        if (sjt_functionParam410._parent->_refCount <= 0) {
            sjt_functionParam410._vtbl->destroy(sjt_functionParam410._parent);
            free(sjt_functionParam410._parent);
        }
    }
    if (sjt_functionParam412._parent != 0) {
        sjt_functionParam412._parent->_refCount--;
        if (sjt_functionParam412._parent->_refCount <= 0) {
            sjt_functionParam412._vtbl->destroy(sjt_functionParam412._parent);
            free(sjt_functionParam412._parent);
        }
    }
    if (sjt_functionParam46._parent != 0) {
        sjt_functionParam46._parent->_refCount--;
        if (sjt_functionParam46._parent->_refCount <= 0) {
            sjt_functionParam46._vtbl->destroy(sjt_functionParam46._parent);
            free(sjt_functionParam46._parent);
        }
    }
    if (sjt_functionParam584._parent != 0) {
        sjt_functionParam584._parent->_refCount--;
        if (sjt_functionParam584._parent->_refCount <= 0) {
            sjt_functionParam584._vtbl->destroy(sjt_functionParam584._parent);
            free(sjt_functionParam584._parent);
        }
    }
    if (sjt_functionParam586._parent != 0) {
        sjt_functionParam586._parent->_refCount--;
        if (sjt_functionParam586._parent->_refCount <= 0) {
            sjt_functionParam586._vtbl->destroy(sjt_functionParam586._parent);
            free(sjt_functionParam586._parent);
        }
    }
    if (sjt_functionParam62._parent != 0) {
        sjt_functionParam62._parent->_refCount--;
        if (sjt_functionParam62._parent->_refCount <= 0) {
            sjt_functionParam62._vtbl->destroy(sjt_functionParam62._parent);
            free(sjt_functionParam62._parent);
        }
    }
    if (sjt_functionParam621._parent != 0) {
        sjt_functionParam621._parent->_refCount--;
        if (sjt_functionParam621._parent->_refCount <= 0) {
            sjt_functionParam621._vtbl->destroy(sjt_functionParam621._parent);
            free(sjt_functionParam621._parent);
        }
    }
    if (sjt_functionParam623._parent != 0) {
        sjt_functionParam623._parent->_refCount--;
        if (sjt_functionParam623._parent->_refCount <= 0) {
            sjt_functionParam623._vtbl->destroy(sjt_functionParam623._parent);
            free(sjt_functionParam623._parent);
        }
    }
    if (sjt_value12._parent != 0) {
        sjt_value12._parent->_refCount--;
        if (sjt_value12._parent->_refCount <= 0) {
            sjt_value12._vtbl->destroy(sjt_value12._parent);
            free(sjt_value12._parent);
        }
    }
    if (sjt_value4._parent != 0) {
        sjt_value4._parent->_refCount--;
        if (sjt_value4._parent->_refCount <= 0) {
            sjt_value4._vtbl->destroy(sjt_value4._parent);
            free(sjt_value4._parent);
        }
    }
    if (sjt_value9._parent != 0) {
        sjt_value9._parent->_refCount--;
        if (sjt_value9._parent->_refCount <= 0) {
            sjt_value9._vtbl->destroy(sjt_value9._parent);
            free(sjt_value9._parent);
        }
    }
    if (g_animator._refCount == 1) { sjf_animator_destroy(&g_animator); }
;
    if (g_blurhorizontalshader._refCount == 1) { sjf_shader_destroy(&g_blurhorizontalshader); }
;
    if (g_blurverticalshader._refCount == 1) { sjf_shader_destroy(&g_blurverticalshader); }
;
    if (g_boxshader._refCount == 1) { sjf_shader_destroy(&g_boxshader); }
;
    if (g_colors_black._refCount == 1) { sjf_color_destroy(&g_colors_black); }
;
    if (g_colors_blue._refCount == 1) { sjf_color_destroy(&g_colors_blue); }
;
    if (g_colors_gray._refCount == 1) { sjf_color_destroy(&g_colors_gray); }
;
    if (g_colors_green._refCount == 1) { sjf_color_destroy(&g_colors_green); }
;
    if (g_colors_red._refCount == 1) { sjf_color_destroy(&g_colors_red); }
;
    if (g_colors_white._refCount == 1) { sjf_color_destroy(&g_colors_white); }
;
    if (g_elementsbyid._refCount == 1) { sjf_hash_string_weak_iface_element_destroy(&g_elementsbyid); }
;
    if (g_fadeshader._refCount == 1) { sjf_shader_destroy(&g_fadeshader); }
;
    if (g_fonthash._refCount == 1) { sjf_hash_fontkey_weak_font_destroy(&g_fonthash); }
;
    if (g_glframebuffers._refCount == 1) { sjf_list_u32_destroy(&g_glframebuffers); }
;
    if (g_glviewports._refCount == 1) { sjf_list_rect_destroy(&g_glviewports); }
;
    if (g_imageshader._refCount == 1) { sjf_shader_destroy(&g_imageshader); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (g_looplastrect._refCount == 1) { sjf_rect_destroy(&g_looplastrect); }
;
    if (g_modelsbyid._refCount == 1) { sjf_hash_string_weak_iface_model_destroy(&g_modelsbyid); }
;
    if (g_phongcolorshader._refCount == 1) { sjf_shader_destroy(&g_phongcolorshader); }
;
    if (g_phongtextureshader._refCount == 1) { sjf_shader_destroy(&g_phongtextureshader); }
;
    if (g_rootscene._refCount == 1) { sjf_scene2d_destroy(&g_rootscene); }
;
    if (g_rootwindowrenderer._refCount == 1) { sjf_windowrenderer_destroy(&g_rootwindowrenderer); }
;
    if (g_saturateshader._refCount == 1) { sjf_shader_destroy(&g_saturateshader); }
;
    if (g_style._refCount == 1) { sjf_style_destroy(&g_style); }
;
    if (g_textshader._refCount == 1) { sjf_shader_destroy(&g_textshader); }
;
    if (g_vertex_location_texture_normal_format._refCount == 1) { sjf_string_destroy(&g_vertex_location_texture_normal_format); }
;
    if (sjt_call166._refCount == 1) { sjf_gridunit_destroy(&sjt_call166); }
;
    if (sjt_call167._refCount == 1) { sjf_gridunit_destroy(&sjt_call167); }
;
    if (sjt_call168._refCount == 1) { sjf_gridunit_destroy(&sjt_call168); }
;
    if (sjt_call169._refCount == 1) { sjf_gridunit_destroy(&sjt_call169); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
