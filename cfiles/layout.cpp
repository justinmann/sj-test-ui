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
    char data[33];
} sjg_string16 = { 1, 33, 32, "assets/sj-lib-ui/fonts/arial.ttf"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string17 = { 1, 8, 7, "texture"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string18 = { 1, 6, 5, "model"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string19 = { 1, 5, 4, "view"};
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
    char data[11];
} sjg_string20 = { 1, 11, 10, "projection"};
struct {
    int refcount;
    int size;
    int count;
    char data[2];
} sjg_string21 = { 1, 2, 1, "1"};
struct {
    int refcount;
    int size;
    int count;
    char data[2];
} sjg_string22 = { 1, 2, 1, "2"};
struct {
    int refcount;
    int size;
    int count;
    char data[2];
} sjg_string23 = { 1, 2, 1, "3"};
struct {
    int refcount;
    int size;
    int count;
    char data[2];
} sjg_string24 = { 1, 2, 1, "4"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string25 = { 1, 5, 4, "left"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string26 = { 1, 7, 6, "bottom"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string27 = { 1, 4, 3, "top"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string28 = { 1, 6, 5, "right"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string29 = { 1, 5, 4, "fill"};
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
    char data[6];
} sjg_string30 = { 1, 6, 5, "FPS: "};
struct {
    int refcount;
    int size;
    int count;
    char data[31];
} sjg_string31 = { 1, 31, 30, "viewport being pop'ed is wrong"};
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
#define sjs_array_heap_iface_model_typeId 228
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
#define sji_effect_typeId 118
#define sjs_filllayout_typeId 115
#define cb_rect_void_typeId 116
#define cb_rect_void_heap_typeId 116
#define cb_scene2d_void_typeId 117
#define cb_scene2d_void_heap_typeId 117
#define sjs_boxrenderer_typeId 130
#define sjs_boxelement_typeId 129
#define sjs_textrenderer_typeId 147
#define sjs_textelement_typeId 142
#define sji_textelement_typeId 229
#define sjs_borderlayout_typeId 163
#define sji_borderchild_typeId 165
#define sjs_borderchild_typeId 169
#define sjs_listlayout_typeId 177
#define sjs_flowlayout_typeId 183
#define sjs_centerlayout_typeId 188

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
typedef struct td_sjs_textrenderer sjs_textrenderer;
typedef struct td_sjs_textelement sjs_textelement;
typedef struct td_sji_textelement_vtbl sji_textelement_vtbl;
typedef struct td_sji_textelement sji_textelement;
typedef struct td_sjs_borderlayout sjs_borderlayout;
typedef struct td_sji_borderchild_vtbl sji_borderchild_vtbl;
typedef struct td_sji_borderchild sji_borderchild;
typedef struct td_sjs_borderchild sjs_borderchild;
typedef struct td_sjs_listlayout sjs_listlayout;
typedef struct td_sjs_flowlayout sjs_flowlayout;
typedef struct td_sjs_centerlayout sjs_centerlayout;

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

struct td_sjs_borderlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    sjs_rect _rect;
};

struct td_sji_borderchild_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*getposition)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_borderchild {
    sjs_object* _parent;
    sji_borderchild_vtbl* _vtbl;
};

struct td_sjs_borderchild {
    int _refCount;
    sji_element child;
    int32_t position;
    sjs_rect _rect;
};

struct td_sjs_listlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    int32_t orientation;
    sjs_rect _rect;
};

struct td_sjs_flowlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    int32_t orientation;
    sjs_rect _rect;
};

struct td_sjs_centerlayout {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_margin margin;
    float_option centerx;
    float_option centery;
    sjs_rect _rect;
};

sji_borderchild_vtbl sjs_borderchild_borderchild_vtbl;
sji_element_vtbl sjs_borderchild_element_vtbl;
sji_element_vtbl sjs_borderlayout_element_vtbl;
sji_element_vtbl sjs_boxelement_element_vtbl;
sji_element_vtbl sjs_centerlayout_element_vtbl;
sji_element_vtbl sjs_filllayout_element_vtbl;
sji_element_vtbl sjs_flowlayout_element_vtbl;
sji_element_vtbl sjs_gridlayout_element_vtbl;
sji_element_vtbl sjs_listlayout_element_vtbl;
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
sjs_string sjt_call18 = { -1 };
sjs_string sjt_call19 = { -1 };
sjs_string sjt_call20 = { -1 };
sjs_string sjt_call21 = { -1 };
sjs_gridunit sjt_call22 = { -1 };
sjs_gridunit sjt_call23 = { -1 };
sjs_gridunit sjt_call24 = { -1 };
sjs_gridunit sjt_call25 = { -1 };
sjs_borderlayout* sjt_call26 = 0;
sjs_gridlayout* sjt_call3 = 0;
sjs_borderchild* sjt_call32 = 0;
sjs_string sjt_call33 = { -1 };
sjs_borderchild* sjt_call34 = 0;
sjs_string sjt_call35 = { -1 };
sjs_borderchild* sjt_call36 = 0;
sjs_string sjt_call37 = { -1 };
sjs_borderchild* sjt_call38 = 0;
sjs_string sjt_call39 = { -1 };
sjs_borderchild* sjt_call40 = 0;
sjs_string sjt_call41 = { -1 };
sjs_listlayout* sjt_call42 = 0;
sjs_gridlayout* sjt_call5 = 0;
sjs_string sjt_call51 = { -1 };
sjs_string sjt_call52 = { -1 };
sjs_string sjt_call53 = { -1 };
sjs_string sjt_call54 = { -1 };
sjs_flowlayout* sjt_call55 = 0;
sjs_string sjt_call64 = { -1 };
sjs_string sjt_call65 = { -1 };
sjs_string sjt_call66 = { -1 };
sjs_string sjt_call67 = { -1 };
sjs_string sjt_call68 = { -1 };
sjs_string sjt_call69 = { -1 };
sjs_string sjt_call70 = { -1 };
sjs_string sjt_call71 = { -1 };
sjs_string sjt_call72 = { -1 };
sjs_string sjt_call73 = { -1 };
sjs_string sjt_call74 = { -1 };
sjs_string sjt_call75 = { -1 };
sjs_string sjt_call76 = { -1 };
sjs_string sjt_call77 = { -1 };
sjs_string sjt_call78 = { -1 };
sjs_string sjt_call79 = { -1 };
sjs_string sjt_call80 = { -1 };
sjs_string sjt_call81 = { -1 };
sjs_string sjt_call82 = { -1 };
sjs_string sjt_call83 = { -1 };
sjs_centerlayout* sjt_call84 = 0;
sjs_string sjt_call89 = { -1 };
sjs_gridunit sjt_call90 = { -1 };
sjs_gridunit sjt_call91 = { -1 };
sjs_gridunit sjt_call92 = { -1 };
sjs_gridunit sjt_call93 = { -1 };
sjs_gridunit sjt_call94 = { -1 };
sjs_borderchild* sjt_cast12 = 0;
sjs_borderchild* sjt_cast13 = 0;
sjs_borderchild* sjt_cast14 = 0;
sjs_borderchild* sjt_cast15 = 0;
sjs_borderchild* sjt_cast16 = 0;
sjs_listlayout* sjt_cast17 = 0;
sjs_flowlayout* sjt_cast18 = 0;
sjs_centerlayout* sjt_cast19 = 0;
sjs_gridlayout* sjt_cast2 = 0;
sjs_gridlayout* sjt_cast4 = 0;
sjs_borderlayout* sjt_cast9 = 0;
sjs_string* sjt_functionParam109 = 0;
int32_t sjt_functionParam110;
sji_element sjt_functionParam111 = { 0 };
sjs_string* sjt_functionParam112 = 0;
int32_t sjt_functionParam113;
sji_element sjt_functionParam114 = { 0 };
sjs_string* sjt_functionParam115 = 0;
int32_t sjt_functionParam116;
sji_element sjt_functionParam117 = { 0 };
sjs_string* sjt_functionParam118 = 0;
int32_t sjt_functionParam119;
sjs_gridunit* sjt_functionParam120 = 0;
int32_t sjt_functionParam121;
sjs_gridunit* sjt_functionParam122 = 0;
int32_t sjt_functionParam123;
sjs_gridunit* sjt_functionParam124 = 0;
int32_t sjt_functionParam125;
sjs_gridunit* sjt_functionParam126 = 0;
int32_t sjt_functionParam127;
sji_element sjt_functionParam128 = { 0 };
int32_t sjt_functionParam134;
sji_element sjt_functionParam135 = { 0 };
sjs_string* sjt_functionParam136 = 0;
int32_t sjt_functionParam137;
sji_element sjt_functionParam138 = { 0 };
sjs_string* sjt_functionParam139 = 0;
int32_t sjt_functionParam140;
sji_element sjt_functionParam141 = { 0 };
sjs_string* sjt_functionParam142 = 0;
int32_t sjt_functionParam143;
sji_element sjt_functionParam144 = { 0 };
sjs_string* sjt_functionParam145 = 0;
int32_t sjt_functionParam146;
sji_element sjt_functionParam147 = { 0 };
sjs_string* sjt_functionParam148 = 0;
int32_t sjt_functionParam149;
sji_element sjt_functionParam150 = { 0 };
int32_t sjt_functionParam155;
sji_element sjt_functionParam156 = { 0 };
sjs_string* sjt_functionParam157 = 0;
int32_t sjt_functionParam158;
sji_element sjt_functionParam159 = { 0 };
sjs_string* sjt_functionParam160 = 0;
int32_t sjt_functionParam161;
sji_element sjt_functionParam162 = { 0 };
sjs_string* sjt_functionParam163 = 0;
int32_t sjt_functionParam164;
sji_element sjt_functionParam165 = { 0 };
sjs_string* sjt_functionParam166 = 0;
int32_t sjt_functionParam167;
sji_element sjt_functionParam168 = { 0 };
int32_t sjt_functionParam181;
sji_element sjt_functionParam182 = { 0 };
sjs_string* sjt_functionParam183 = 0;
int32_t sjt_functionParam184;
sji_element sjt_functionParam185 = { 0 };
sjs_string* sjt_functionParam186 = 0;
int32_t sjt_functionParam187;
sji_element sjt_functionParam188 = { 0 };
sjs_string* sjt_functionParam189 = 0;
int32_t sjt_functionParam190;
sji_element sjt_functionParam191 = { 0 };
sjs_string* sjt_functionParam192 = 0;
int32_t sjt_functionParam193;
sji_element sjt_functionParam194 = { 0 };
sjs_string* sjt_functionParam195 = 0;
int32_t sjt_functionParam196;
sji_element sjt_functionParam197 = { 0 };
sjs_string* sjt_functionParam198 = 0;
int32_t sjt_functionParam199;
sji_element sjt_functionParam200 = { 0 };
sjs_string* sjt_functionParam201 = 0;
int32_t sjt_functionParam202;
sji_element sjt_functionParam203 = { 0 };
sjs_string* sjt_functionParam204 = 0;
int32_t sjt_functionParam205;
sji_element sjt_functionParam206 = { 0 };
sjs_string* sjt_functionParam207 = 0;
int32_t sjt_functionParam208;
sji_element sjt_functionParam209 = { 0 };
sjs_string* sjt_functionParam210 = 0;
int32_t sjt_functionParam211;
sji_element sjt_functionParam212 = { 0 };
sjs_string* sjt_functionParam213 = 0;
int32_t sjt_functionParam214;
sji_element sjt_functionParam215 = { 0 };
sjs_string* sjt_functionParam216 = 0;
int32_t sjt_functionParam217;
sji_element sjt_functionParam218 = { 0 };
sjs_string* sjt_functionParam219 = 0;
int32_t sjt_functionParam220;
sji_element sjt_functionParam221 = { 0 };
sjs_string* sjt_functionParam222 = 0;
int32_t sjt_functionParam223;
sji_element sjt_functionParam224 = { 0 };
sjs_string* sjt_functionParam225 = 0;
int32_t sjt_functionParam226;
sji_element sjt_functionParam227 = { 0 };
sjs_string* sjt_functionParam228 = 0;
int32_t sjt_functionParam229;
sji_element sjt_functionParam230 = { 0 };
sjs_string* sjt_functionParam231 = 0;
int32_t sjt_functionParam232;
sji_element sjt_functionParam233 = { 0 };
sjs_string* sjt_functionParam234 = 0;
int32_t sjt_functionParam235;
sji_element sjt_functionParam236 = { 0 };
sjs_string* sjt_functionParam237 = 0;
int32_t sjt_functionParam238;
sji_element sjt_functionParam239 = { 0 };
sjs_string* sjt_functionParam240 = 0;
int32_t sjt_functionParam241;
sji_element sjt_functionParam242 = { 0 };
int32_t sjt_functionParam255;
sji_element sjt_functionParam256 = { 0 };
sjs_string* sjt_functionParam257 = 0;
int32_t sjt_functionParam258;
sjs_gridunit* sjt_functionParam259 = 0;
int32_t sjt_functionParam260;
sjs_gridunit* sjt_functionParam261 = 0;
int32_t sjt_functionParam262;
sjs_gridunit* sjt_functionParam263 = 0;
int32_t sjt_functionParam264;
sjs_gridunit* sjt_functionParam265 = 0;
int32_t sjt_functionParam266;
sjs_gridunit* sjt_functionParam267 = 0;
int32_t sjt_functionParam45;
sji_element sjt_functionParam46 = { 0 };
int32_t sjt_functionParam47;
sji_element sjt_functionParam48 = { 0 };
sjs_array_heap_iface_element* sjt_parent114 = 0;
sjs_array_heap_iface_element* sjt_parent120 = 0;
sjs_array_heap_iface_element* sjt_parent121 = 0;
sjs_array_heap_iface_element* sjt_parent122 = 0;
sjs_array_heap_iface_element* sjt_parent123 = 0;
sjs_array_heap_iface_element* sjt_parent124 = 0;
sjs_array_heap_iface_element* sjt_parent140 = 0;
sjs_array_heap_iface_element* sjt_parent141 = 0;
sjs_array_heap_iface_element* sjt_parent142 = 0;
sjs_array_heap_iface_element* sjt_parent143 = 0;
sjs_array_heap_iface_element* sjt_parent144 = 0;
sjs_array_heap_iface_element* sjt_parent160 = 0;
sjs_array_heap_iface_element* sjt_parent161 = 0;
sjs_array_heap_iface_element* sjt_parent162 = 0;
sjs_array_heap_iface_element* sjt_parent163 = 0;
sjs_array_heap_iface_element* sjt_parent164 = 0;
sjs_array_heap_iface_element* sjt_parent165 = 0;
sjs_array_heap_iface_element* sjt_parent166 = 0;
sjs_array_heap_iface_element* sjt_parent167 = 0;
sjs_array_heap_iface_element* sjt_parent168 = 0;
sjs_array_heap_iface_element* sjt_parent169 = 0;
sjs_array_heap_iface_element* sjt_parent170 = 0;
sjs_array_heap_iface_element* sjt_parent171 = 0;
sjs_array_heap_iface_element* sjt_parent172 = 0;
sjs_array_heap_iface_element* sjt_parent173 = 0;
sjs_array_heap_iface_element* sjt_parent174 = 0;
sjs_array_heap_iface_element* sjt_parent175 = 0;
sjs_array_heap_iface_element* sjt_parent176 = 0;
sjs_array_heap_iface_element* sjt_parent177 = 0;
sjs_array_heap_iface_element* sjt_parent178 = 0;
sjs_array_heap_iface_element* sjt_parent179 = 0;
sjs_array_heap_iface_element* sjt_parent180 = 0;
sjs_array_heap_iface_element* sjt_parent202 = 0;
sjs_array_gridunit* sjt_parent203 = 0;
sjs_array_gridunit* sjt_parent204 = 0;
sjs_array_gridunit* sjt_parent205 = 0;
sjs_array_gridunit* sjt_parent206 = 0;
sjs_array_gridunit* sjt_parent207 = 0;
sjs_array_heap_iface_element* sjt_parent41 = 0;
sjs_array_heap_iface_element* sjt_parent42 = 0;
sjs_array_heap_iface_element* sjt_parent87 = 0;
sjs_array_heap_iface_element* sjt_parent88 = 0;
sjs_array_heap_iface_element* sjt_parent89 = 0;
sjs_array_gridunit* sjt_parent90 = 0;
sjs_array_gridunit* sjt_parent91 = 0;
sjs_array_gridunit* sjt_parent92 = 0;
sjs_array_gridunit* sjt_parent93 = 0;
sjs_array_heap_iface_element* sjt_parent94 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };
float sjt_value8;
float sjt_value9;

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
void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from);
void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
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
void sjf_array_u32_copy(sjs_array_u32* _this, sjs_array_u32* _from);
void sjf_array_u32_destroy(sjs_array_u32* _this);
void sjf_array_u32_heap(sjs_array_u32* _this);
void sjf_borderchild(sjs_borderchild* _this);
void sjf_borderchild_as_sji_borderchild(sjs_borderchild* _this, sji_borderchild* _return);
void sjf_borderchild_as_sji_element(sjs_borderchild* _this, sji_element* _return);
void sjf_borderchild_asinterface(sjs_borderchild* _this, int typeId, sjs_interface* _return);
void sjf_borderchild_copy(sjs_borderchild* _this, sjs_borderchild* _from);
void sjf_borderchild_destroy(sjs_borderchild* _this);
void sjf_borderchild_firemouseevent(sjs_borderchild* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_borderchild_getclasstype(sjs_object* _this, int* _return);
void sjf_borderchild_getposition(sjs_borderchild* _parent, int32_t* _return);
void sjf_borderchild_getrect(sjs_borderchild* _parent, sjs_rect* _return);
void sjf_borderchild_getrect_heap(sjs_borderchild* _parent, sjs_rect** _return);
void sjf_borderchild_getsize(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_borderchild_getsize_heap(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_borderchild_heap(sjs_borderchild* _this);
void sjf_borderchild_render(sjs_borderchild* _parent, sjs_scene2d* scene);
void sjf_borderchild_setrect(sjs_borderchild* _parent, sjs_rect* rect_);
void sjf_borderlayout(sjs_borderlayout* _this);
void sjf_borderlayout_as_sji_element(sjs_borderlayout* _this, sji_element* _return);
void sjf_borderlayout_asinterface(sjs_borderlayout* _this, int typeId, sjs_interface* _return);
void sjf_borderlayout_copy(sjs_borderlayout* _this, sjs_borderlayout* _from);
void sjf_borderlayout_destroy(sjs_borderlayout* _this);
void sjf_borderlayout_firemouseevent(sjs_borderlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_borderlayout_getclasstype(sjs_object* _this, int* _return);
void sjf_borderlayout_getrect(sjs_borderlayout* _parent, sjs_rect* _return);
void sjf_borderlayout_getrect_heap(sjs_borderlayout* _parent, sjs_rect** _return);
void sjf_borderlayout_getsize(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_borderlayout_getsize_heap(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_borderlayout_heap(sjs_borderlayout* _this);
void sjf_borderlayout_render(sjs_borderlayout* _parent, sjs_scene2d* scene);
void sjf_borderlayout_setrect(sjs_borderlayout* _parent, sjs_rect* rect_);
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
void sjf_centerlayout(sjs_centerlayout* _this);
void sjf_centerlayout_as_sji_element(sjs_centerlayout* _this, sji_element* _return);
void sjf_centerlayout_asinterface(sjs_centerlayout* _this, int typeId, sjs_interface* _return);
void sjf_centerlayout_copy(sjs_centerlayout* _this, sjs_centerlayout* _from);
void sjf_centerlayout_destroy(sjs_centerlayout* _this);
void sjf_centerlayout_firemouseevent(sjs_centerlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_centerlayout_getclasstype(sjs_object* _this, int* _return);
void sjf_centerlayout_getrect(sjs_centerlayout* _parent, sjs_rect* _return);
void sjf_centerlayout_getrect_heap(sjs_centerlayout* _parent, sjs_rect** _return);
void sjf_centerlayout_getsize(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_centerlayout_getsize_heap(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_centerlayout_heap(sjs_centerlayout* _this);
void sjf_centerlayout_render(sjs_centerlayout* _parent, sjs_scene2d* scene);
void sjf_centerlayout_setrect(sjs_centerlayout* _parent, sjs_rect* rect_);
void sjf_color(sjs_color* _this);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_f32_asstring(float val, sjs_string* _return);
void sjf_f32_asstring_heap(float val, sjs_string** _return);
void sjf_f32_hash(float val, uint32_t* _return);
void sjf_f32_random(float* _return);
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
void sjf_flowlayout(sjs_flowlayout* _this);
void sjf_flowlayout_as_sji_element(sjs_flowlayout* _this, sji_element* _return);
void sjf_flowlayout_asinterface(sjs_flowlayout* _this, int typeId, sjs_interface* _return);
void sjf_flowlayout_copy(sjs_flowlayout* _this, sjs_flowlayout* _from);
void sjf_flowlayout_destroy(sjs_flowlayout* _this);
void sjf_flowlayout_firemouseevent(sjs_flowlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_flowlayout_getclasstype(sjs_object* _this, int* _return);
void sjf_flowlayout_getrect(sjs_flowlayout* _parent, sjs_rect* _return);
void sjf_flowlayout_getrect_heap(sjs_flowlayout* _parent, sjs_rect** _return);
void sjf_flowlayout_getsize(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_flowlayout_getsize_heap(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_flowlayout_heap(sjs_flowlayout* _this);
void sjf_flowlayout_render(sjs_flowlayout* _parent, sjs_scene2d* scene);
void sjf_flowlayout_setrect(sjs_flowlayout* _parent, sjs_rect* rect_);
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
void sjf_glblendfunc(int32_t sfactor, int32_t dfactor);
void sjf_glclearcolor(sjs_color* color);
void sjf_glenable(int32_t feature);
void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return);
void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect);
void sjf_gluniformi32(int32_t loc, int32_t v);
void sjf_gluniformmat4(int32_t loc, sjs_mat4* m);
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
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_i32_random(int32_t* _return);
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
void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from);
void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this);
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
void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from);
void sjf_list_u32_destroy(sjs_list_u32* _this);
void sjf_list_u32_heap(sjs_list_u32* _this);
void sjf_listlayout(sjs_listlayout* _this);
void sjf_listlayout_as_sji_element(sjs_listlayout* _this, sji_element* _return);
void sjf_listlayout_asinterface(sjs_listlayout* _this, int typeId, sjs_interface* _return);
void sjf_listlayout_copy(sjs_listlayout* _this, sjs_listlayout* _from);
void sjf_listlayout_destroy(sjs_listlayout* _this);
void sjf_listlayout_firemouseevent(sjs_listlayout* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_listlayout_getclasstype(sjs_object* _this, int* _return);
void sjf_listlayout_getrect(sjs_listlayout* _parent, sjs_rect* _return);
void sjf_listlayout_getrect_heap(sjs_listlayout* _parent, sjs_rect** _return);
void sjf_listlayout_getsize(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_listlayout_getsize_heap(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_listlayout_heap(sjs_listlayout* _this);
void sjf_listlayout_render(sjs_listlayout* _parent, sjs_scene2d* scene);
void sjf_listlayout_setrect(sjs_listlayout* _parent, sjs_rect* rect_);
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
void sjf_mat4_heap(sjs_mat4* _this);
void sjf_mat4_identity(sjs_mat4* _return);
void sjf_mat4_identity_heap(sjs_mat4** _return);
void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return);
void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return);
void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return);
void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4** _return);
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
void sjf_runloop(void);
void sjf_scene2d(sjs_scene2d* _this);
void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from);
void sjf_scene2d_destroy(sjs_scene2d* _this);
void sjf_scene2d_end(sjs_scene2d* _parent);
void sjf_scene2d_heap(sjs_scene2d* _this);
void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size);
void sjf_scene2d_start(sjs_scene2d* _parent);
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
void sjf_testelement_heap(sjs_string* text, sji_element* _return);
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
void sjf_type_hash(int32_t val, uint32_t* _return);
void sjf_type_isequal(int32_t l, int32_t r, bool* _return);
void sjf_vec3(sjs_vec3* _this);
void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from);
void sjf_vec3_destroy(sjs_vec3* _this);
void sjf_vec3_heap(sjs_vec3* _this);
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
    int32_t sjt_capture24;
    sjs_list_heap_iface_animation* sjt_parent209 = 0;

#line 31 "lib/sj-lib-ui/animation.sj"
    _parent->current = time;
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent209 = &_parent->animations;
#line 4
    sjf_list_heap_iface_animation_getcount(sjt_parent209, &sjt_capture24);
    if (sjt_capture24 > 0) {
        int32_t i;
        int32_t sjt_forEnd23;
        int32_t sjt_forStart23;
        sjs_list_heap_iface_animation* sjt_parent210 = 0;

#line 35 "lib/sj-lib-ui/animation.sj"
        sjt_forStart23 = 0;
#line 4 "lib/sj-lib-common/list.sj"
        sjt_parent210 = &_parent->animations;
#line 4
        sjf_list_heap_iface_animation_getcount(sjt_parent210, &sjt_forEnd23);
#line 35 "lib/sj-lib-ui/animation.sj"
        i = sjt_forEnd23 - 1;
        while (i >= sjt_forStart23) {
            sji_animation a = { 0 };
            bool sjt_capture25;
            int32_t sjt_functionParam269;
            int32_t sjt_interfaceParam47;
            sjs_list_heap_iface_animation* sjt_parent212 = 0;
            sji_animation sjt_parent213 = { 0 };

#line 8 "lib/sj-lib-common/list.sj"
            sjt_parent212 = &_parent->animations;
#line 35 "lib/sj-lib-ui/animation.sj"
            sjt_functionParam269 = i;
#line 35
            sjf_list_heap_iface_animation_getat_heap(sjt_parent212, sjt_functionParam269, &a);
#line 2
            sjt_parent213 = a;
#line 31
            sjt_interfaceParam47 = time;
#line 37
            sjt_parent213._vtbl->nextframe(sjt_parent213._parent, sjt_interfaceParam47, &sjt_capture25);
            if (sjt_capture25) {
                int32_t sjt_functionParam270;
                sjs_list_heap_iface_animation* sjt_parent214 = 0;

#line 53 "lib/sj-lib-common/list.sj"
                sjt_parent214 = &_parent->animations;
#line 35 "lib/sj-lib-ui/animation.sj"
                sjt_functionParam270 = i;
#line 35
                sjf_list_heap_iface_animation_removeat(sjt_parent214, sjt_functionParam270);
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

void sjf_borderchild(sjs_borderchild* _this) {
}

void sjf_borderchild_as_sji_borderchild(sjs_borderchild* _this, sji_borderchild* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_borderchild_borderchild_vtbl;
}

void sjf_borderchild_as_sji_element(sjs_borderchild* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_borderchild_element_vtbl;
}

void sjf_borderchild_asinterface(sjs_borderchild* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_borderchild_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        case sji_borderchild_typeId:  {
            sjf_borderchild_as_sji_borderchild(_this, (sji_borderchild*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_borderchild_copy(sjs_borderchild* _this, sjs_borderchild* _from) {
#line 13 "lib/sj-lib-ui/borderLayout.sj"
    _this->child = _from->child;
    if (_this->child._parent != 0) {
        _this->child._parent->_refCount++;
    }

#line 13
    _this->position = _from->position;
#line 13
    _this->_rect._refCount = 1;
#line 13
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_borderchild_destroy(sjs_borderchild* _this) {
    if (_this->child._parent != 0) {
        _this->child._parent->_refCount--;
        if (_this->child._parent->_refCount <= 0) {
            _this->child._vtbl->destroy(_this->child._parent);
            free(_this->child._parent);
        }
    }

    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_borderchild_firemouseevent(sjs_borderchild* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_mouseevent* sjt_interfaceParam23 = 0;
    sji_element sjt_parent119 = { 0 };

#line 6 "lib/sj-lib-ui/element.sj"
    sjt_parent119 = _parent->child;
#line 36 "lib/sj-lib-ui/borderLayout.sj"
    sjt_interfaceParam23 = mouseevent;
#line 37
    sjt_parent119._vtbl->firemouseevent(sjt_parent119._parent, sjt_interfaceParam23, _return);
}

void sjf_borderchild_getclasstype(sjs_object* _this, int* _return) {
    *_return = 169;
}

void sjf_borderchild_getposition(sjs_borderchild* _parent, int32_t* _return) {
#line 18 "lib/sj-lib-ui/borderLayout.sj"
    (*_return) = _parent->position;
}

void sjf_borderchild_getrect(sjs_borderchild* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 24 "lib/sj-lib-ui/borderLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_borderchild_getrect_heap(sjs_borderchild* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 24 "lib/sj-lib-ui/borderLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_borderchild_getsize(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_interfaceParam19 = 0;
    sji_element sjt_parent115 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
    sjt_parent115 = _parent->child;
#line 20 "lib/sj-lib-ui/borderLayout.sj"
    sjt_interfaceParam19 = maxsize;
#line 21
    sjt_parent115._vtbl->getsize(sjt_parent115._parent, sjt_interfaceParam19, _return);
}

void sjf_borderchild_getsize_heap(sjs_borderchild* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_interfaceParam20 = 0;
    sji_element sjt_parent116 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
    sjt_parent116 = _parent->child;
#line 20 "lib/sj-lib-ui/borderLayout.sj"
    sjt_interfaceParam20 = maxsize;
#line 21
    sjt_parent116._vtbl->getsize_heap(sjt_parent116._parent, sjt_interfaceParam20, _return);
}

void sjf_borderchild_heap(sjs_borderchild* _this) {
}

void sjf_borderchild_render(sjs_borderchild* _parent, sjs_scene2d* scene) {
    sjs_scene2d* sjt_interfaceParam22 = 0;
    sji_element sjt_parent118 = { 0 };

#line 5 "lib/sj-lib-ui/element.sj"
    sjt_parent118 = _parent->child;
#line 32 "lib/sj-lib-ui/borderLayout.sj"
    sjt_interfaceParam22 = scene;
#line 33
    sjt_parent118._vtbl->render(sjt_parent118._parent, sjt_interfaceParam22);
}

void sjf_borderchild_setrect(sjs_borderchild* _parent, sjs_rect* rect_) {
    sjs_rect* sjt_interfaceParam21 = 0;
    sji_element sjt_parent117 = { 0 };

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 26 "lib/sj-lib-ui/borderLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 4 "lib/sj-lib-ui/element.sj"
    sjt_parent117 = _parent->child;
#line 28 "lib/sj-lib-ui/borderLayout.sj"
    sjt_interfaceParam21 = &_parent->_rect;
#line 28
    sjt_parent117._vtbl->setrect(sjt_parent117._parent, sjt_interfaceParam21);
}

void sjf_borderlayout(sjs_borderlayout* _this) {
}

void sjf_borderlayout_as_sji_element(sjs_borderlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_borderlayout_element_vtbl;
}

void sjf_borderlayout_asinterface(sjs_borderlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_borderlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_borderlayout_copy(sjs_borderlayout* _this, sjs_borderlayout* _from) {
    _this->children._refCount = 1;
#line 41 "lib/sj-lib-ui/borderLayout.sj"
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 41
    _this->margin._refCount = 1;
#line 41
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 41
    _this->_rect._refCount = 1;
#line 41
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_borderlayout_destroy(sjs_borderlayout* _this) {
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_borderlayout_firemouseevent(sjs_borderlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam133 = 0;
    sjs_mouseevent* sjt_parent113 = 0;

#line 101 "lib/sj-lib-ui/borderLayout.sj"
    sjt_parent113 = mouseevent;
#line 102
    sjt_functionParam133 = &_parent->children;
#line 102
    sjf_mouseevent_firechildren(sjt_parent113, sjt_functionParam133, _return);
}

void sjf_borderlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 163;
}

void sjf_borderlayout_getrect(sjs_borderlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 50 "lib/sj-lib-ui/borderLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_borderlayout_getrect_heap(sjs_borderlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 50 "lib/sj-lib-ui/borderLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_borderlayout_getsize(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 47 "lib/sj-lib-ui/borderLayout.sj"
    _return->w = maxsize->w;
#line 47
    _return->h = maxsize->h;
#line 47
    sjf_size(_return);
}

void sjf_borderlayout_getsize_heap(sjs_borderlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 47 "lib/sj-lib-ui/borderLayout.sj"
    (*_return)->w = maxsize->w;
#line 47
    (*_return)->h = maxsize->h;
#line 47
    sjf_size_heap((*_return));
}

void sjf_borderlayout_heap(sjs_borderlayout* _this) {
}

void sjf_borderlayout_render(sjs_borderlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd14;
    int32_t sjt_forStart14;
    sjs_array_heap_iface_element* sjt_parent110 = 0;

#line 95 "lib/sj-lib-ui/borderLayout.sj"
    sjt_forStart14 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent110 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent110, &sjt_forEnd14);
#line 95 "lib/sj-lib-ui/borderLayout.sj"
    i = sjt_forStart14;
    while (i < sjt_forEnd14) {
        sji_element child = { 0 };
        int32_t sjt_functionParam132;
        sjs_scene2d* sjt_interfaceParam18 = 0;
        sjs_array_heap_iface_element* sjt_parent111 = 0;
        sji_element sjt_parent112 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent111 = &_parent->children;
#line 95 "lib/sj-lib-ui/borderLayout.sj"
        sjt_functionParam132 = i;
#line 95
        sjf_array_heap_iface_element_getat_heap(sjt_parent111, sjt_functionParam132, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent112 = child;
#line 94 "lib/sj-lib-ui/borderLayout.sj"
        sjt_interfaceParam18 = scene;
#line 97
        sjt_parent112._vtbl->render(sjt_parent112._parent, sjt_interfaceParam18);
#line 95
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

void sjf_borderlayout_setrect(sjs_borderlayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect remaining = { -1 };
    int32_t sjt_forEnd12;
    int32_t sjt_forEnd13;
    int32_t sjt_forStart12;
    int32_t sjt_forStart13;
    sjs_margin* sjt_functionParam129 = 0;
    sjs_array_heap_iface_element* sjt_parent105 = 0;
    sjs_rect* sjt_parent95 = 0;
    sjs_array_heap_iface_element* sjt_parent96 = 0;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 52 "lib/sj-lib-ui/borderLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 52
    sjt_parent95 = rect_;
#line 54
    sjt_functionParam129 = &_parent->margin;
#line 54
    sjf_rect_subtractmargin(sjt_parent95, sjt_functionParam129, &remaining);
#line 55
    sjt_forStart12 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent96 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent96, &sjt_forEnd12);
#line 55 "lib/sj-lib-ui/borderLayout.sj"
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sji_borderchild borderchild = { 0 };
        sji_element child = { 0 };
        sjs_size childsize = { -1 };
        int32_t position;
        sjs_size sjt_call27 = { -1 };
        sjs_rect sjt_call28 = { -1 };
        sjs_rect sjt_call29 = { -1 };
        sjs_rect sjt_call30 = { -1 };
        sjs_rect sjt_call31 = { -1 };
        int32_option sjt_capture22;
        sji_element sjt_cast10 = { 0 };
        sjs_rect sjt_funcold10 = { -1 };
        sjs_rect sjt_funcold7 = { -1 };
        sjs_rect sjt_funcold8 = { -1 };
        sjs_rect sjt_funcold9 = { -1 };
        int32_t sjt_functionParam130;
        sjs_array_heap_iface_element* sjt_parent97 = 0;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent97 = &_parent->children;
#line 55 "lib/sj-lib-ui/borderLayout.sj"
        sjt_functionParam130 = i;
#line 55
        sjf_array_heap_iface_element_getat_heap(sjt_parent97, sjt_functionParam130, &child);
#line 57
        sjt_cast10 = child;
#line 9
        sjt_cast10._vtbl->asinterface(sjt_cast10._parent, sji_borderchild_typeId, (sjs_interface*)&borderchild);
        if (borderchild._parent != 0) {
            borderchild._parent->_refCount++;
        }

        if (borderchild._parent != 0) {
            sji_borderchild sjt_parent98 = { 0 };
            int32_t sjt_value4;

#line 10 "lib/sj-lib-ui/borderLayout.sj"
            sjt_parent98 = borderchild;
#line 58
            sjt_parent98._vtbl->getposition(sjt_parent98._parent, &sjt_value4);
#line 58
            sjt_capture22.isvalid = true;
#line 58
            sjt_capture22.value = sjt_value4;
        } else {
#line 58 "lib/sj-lib-ui/borderLayout.sj"
            sjt_capture22 = int32_empty;
        }

        if (sjt_capture22.isvalid) {
            int32_option sjt_getValue1;

            if (borderchild._parent != 0) {
                sji_borderchild sjt_parent99 = { 0 };
                int32_t sjt_value5;

#line 10 "lib/sj-lib-ui/borderLayout.sj"
                sjt_parent99 = borderchild;
#line 58
                sjt_parent99._vtbl->getposition(sjt_parent99._parent, &sjt_value5);
#line 58
                sjt_getValue1.isvalid = true;
#line 58
                sjt_getValue1.value = sjt_value5;
            } else {
#line 58 "lib/sj-lib-ui/borderLayout.sj"
                sjt_getValue1 = int32_empty;
            }

#line 58 "lib/sj-lib-ui/borderLayout.sj"
            position = sjt_getValue1.value;
        } else {
#line 58 "lib/sj-lib-ui/borderLayout.sj"
            position = g_borderposition_fill;
        }

        if (position != g_borderposition_fill) {
            sjs_size* sjt_interfaceParam12 = 0;
            sji_element sjt_parent100 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
            sjt_parent100 = child;
#line 2
            sjt_call27._refCount = 1;
#line 61 "lib/sj-lib-ui/borderLayout.sj"
            sjt_call27.w = (&remaining)->w;
#line 61
            sjt_call27.h = (&remaining)->h;
#line 61
            sjf_size(&sjt_call27);
#line 61
            sjt_interfaceParam12 = &sjt_call27;
#line 61
            sjt_parent100._vtbl->getsize(sjt_parent100._parent, sjt_interfaceParam12, &childsize);
            if (position == g_borderposition_left) {
                sjs_rect* sjt_interfaceParam13 = 0;
                sji_element sjt_parent101 = { 0 };

#line 4 "lib/sj-lib-ui/element.sj"
                sjt_parent101 = child;
#line 4
                sjt_call28._refCount = 1;
#line 63 "lib/sj-lib-ui/borderLayout.sj"
                sjt_call28.x = (&remaining)->x;
#line 63
                sjt_call28.y = (&remaining)->y;
#line 63
                sjt_call28.w = (&childsize)->w;
#line 63
                sjt_call28.h = (&remaining)->h;
#line 63
                sjf_rect(&sjt_call28);
#line 63
                sjt_interfaceParam13 = &sjt_call28;
#line 63
                sjt_parent101._vtbl->setrect(sjt_parent101._parent, sjt_interfaceParam13);
#line 63
                sjt_funcold7._refCount = 1;
#line 64
                sjt_funcold7.x = (&remaining)->x + (&childsize)->w;
#line 64
                sjt_funcold7.y = (&remaining)->y;
#line 64
                sjt_funcold7.w = (&remaining)->w - (&childsize)->w;
#line 64
                sjt_funcold7.h = (&remaining)->h;
#line 64
                sjf_rect(&sjt_funcold7);
#line 64
                if (remaining._refCount == 1) { sjf_rect_destroy(&remaining); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
                sjf_rect_copy(&remaining, &sjt_funcold7);
            } else {
                if (position == g_borderposition_right) {
                    sjs_rect* sjt_interfaceParam14 = 0;
                    sji_element sjt_parent102 = { 0 };

#line 4 "lib/sj-lib-ui/element.sj"
                    sjt_parent102 = child;
#line 4
                    sjt_call29._refCount = 1;
#line 67 "lib/sj-lib-ui/borderLayout.sj"
                    sjt_call29.x = ((&remaining)->x + (&remaining)->w) - (&childsize)->w;
#line 67
                    sjt_call29.y = (&remaining)->y;
#line 67
                    sjt_call29.w = (&childsize)->w;
#line 67
                    sjt_call29.h = (&remaining)->h;
#line 67
                    sjf_rect(&sjt_call29);
#line 67
                    sjt_interfaceParam14 = &sjt_call29;
#line 67
                    sjt_parent102._vtbl->setrect(sjt_parent102._parent, sjt_interfaceParam14);
#line 67
                    sjt_funcold8._refCount = 1;
#line 68
                    sjt_funcold8.x = (&remaining)->x;
#line 68
                    sjt_funcold8.y = (&remaining)->y;
#line 68
                    sjt_funcold8.w = (&remaining)->w - (&childsize)->w;
#line 68
                    sjt_funcold8.h = (&remaining)->h;
#line 68
                    sjf_rect(&sjt_funcold8);
#line 68
                    if (remaining._refCount == 1) { sjf_rect_destroy(&remaining); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
                    sjf_rect_copy(&remaining, &sjt_funcold8);
                } else {
                    if (position == g_borderposition_top) {
                        sjs_rect* sjt_interfaceParam15 = 0;
                        sji_element sjt_parent103 = { 0 };

#line 4 "lib/sj-lib-ui/element.sj"
                        sjt_parent103 = child;
#line 4
                        sjt_call30._refCount = 1;
#line 71 "lib/sj-lib-ui/borderLayout.sj"
                        sjt_call30.x = (&remaining)->x;
#line 71
                        sjt_call30.y = (&remaining)->y;
#line 71
                        sjt_call30.w = (&remaining)->w;
#line 71
                        sjt_call30.h = (&childsize)->h;
#line 71
                        sjf_rect(&sjt_call30);
#line 71
                        sjt_interfaceParam15 = &sjt_call30;
#line 71
                        sjt_parent103._vtbl->setrect(sjt_parent103._parent, sjt_interfaceParam15);
#line 71
                        sjt_funcold9._refCount = 1;
#line 72
                        sjt_funcold9.x = (&remaining)->x;
#line 72
                        sjt_funcold9.y = (&remaining)->y + (&childsize)->h;
#line 72
                        sjt_funcold9.w = (&remaining)->w;
#line 72
                        sjt_funcold9.h = (&remaining)->h - (&childsize)->h;
#line 72
                        sjf_rect(&sjt_funcold9);
#line 72
                        if (remaining._refCount == 1) { sjf_rect_destroy(&remaining); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
                        sjf_rect_copy(&remaining, &sjt_funcold9);
                    } else {
                        if (position == g_borderposition_bottom) {
                            sjs_rect* sjt_interfaceParam16 = 0;
                            sji_element sjt_parent104 = { 0 };

#line 4 "lib/sj-lib-ui/element.sj"
                            sjt_parent104 = child;
#line 4
                            sjt_call31._refCount = 1;
#line 75 "lib/sj-lib-ui/borderLayout.sj"
                            sjt_call31.x = (&remaining)->x;
#line 75
                            sjt_call31.y = ((&remaining)->y + (&remaining)->h) - (&childsize)->h;
#line 75
                            sjt_call31.w = (&remaining)->w;
#line 75
                            sjt_call31.h = (&childsize)->h;
#line 75
                            sjf_rect(&sjt_call31);
#line 75
                            sjt_interfaceParam16 = &sjt_call31;
#line 75
                            sjt_parent104._vtbl->setrect(sjt_parent104._parent, sjt_interfaceParam16);
#line 75
                            sjt_funcold10._refCount = 1;
#line 76
                            sjt_funcold10.x = (&remaining)->x;
#line 76
                            sjt_funcold10.y = (&remaining)->y;
#line 76
                            sjt_funcold10.w = (&remaining)->w;
#line 76
                            sjt_funcold10.h = (&remaining)->h - (&childsize)->h;
#line 76
                            sjf_rect(&sjt_funcold10);
#line 76
                            if (remaining._refCount == 1) { sjf_rect_destroy(&remaining); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
                            sjf_rect_copy(&remaining, &sjt_funcold10);
                        }
                    }
                }
            }
        }

#line 55
        i++;

        if (borderchild._parent != 0) {
            borderchild._parent->_refCount--;
            if (borderchild._parent->_refCount <= 0) {
                borderchild._vtbl->destroy(borderchild._parent);
                free(borderchild._parent);
            }
        }
        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
        if (sjt_call27._refCount == 1) { sjf_size_destroy(&sjt_call27); }
;
        if (sjt_call28._refCount == 1) { sjf_rect_destroy(&sjt_call28); }
;
        if (sjt_call29._refCount == 1) { sjf_rect_destroy(&sjt_call29); }
;
        if (sjt_call30._refCount == 1) { sjf_rect_destroy(&sjt_call30); }
;
        if (sjt_call31._refCount == 1) { sjf_rect_destroy(&sjt_call31); }
;
        if (sjt_funcold10._refCount == 1) { sjf_rect_destroy(&sjt_funcold10); }
;
        if (sjt_funcold7._refCount == 1) { sjf_rect_destroy(&sjt_funcold7); }
;
        if (sjt_funcold8._refCount == 1) { sjf_rect_destroy(&sjt_funcold8); }
;
        if (sjt_funcold9._refCount == 1) { sjf_rect_destroy(&sjt_funcold9); }
;
    }

#line 82
    sjt_forStart13 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent105 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent105, &sjt_forEnd13);
#line 82 "lib/sj-lib-ui/borderLayout.sj"
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sji_borderchild borderchild2 = { 0 };
        sji_element child2 = { 0 };
        int32_t position2;
        int32_option sjt_capture23;
        sji_element sjt_cast11 = { 0 };
        int32_t sjt_functionParam131;
        sjs_array_heap_iface_element* sjt_parent106 = 0;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent106 = &_parent->children;
#line 82 "lib/sj-lib-ui/borderLayout.sj"
        sjt_functionParam131 = i;
#line 82
        sjf_array_heap_iface_element_getat_heap(sjt_parent106, sjt_functionParam131, &child2);
#line 84
        sjt_cast11 = child2;
#line 9
        sjt_cast11._vtbl->asinterface(sjt_cast11._parent, sji_borderchild_typeId, (sjs_interface*)&borderchild2);
        if (borderchild2._parent != 0) {
            borderchild2._parent->_refCount++;
        }

        if (borderchild2._parent != 0) {
            sji_borderchild sjt_parent107 = { 0 };
            int32_t sjt_value6;

#line 10 "lib/sj-lib-ui/borderLayout.sj"
            sjt_parent107 = borderchild2;
#line 85
            sjt_parent107._vtbl->getposition(sjt_parent107._parent, &sjt_value6);
#line 85
            sjt_capture23.isvalid = true;
#line 85
            sjt_capture23.value = sjt_value6;
        } else {
#line 85 "lib/sj-lib-ui/borderLayout.sj"
            sjt_capture23 = int32_empty;
        }

        if (sjt_capture23.isvalid) {
            int32_option sjt_getValue2;

            if (borderchild2._parent != 0) {
                sji_borderchild sjt_parent108 = { 0 };
                int32_t sjt_value7;

#line 10 "lib/sj-lib-ui/borderLayout.sj"
                sjt_parent108 = borderchild2;
#line 85
                sjt_parent108._vtbl->getposition(sjt_parent108._parent, &sjt_value7);
#line 85
                sjt_getValue2.isvalid = true;
#line 85
                sjt_getValue2.value = sjt_value7;
            } else {
#line 85 "lib/sj-lib-ui/borderLayout.sj"
                sjt_getValue2 = int32_empty;
            }

#line 85 "lib/sj-lib-ui/borderLayout.sj"
            position2 = sjt_getValue2.value;
        } else {
#line 85 "lib/sj-lib-ui/borderLayout.sj"
            position2 = g_borderposition_fill;
        }

        if (position2 == g_borderposition_fill) {
            sjs_rect* sjt_interfaceParam17 = 0;
            sji_element sjt_parent109 = { 0 };

#line 4 "lib/sj-lib-ui/element.sj"
            sjt_parent109 = child2;
#line 87 "lib/sj-lib-ui/borderLayout.sj"
            sjt_interfaceParam17 = &remaining;
#line 87
            sjt_parent109._vtbl->setrect(sjt_parent109._parent, sjt_interfaceParam17);
        }

#line 82
        i++;

        if (borderchild2._parent != 0) {
            borderchild2._parent->_refCount--;
            if (borderchild2._parent->_refCount <= 0) {
                borderchild2._vtbl->destroy(borderchild2._parent);
                free(borderchild2._parent);
            }
        }
        if (child2._parent != 0) {
            child2._parent->_refCount--;
            if (child2._parent->_refCount <= 0) {
                child2._vtbl->destroy(child2._parent);
                free(child2._parent);
            }
        }
    }

    if (remaining._refCount == 1) { sjf_rect_destroy(&remaining); }
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

void sjf_centerlayout(sjs_centerlayout* _this) {
}

void sjf_centerlayout_as_sji_element(sjs_centerlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_centerlayout_element_vtbl;
}

void sjf_centerlayout_asinterface(sjs_centerlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_centerlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_centerlayout_copy(sjs_centerlayout* _this, sjs_centerlayout* _from) {
    _this->children._refCount = 1;
#line 1 "lib/sj-lib-ui/centerLayout.sj"
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 1
    _this->margin._refCount = 1;
#line 1
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 1
    _this->centerx = _from->centerx;
#line 1
    _this->centery = _from->centery;
#line 1
    _this->_rect._refCount = 1;
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_centerlayout_destroy(sjs_centerlayout* _this) {
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_centerlayout_firemouseevent(sjs_centerlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam254 = 0;
    sjs_mouseevent* sjt_parent201 = 0;

#line 53 "lib/sj-lib-ui/centerLayout.sj"
    sjt_parent201 = mouseevent;
#line 54
    sjt_functionParam254 = &_parent->children;
#line 54
    sjf_mouseevent_firechildren(sjt_parent201, sjt_functionParam254, _return);
}

void sjf_centerlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 188;
}

void sjf_centerlayout_getrect(sjs_centerlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 18 "lib/sj-lib-ui/centerLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_centerlayout_getrect_heap(sjs_centerlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 18 "lib/sj-lib-ui/centerLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_centerlayout_getsize(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    sjs_size innersize = { -1 };
    sjs_size size = { -1 };
    int32_t sjt_forEnd19;
    int32_t sjt_forStart19;
    sjs_margin* sjt_functionParam243 = 0;
    sjs_margin* sjt_functionParam246 = 0;
    sjs_size* sjt_parent181 = 0;
    sjs_array_heap_iface_element* sjt_parent182 = 0;
    sjs_size* sjt_parent186 = 0;

    size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    size.w = 0;
#line 3
    size.h = 0;
#line 3
    sjf_size(&size);
#line 8 "lib/sj-lib-ui/centerLayout.sj"
    sjt_parent181 = maxsize;
#line 10
    sjt_functionParam243 = &_parent->margin;
#line 10
    sjf_size_subtractmargin(sjt_parent181, sjt_functionParam243, &innersize);
#line 11
    sjt_forStart19 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent182 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent182, &sjt_forEnd19);
#line 11 "lib/sj-lib-ui/centerLayout.sj"
    i = sjt_forStart19;
    while (i < sjt_forEnd19) {
        sji_element child = { 0 };
        sjs_size sjt_call85 = { -1 };
        sjs_size sjt_funcold15 = { -1 };
        int32_t sjt_functionParam244;
        sjs_size* sjt_functionParam245 = 0;
        sjs_size* sjt_interfaceParam42 = 0;
        sjs_array_heap_iface_element* sjt_parent183 = 0;
        sjs_size* sjt_parent184 = 0;
        sji_element sjt_parent185 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent183 = &_parent->children;
#line 11 "lib/sj-lib-ui/centerLayout.sj"
        sjt_functionParam244 = i;
#line 11
        sjf_array_heap_iface_element_getat_heap(sjt_parent183, sjt_functionParam244, &child);
#line 12 "lib/sj-lib-ui/size.sj"
        sjt_parent184 = &size;
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent185 = child;
#line 13 "lib/sj-lib-ui/centerLayout.sj"
        sjt_interfaceParam42 = &innersize;
#line 13
        sjt_parent185._vtbl->getsize(sjt_parent185._parent, sjt_interfaceParam42, &sjt_call85);
#line 13
        sjt_functionParam245 = &sjt_call85;
#line 13
        sjf_size_max(sjt_parent184, sjt_functionParam245, &sjt_funcold15);
#line 13
        if (size._refCount == 1) { sjf_size_destroy(&size); }
;
#line 12 "lib/sj-lib-ui/size.sj"
        sjf_size_copy(&size, &sjt_funcold15);
#line 11 "lib/sj-lib-ui/centerLayout.sj"
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (sjt_call85._refCount == 1) { sjf_size_destroy(&sjt_call85); }
;
        if (sjt_funcold15._refCount == 1) { sjf_size_destroy(&sjt_funcold15); }
;
    }

#line 19 "lib/sj-lib-ui/size.sj"
    sjt_parent186 = &size;
#line 15 "lib/sj-lib-ui/centerLayout.sj"
    sjt_functionParam246 = &_parent->margin;
#line 15
    sjf_size_addmargin(sjt_parent186, sjt_functionParam246, _return);

    if (innersize._refCount == 1) { sjf_size_destroy(&innersize); }
;
    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
}

void sjf_centerlayout_getsize_heap(sjs_centerlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    sjs_size innersize = { -1 };
    sjs_size size = { -1 };
    int32_t sjt_forEnd20;
    int32_t sjt_forStart20;
    sjs_margin* sjt_functionParam247 = 0;
    sjs_margin* sjt_functionParam250 = 0;
    sjs_size* sjt_parent187 = 0;
    sjs_array_heap_iface_element* sjt_parent188 = 0;
    sjs_size* sjt_parent192 = 0;

    size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    size.w = 0;
#line 3
    size.h = 0;
#line 3
    sjf_size(&size);
#line 8 "lib/sj-lib-ui/centerLayout.sj"
    sjt_parent187 = maxsize;
#line 10
    sjt_functionParam247 = &_parent->margin;
#line 10
    sjf_size_subtractmargin(sjt_parent187, sjt_functionParam247, &innersize);
#line 11
    sjt_forStart20 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent188 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent188, &sjt_forEnd20);
#line 11 "lib/sj-lib-ui/centerLayout.sj"
    i = sjt_forStart20;
    while (i < sjt_forEnd20) {
        sji_element child = { 0 };
        sjs_size sjt_call86 = { -1 };
        sjs_size sjt_funcold16 = { -1 };
        int32_t sjt_functionParam248;
        sjs_size* sjt_functionParam249 = 0;
        sjs_size* sjt_interfaceParam43 = 0;
        sjs_array_heap_iface_element* sjt_parent189 = 0;
        sjs_size* sjt_parent190 = 0;
        sji_element sjt_parent191 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent189 = &_parent->children;
#line 11 "lib/sj-lib-ui/centerLayout.sj"
        sjt_functionParam248 = i;
#line 11
        sjf_array_heap_iface_element_getat_heap(sjt_parent189, sjt_functionParam248, &child);
#line 12 "lib/sj-lib-ui/size.sj"
        sjt_parent190 = &size;
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent191 = child;
#line 13 "lib/sj-lib-ui/centerLayout.sj"
        sjt_interfaceParam43 = &innersize;
#line 13
        sjt_parent191._vtbl->getsize(sjt_parent191._parent, sjt_interfaceParam43, &sjt_call86);
#line 13
        sjt_functionParam249 = &sjt_call86;
#line 13
        sjf_size_max(sjt_parent190, sjt_functionParam249, &sjt_funcold16);
#line 13
        if (size._refCount == 1) { sjf_size_destroy(&size); }
;
#line 12 "lib/sj-lib-ui/size.sj"
        sjf_size_copy(&size, &sjt_funcold16);
#line 11 "lib/sj-lib-ui/centerLayout.sj"
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (sjt_call86._refCount == 1) { sjf_size_destroy(&sjt_call86); }
;
        if (sjt_funcold16._refCount == 1) { sjf_size_destroy(&sjt_funcold16); }
;
    }

#line 19 "lib/sj-lib-ui/size.sj"
    sjt_parent192 = &size;
#line 15 "lib/sj-lib-ui/centerLayout.sj"
    sjt_functionParam250 = &_parent->margin;
#line 15
    sjf_size_addmargin_heap(sjt_parent192, sjt_functionParam250, _return);

    if (innersize._refCount == 1) { sjf_size_destroy(&innersize); }
;
    if (size._refCount == 1) { sjf_size_destroy(&size); }
;
}

void sjf_centerlayout_heap(sjs_centerlayout* _this) {
}

void sjf_centerlayout_render(sjs_centerlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd22;
    int32_t sjt_forStart22;
    sjs_array_heap_iface_element* sjt_parent198 = 0;

#line 47 "lib/sj-lib-ui/centerLayout.sj"
    sjt_forStart22 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent198 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent198, &sjt_forEnd22);
#line 47 "lib/sj-lib-ui/centerLayout.sj"
    i = sjt_forStart22;
    while (i < sjt_forEnd22) {
        sji_element child = { 0 };
        int32_t sjt_functionParam253;
        sjs_scene2d* sjt_interfaceParam46 = 0;
        sjs_array_heap_iface_element* sjt_parent199 = 0;
        sji_element sjt_parent200 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent199 = &_parent->children;
#line 47 "lib/sj-lib-ui/centerLayout.sj"
        sjt_functionParam253 = i;
#line 47
        sjf_array_heap_iface_element_getat_heap(sjt_parent199, sjt_functionParam253, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent200 = child;
#line 46 "lib/sj-lib-ui/centerLayout.sj"
        sjt_interfaceParam46 = scene;
#line 49
        sjt_parent200._vtbl->render(sjt_parent200._parent, sjt_interfaceParam46);
#line 47
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

void sjf_centerlayout_setrect(sjs_centerlayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect innerrect = { -1 };
    int32_t sjt_forEnd21;
    int32_t sjt_forStart21;
    sjs_margin* sjt_functionParam251 = 0;
    sjs_rect* sjt_parent193 = 0;
    sjs_array_heap_iface_element* sjt_parent194 = 0;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 20 "lib/sj-lib-ui/centerLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 7 "lib/sj-lib-ui/rect.sj"
    sjt_parent193 = &_parent->_rect;
#line 22 "lib/sj-lib-ui/centerLayout.sj"
    sjt_functionParam251 = &_parent->margin;
#line 22
    sjf_rect_subtractmargin(sjt_parent193, sjt_functionParam251, &innerrect);
#line 23
    sjt_forStart21 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent194 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent194, &sjt_forEnd21);
#line 23 "lib/sj-lib-ui/centerLayout.sj"
    i = sjt_forStart21;
    while (i < sjt_forEnd21) {
        sji_element child = { 0 };
        sjs_size childsize = { -1 };
        int32_t h;
        sjs_size sjt_call87 = { -1 };
        sjs_rect sjt_call88 = { -1 };
        int32_t sjt_functionParam252;
        sjs_size* sjt_interfaceParam44 = 0;
        sjs_rect* sjt_interfaceParam45 = 0;
        sjs_array_heap_iface_element* sjt_parent195 = 0;
        sji_element sjt_parent196 = { 0 };
        sji_element sjt_parent197 = { 0 };
        int32_t w;
        int32_t x;
        int32_t y;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent195 = &_parent->children;
#line 23 "lib/sj-lib-ui/centerLayout.sj"
        sjt_functionParam252 = i;
#line 23
        sjf_array_heap_iface_element_getat_heap(sjt_parent195, sjt_functionParam252, &child);
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent196 = child;
#line 2
        sjt_call87._refCount = 1;
#line 25 "lib/sj-lib-ui/centerLayout.sj"
        sjt_call87.w = (&innerrect)->w;
#line 25
        sjt_call87.h = (&innerrect)->h;
#line 25
        sjf_size(&sjt_call87);
#line 25
        sjt_interfaceParam44 = &sjt_call87;
#line 25
        sjt_parent196._vtbl->getsize(sjt_parent196._parent, sjt_interfaceParam44, &childsize);
#line 27
        x = (&innerrect)->x;
#line 28
        w = (&innerrect)->w;
        if (_parent->centerx.isvalid) {
            float ifValue13;
            float sjt_cast20;
            int32_t sjt_cast21;
            float_option sjt_getValue3;

#line 29 "lib/sj-lib-ui/centerLayout.sj"
            sjt_getValue3 = _parent->centerx;
#line 29
            ifValue13 = sjt_getValue3.value;
#line 30
            sjt_cast21 = (&innerrect)->w - (&childsize)->w;
#line 30
            sjt_cast20 = (float)sjt_cast21 * ifValue13;
#line 30
            x = (&innerrect)->x + (int32_t)sjt_cast20;
#line 31
            w = (&childsize)->w;
        }

#line 34
        y = (&innerrect)->y;
#line 35
        h = (&innerrect)->h;
        if (_parent->centery.isvalid) {
            float ifValue14;
            float sjt_cast22;
            int32_t sjt_cast23;
            float_option sjt_getValue4;

#line 36 "lib/sj-lib-ui/centerLayout.sj"
            sjt_getValue4 = _parent->centery;
#line 36
            ifValue14 = sjt_getValue4.value;
#line 37
            sjt_cast23 = (&innerrect)->h - (&childsize)->h;
#line 37
            sjt_cast22 = (float)sjt_cast23 * ifValue14;
#line 37
            y = (&innerrect)->y + (int32_t)sjt_cast22;
#line 38
            h = (&childsize)->h;
        }

#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent197 = child;
#line 4
        sjt_call88._refCount = 1;
#line 41 "lib/sj-lib-ui/centerLayout.sj"
        sjt_call88.x = x;
#line 41
        sjt_call88.y = y;
#line 41
        sjt_call88.w = w;
#line 41
        sjt_call88.h = h;
#line 41
        sjf_rect(&sjt_call88);
#line 41
        sjt_interfaceParam45 = &sjt_call88;
#line 41
        sjt_parent197._vtbl->setrect(sjt_parent197._parent, sjt_interfaceParam45);
#line 23
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
        if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
        if (sjt_call87._refCount == 1) { sjf_size_destroy(&sjt_call87); }
;
        if (sjt_call88._refCount == 1) { sjf_rect_destroy(&sjt_call88); }
;
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
}

void sjf_color(sjs_color* _this) {
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

void sjf_f32_random(float* _return) {
    float x;

#line 52 "lib/sj-lib-common/f32.sj"
    x = 0.0f;
#line 54
    x = (float)rand() / (float)RAND_MAX;
#line 51
    (*_return) = x;
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
    sjs_array_heap_iface_element* sjt_functionParam62 = 0;
    sjs_mouseevent* sjt_parent64 = 0;

#line 55 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent64 = mouseevent;
#line 56
    sjt_functionParam62 = &_parent->children;
#line 56
    sjf_mouseevent_firechildren(sjt_parent64, sjt_functionParam62, _return);
}

void sjf_filllayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 115;
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
    sjs_margin* sjt_functionParam49 = 0;
    sjs_margin* sjt_functionParam52 = 0;
    sjs_size* sjt_parent43 = 0;
    sjs_array_heap_iface_element* sjt_parent44 = 0;
    sjs_size* sjt_parent48 = 0;

    size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    size.w = 0;
#line 3
    size.h = 0;
#line 3
    sjf_size(&size);
#line 7 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent43 = maxsize;
#line 9
    sjt_functionParam49 = &_parent->margin;
#line 9
    sjf_size_subtractmargin(sjt_parent43, sjt_functionParam49, &innersize);
#line 10
    sjt_forStart8 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent44 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent44, &sjt_forEnd8);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart8;
    while (i < sjt_forEnd8) {
        sji_element child = { 0 };
        sjs_size sjt_call7 = { -1 };
        sjs_size sjt_funcold5 = { -1 };
        int32_t sjt_functionParam50;
        sjs_size* sjt_functionParam51 = 0;
        sjs_size* sjt_interfaceParam4 = 0;
        sjs_array_heap_iface_element* sjt_parent45 = 0;
        sjs_size* sjt_parent46 = 0;
        sji_element sjt_parent47 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent45 = &_parent->children;
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam50 = i;
#line 10
        sjf_array_heap_iface_element_getat_heap(sjt_parent45, sjt_functionParam50, &child);
#line 12 "lib/sj-lib-ui/size.sj"
        sjt_parent46 = &size;
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent47 = child;
#line 12 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam4 = &innersize;
#line 12
        sjt_parent47._vtbl->getsize(sjt_parent47._parent, sjt_interfaceParam4, &sjt_call7);
#line 12
        sjt_functionParam51 = &sjt_call7;
#line 12
        sjf_size_max(sjt_parent46, sjt_functionParam51, &sjt_funcold5);
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
        if (sjt_call7._refCount == 1) { sjf_size_destroy(&sjt_call7); }
;
        if (sjt_funcold5._refCount == 1) { sjf_size_destroy(&sjt_funcold5); }
;
    }

#line 19 "lib/sj-lib-ui/size.sj"
    sjt_parent48 = &size;
#line 14 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam52 = &_parent->margin;
#line 14
    sjf_size_addmargin(sjt_parent48, sjt_functionParam52, _return);

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
    sjs_margin* sjt_functionParam53 = 0;
    sjs_margin* sjt_functionParam56 = 0;
    sjs_size* sjt_parent49 = 0;
    sjs_array_heap_iface_element* sjt_parent50 = 0;
    sjs_size* sjt_parent54 = 0;

    size._refCount = 1;
#line 2 "lib/sj-lib-ui/size.sj"
    size.w = 0;
#line 3
    size.h = 0;
#line 3
    sjf_size(&size);
#line 7 "lib/sj-lib-ui/fillLayout.sj"
    sjt_parent49 = maxsize;
#line 9
    sjt_functionParam53 = &_parent->margin;
#line 9
    sjf_size_subtractmargin(sjt_parent49, sjt_functionParam53, &innersize);
#line 10
    sjt_forStart9 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent50 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent50, &sjt_forEnd9);
#line 10 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sji_element child = { 0 };
        sjs_size sjt_call8 = { -1 };
        sjs_size sjt_funcold6 = { -1 };
        int32_t sjt_functionParam54;
        sjs_size* sjt_functionParam55 = 0;
        sjs_size* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent51 = 0;
        sjs_size* sjt_parent52 = 0;
        sji_element sjt_parent53 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent51 = &_parent->children;
#line 10 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam54 = i;
#line 10
        sjf_array_heap_iface_element_getat_heap(sjt_parent51, sjt_functionParam54, &child);
#line 12 "lib/sj-lib-ui/size.sj"
        sjt_parent52 = &size;
#line 2 "lib/sj-lib-ui/element.sj"
        sjt_parent53 = child;
#line 12 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam5 = &innersize;
#line 12
        sjt_parent53._vtbl->getsize(sjt_parent53._parent, sjt_interfaceParam5, &sjt_call8);
#line 12
        sjt_functionParam55 = &sjt_call8;
#line 12
        sjf_size_max(sjt_parent52, sjt_functionParam55, &sjt_funcold6);
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
        if (sjt_call8._refCount == 1) { sjf_size_destroy(&sjt_call8); }
;
        if (sjt_funcold6._refCount == 1) { sjf_size_destroy(&sjt_funcold6); }
;
    }

#line 19 "lib/sj-lib-ui/size.sj"
    sjt_parent54 = &size;
#line 14 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam56 = &_parent->margin;
#line 14
    sjf_size_addmargin_heap(sjt_parent54, sjt_functionParam56, _return);

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
        sji_effect sjt_parent60 = { 0 };

#line 41 "lib/sj-lib-ui/fillLayout.sj"
        ifValue5 = _parent->effect;
        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount++;
        }

#line 4 "lib/sj-lib-ui/effect.sj"
        sjt_parent60 = ifValue5;
#line 40 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam9 = scene;
#line 42
        sjt_interfaceParam10._parent = (sjs_object*)_parent;
#line 42
        sjt_interfaceParam10._cb = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_renderinner;
#line 42
        sjt_parent60._vtbl->render(sjt_parent60._parent, sjt_interfaceParam9, sjt_interfaceParam10);

        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount--;
            if (ifValue5._parent->_refCount <= 0) {
                ifValue5._vtbl->destroy(ifValue5._parent);
                free(ifValue5._parent);
            }
        }
    } else {
        sjs_scene2d* sjt_functionParam61 = 0;

#line 40 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam61 = scene;
#line 40
        sjf_filllayout_renderinner(_parent, sjt_functionParam61);
    }
}

void sjf_filllayout_renderinner(sjs_filllayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd11;
    int32_t sjt_forStart11;
    sjs_array_heap_iface_element* sjt_parent61 = 0;

#line 49 "lib/sj-lib-ui/fillLayout.sj"
    sjt_forStart11 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent61 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent61, &sjt_forEnd11);
#line 49 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        sji_element child = { 0 };
        int32_t sjt_functionParam60;
        sjs_scene2d* sjt_interfaceParam11 = 0;
        sjs_array_heap_iface_element* sjt_parent62 = 0;
        sji_element sjt_parent63 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent62 = &_parent->children;
#line 49 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam60 = i;
#line 49
        sjf_array_heap_iface_element_getat_heap(sjt_parent62, sjt_functionParam60, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent63 = child;
#line 48 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam11 = scene;
#line 51
        sjt_parent63._vtbl->render(sjt_parent63._parent, sjt_interfaceParam11);
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
    sjs_margin* sjt_functionParam57 = 0;
    sjs_rect* sjt_parent55 = 0;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 19 "lib/sj-lib-ui/fillLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 7 "lib/sj-lib-ui/rect.sj"
    sjt_parent55 = &_parent->_rect;
#line 21 "lib/sj-lib-ui/fillLayout.sj"
    sjt_functionParam57 = &_parent->margin;
#line 21
    sjf_rect_subtractmargin(sjt_parent55, sjt_functionParam57, &innerrect);
    if ((_parent->effect._parent != 0)) {
        sji_effect ifValue3 = { 0 };
        sjs_rect* sjt_interfaceParam6 = 0;
        cb_rect_void sjt_interfaceParam7;
        sji_effect sjt_parent56 = { 0 };

#line 23 "lib/sj-lib-ui/fillLayout.sj"
        ifValue3 = _parent->effect;
        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount++;
        }

#line 3 "lib/sj-lib-ui/effect.sj"
        sjt_parent56 = ifValue3;
#line 24 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam6 = &innerrect;
#line 24
        sjt_interfaceParam7._parent = (sjs_object*)_parent;
#line 24
        sjt_interfaceParam7._cb = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrectinner;
#line 24
        sjt_parent56._vtbl->setrect(sjt_parent56._parent, sjt_interfaceParam6, sjt_interfaceParam7);

        if (ifValue3._parent != 0) {
            ifValue3._parent->_refCount--;
            if (ifValue3._parent->_refCount <= 0) {
                ifValue3._vtbl->destroy(ifValue3._parent);
                free(ifValue3._parent);
            }
        }
    } else {
        sjs_rect* sjt_functionParam59 = 0;

#line 26 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam59 = &innerrect;
#line 26
        sjf_filllayout_setrectinner(_parent, sjt_functionParam59);
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
}

void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect) {
    int32_t i;
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;
    sjs_array_heap_iface_element* sjt_parent57 = 0;

#line 33 "lib/sj-lib-ui/fillLayout.sj"
    sjt_forStart10 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent57 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent57, &sjt_forEnd10);
#line 33 "lib/sj-lib-ui/fillLayout.sj"
    i = sjt_forStart10;
    while (i < sjt_forEnd10) {
        sji_element child = { 0 };
        int32_t sjt_functionParam58;
        sjs_rect* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent58 = 0;
        sji_element sjt_parent59 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent58 = &_parent->children;
#line 33 "lib/sj-lib-ui/fillLayout.sj"
        sjt_functionParam58 = i;
#line 33
        sjf_array_heap_iface_element_getat_heap(sjt_parent58, sjt_functionParam58, &child);
#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent59 = child;
#line 32 "lib/sj-lib-ui/fillLayout.sj"
        sjt_interfaceParam8 = innerrect;
#line 35
        sjt_parent59._vtbl->setrect(sjt_parent59._parent, sjt_interfaceParam8);
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

void sjf_flowlayout(sjs_flowlayout* _this) {
}

void sjf_flowlayout_as_sji_element(sjs_flowlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_flowlayout_element_vtbl;
}

void sjf_flowlayout_asinterface(sjs_flowlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_flowlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_flowlayout_copy(sjs_flowlayout* _this, sjs_flowlayout* _from) {
    _this->children._refCount = 1;
#line 8 "lib/sj-lib-ui/flowLayout.sj"
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 8
    _this->margin._refCount = 1;
#line 8
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 8
    _this->orientation = _from->orientation;
#line 8
    _this->_rect._refCount = 1;
#line 8
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_flowlayout_destroy(sjs_flowlayout* _this) {
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_flowlayout_firemouseevent(sjs_flowlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam180 = 0;
    sjs_mouseevent* sjt_parent159 = 0;

#line 90 "lib/sj-lib-ui/flowLayout.sj"
    sjt_parent159 = mouseevent;
#line 91
    sjt_functionParam180 = &_parent->children;
#line 91
    sjf_mouseevent_firechildren(sjt_parent159, sjt_functionParam180, _return);
}

void sjf_flowlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 183;
}

void sjf_flowlayout_getrect(sjs_flowlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 18 "lib/sj-lib-ui/flowLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_flowlayout_getrect_heap(sjs_flowlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 18 "lib/sj-lib-ui/flowLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_flowlayout_getsize(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 15 "lib/sj-lib-ui/flowLayout.sj"
    _return->w = maxsize->w;
#line 15
    _return->h = maxsize->h;
#line 15
    sjf_size(_return);
}

void sjf_flowlayout_getsize_heap(sjs_flowlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 15 "lib/sj-lib-ui/flowLayout.sj"
    (*_return)->w = maxsize->w;
#line 15
    (*_return)->h = maxsize->h;
#line 15
    sjf_size_heap((*_return));
}

void sjf_flowlayout_heap(sjs_flowlayout* _this) {
}

void sjf_flowlayout_render(sjs_flowlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd18;
    int32_t sjt_forStart18;
    sjs_array_heap_iface_element* sjt_parent156 = 0;

#line 84 "lib/sj-lib-ui/flowLayout.sj"
    sjt_forStart18 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent156 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent156, &sjt_forEnd18);
#line 84 "lib/sj-lib-ui/flowLayout.sj"
    i = sjt_forStart18;
    while (i < sjt_forEnd18) {
        sji_element child = { 0 };
        int32_t sjt_functionParam179;
        sjs_scene2d* sjt_interfaceParam41 = 0;
        sjs_array_heap_iface_element* sjt_parent157 = 0;
        sji_element sjt_parent158 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent157 = &_parent->children;
#line 84 "lib/sj-lib-ui/flowLayout.sj"
        sjt_functionParam179 = i;
#line 84
        sjf_array_heap_iface_element_getat_heap(sjt_parent157, sjt_functionParam179, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent158 = child;
#line 83 "lib/sj-lib-ui/flowLayout.sj"
        sjt_interfaceParam41 = scene;
#line 86
        sjt_parent158._vtbl->render(sjt_parent158._parent, sjt_interfaceParam41);
#line 84
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

void sjf_flowlayout_setrect(sjs_flowlayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect innerrect = { -1 };
    int32_t sjt_forEnd17;
    int32_t sjt_forStart17;
    sjs_margin* sjt_functionParam169 = 0;
    sjs_rect* sjt_parent145 = 0;
    sjs_array_heap_iface_element* sjt_parent146 = 0;
    int32_t val1;
    int32_t val2;
    int32_t valmax;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 20 "lib/sj-lib-ui/flowLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 20
    sjt_parent145 = rect_;
#line 22
    sjt_functionParam169 = &_parent->margin;
#line 22
    sjf_rect_subtractmargin(sjt_parent145, sjt_functionParam169, &innerrect);
#line 24
    val1 = 0;
#line 25
    val2 = 0;
#line 26
    valmax = 0;
#line 27
    sjt_forStart17 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent146 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent146, &sjt_forEnd17);
#line 27 "lib/sj-lib-ui/flowLayout.sj"
    i = sjt_forStart17;
    while (i < sjt_forEnd17) {
        sji_element child = { 0 };
        int32_t sjt_functionParam170;
        sjs_array_heap_iface_element* sjt_parent147 = 0;
        int32_t underscore7;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent147 = &_parent->children;
#line 27 "lib/sj-lib-ui/flowLayout.sj"
        sjt_functionParam170 = i;
#line 27
        sjf_array_heap_iface_element_getat_heap(sjt_parent147, sjt_functionParam170, &child);
#line 29
        underscore7 = _parent->orientation;
        if (underscore7 == g_flowlayoutorientation_topbottom) {
            sjs_size childsize = { -1 };
            sjs_size sjt_call56 = { -1 };
            sjs_rect sjt_call57 = { -1 };
            int32_t sjt_funcold11;
            int32_t sjt_functionParam171;
            int32_t sjt_functionParam172;
            sjs_size* sjt_interfaceParam33 = 0;
            sjs_rect* sjt_interfaceParam34 = 0;
            sji_element sjt_parent148 = { 0 };
            sji_element sjt_parent149 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
            sjt_parent148 = child;
#line 2
            sjt_call56._refCount = 1;
#line 31 "lib/sj-lib-ui/flowLayout.sj"
            sjt_call56.w = (&innerrect)->w;
#line 31
            sjt_call56.h = (&innerrect)->h;
#line 31
            sjf_size(&sjt_call56);
#line 31
            sjt_interfaceParam33 = &sjt_call56;
#line 31
            sjt_parent148._vtbl->getsize(sjt_parent148._parent, sjt_interfaceParam33, &childsize);
#line 32
            sjt_functionParam171 = valmax;
#line 32
            sjt_functionParam172 = (&childsize)->w;
#line 32
            sjf_i32_max(sjt_functionParam171, sjt_functionParam172, &sjt_funcold11);
#line 6 "lib/sj-lib-common/i32.sj"
            valmax = sjt_funcold11;
            if ((val1 + (&childsize)->h) > (&innerrect)->h) {
#line 34 "lib/sj-lib-ui/flowLayout.sj"
                val1 = 0;
#line 35
                val2 = val2 + valmax;
#line 36
                valmax = 0;
            }

#line 4 "lib/sj-lib-ui/element.sj"
            sjt_parent149 = child;
#line 4
            sjt_call57._refCount = 1;
#line 39 "lib/sj-lib-ui/flowLayout.sj"
            sjt_call57.x = (&innerrect)->x + val2;
#line 39
            sjt_call57.y = (&innerrect)->y + val1;
#line 39
            sjt_call57.w = (&childsize)->w;
#line 39
            sjt_call57.h = (&childsize)->h;
#line 39
            sjf_rect(&sjt_call57);
#line 39
            sjt_interfaceParam34 = &sjt_call57;
#line 39
            sjt_parent149._vtbl->setrect(sjt_parent149._parent, sjt_interfaceParam34);
#line 40
            val1 = val1 + (&childsize)->h;

            if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
            if (sjt_call56._refCount == 1) { sjf_size_destroy(&sjt_call56); }
;
            if (sjt_call57._refCount == 1) { sjf_rect_destroy(&sjt_call57); }
;
        } else {
            if (underscore7 == g_flowlayoutorientation_bottomtop) {
                sjs_size childsize = { -1 };
                sjs_size sjt_call58 = { -1 };
                sjs_rect sjt_call59 = { -1 };
                int32_t sjt_funcold12;
                int32_t sjt_functionParam173;
                int32_t sjt_functionParam174;
                sjs_size* sjt_interfaceParam35 = 0;
                sjs_rect* sjt_interfaceParam36 = 0;
                sji_element sjt_parent150 = { 0 };
                sji_element sjt_parent151 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
                sjt_parent150 = child;
#line 2
                sjt_call58._refCount = 1;
#line 43 "lib/sj-lib-ui/flowLayout.sj"
                sjt_call58.w = (&innerrect)->w;
#line 43
                sjt_call58.h = (&innerrect)->h;
#line 43
                sjf_size(&sjt_call58);
#line 43
                sjt_interfaceParam35 = &sjt_call58;
#line 43
                sjt_parent150._vtbl->getsize(sjt_parent150._parent, sjt_interfaceParam35, &childsize);
#line 44
                sjt_functionParam173 = valmax;
#line 44
                sjt_functionParam174 = (&childsize)->w;
#line 44
                sjf_i32_max(sjt_functionParam173, sjt_functionParam174, &sjt_funcold12);
#line 6 "lib/sj-lib-common/i32.sj"
                valmax = sjt_funcold12;
                if ((val1 + (&childsize)->h) >= (&innerrect)->h) {
#line 46 "lib/sj-lib-ui/flowLayout.sj"
                    val1 = 0;
#line 47
                    val2 = val2 + valmax;
#line 48
                    valmax = 0;
                }

#line 4 "lib/sj-lib-ui/element.sj"
                sjt_parent151 = child;
#line 4
                sjt_call59._refCount = 1;
#line 51 "lib/sj-lib-ui/flowLayout.sj"
                sjt_call59.x = (&innerrect)->x + val2;
#line 51
                sjt_call59.y = (((&innerrect)->y + (&innerrect)->h) - val1) - (&childsize)->h;
#line 51
                sjt_call59.w = (&childsize)->w;
#line 51
                sjt_call59.h = (&childsize)->h;
#line 51
                sjf_rect(&sjt_call59);
#line 51
                sjt_interfaceParam36 = &sjt_call59;
#line 51
                sjt_parent151._vtbl->setrect(sjt_parent151._parent, sjt_interfaceParam36);
#line 52
                val1 = val1 + (&childsize)->h;

                if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
                if (sjt_call58._refCount == 1) { sjf_size_destroy(&sjt_call58); }
;
                if (sjt_call59._refCount == 1) { sjf_rect_destroy(&sjt_call59); }
;
            } else {
                if (underscore7 == g_flowlayoutorientation_leftright) {
                    sjs_size childsize = { -1 };
                    sjs_size sjt_call60 = { -1 };
                    sjs_rect sjt_call61 = { -1 };
                    int32_t sjt_funcold13;
                    int32_t sjt_functionParam175;
                    int32_t sjt_functionParam176;
                    sjs_size* sjt_interfaceParam37 = 0;
                    sjs_rect* sjt_interfaceParam38 = 0;
                    sji_element sjt_parent152 = { 0 };
                    sji_element sjt_parent153 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
                    sjt_parent152 = child;
#line 2
                    sjt_call60._refCount = 1;
#line 55 "lib/sj-lib-ui/flowLayout.sj"
                    sjt_call60.w = (&innerrect)->w;
#line 55
                    sjt_call60.h = (&innerrect)->h;
#line 55
                    sjf_size(&sjt_call60);
#line 55
                    sjt_interfaceParam37 = &sjt_call60;
#line 55
                    sjt_parent152._vtbl->getsize(sjt_parent152._parent, sjt_interfaceParam37, &childsize);
#line 56
                    sjt_functionParam175 = valmax;
#line 56
                    sjt_functionParam176 = (&childsize)->h;
#line 56
                    sjf_i32_max(sjt_functionParam175, sjt_functionParam176, &sjt_funcold13);
#line 6 "lib/sj-lib-common/i32.sj"
                    valmax = sjt_funcold13;
                    if ((val1 + (&childsize)->w) > (&innerrect)->w) {
#line 58 "lib/sj-lib-ui/flowLayout.sj"
                        val1 = 0;
#line 59
                        val2 = val2 + valmax;
#line 60
                        valmax = 0;
                    }

#line 4 "lib/sj-lib-ui/element.sj"
                    sjt_parent153 = child;
#line 4
                    sjt_call61._refCount = 1;
#line 63 "lib/sj-lib-ui/flowLayout.sj"
                    sjt_call61.x = (&innerrect)->x + val1;
#line 63
                    sjt_call61.y = (&innerrect)->y + val2;
#line 63
                    sjt_call61.w = (&childsize)->w;
#line 63
                    sjt_call61.h = (&childsize)->h;
#line 63
                    sjf_rect(&sjt_call61);
#line 63
                    sjt_interfaceParam38 = &sjt_call61;
#line 63
                    sjt_parent153._vtbl->setrect(sjt_parent153._parent, sjt_interfaceParam38);
#line 64
                    val1 = val1 + (&childsize)->w;

                    if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
                    if (sjt_call60._refCount == 1) { sjf_size_destroy(&sjt_call60); }
;
                    if (sjt_call61._refCount == 1) { sjf_rect_destroy(&sjt_call61); }
;
                } else {
                    if (underscore7 == g_flowlayoutorientation_rightleft) {
                        sjs_size childsize = { -1 };
                        sjs_size sjt_call62 = { -1 };
                        sjs_rect sjt_call63 = { -1 };
                        int32_t sjt_funcold14;
                        int32_t sjt_functionParam177;
                        int32_t sjt_functionParam178;
                        sjs_size* sjt_interfaceParam39 = 0;
                        sjs_rect* sjt_interfaceParam40 = 0;
                        sji_element sjt_parent154 = { 0 };
                        sji_element sjt_parent155 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
                        sjt_parent154 = child;
#line 2
                        sjt_call62._refCount = 1;
#line 67 "lib/sj-lib-ui/flowLayout.sj"
                        sjt_call62.w = (&innerrect)->w;
#line 67
                        sjt_call62.h = (&innerrect)->h;
#line 67
                        sjf_size(&sjt_call62);
#line 67
                        sjt_interfaceParam39 = &sjt_call62;
#line 67
                        sjt_parent154._vtbl->getsize(sjt_parent154._parent, sjt_interfaceParam39, &childsize);
#line 68
                        sjt_functionParam177 = valmax;
#line 68
                        sjt_functionParam178 = (&childsize)->h;
#line 68
                        sjf_i32_max(sjt_functionParam177, sjt_functionParam178, &sjt_funcold14);
#line 6 "lib/sj-lib-common/i32.sj"
                        valmax = sjt_funcold14;
                        if ((val1 + (&childsize)->w) > (&innerrect)->w) {
#line 70 "lib/sj-lib-ui/flowLayout.sj"
                            val1 = 0;
#line 71
                            val2 = val2 + valmax;
#line 72
                            valmax = 0;
                        }

#line 4 "lib/sj-lib-ui/element.sj"
                        sjt_parent155 = child;
#line 4
                        sjt_call63._refCount = 1;
#line 75 "lib/sj-lib-ui/flowLayout.sj"
                        sjt_call63.x = (((&innerrect)->x + (&innerrect)->w) - val1) - (&childsize)->w;
#line 75
                        sjt_call63.y = (&innerrect)->y + val2;
#line 75
                        sjt_call63.w = (&childsize)->w;
#line 75
                        sjt_call63.h = (&childsize)->h;
#line 75
                        sjf_rect(&sjt_call63);
#line 75
                        sjt_interfaceParam40 = &sjt_call63;
#line 75
                        sjt_parent155._vtbl->setrect(sjt_parent155._parent, sjt_interfaceParam40);
#line 76
                        val1 = val1 + (&childsize)->w;

                        if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
                        if (sjt_call62._refCount == 1) { sjf_size_destroy(&sjt_call62); }
;
                        if (sjt_call63._refCount == 1) { sjf_rect_destroy(&sjt_call63); }
;
                    }
                }
            }
        }

#line 27
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
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
    sjs_fontkey* sjt_functionParam104 = 0;
    sjs_hash_fontkey_weak_font* sjt_parent84 = 0;
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
    sjt_parent84 = &g_fonthash;
#line 7 "lib/sj-lib-ui/font.sj"
    sjt_functionParam104 = &k;
#line 7
    sjf_hash_fontkey_weak_font_getat(sjt_parent84, sjt_functionParam104, &w);
#line 8
    h = w;
    if (h != 0) {
        h->_refCount++;
    }

    if ((h != 0)) {
        sjs_font* ifValue9 = 0;

#line 9 "lib/sj-lib-ui/font.sj"
        ifValue9 = h;
        if (ifValue9 != 0) {
            ifValue9->_refCount++;
        }

#line 3
        (*_return) = ifValue9;
#line 3
        (*_return)->_refCount++;

        ifValue9->_refCount--;
        if (ifValue9->_refCount <= 0) {
            weakptr_release(ifValue9);
            sjf_font_destroy(ifValue9);
            free(ifValue9);
        }
    } else {
        sjs_font* result = 0;
        sjs_fontkey* sjt_functionParam105 = 0;
        sjs_font* sjt_functionParam106 = 0;
        sjs_hash_fontkey_weak_font* sjt_parent85 = 0;

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
        sjt_parent85 = &g_fonthash;
#line 15 "lib/sj-lib-ui/font.sj"
        sjt_functionParam105 = &k;
#line 15
        sjt_functionParam106 = result;
#line 15
        delete_cb weakptrcb21 = { &sjt_functionParam106, weakptr_clear };
#line 15
        if (sjt_functionParam106 != 0) { weakptr_cb_add(sjt_functionParam106, weakptrcb21); }
#line 15
        sjf_hash_fontkey_weak_font_setat(sjt_parent85, sjt_functionParam105, sjt_functionParam106);
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
        delete_cb weakptrcb22 = { &sjt_functionParam106, weakptr_clear };
        if (sjt_functionParam106 != 0) { weakptr_cb_remove(sjt_functionParam106, weakptrcb22); }
    }

    if (h != 0) {
        h->_refCount--;
        if (h->_refCount <= 0) {
            weakptr_release(h);
            sjf_font_destroy(h);
            free(h);
        }
    }
    delete_cb weakptrcb23 = { &w, weakptr_clear };
    if (w != 0) { weakptr_cb_remove(w, weakptrcb23); }
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

void sjf_glblendfunc(int32_t sfactor, int32_t dfactor) {
#line 285 "lib/sj-lib-ui/gl.sj"
    glBlendFunc(sfactor, dfactor);
}

void sjf_glclearcolor(sjs_color* color) {
#line 279 "lib/sj-lib-ui/gl.sj"
    glClearColor(color->r, color->g, color->b, color->a);
}

void sjf_glenable(int32_t feature) {
#line 113 "lib/sj-lib-ui/gl.sj"
    glEnable(feature);
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
#line 179 "lib/sj-lib-ui/gl.sj"
    int result = glGetUniformLocation(shader->id, string_char(name));
#line 180
    #line 178 "lib/sj-lib-ui/gl.sj"
(*_return) = result;
return;;
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect newrect = { -1 };
    sjs_rect oldrect = { -1 };
    bool result11;
    sjs_rect sjt_call98 = { -1 };
    sjs_string sjt_call99 = { -1 };
    int32_t sjt_capture37;
    bool sjt_capture38;
    int32_t sjt_capture39;
    int32_t sjt_capture40;
    int32_t sjt_functionParam318;
    sjs_rect* sjt_functionParam319 = 0;
    int32_t sjt_functionParam321;
    sjs_rect* sjt_parent249 = 0;
    sjs_list_rect* sjt_parent252 = 0;
    sjs_list_rect* sjt_parent254 = 0;
    sjs_list_rect* sjt_parent255 = 0;
    sjs_list_rect* sjt_parent256 = 0;
    sjs_list_rect* sjt_parent257 = 0;

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
    sjt_parent252 = &g_glviewports;
#line 4
    sjt_parent254 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent254, &sjt_capture37);
#line 135 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam318 = sjt_capture37 - 1;
#line 135
    sjf_list_rect_getat(sjt_parent252, sjt_functionParam318, &sjt_call98);
#line 135
    sjt_parent249 = &sjt_call98;
#line 135
    sjt_functionParam319 = &oldrect;
#line 135
    sjf_rect_isequal(sjt_parent249, sjt_functionParam319, &sjt_capture38);
#line 135
    result11 = !sjt_capture38;
    if (result11) {
        sjs_string* sjt_functionParam320 = 0;

        sjt_call99._refCount = 1;
#line 136 "lib/sj-lib-ui/gl.sj"
        sjt_call99.offset = 0;
#line 136
        sjt_call99.count = 30;
#line 136
        sjt_call99.data._refCount = 1;
#line 136
        sjt_call99.data.v = &sjg_string31;
#line 136
        sjf_array_char(&sjt_call99.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call99._isnullterminated = false;
#line 16
        sjf_string(&sjt_call99);
#line 136 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam320 = &sjt_call99;
#line 136
        sjf_halt(sjt_functionParam320);
    }

#line 53 "lib/sj-lib-common/list.sj"
    sjt_parent255 = &g_glviewports;
#line 4
    sjt_parent256 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent256, &sjt_capture39);
#line 138 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam321 = sjt_capture39 - 1;
#line 138
    sjf_list_rect_removeat(sjt_parent255, sjt_functionParam321);
#line 4 "lib/sj-lib-common/list.sj"
    sjt_parent257 = &g_glviewports;
#line 4
    sjf_list_rect_getcount(sjt_parent257, &sjt_capture40);
    if (sjt_capture40 > 0) {
        int32_t sjt_capture41;
        int32_t sjt_functionParam322;
        sjs_list_rect* sjt_parent258 = 0;
        sjs_list_rect* sjt_parent259 = 0;

#line 8 "lib/sj-lib-common/list.sj"
        sjt_parent258 = &g_glviewports;
#line 4
        sjt_parent259 = &g_glviewports;
#line 4
        sjf_list_rect_getcount(sjt_parent259, &sjt_capture41);
#line 139 "lib/sj-lib-ui/gl.sj"
        sjt_functionParam322 = sjt_capture41 - 1;
#line 139
        sjf_list_rect_getat(sjt_parent258, sjt_functionParam322, &newrect);
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
    if (sjt_call98._refCount == 1) { sjf_rect_destroy(&sjt_call98); }
;
    if (sjt_call99._refCount == 1) { sjf_string_destroy(&sjt_call99); }
;
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect newrect = { -1 };
    sjs_rect* sjt_functionParam312 = 0;
    sjs_list_rect* sjt_parent244 = 0;

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
    sjt_parent244 = &g_glviewports;
#line 127 "lib/sj-lib-ui/gl.sj"
    sjt_functionParam312 = &newrect;
#line 127
    sjf_list_rect_add(sjt_parent244, sjt_functionParam312);
#line 129
    glViewport(newrect.x, newrect.y, newrect.w, newrect.h);

    if (newrect._refCount == 1) { sjf_rect_destroy(&newrect); }
;
}

void sjf_gluniformi32(int32_t loc, int32_t v) {
#line 198 "lib/sj-lib-ui/gl.sj"
    glUniform1i(loc, v);
}

void sjf_gluniformmat4(int32_t loc, sjs_mat4* m) {
#line 186 "lib/sj-lib-ui/gl.sj"
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
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
                delete_cb weakptrcb13 = { &kh_value(p, k), weakptr_clear };
if (kh_value(p, k) != 0) { weakptr_cb_remove(kh_value(p, k), weakptrcb13); }
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
delete_cb weakptrcb17 = { &(*_return), weakptr_clear };
#line 22
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb17); }
return;
#line 33
    }
#line 34
    #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = kh_val(p, k);
#line 22
delete_cb weakptrcb18 = { &(*_return), weakptr_clear };
#line 22
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb18); }
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
    delete_cb weakptrcb19 = { &kh_val(p, k), weakptr_clear };
if (kh_val(p, k) != 0) { weakptr_cb_remove(kh_val(p, k), weakptrcb19); }
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
delete_cb weakptrcb20 = { &kh_val(p, k), weakptr_clear };
#line 38
if (kh_val(p, k) != 0) { weakptr_cb_add(kh_val(p, k), weakptrcb20); }
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
                delete_cb weakptrcb12 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb12); }
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
    delete_cb weakptrcb14 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb14); }
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
delete_cb weakptrcb15 = { &kh_val(p, k)._parent, weakptr_clear };
#line 38
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb15); }
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
                delete_cb weakptrcb11 = { &kh_value(p, k)._parent, weakptr_clear };
if (kh_value(p, k)._parent != 0) { weakptr_cb_remove(kh_value(p, k)._parent, weakptrcb11); }
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

void sjf_i32_random(int32_t* _return) {
    int32_t x;

#line 15 "lib/sj-lib-common/i32.sj"
    x = 0;
#line 17
    x = rand();
#line 14
    (*_return) = x;
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
    int32_t sjt_functionParam268;
    sjs_array_heap_iface_animation* sjt_parent211 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent211 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam268 = index;
#line 8
    sjf_array_heap_iface_animation_getat_heap(sjt_parent211, sjt_functionParam268, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
    sjs_array_heap_iface_animation* sjt_parent208 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent208 = &_parent->arr;
#line 29
    sjf_array_heap_iface_animation_getcount(sjt_parent208, _return);
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

void sjf_list_heap_iface_model_copy(sjs_list_heap_iface_model* _this, sjs_list_heap_iface_model* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_heap_iface_model_copy(&_this->arr, &_from->arr);
}

void sjf_list_heap_iface_model_destroy(sjs_list_heap_iface_model* _this) {
    if (_this->arr._refCount == 1) { sjf_array_heap_iface_model_destroy(&_this->arr); }
;
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    int32_t sjt_capture33;
    int32_t sjt_capture34;
    sjs_array_rect sjt_funcold21 = { -1 };
    int32_t sjt_functionParam310;
    sjs_rect* sjt_functionParam311 = 0;
    sjs_array_rect* sjt_parent237 = 0;
    sjs_array_rect* sjt_parent238 = 0;
    sjs_array_rect* sjt_parent242 = 0;
    sjs_array_rect* sjt_parent243 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent237 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent237, &sjt_capture33);
#line 35
    sjt_parent238 = &_parent->arr;
#line 35
    sjf_array_rect_gettotalcount(sjt_parent238, &sjt_capture34);
    if (sjt_capture33 == sjt_capture34) {
        int32_t sjt_capture35;
        int32_t sjt_functionParam305;
        int32_t sjt_functionParam306;
        int32_t sjt_functionParam307;
        int32_t sjt_functionParam308;
        int32_t sjt_functionParam309;
        sjs_array_rect* sjt_parent239 = 0;
        sjs_array_rect* sjt_parent240 = 0;
        sjs_array_rect* sjt_parent241 = 0;

#line 168 "lib/sj-lib-common/array.sj"
        sjt_parent239 = &_parent->arr;
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam305 = 0;
#line 29 "lib/sj-lib-common/array.sj"
        sjt_parent240 = &_parent->arr;
#line 29
        sjf_array_rect_getcount(sjt_parent240, &sjt_functionParam306);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam308 = 10;
#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent241 = &_parent->arr;
#line 35
        sjf_array_rect_gettotalcount(sjt_parent241, &sjt_capture35);
#line 46 "lib/sj-lib-common/list.sj"
        sjt_functionParam309 = sjt_capture35 * 2;
#line 46
        sjf_i32_max(sjt_functionParam308, sjt_functionParam309, &sjt_functionParam307);
#line 46
        sjf_array_rect_clone(sjt_parent239, sjt_functionParam305, sjt_functionParam306, sjt_functionParam307, &sjt_funcold21);
#line 46
        if (_parent->arr._refCount == 1) { sjf_array_rect_destroy(&_parent->arr); }
;
#line 168 "lib/sj-lib-common/array.sj"
        sjf_array_rect_copy(&_parent->arr, &sjt_funcold21);
    }

#line 52
    sjt_parent242 = &_parent->arr;
#line 29
    sjt_parent243 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent243, &sjt_functionParam310);
#line 44 "lib/sj-lib-common/list.sj"
    sjt_functionParam311 = item;
#line 44
    sjf_array_rect_initat(sjt_parent242, sjt_functionParam310, sjt_functionParam311);

    if (sjt_funcold21._refCount == 1) { sjf_array_rect_destroy(&sjt_funcold21); }
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
    int32_t sjt_functionParam316;
    sjs_array_rect* sjt_parent250 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent250 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam316 = index;
#line 8
    sjf_array_rect_getat(sjt_parent250, sjt_functionParam316, _return);
}

void sjf_list_rect_getat_heap(sjs_list_rect* _parent, int32_t index, sjs_rect** _return) {
    int32_t sjt_functionParam317;
    sjs_array_rect* sjt_parent251 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent251 = &_parent->arr;
#line 8 "lib/sj-lib-common/list.sj"
    sjt_functionParam317 = index;
#line 8
    sjf_array_rect_getat_heap(sjt_parent251, sjt_functionParam317, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
    sjs_array_rect* sjt_parent253 = 0;

#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent253 = &_parent->arr;
#line 29
    sjf_array_rect_getcount(sjt_parent253, _return);
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

void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from) {
    _this->arr._refCount = 1;
#line 1 "lib/sj-lib-common/list.sj"
    sjf_array_u32_copy(&_this->arr, &_from->arr);
}

void sjf_list_u32_destroy(sjs_list_u32* _this) {
    if (_this->arr._refCount == 1) { sjf_array_u32_destroy(&_this->arr); }
;
}

void sjf_list_u32_heap(sjs_list_u32* _this) {
}

void sjf_listlayout(sjs_listlayout* _this) {
}

void sjf_listlayout_as_sji_element(sjs_listlayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_listlayout_element_vtbl;
}

void sjf_listlayout_asinterface(sjs_listlayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_listlayout_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_listlayout_copy(sjs_listlayout* _this, sjs_listlayout* _from) {
    _this->children._refCount = 1;
#line 8 "lib/sj-lib-ui/listLayout.sj"
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
#line 8
    _this->margin._refCount = 1;
#line 8
    sjf_margin_copy(&_this->margin, &_from->margin);
#line 8
    _this->orientation = _from->orientation;
#line 8
    _this->_rect._refCount = 1;
#line 8
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_listlayout_destroy(sjs_listlayout* _this) {
    if (_this->children._refCount == 1) { sjf_array_heap_iface_element_destroy(&_this->children); }
;
    if (_this->margin._refCount == 1) { sjf_margin_destroy(&_this->margin); }
;
    if (_this->_rect._refCount == 1) { sjf_rect_destroy(&_this->_rect); }
;
}

void sjf_listlayout_firemouseevent(sjs_listlayout* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_array_heap_iface_element* sjt_functionParam154 = 0;
    sjs_mouseevent* sjt_parent139 = 0;

#line 60 "lib/sj-lib-ui/listLayout.sj"
    sjt_parent139 = mouseevent;
#line 61
    sjt_functionParam154 = &_parent->children;
#line 61
    sjf_mouseevent_firechildren(sjt_parent139, sjt_functionParam154, _return);
}

void sjf_listlayout_getclasstype(sjs_object* _this, int* _return) {
    *_return = 177;
}

void sjf_listlayout_getrect(sjs_listlayout* _parent, sjs_rect* _return) {
    _return->_refCount = 1;
#line 18 "lib/sj-lib-ui/listLayout.sj"
    sjf_rect_copy(_return, &_parent->_rect);
}

void sjf_listlayout_getrect_heap(sjs_listlayout* _parent, sjs_rect** _return) {
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
#line 18 "lib/sj-lib-ui/listLayout.sj"
    sjf_rect_copy((*_return), &_parent->_rect);
}

void sjf_listlayout_getsize(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    _return->_refCount = 1;
#line 15 "lib/sj-lib-ui/listLayout.sj"
    _return->w = maxsize->w;
#line 15
    _return->h = maxsize->h;
#line 15
    sjf_size(_return);
}

void sjf_listlayout_getsize_heap(sjs_listlayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
#line 15 "lib/sj-lib-ui/listLayout.sj"
    (*_return)->w = maxsize->w;
#line 15
    (*_return)->h = maxsize->h;
#line 15
    sjf_size_heap((*_return));
}

void sjf_listlayout_heap(sjs_listlayout* _this) {
}

void sjf_listlayout_render(sjs_listlayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    int32_t sjt_forEnd16;
    int32_t sjt_forStart16;
    sjs_array_heap_iface_element* sjt_parent136 = 0;

#line 54 "lib/sj-lib-ui/listLayout.sj"
    sjt_forStart16 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent136 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent136, &sjt_forEnd16);
#line 54 "lib/sj-lib-ui/listLayout.sj"
    i = sjt_forStart16;
    while (i < sjt_forEnd16) {
        sji_element child = { 0 };
        int32_t sjt_functionParam153;
        sjs_scene2d* sjt_interfaceParam32 = 0;
        sjs_array_heap_iface_element* sjt_parent137 = 0;
        sji_element sjt_parent138 = { 0 };

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent137 = &_parent->children;
#line 54 "lib/sj-lib-ui/listLayout.sj"
        sjt_functionParam153 = i;
#line 54
        sjf_array_heap_iface_element_getat_heap(sjt_parent137, sjt_functionParam153, &child);
#line 5 "lib/sj-lib-ui/element.sj"
        sjt_parent138 = child;
#line 53 "lib/sj-lib-ui/listLayout.sj"
        sjt_interfaceParam32 = scene;
#line 56
        sjt_parent138._vtbl->render(sjt_parent138._parent, sjt_interfaceParam32);
#line 54
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

void sjf_listlayout_setrect(sjs_listlayout* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect innerrect = { -1 };
    int32_t sjt_forEnd15;
    int32_t sjt_forStart15;
    sjs_margin* sjt_functionParam151 = 0;
    sjs_rect* sjt_parent125 = 0;
    sjs_array_heap_iface_element* sjt_parent126 = 0;
    int32_t val;

    if (_parent->_rect._refCount == 1) { sjf_rect_destroy(&_parent->_rect); }
;
#line 20 "lib/sj-lib-ui/listLayout.sj"
    sjf_rect_copy(&_parent->_rect, rect_);
#line 20
    sjt_parent125 = rect_;
#line 22
    sjt_functionParam151 = &_parent->margin;
#line 22
    sjf_rect_subtractmargin(sjt_parent125, sjt_functionParam151, &innerrect);
#line 24
    val = 0;
#line 25
    sjt_forStart15 = 0;
#line 29 "lib/sj-lib-common/array.sj"
    sjt_parent126 = &_parent->children;
#line 29
    sjf_array_heap_iface_element_getcount(sjt_parent126, &sjt_forEnd15);
#line 25 "lib/sj-lib-ui/listLayout.sj"
    i = sjt_forStart15;
    while (i < sjt_forEnd15) {
        sji_element child = { 0 };
        int32_t sjt_functionParam152;
        sjs_array_heap_iface_element* sjt_parent127 = 0;
        int32_t underscore5;

#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent127 = &_parent->children;
#line 25 "lib/sj-lib-ui/listLayout.sj"
        sjt_functionParam152 = i;
#line 25
        sjf_array_heap_iface_element_getat_heap(sjt_parent127, sjt_functionParam152, &child);
#line 27
        underscore5 = _parent->orientation;
        if (underscore5 == g_listlayoutorientation_topbottom) {
            sjs_size childsize = { -1 };
            sjs_size sjt_call43 = { -1 };
            sjs_rect sjt_call44 = { -1 };
            sjs_size* sjt_interfaceParam24 = 0;
            sjs_rect* sjt_interfaceParam25 = 0;
            sji_element sjt_parent128 = { 0 };
            sji_element sjt_parent129 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
            sjt_parent128 = child;
#line 2
            sjt_call43._refCount = 1;
#line 29 "lib/sj-lib-ui/listLayout.sj"
            sjt_call43.w = (&innerrect)->w;
#line 29
            sjt_call43.h = (&innerrect)->h - val;
#line 29
            sjf_size(&sjt_call43);
#line 29
            sjt_interfaceParam24 = &sjt_call43;
#line 29
            sjt_parent128._vtbl->getsize(sjt_parent128._parent, sjt_interfaceParam24, &childsize);
#line 4 "lib/sj-lib-ui/element.sj"
            sjt_parent129 = child;
#line 4
            sjt_call44._refCount = 1;
#line 30 "lib/sj-lib-ui/listLayout.sj"
            sjt_call44.x = (&innerrect)->x;
#line 30
            sjt_call44.y = (&innerrect)->y + val;
#line 30
            sjt_call44.w = (&innerrect)->w;
#line 30
            sjt_call44.h = (&childsize)->h;
#line 30
            sjf_rect(&sjt_call44);
#line 30
            sjt_interfaceParam25 = &sjt_call44;
#line 30
            sjt_parent129._vtbl->setrect(sjt_parent129._parent, sjt_interfaceParam25);
#line 31
            val = val + (&childsize)->h;

            if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
            if (sjt_call43._refCount == 1) { sjf_size_destroy(&sjt_call43); }
;
            if (sjt_call44._refCount == 1) { sjf_rect_destroy(&sjt_call44); }
;
        } else {
            if (underscore5 == g_listlayoutorientation_bottomtop) {
                sjs_size childsize = { -1 };
                sjs_size sjt_call45 = { -1 };
                sjs_rect sjt_call46 = { -1 };
                sjs_size* sjt_interfaceParam26 = 0;
                sjs_rect* sjt_interfaceParam27 = 0;
                sji_element sjt_parent130 = { 0 };
                sji_element sjt_parent131 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
                sjt_parent130 = child;
#line 2
                sjt_call45._refCount = 1;
#line 34 "lib/sj-lib-ui/listLayout.sj"
                sjt_call45.w = (&innerrect)->w;
#line 34
                sjt_call45.h = (&innerrect)->h - val;
#line 34
                sjf_size(&sjt_call45);
#line 34
                sjt_interfaceParam26 = &sjt_call45;
#line 34
                sjt_parent130._vtbl->getsize(sjt_parent130._parent, sjt_interfaceParam26, &childsize);
#line 4 "lib/sj-lib-ui/element.sj"
                sjt_parent131 = child;
#line 4
                sjt_call46._refCount = 1;
#line 35 "lib/sj-lib-ui/listLayout.sj"
                sjt_call46.x = (&innerrect)->x;
#line 35
                sjt_call46.y = (((&innerrect)->y + (&innerrect)->h) - val) - (&childsize)->h;
#line 35
                sjt_call46.w = (&innerrect)->w;
#line 35
                sjt_call46.h = (&childsize)->h;
#line 35
                sjf_rect(&sjt_call46);
#line 35
                sjt_interfaceParam27 = &sjt_call46;
#line 35
                sjt_parent131._vtbl->setrect(sjt_parent131._parent, sjt_interfaceParam27);
#line 36
                val = val + (&childsize)->h;

                if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
                if (sjt_call45._refCount == 1) { sjf_size_destroy(&sjt_call45); }
;
                if (sjt_call46._refCount == 1) { sjf_rect_destroy(&sjt_call46); }
;
            } else {
                if (underscore5 == g_listlayoutorientation_leftright) {
                    sjs_size childsize = { -1 };
                    sjs_size sjt_call47 = { -1 };
                    sjs_rect sjt_call48 = { -1 };
                    sjs_size* sjt_interfaceParam28 = 0;
                    sjs_rect* sjt_interfaceParam29 = 0;
                    sji_element sjt_parent132 = { 0 };
                    sji_element sjt_parent133 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
                    sjt_parent132 = child;
#line 2
                    sjt_call47._refCount = 1;
#line 39 "lib/sj-lib-ui/listLayout.sj"
                    sjt_call47.w = (&innerrect)->w - val;
#line 39
                    sjt_call47.h = (&innerrect)->h;
#line 39
                    sjf_size(&sjt_call47);
#line 39
                    sjt_interfaceParam28 = &sjt_call47;
#line 39
                    sjt_parent132._vtbl->getsize(sjt_parent132._parent, sjt_interfaceParam28, &childsize);
#line 4 "lib/sj-lib-ui/element.sj"
                    sjt_parent133 = child;
#line 4
                    sjt_call48._refCount = 1;
#line 40 "lib/sj-lib-ui/listLayout.sj"
                    sjt_call48.x = (&innerrect)->x + val;
#line 40
                    sjt_call48.y = (&innerrect)->y;
#line 40
                    sjt_call48.w = (&childsize)->w;
#line 40
                    sjt_call48.h = (&innerrect)->h;
#line 40
                    sjf_rect(&sjt_call48);
#line 40
                    sjt_interfaceParam29 = &sjt_call48;
#line 40
                    sjt_parent133._vtbl->setrect(sjt_parent133._parent, sjt_interfaceParam29);
#line 41
                    val = val + (&childsize)->w;

                    if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
                    if (sjt_call47._refCount == 1) { sjf_size_destroy(&sjt_call47); }
;
                    if (sjt_call48._refCount == 1) { sjf_rect_destroy(&sjt_call48); }
;
                } else {
                    if (underscore5 == g_listlayoutorientation_rightleft) {
                        sjs_size childsize = { -1 };
                        sjs_size sjt_call49 = { -1 };
                        sjs_rect sjt_call50 = { -1 };
                        sjs_size* sjt_interfaceParam30 = 0;
                        sjs_rect* sjt_interfaceParam31 = 0;
                        sji_element sjt_parent134 = { 0 };
                        sji_element sjt_parent135 = { 0 };

#line 2 "lib/sj-lib-ui/element.sj"
                        sjt_parent134 = child;
#line 2
                        sjt_call49._refCount = 1;
#line 44 "lib/sj-lib-ui/listLayout.sj"
                        sjt_call49.w = (&innerrect)->w - val;
#line 44
                        sjt_call49.h = (&innerrect)->h;
#line 44
                        sjf_size(&sjt_call49);
#line 44
                        sjt_interfaceParam30 = &sjt_call49;
#line 44
                        sjt_parent134._vtbl->getsize(sjt_parent134._parent, sjt_interfaceParam30, &childsize);
#line 4 "lib/sj-lib-ui/element.sj"
                        sjt_parent135 = child;
#line 4
                        sjt_call50._refCount = 1;
#line 45 "lib/sj-lib-ui/listLayout.sj"
                        sjt_call50.x = (((&innerrect)->x + (&innerrect)->w) - val) - (&childsize)->w;
#line 45
                        sjt_call50.y = (&innerrect)->y;
#line 45
                        sjt_call50.w = (&childsize)->w;
#line 45
                        sjt_call50.h = (&innerrect)->h;
#line 45
                        sjf_rect(&sjt_call50);
#line 45
                        sjt_interfaceParam31 = &sjt_call50;
#line 45
                        sjt_parent135._vtbl->setrect(sjt_parent135._parent, sjt_interfaceParam31);
#line 46
                        val = val + (&childsize)->w;

                        if (childsize._refCount == 1) { sjf_size_destroy(&childsize); }
;
                        if (sjt_call49._refCount == 1) { sjf_size_destroy(&sjt_call49); }
;
                        if (sjt_call50._refCount == 1) { sjf_rect_destroy(&sjt_call50); }
;
                    }
                }
            }
        }

#line 25
        i++;

        if (child._parent != 0) {
            child._parent->_refCount--;
            if (child._parent->_refCount <= 0) {
                child._vtbl->destroy(child._parent);
                free(child._parent);
            }
        }
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
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
    bool result10;
    bool shouldappcontinue;
    bool shouldcontinue;
    sjs_size size = { -1 };
    sjs_string sjt_call95 = { -1 };
    sjs_string sjt_call96 = { -1 };
    sjs_string sjt_call97 = { -1 };
    bool sjt_capture36;
    int32_t sjt_functionParam271;
    sjs_size* sjt_functionParam304 = 0;
    sjs_rect* sjt_functionParam315 = 0;
    sjs_scene2d* sjt_interfaceParam49 = 0;
    sjs_animator* sjt_parent215 = 0;
    sjs_windowrenderer* sjt_parent234 = 0;
    sjs_scene2d* sjt_parent236 = 0;
    sjs_scene2d* sjt_parent245 = 0;
    sjs_rect* sjt_parent246 = 0;
    sji_element sjt_parent248 = { 0 };
    sjs_scene2d* sjt_parent260 = 0;
    sjs_windowrenderer* sjt_parent261 = 0;
    int32_t ticks;

#line 9 "lib/sj-lib-ui/loop.sj"
    shouldappcontinue = true;
#line 10
    ticks = 0;
#line 12
    ticks = SDL_GetTicks();
#line 31 "lib/sj-lib-ui/animation.sj"
    sjt_parent215 = &g_animator;
#line 14 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam271 = ticks;
#line 14
    sjf_animator_nextframe(sjt_parent215, sjt_functionParam271);
    if (g_mainloop_showfps) {
#line 17 "lib/sj-lib-ui/loop.sj"
        g_mainloop_frames = g_mainloop_frames + 1;
        if ((g_mainloop_lasttick + 1000) < ticks) {
            float fps;
            int32_t sjt_cast24;
            int32_t sjt_cast25;
            sjs_string* sjt_functionParam272 = 0;
            sjs_string* sjt_functionParam292 = 0;
            float sjt_functionParam293;
            sjs_string* sjt_parent233 = 0;

#line 19 "lib/sj-lib-ui/loop.sj"
            sjt_cast24 = g_mainloop_frames;
#line 19
            sjt_cast25 = ticks - g_mainloop_lasttick;
#line 19
            fps = ((float)sjt_cast24 * 1000.0f) / (float)sjt_cast25;
#line 19
            sjt_call96._refCount = 1;
#line 20
            sjt_call96.offset = 0;
#line 20
            sjt_call96.count = 5;
#line 20
            sjt_call96.data._refCount = 1;
#line 20
            sjt_call96.data.v = &sjg_string30;
#line 20
            sjf_array_char(&sjt_call96.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call96._isnullterminated = false;
#line 16
            sjf_string(&sjt_call96);
#line 20 "lib/sj-lib-ui/loop.sj"
            sjt_parent233 = &sjt_call96;
#line 20
            sjt_functionParam293 = fps;
#line 20
            sjf_f32_asstring(sjt_functionParam293, &sjt_call97);
#line 20
            sjt_functionParam292 = &sjt_call97;
#line 20
            sjf_string_add(sjt_parent233, sjt_functionParam292, &sjt_call95);
#line 20
            sjt_functionParam272 = &sjt_call95;
#line 20
            sjf_debug_writeline(sjt_functionParam272);
#line 21
            g_mainloop_lasttick = ticks;
#line 22
            g_mainloop_frames = 0;
        }
    }

#line 7 "lib/sj-lib-ui/windowRenderer.sj"
    sjt_parent234 = &g_rootwindowrenderer;
#line 7
    sjf_windowrenderer_getsize(sjt_parent234, &size);
#line 27 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent236 = &g_rootscene;
#line 27 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam304 = &size;
#line 27
    sjf_scene2d_setsize(sjt_parent236, sjt_functionParam304);
#line 8 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent245 = &g_rootscene;
#line 8
    sjf_scene2d_start(sjt_parent245);
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
    sjt_parent246 = &g_looplastrect;
#line 30 "lib/sj-lib-ui/loop.sj"
    sjt_functionParam315 = &rect;
#line 30
    sjf_rect_isequal(sjt_parent246, sjt_functionParam315, &sjt_capture36);
#line 30
    result10 = !sjt_capture36;
    if (result10) {
        sjs_rect* sjt_interfaceParam48 = 0;
        sji_element sjt_parent247 = { 0 };

#line 4 "lib/sj-lib-ui/element.sj"
        sjt_parent247 = g_root;
#line 31 "lib/sj-lib-ui/loop.sj"
        sjt_interfaceParam48 = &rect;
#line 31
        sjt_parent247._vtbl->setrect(sjt_parent247._parent, sjt_interfaceParam48);
    }

#line 5 "lib/sj-lib-ui/element.sj"
    sjt_parent248 = g_root;
#line 33 "lib/sj-lib-ui/loop.sj"
    sjt_interfaceParam49 = &g_rootscene;
#line 33
    sjt_parent248._vtbl->render(sjt_parent248._parent, sjt_interfaceParam49);
#line 19 "lib/sj-lib-ui/scene2d.sj"
    sjt_parent260 = &g_rootscene;
#line 19
    sjf_scene2d_end(sjt_parent260);
#line 22 "lib/sj-lib-ui/windowRenderer.sj"
    sjt_parent261 = &g_rootwindowrenderer;
#line 22
    sjf_windowrenderer_present(sjt_parent261);
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
            int32_t ifValue17;
            int32_option sjt_getValue5;

#line 76 "lib/sj-lib-ui/loop.sj"
            sjt_getValue5 = mouse_eventtype;
#line 76
            ifValue17 = sjt_getValue5.value;
            if ((g_mouse_captureelement._parent != 0)) {
                sji_element ifValue18 = { 0 };
                sjs_mouseevent sjt_call100 = { -1 };
                bool sjt_funcold22;
                sjs_mouseevent* sjt_interfaceParam50 = 0;
                sji_element sjt_parent262 = { 0 };

#line 77 "lib/sj-lib-ui/loop.sj"
                ifValue18 = g_mouse_captureelement;
                if (ifValue18._parent != 0) {
                    ifValue18._parent->_refCount++;
                }

#line 6 "lib/sj-lib-ui/element.sj"
                sjt_parent262 = ifValue18;
#line 6
                sjt_funcold22 = shouldcontinue;
#line 6
                sjt_call100._refCount = 1;
#line 78 "lib/sj-lib-ui/loop.sj"
                sjt_call100.eventtype = ifValue17;
#line 78
                sjt_call100.point._refCount = 1;
#line 80
                sjt_call100.point.x = mouse_x;
#line 80
                sjt_call100.point.y = mouse_y;
#line 80
                sjf_point(&sjt_call100.point);
#line 81
                sjt_call100.iscaptured = true;
#line 78
                sjt_call100.isleftdown = mouse_isleftdown;
#line 78
                sjf_mouseevent(&sjt_call100);
#line 78
                sjt_interfaceParam50 = &sjt_call100;
#line 78
                sjt_parent262._vtbl->firemouseevent(sjt_parent262._parent, sjt_interfaceParam50, &sjt_funcold22);
#line 6 "lib/sj-lib-ui/element.sj"
                shouldcontinue = sjt_funcold22;

                if (ifValue18._parent != 0) {
                    ifValue18._parent->_refCount--;
                    if (ifValue18._parent->_refCount <= 0) {
                        ifValue18._vtbl->destroy(ifValue18._parent);
                        free(ifValue18._parent);
                    }
                }
                if (sjt_call100._refCount == 1) { sjf_mouseevent_destroy(&sjt_call100); }
;
            } else {
                sjs_mouseevent sjt_call101 = { -1 };
                bool sjt_funcold23;
                sjs_mouseevent* sjt_interfaceParam51 = 0;
                sji_element sjt_parent263 = { 0 };

#line 6 "lib/sj-lib-ui/element.sj"
                sjt_parent263 = g_root;
#line 6
                sjt_funcold23 = shouldcontinue;
#line 6
                sjt_call101._refCount = 1;
#line 86 "lib/sj-lib-ui/loop.sj"
                sjt_call101.eventtype = ifValue17;
#line 86
                sjt_call101.point._refCount = 1;
#line 88
                sjt_call101.point.x = mouse_x;
#line 88
                sjt_call101.point.y = mouse_y;
#line 88
                sjf_point(&sjt_call101.point);
#line 89
                sjt_call101.iscaptured = false;
#line 86
                sjt_call101.isleftdown = mouse_isleftdown;
#line 86
                sjf_mouseevent(&sjt_call101);
#line 86
                sjt_interfaceParam51 = &sjt_call101;
#line 86
                sjt_parent263._vtbl->firemouseevent(sjt_parent263._parent, sjt_interfaceParam51, &sjt_funcold23);
#line 6 "lib/sj-lib-ui/element.sj"
                shouldcontinue = sjt_funcold23;

                if (sjt_call101._refCount == 1) { sjf_mouseevent_destroy(&sjt_call101); }
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
    if (sjt_call95._refCount == 1) { sjf_string_destroy(&sjt_call95); }
;
    if (sjt_call96._refCount == 1) { sjf_string_destroy(&sjt_call96); }
;
    if (sjt_call97._refCount == 1) { sjf_string_destroy(&sjt_call97); }
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

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result6;

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
    result6 = -2.0f;
#line 176
    _return->m22 = result6 / (zfar - znear);
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
    float result7;

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
    result7 = -2.0f;
#line 176
    (*_return)->m22 = result7 / (zfar - znear);
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
    sjs_rect* sjt_functionParam323 = 0;
    sjs_rect* sjt_functionParam324 = 0;

#line 20 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam323 = &_parent->windowrect;
#line 20
    sjt_functionParam324 = &_parent->windowrect;
#line 20
    sjf_glpopviewport(sjt_functionParam323, sjt_functionParam324);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result5;
    bool sjt_capture32;
    sjs_mat4 sjt_funcold17 = { -1 };
    sjs_mat4 sjt_funcold18 = { -1 };
    sjs_mat4 sjt_funcold19 = { -1 };
    sjs_size* sjt_functionParam294 = 0;
    sjs_size* sjt_parent235 = 0;

#line 27 "lib/sj-lib-ui/size.sj"
    sjt_parent235 = &_parent->_size;
#line 27 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam294 = size;
#line 27
    sjf_size_isequal(sjt_parent235, sjt_functionParam294, &sjt_capture32);
#line 28
    result5 = !sjt_capture32;
    if (result5) {
        float result8;
        float result9;
        int32_t sjt_cast26;
        int32_t sjt_cast27;
        float sjt_functionParam295;
        float sjt_functionParam296;
        float sjt_functionParam297;
        float sjt_functionParam298;
        float sjt_functionParam299;
        float sjt_functionParam300;
        float sjt_functionParam301;
        float sjt_functionParam302;
        float sjt_functionParam303;

        if (_parent->_size._refCount == 1) { sjf_size_destroy(&_parent->_size); }
;
#line 27 "lib/sj-lib-ui/scene2d.sj"
        sjf_size_copy(&_parent->_size, size);
#line 30
        sjt_functionParam295 = 0.0f;
#line 30
        sjt_cast26 = (&_parent->_size)->w;
#line 30
        sjt_functionParam296 = (float)sjt_cast26;
#line 30
        sjt_cast27 = 0 - (&_parent->_size)->h;
#line 30
        sjt_functionParam297 = (float)sjt_cast27;
#line 30
        sjt_functionParam298 = 0.0f;
#line 30
        result8 = -1.0f;
#line 30
        sjt_functionParam299 = result8;
#line 30
        sjt_functionParam300 = 1.0f;
#line 30
        sjf_mat4_orthographic(sjt_functionParam295, sjt_functionParam296, sjt_functionParam297, sjt_functionParam298, sjt_functionParam299, sjt_functionParam300, &sjt_funcold17);
#line 30
        if (_parent->projection._refCount == 1) { sjf_mat4_destroy(&_parent->projection); }
;
#line 170 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->projection, &sjt_funcold17);
#line 31 "lib/sj-lib-ui/scene2d.sj"
        sjt_functionParam301 = 1.0f;
#line 31
        result9 = -1.0f;
#line 31
        sjt_functionParam302 = result9;
#line 31
        sjt_functionParam303 = 1.0f;
#line 31
        sjf_mat4_scale(sjt_functionParam301, sjt_functionParam302, sjt_functionParam303, &sjt_funcold18);
#line 31
        if (_parent->model._refCount == 1) { sjf_mat4_destroy(&_parent->model); }
;
#line 213 "lib/sj-lib-ui/mat4.sj"
        sjf_mat4_copy(&_parent->model, &sjt_funcold18);
#line 213
        sjf_mat4_identity(&sjt_funcold19);
#line 213
        if (_parent->view._refCount == 1) { sjf_mat4_destroy(&_parent->view); }
;
#line 124
        sjf_mat4_copy(&_parent->view, &sjt_funcold19);
    }

    if (sjt_funcold17._refCount == 1) { sjf_mat4_destroy(&sjt_funcold17); }
;
    if (sjt_funcold18._refCount == 1) { sjf_mat4_destroy(&sjt_funcold18); }
;
    if (sjt_funcold19._refCount == 1) { sjf_mat4_destroy(&sjt_funcold19); }
;
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_rect sjt_funcold20 = { -1 };
    sjs_rect* sjt_functionParam313 = 0;
    sjs_rect* sjt_functionParam314 = 0;

    sjt_funcold20._refCount = 1;
#line 9 "lib/sj-lib-ui/scene2d.sj"
    sjt_funcold20.x = 0;
#line 9
    sjt_funcold20.y = 0;
#line 9
    sjt_funcold20.w = (&_parent->_size)->w;
#line 9
    sjt_funcold20.h = (&_parent->_size)->h;
#line 9
    sjf_rect(&sjt_funcold20);
#line 9
    if (_parent->windowrect._refCount == 1) { sjf_rect_destroy(&_parent->windowrect); }
;
#line 1 "lib/sj-lib-ui/rect.sj"
    sjf_rect_copy(&_parent->windowrect, &sjt_funcold20);
#line 10 "lib/sj-lib-ui/scene2d.sj"
    sjt_functionParam313 = &_parent->windowrect;
#line 10
    sjt_functionParam314 = &_parent->windowrect;
#line 10
    sjf_glpushviewport(sjt_functionParam313, sjt_functionParam314);
#line 12
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
#line 13
    glEnable( GL_TEXTURE_2D );
#line 14
    glDisable( GL_DEPTH_TEST );

    if (sjt_funcold20._refCount == 1) { sjf_rect_destroy(&sjt_funcold20); }
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
        bool sjt_capture26;
        int32_t sjt_capture27;
        sjs_array_char* sjt_parent216 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent216 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent216, &sjt_capture27);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture27) {
            int32_t sjt_capture28;
            sjs_array_char* sjt_parent217 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent217 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent217, &sjt_capture28);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture26 = ((_parent->offset + _parent->count) == sjt_capture28);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture26 = false;
        }

        if (sjt_capture26) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd24;
            int32_t sjt_forStart24;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart24 = 0;
#line 27
            sjt_forEnd24 = item->count;
#line 27
            i = sjt_forStart24;
            while (i < sjt_forEnd24) {
                int32_t sjt_functionParam273;
                char sjt_functionParam274;
                int32_t sjt_functionParam276;
                sjs_array_char* sjt_parent218 = 0;
                sjs_string* sjt_parent220 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent218 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam273 = newcount;
#line 18
                sjt_parent220 = item;
#line 27
                sjt_functionParam276 = i;
#line 27
                sjf_string_getat(sjt_parent220, sjt_functionParam276, &sjt_functionParam274);
#line 27
                sjf_array_char_initat(sjt_parent218, sjt_functionParam273, sjt_functionParam274);
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
            int32_t sjt_forEnd25;
            int32_t sjt_forStart25;
            int32_t sjt_functionParam277;
            int32_t sjt_functionParam278;
            int32_t sjt_functionParam279;
            sjs_array_char* sjt_parent221 = 0;
            sjs_array_char* sjt_parent222 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent221 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam277 = _parent->offset;
#line 34
            sjt_functionParam278 = _parent->count;
#line 34
            sjt_functionParam279 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent221, sjt_functionParam277, sjt_functionParam278, sjt_functionParam279, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent222 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent222, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart25 = 0;
#line 37
            sjt_forEnd25 = item->count;
#line 37
            i = sjt_forStart25;
            while (i < sjt_forEnd25) {
                int32_t sjt_functionParam280;
                char sjt_functionParam281;
                int32_t sjt_functionParam282;
                sjs_array_char* sjt_parent223 = 0;
                sjs_string* sjt_parent224 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent223 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam280 = newcount;
#line 18
                sjt_parent224 = item;
#line 37
                sjt_functionParam282 = i;
#line 37
                sjf_string_getat(sjt_parent224, sjt_functionParam282, &sjt_functionParam281);
#line 37
                sjf_array_char_initat(sjt_parent223, sjt_functionParam280, sjt_functionParam281);
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
        bool sjt_capture29;
        int32_t sjt_capture30;
        sjs_array_char* sjt_parent225 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent225 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent225, &sjt_capture30);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture30) {
            int32_t sjt_capture31;
            sjs_array_char* sjt_parent226 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent226 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent226, &sjt_capture31);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture29 = ((_parent->offset + _parent->count) == sjt_capture31);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture29 = false;
        }

        if (sjt_capture29) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd26;
            int32_t sjt_forStart26;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart26 = 0;
#line 27
            sjt_forEnd26 = item->count;
#line 27
            i = sjt_forStart26;
            while (i < sjt_forEnd26) {
                int32_t sjt_functionParam283;
                char sjt_functionParam284;
                int32_t sjt_functionParam285;
                sjs_array_char* sjt_parent227 = 0;
                sjs_string* sjt_parent228 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent227 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam283 = newcount;
#line 18
                sjt_parent228 = item;
#line 27
                sjt_functionParam285 = i;
#line 27
                sjf_string_getat(sjt_parent228, sjt_functionParam285, &sjt_functionParam284);
#line 27
                sjf_array_char_initat(sjt_parent227, sjt_functionParam283, sjt_functionParam284);
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
            int32_t sjt_forEnd27;
            int32_t sjt_forStart27;
            int32_t sjt_functionParam286;
            int32_t sjt_functionParam287;
            int32_t sjt_functionParam288;
            sjs_array_char* sjt_parent229 = 0;
            sjs_array_char* sjt_parent230 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent229 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam286 = _parent->offset;
#line 34
            sjt_functionParam287 = _parent->count;
#line 34
            sjt_functionParam288 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent229, sjt_functionParam286, sjt_functionParam287, sjt_functionParam288, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent230 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent230, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart27 = 0;
#line 37
            sjt_forEnd27 = item->count;
#line 37
            i = sjt_forStart27;
            while (i < sjt_forEnd27) {
                int32_t sjt_functionParam289;
                char sjt_functionParam290;
                int32_t sjt_functionParam291;
                sjs_array_char* sjt_parent231 = 0;
                sjs_string* sjt_parent232 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent231 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam289 = newcount;
#line 18
                sjt_parent232 = item;
#line 37
                sjt_functionParam291 = i;
#line 37
                sjf_string_getat(sjt_parent232, sjt_functionParam291, &sjt_functionParam290);
#line 37
                sjf_array_char_initat(sjt_parent231, sjt_functionParam289, sjt_functionParam290);
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
    int32_t sjt_functionParam275;
    sjs_array_char* sjt_parent219 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent219 = &_parent->data;
#line 64 "lib/sj-lib-common/string.sj"
    sjt_functionParam275 = _parent->offset + index;
#line 64
    sjf_array_char_getat(sjt_parent219, sjt_functionParam275, _return);
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
    sjs_string sjt_call17 = { -1 };
    sjs_string* sjt_functionParam107 = 0;
    float sjt_functionParam108;

    sjt_call17._refCount = 1;
#line 3 "lib/sj-lib-ui/style.sj"
    sjt_call17.offset = 0;
#line 3
    sjt_call17.count = 32;
#line 3
    sjt_call17.data._refCount = 1;
#line 3
    sjt_call17.data.v = &sjg_string16;
#line 3
    sjf_array_char(&sjt_call17.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call17._isnullterminated = false;
#line 16
    sjf_string(&sjt_call17);
#line 3 "lib/sj-lib-ui/style.sj"
    sjt_functionParam107 = &sjt_call17;
#line 3
    sjt_functionParam108 = 24.0f;
#line 3
    sjf_font_load_heap(sjt_functionParam107, sjt_functionParam108, _return);

    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
;
}

void sjf_style_heap(sjs_style* _this) {
}

void sjf_testelement_heap(sjs_string* text, sji_element* _return) {
    sjs_textelement* sjt_call10 = 0;
    sjs_filllayout* sjt_call6 = 0;
    sjs_boxelement* sjt_call9 = 0;
    int32_t sjt_capture19;
    int32_t sjt_capture20;
    sjs_filllayout* sjt_cast5 = 0;
    sjs_boxelement* sjt_cast6 = 0;
    sjs_textelement* sjt_cast7 = 0;
    int32_t sjt_functionParam63;
    sji_element sjt_functionParam64 = { 0 };
    int32_t sjt_functionParam69;
    sji_element sjt_functionParam70 = { 0 };
    sjs_array_heap_iface_element* sjt_parent65 = 0;
    sjs_array_heap_iface_element* sjt_parent70 = 0;
    sjs_style* sjt_parent86 = 0;

    sjt_call6 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call6->_refCount = 1;
    sjt_call6->children._refCount = 1;
#line 5 "layout.sj"
    sjt_call6->children.v = createarray(sizeof(sji_element), 2);
#line 5
    sjf_array_heap_iface_element(&sjt_call6->children);
#line 5
    sjs_array_heap_iface_element* array6;
#line 5
    array6 = &sjt_call6->children;
#line 5
    sjt_parent65 = array6;
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
#line 14
    sjf_i32_random(&sjt_capture19);
#line 8 "layout.sj"
    sjt_call9->idealsize.w = (sjt_capture19 % 20) + 30;
#line 8
    sjf_i32_random(&sjt_capture20);
#line 8
    sjt_call9->idealsize.h = (sjt_capture20 % 20) + 30;
#line 8
    sjf_size(&sjt_call9->idealsize);
#line 8
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
#line 6 "layout.sj"
    sjt_cast6 = sjt_call9;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_boxelement_as_sji_element(sjt_cast6, &sjt_functionParam64);
    if (sjt_functionParam64._parent != 0) {
        sjt_functionParam64._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent65, sjt_functionParam63, sjt_functionParam64);
#line 5 "layout.sj"
    sjt_parent70 = array6;
#line 5
    sjt_functionParam69 = 1;
#line 5
    sjt_call10 = (sjs_textelement*)malloc(sizeof(sjs_textelement));
#line 5
    sjt_call10->_refCount = 1;
#line 20 "lib/sj-lib-ui/textElement.sj"
    sjt_call10->id._refCount = -1;
#line 2 "lib/sj-lib-ui/style.sj"
    sjt_parent86 = &g_style;
#line 2
    sjf_style_getfont_heap(sjt_parent86, &sjt_call10->font);
#line 2
    sjt_call10->text._refCount = 1;
#line 3 "layout.sj"
    sjf_string_copy(&sjt_call10->text, text);
#line 3
    sjt_call10->color._refCount = 1;
#line 10
    sjf_color_copy(&sjt_call10->color, &g_colors_white);
#line 10
    sjt_call10->margin._refCount = 1;
#line 11
    sjt_call10->margin.l = 4;
#line 11
    sjt_call10->margin.t = 4;
#line 11
    sjt_call10->margin.r = 4;
#line 11
    sjt_call10->margin.b = 4;
#line 11
    sjf_margin(&sjt_call10->margin);
#line 10
    sjt_call10->halign = g_texthorizontal_center;
#line 10
    sjt_call10->valign = g_textvertical_center;
#line 27 "lib/sj-lib-ui/textElement.sj"
    sjt_call10->idealsize._refCount = -1;
#line 27
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
#line 29 "lib/sj-lib-ui/textElement.sj"
    sjt_call10->_textrenderer._refCount = -1;
#line 29
    sjf_textelement_heap(sjt_call10);
#line 10 "layout.sj"
    sjt_cast7 = sjt_call10;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_textelement_as_sji_element(sjt_cast7, &sjt_functionParam70);
    if (sjt_functionParam70._parent != 0) {
        sjt_functionParam70._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent70, sjt_functionParam69, sjt_functionParam70);
#line 1
    sjt_call6->margin._refCount = 1;
#line 2 "lib/sj-lib-ui/margin.sj"
    sjt_call6->margin.l = 0;
#line 3
    sjt_call6->margin.t = 0;
#line 4
    sjt_call6->margin.r = 0;
#line 5
    sjt_call6->margin.b = 0;
#line 5
    sjf_margin(&sjt_call6->margin);
#line 4 "lib/sj-lib-ui/fillLayout.sj"
    sjt_call6->effect._parent = 0;
#line 4
    sjt_call6->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call6->_rect.x = 0;
#line 3
    sjt_call6->_rect.y = 0;
#line 4
    sjt_call6->_rect.w = 0;
#line 5
    sjt_call6->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call6->_rect);
#line 5
    sjf_filllayout_heap(sjt_call6);
#line 4 "layout.sj"
    sjt_cast5 = sjt_call6;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_filllayout_as_sji_element(sjt_cast5, &(*_return));
    if ((*_return)._parent != 0) {
        (*_return)._parent->_refCount++;
    }

    sjt_call10->_refCount--;
    if (sjt_call10->_refCount <= 0) {
        weakptr_release(sjt_call10);
        sjf_textelement_destroy(sjt_call10);
        free(sjt_call10);
    }
    sjt_call6->_refCount--;
    if (sjt_call6->_refCount <= 0) {
        weakptr_release(sjt_call6);
        sjf_filllayout_destroy(sjt_call6);
        free(sjt_call6);
    }
    sjt_call9->_refCount--;
    if (sjt_call9->_refCount <= 0) {
        weakptr_release(sjt_call9);
        sjf_boxelement_destroy(sjt_call9);
        free(sjt_call9);
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
    sjs_string* copyoption16 = (_from->id._refCount != -1 ? &_from->id : 0);
    if (copyoption16 != 0) {
        _this->id._refCount = 1;
#line 18 "lib/sj-lib-ui/textElement.sj"
        sjf_string_copy(&_this->id, copyoption16);
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
    sjs_size* copyoption17 = (_from->idealsize._refCount != -1 ? &_from->idealsize : 0);
    if (copyoption17 != 0) {
        _this->idealsize._refCount = 1;
#line 18 "lib/sj-lib-ui/textElement.sj"
        sjf_size_copy(&_this->idealsize, copyoption17);
    } else {
        _this->idealsize._refCount = -1;
    }

#line 18
    _this->_rect._refCount = 1;
#line 18
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 18
    sjs_textrenderer* copyoption18 = (_from->_textrenderer._refCount != -1 ? &_from->_textrenderer : 0);
    if (copyoption18 != 0) {
        _this->_textrenderer._refCount = 1;
#line 18 "lib/sj-lib-ui/textElement.sj"
        sjf_textrenderer_copy(&_this->_textrenderer, copyoption18);
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
    *_return = 142;
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
        sjs_size* ifValue7 = 0;
        sjs_size* sjt_functionParam73 = 0;
        sjs_size* sjt_parent72 = 0;

#line 32 "lib/sj-lib-ui/textElement.sj"
        ifValue7 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
#line 5 "lib/sj-lib-ui/size.sj"
        sjt_parent72 = ifValue7;
#line 31 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam73 = maxsize;
#line 31
        sjf_size_min(sjt_parent72, sjt_functionParam73, _return);
    } else {
        sjs_size sjt_call11 = { -1 };
        sjs_string* sjt_functionParam74 = 0;
        sjs_margin* sjt_functionParam75 = 0;
        sjs_size* sjt_functionParam76 = 0;
        sjs_size* sjt_parent73 = 0;
        sjs_font* sjt_parent74 = 0;
        sjs_size* sjt_parent75 = 0;
        sjs_size textsize = { -1 };

#line 53 "lib/sj-lib-ui/font.sj"
        sjt_parent74 = _parent->font;
#line 35 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam74 = &_parent->text;
#line 35
        sjf_font_gettextsize(sjt_parent74, sjt_functionParam74, &sjt_call11);
#line 35
        sjt_parent73 = &sjt_call11;
#line 35
        sjt_functionParam75 = &_parent->margin;
#line 35
        sjf_size_addmargin(sjt_parent73, sjt_functionParam75, &textsize);
#line 5 "lib/sj-lib-ui/size.sj"
        sjt_parent75 = &textsize;
#line 31 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam76 = maxsize;
#line 31
        sjf_size_min(sjt_parent75, sjt_functionParam76, _return);

        if (sjt_call11._refCount == 1) { sjf_size_destroy(&sjt_call11); }
;
        if (textsize._refCount == 1) { sjf_size_destroy(&textsize); }
;
    }
}

void sjf_textelement_getsize_heap(sjs_textelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    if (((_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0) != 0)) {
        sjs_size* ifValue10 = 0;
        sjs_size* sjt_functionParam77 = 0;
        sjs_size* sjt_parent76 = 0;

#line 32 "lib/sj-lib-ui/textElement.sj"
        ifValue10 = (_parent->idealsize._refCount != -1 ? &_parent->idealsize : 0);
#line 5 "lib/sj-lib-ui/size.sj"
        sjt_parent76 = ifValue10;
#line 31 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam77 = maxsize;
#line 31
        sjf_size_min_heap(sjt_parent76, sjt_functionParam77, _return);
    } else {
        sjs_size sjt_call12 = { -1 };
        sjs_string* sjt_functionParam78 = 0;
        sjs_margin* sjt_functionParam79 = 0;
        sjs_size* sjt_functionParam80 = 0;
        sjs_size* sjt_parent77 = 0;
        sjs_font* sjt_parent78 = 0;
        sjs_size* sjt_parent79 = 0;
        sjs_size textsize = { -1 };

#line 53 "lib/sj-lib-ui/font.sj"
        sjt_parent78 = _parent->font;
#line 35 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam78 = &_parent->text;
#line 35
        sjf_font_gettextsize(sjt_parent78, sjt_functionParam78, &sjt_call12);
#line 35
        sjt_parent77 = &sjt_call12;
#line 35
        sjt_functionParam79 = &_parent->margin;
#line 35
        sjf_size_addmargin(sjt_parent77, sjt_functionParam79, &textsize);
#line 5 "lib/sj-lib-ui/size.sj"
        sjt_parent79 = &textsize;
#line 31 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam80 = maxsize;
#line 31
        sjf_size_min_heap(sjt_parent79, sjt_functionParam80, _return);

        if (sjt_call12._refCount == 1) { sjf_size_destroy(&sjt_call12); }
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
        sjs_string* ifValue12 = 0;
        sjs_textelement* sjt_cast8 = 0;
        sjs_string* sjt_functionParam71 = 0;
        sji_element sjt_functionParam72 = { 0 };
        sjs_hash_string_weak_iface_element* sjt_parent71 = 0;

#line 90 "lib/sj-lib-ui/textElement.sj"
        ifValue12 = (_this->id._refCount != -1 ? &_this->id : 0);
#line 38 "lib/sj-lib-common/hash.sj"
        sjt_parent71 = &g_elementsbyid;
#line 91 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam71 = ifValue12;
#line 18
        sjt_cast8 = _this;
#line 1 "lib/sj-lib-ui/element.sj"
        sjf_textelement_as_sji_element(sjt_cast8, &sjt_functionParam72);
#line 1
        delete_cb weakptrcb16 = { &sjt_functionParam72._parent, weakptr_clear };
#line 1
        if (sjt_functionParam72._parent != 0) { weakptr_cb_add(sjt_functionParam72._parent, weakptrcb16); }
#line 1
        sjf_hash_string_weak_iface_element_setat(sjt_parent71, sjt_functionParam71, sjt_functionParam72);

        delete_cb weakptrcb24 = { &sjt_functionParam72._parent, weakptr_clear };
        if (sjt_functionParam72._parent != 0) { weakptr_cb_remove(sjt_functionParam72._parent, weakptrcb24); }
    }
}

void sjf_textelement_render(sjs_textelement* _parent, sjs_scene2d* scene) {
    sjs_rect innerrect = { -1 };
    sjs_textrenderer sjt_value3 = { -1 };
    sjs_size textsize = { -1 };

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) == 0) {
        sjs_string* sjt_functionParam82 = 0;
        sjs_margin* sjt_functionParam83 = 0;
        sjs_font* sjt_parent81 = 0;
        sjs_rect* sjt_parent82 = 0;
        int32_t underscore1;
        int32_t underscore2;
        int32_t x;
        int32_t y;

#line 53 "lib/sj-lib-ui/font.sj"
        sjt_parent81 = _parent->font;
#line 58 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam82 = &_parent->text;
#line 58
        sjf_font_gettextsize(sjt_parent81, sjt_functionParam82, &textsize);
#line 7 "lib/sj-lib-ui/rect.sj"
        sjt_parent82 = &_parent->_rect;
#line 59 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam83 = &_parent->margin;
#line 59
        sjf_rect_subtractmargin(sjt_parent82, sjt_functionParam83, &innerrect);
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
        sjs_textrenderer* copyoption19 = &sjt_value3;
        if (copyoption19 != 0) {
            _parent->_textrenderer._refCount = 1;
#line 74 "lib/sj-lib-ui/textElement.sj"
            sjf_textrenderer_copy(&_parent->_textrenderer, copyoption19);
        } else {
            _parent->_textrenderer._refCount = -1;
        }
    }

    if ((_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0) != 0) {
        sjs_scene2d* sjt_functionParam103 = 0;
        sjs_textrenderer* sjt_parent83 = 0;

#line 10 "lib/sj-lib-ui/textRenderer.sj"
        sjt_parent83 = (_parent->_textrenderer._refCount != -1 ? &_parent->_textrenderer : 0);
#line 56 "lib/sj-lib-ui/textElement.sj"
        sjt_functionParam103 = scene;
#line 56
        sjf_textrenderer_render(sjt_parent83, sjt_functionParam103);
    }

    if (innerrect._refCount == 1) { sjf_rect_destroy(&innerrect); }
;
    if (sjt_value3._refCount == 1) { sjf_textrenderer_destroy(&sjt_value3); }
;
    if (textsize._refCount == 1) { sjf_size_destroy(&textsize); }
;
}

void sjf_textelement_setrect(sjs_textelement* _parent, sjs_rect* rect_) {
    bool result4;
    bool sjt_capture21;
    sjs_rect* sjt_functionParam81 = 0;
    sjs_rect* sjt_parent80 = 0;

#line 15 "lib/sj-lib-ui/rect.sj"
    sjt_parent80 = &_parent->_rect;
#line 41 "lib/sj-lib-ui/textElement.sj"
    sjt_functionParam81 = rect_;
#line 41
    sjf_rect_isequal(sjt_parent80, sjt_functionParam81, &sjt_capture21);
#line 42
    result4 = !sjt_capture21;
    if (result4) {
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
    sjs_string sjt_call13 = { -1 };
    sjs_string sjt_call14 = { -1 };
    sjs_string sjt_call15 = { -1 };
    sjs_string sjt_call16 = { -1 };
    sjs_shader* sjt_functionParam100 = 0;
    sjs_string* sjt_functionParam101 = 0;
    sjs_mat4* sjt_functionParam102 = 0;
    sjs_shader* sjt_functionParam84 = 0;
    int32_t sjt_functionParam85;
    int32_t sjt_functionParam86;
    int32_t sjt_functionParam87;
    sjs_shader* sjt_functionParam88 = 0;
    sjs_string* sjt_functionParam89 = 0;
    int32_t sjt_functionParam90;
    int32_t sjt_functionParam91;
    sjs_shader* sjt_functionParam92 = 0;
    sjs_string* sjt_functionParam93 = 0;
    sjs_mat4* sjt_functionParam94 = 0;
    int32_t sjt_functionParam95;
    sjs_shader* sjt_functionParam96 = 0;
    sjs_string* sjt_functionParam97 = 0;
    sjs_mat4* sjt_functionParam98 = 0;
    int32_t sjt_functionParam99;

#line 12 "lib/sj-lib-ui/textRenderer.sj"
    glBindTexture(GL_TEXTURE_2D, _parent->font->atlas->id);
#line 14
    sjt_functionParam84 = &g_textshader;
#line 14
    sjf_gluseprogram(sjt_functionParam84);
#line 15
    sjt_functionParam85 = g_glblendfunctype_gl_src_alpha;
#line 15
    sjt_functionParam86 = g_glblendfunctype_gl_one_minus_src_alpha;
#line 15
    sjf_glblendfunc(sjt_functionParam85, sjt_functionParam86);
#line 16
    sjt_functionParam88 = &g_textshader;
#line 16
    sjt_call13._refCount = 1;
#line 16
    sjt_call13.offset = 0;
#line 16
    sjt_call13.count = 7;
#line 16
    sjt_call13.data._refCount = 1;
#line 16
    sjt_call13.data.v = &sjg_string17;
#line 16
    sjf_array_char(&sjt_call13.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call13._isnullterminated = false;
#line 16
    sjf_string(&sjt_call13);
#line 16 "lib/sj-lib-ui/textRenderer.sj"
    sjt_functionParam89 = &sjt_call13;
#line 16
    sjf_glgetuniformlocation(sjt_functionParam88, sjt_functionParam89, &sjt_functionParam87);
#line 16
    sjt_functionParam90 = 0;
#line 16
    sjf_gluniformi32(sjt_functionParam87, sjt_functionParam90);
#line 17
    sjt_functionParam92 = &g_textshader;
#line 17
    sjt_call14._refCount = 1;
#line 17
    sjt_call14.offset = 0;
#line 17
    sjt_call14.count = 5;
#line 17
    sjt_call14.data._refCount = 1;
#line 17
    sjt_call14.data.v = &sjg_string18;
#line 17
    sjf_array_char(&sjt_call14.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call14._isnullterminated = false;
#line 16
    sjf_string(&sjt_call14);
#line 17 "lib/sj-lib-ui/textRenderer.sj"
    sjt_functionParam93 = &sjt_call14;
#line 17
    sjf_glgetuniformlocation(sjt_functionParam92, sjt_functionParam93, &sjt_functionParam91);
#line 17
    sjt_functionParam94 = &scene->model;
#line 17
    sjf_gluniformmat4(sjt_functionParam91, sjt_functionParam94);
#line 18
    sjt_functionParam96 = &g_textshader;
#line 18
    sjt_call15._refCount = 1;
#line 18
    sjt_call15.offset = 0;
#line 18
    sjt_call15.count = 4;
#line 18
    sjt_call15.data._refCount = 1;
#line 18
    sjt_call15.data.v = &sjg_string19;
#line 18
    sjf_array_char(&sjt_call15.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call15._isnullterminated = false;
#line 16
    sjf_string(&sjt_call15);
#line 18 "lib/sj-lib-ui/textRenderer.sj"
    sjt_functionParam97 = &sjt_call15;
#line 18
    sjf_glgetuniformlocation(sjt_functionParam96, sjt_functionParam97, &sjt_functionParam95);
#line 18
    sjt_functionParam98 = &scene->view;
#line 18
    sjf_gluniformmat4(sjt_functionParam95, sjt_functionParam98);
#line 19
    sjt_functionParam100 = &g_textshader;
#line 19
    sjt_call16._refCount = 1;
#line 19
    sjt_call16.offset = 0;
#line 19
    sjt_call16.count = 10;
#line 19
    sjt_call16.data._refCount = 1;
#line 19
    sjt_call16.data.v = &sjg_string20;
#line 19
    sjf_array_char(&sjt_call16.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call16._isnullterminated = false;
#line 16
    sjf_string(&sjt_call16);
#line 19 "lib/sj-lib-ui/textRenderer.sj"
    sjt_functionParam101 = &sjt_call16;
#line 19
    sjf_glgetuniformlocation(sjt_functionParam100, sjt_functionParam101, &sjt_functionParam99);
#line 19
    sjt_functionParam102 = &scene->projection;
#line 19
    sjf_gluniformmat4(sjt_functionParam99, sjt_functionParam102);
#line 21
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);

    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
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

void sjf_vec3(sjs_vec3* _this) {
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
#line 1 "lib/sj-lib-ui/vec3.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->z = _from->z;
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_heap(sjs_vec3* _this) {
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
    sjs_borderchild_borderchild_vtbl.destroy = (void(*)(void*))sjf_borderchild_destroy;
    sjs_borderchild_borderchild_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderchild_asinterface;
    sjs_borderchild_borderchild_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_borderchild_getclasstype;
    sjs_borderchild_borderchild_vtbl.getposition = (void(*)(sjs_object*, int32_t*))sjf_borderchild_getposition;
    sjs_borderchild_element_vtbl.destroy = (void(*)(void*))sjf_borderchild_destroy;
    sjs_borderchild_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderchild_asinterface;
    sjs_borderchild_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_borderchild_getclasstype;
    sjs_borderchild_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_borderchild_getsize;
    sjs_borderchild_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_borderchild_getsize_heap;
    sjs_borderchild_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_borderchild_getrect;
    sjs_borderchild_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_borderchild_getrect_heap;
    sjs_borderchild_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_borderchild_setrect;
    sjs_borderchild_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_borderchild_render;
    sjs_borderchild_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_borderchild_firemouseevent;
    sjs_borderlayout_element_vtbl.destroy = (void(*)(void*))sjf_borderlayout_destroy;
    sjs_borderlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_borderlayout_asinterface;
    sjs_borderlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_borderlayout_getclasstype;
    sjs_borderlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_borderlayout_getsize;
    sjs_borderlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_borderlayout_getsize_heap;
    sjs_borderlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_borderlayout_getrect;
    sjs_borderlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_borderlayout_getrect_heap;
    sjs_borderlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_borderlayout_setrect;
    sjs_borderlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_borderlayout_render;
    sjs_borderlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_borderlayout_firemouseevent;
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
    sjs_centerlayout_element_vtbl.destroy = (void(*)(void*))sjf_centerlayout_destroy;
    sjs_centerlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_centerlayout_asinterface;
    sjs_centerlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_centerlayout_getclasstype;
    sjs_centerlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_centerlayout_getsize;
    sjs_centerlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_centerlayout_getsize_heap;
    sjs_centerlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_centerlayout_getrect;
    sjs_centerlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_centerlayout_getrect_heap;
    sjs_centerlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_centerlayout_setrect;
    sjs_centerlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_centerlayout_render;
    sjs_centerlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_centerlayout_firemouseevent;
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
    sjs_flowlayout_element_vtbl.destroy = (void(*)(void*))sjf_flowlayout_destroy;
    sjs_flowlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_flowlayout_asinterface;
    sjs_flowlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_flowlayout_getclasstype;
    sjs_flowlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_flowlayout_getsize;
    sjs_flowlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_flowlayout_getsize_heap;
    sjs_flowlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_flowlayout_getrect;
    sjs_flowlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_flowlayout_getrect_heap;
    sjs_flowlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_flowlayout_setrect;
    sjs_flowlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_flowlayout_render;
    sjs_flowlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_flowlayout_firemouseevent;
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
    sjs_listlayout_element_vtbl.destroy = (void(*)(void*))sjf_listlayout_destroy;
    sjs_listlayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_listlayout_asinterface;
    sjs_listlayout_element_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_listlayout_getclasstype;
    sjs_listlayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_listlayout_getsize;
    sjs_listlayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_listlayout_getsize_heap;
    sjs_listlayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_listlayout_getrect;
    sjs_listlayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_listlayout_getrect_heap;
    sjs_listlayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_listlayout_setrect;
    sjs_listlayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_listlayout_render;
    sjs_listlayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_listlayout_firemouseevent;
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
#line 31 "layout.sj"
    sjt_call3->children.v = createarray(sizeof(sji_element), 5);
#line 31
    sjf_array_heap_iface_element(&sjt_call3->children);
#line 31
    sjs_array_heap_iface_element* array8;
#line 31
    array8 = &sjt_call3->children;
#line 31
    sjt_parent41 = array8;
#line 31
    sjt_functionParam45 = 0;
#line 31
    sjt_call5 = (sjs_gridlayout*)malloc(sizeof(sjs_gridlayout));
#line 31
    sjt_call5->_refCount = 1;
#line 31
    sjt_call5->children._refCount = 1;
#line 42
    sjt_call5->children.v = createarray(sizeof(sji_element), 4);
#line 42
    sjf_array_heap_iface_element(&sjt_call5->children);
#line 42
    sjs_array_heap_iface_element* array7;
#line 42
    array7 = &sjt_call5->children;
#line 42
    sjt_parent42 = array7;
#line 42
    sjt_functionParam47 = 0;
#line 42
    sjt_call18._refCount = 1;
#line 43
    sjt_call18.offset = 0;
#line 43
    sjt_call18.count = 1;
#line 43
    sjt_call18.data._refCount = 1;
#line 43
    sjt_call18.data.v = &sjg_string21;
#line 43
    sjf_array_char(&sjt_call18.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call18._isnullterminated = false;
#line 16
    sjf_string(&sjt_call18);
#line 43 "layout.sj"
    sjt_functionParam109 = &sjt_call18;
#line 43
    sjf_testelement_heap(sjt_functionParam109, &sjt_functionParam48);
#line 43
    sjf_array_heap_iface_element_initat(sjt_parent42, sjt_functionParam47, sjt_functionParam48);
#line 42
    sjt_parent87 = array7;
#line 42
    sjt_functionParam110 = 1;
#line 42
    sjt_call19._refCount = 1;
#line 44
    sjt_call19.offset = 0;
#line 44
    sjt_call19.count = 1;
#line 44
    sjt_call19.data._refCount = 1;
#line 44
    sjt_call19.data.v = &sjg_string22;
#line 44
    sjf_array_char(&sjt_call19.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call19._isnullterminated = false;
#line 16
    sjf_string(&sjt_call19);
#line 44 "layout.sj"
    sjt_functionParam112 = &sjt_call19;
#line 44
    sjf_testelement_heap(sjt_functionParam112, &sjt_functionParam111);
#line 44
    sjf_array_heap_iface_element_initat(sjt_parent87, sjt_functionParam110, sjt_functionParam111);
#line 42
    sjt_parent88 = array7;
#line 42
    sjt_functionParam113 = 2;
#line 42
    sjt_call20._refCount = 1;
#line 45
    sjt_call20.offset = 0;
#line 45
    sjt_call20.count = 1;
#line 45
    sjt_call20.data._refCount = 1;
#line 45
    sjt_call20.data.v = &sjg_string23;
#line 45
    sjf_array_char(&sjt_call20.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call20._isnullterminated = false;
#line 16
    sjf_string(&sjt_call20);
#line 45 "layout.sj"
    sjt_functionParam115 = &sjt_call20;
#line 45
    sjf_testelement_heap(sjt_functionParam115, &sjt_functionParam114);
#line 45
    sjf_array_heap_iface_element_initat(sjt_parent88, sjt_functionParam113, sjt_functionParam114);
#line 42
    sjt_parent89 = array7;
#line 42
    sjt_functionParam116 = 3;
#line 42
    sjt_call21._refCount = 1;
#line 46
    sjt_call21.offset = 0;
#line 46
    sjt_call21.count = 1;
#line 46
    sjt_call21.data._refCount = 1;
#line 46
    sjt_call21.data.v = &sjg_string24;
#line 46
    sjf_array_char(&sjt_call21.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call21._isnullterminated = false;
#line 16
    sjf_string(&sjt_call21);
#line 46 "layout.sj"
    sjt_functionParam118 = &sjt_call21;
#line 46
    sjf_testelement_heap(sjt_functionParam118, &sjt_functionParam117);
#line 46
    sjf_array_heap_iface_element_initat(sjt_parent89, sjt_functionParam116, sjt_functionParam117);
#line 46
    sjt_call5->margin._refCount = 1;
#line 33
    sjt_call5->margin.l = 10;
#line 33
    sjt_call5->margin.t = 10;
#line 33
    sjt_call5->margin.r = 10;
#line 33
    sjt_call5->margin.b = 10;
#line 33
    sjf_margin(&sjt_call5->margin);
#line 33
    sjt_call5->cols._refCount = 1;
#line 38
    sjt_call5->cols.v = createarray(sizeof(sjs_gridunit), 2);
#line 38
    sjf_array_gridunit(&sjt_call5->cols);
#line 38
    sjs_array_gridunit* array4;
#line 38
    array4 = &sjt_call5->cols;
#line 38
    sjt_parent90 = array4;
#line 38
    sjt_functionParam119 = 0;
#line 38
    sjt_call22._refCount = 1;
#line 39
    sjt_call22.amount = 1;
#line 39
    sjt_call22.unittype = g_gridunittype_star;
#line 39
    sjf_gridunit(&sjt_call22);
#line 39
    sjt_functionParam120 = &sjt_call22;
#line 39
    sjf_array_gridunit_initat(sjt_parent90, sjt_functionParam119, sjt_functionParam120);
#line 38
    sjt_parent91 = array4;
#line 38
    sjt_functionParam121 = 1;
#line 38
    sjt_call23._refCount = 1;
#line 40
    sjt_call23.amount = 50;
#line 40
    sjt_call23.unittype = g_gridunittype_fixed;
#line 40
    sjf_gridunit(&sjt_call23);
#line 40
    sjt_functionParam122 = &sjt_call23;
#line 40
    sjf_array_gridunit_initat(sjt_parent91, sjt_functionParam121, sjt_functionParam122);
#line 40
    sjt_call5->rows._refCount = 1;
#line 34
    sjt_call5->rows.v = createarray(sizeof(sjs_gridunit), 2);
#line 34
    sjf_array_gridunit(&sjt_call5->rows);
#line 34
    sjs_array_gridunit* array3;
#line 34
    array3 = &sjt_call5->rows;
#line 34
    sjt_parent92 = array3;
#line 34
    sjt_functionParam123 = 0;
#line 34
    sjt_call24._refCount = 1;
#line 35
    sjt_call24.amount = 50;
#line 35
    sjt_call24.unittype = g_gridunittype_fixed;
#line 35
    sjf_gridunit(&sjt_call24);
#line 35
    sjt_functionParam124 = &sjt_call24;
#line 35
    sjf_array_gridunit_initat(sjt_parent92, sjt_functionParam123, sjt_functionParam124);
#line 34
    sjt_parent93 = array3;
#line 34
    sjt_functionParam125 = 1;
#line 34
    sjt_call25._refCount = 1;
#line 36
    sjt_call25.amount = 1;
#line 36
    sjt_call25.unittype = g_gridunittype_star;
#line 36
    sjf_gridunit(&sjt_call25);
#line 36
    sjt_functionParam126 = &sjt_call25;
#line 36
    sjf_array_gridunit_initat(sjt_parent93, sjt_functionParam125, sjt_functionParam126);
#line 36
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
    sjf_gridlayout_heap(sjt_call5);
#line 32 "layout.sj"
    sjt_cast4 = sjt_call5;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_gridlayout_as_sji_element(sjt_cast4, &sjt_functionParam46);
    if (sjt_functionParam46._parent != 0) {
        sjt_functionParam46._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent41, sjt_functionParam45, sjt_functionParam46);
#line 31 "layout.sj"
    sjt_parent94 = array8;
#line 31
    sjt_functionParam127 = 1;
#line 31
    sjt_call26 = (sjs_borderlayout*)malloc(sizeof(sjs_borderlayout));
#line 31
    sjt_call26->_refCount = 1;
#line 31
    sjt_call26->children._refCount = 1;
#line 52
    sjt_call26->children.v = createarray(sizeof(sji_element), 5);
#line 52
    sjf_array_heap_iface_element(&sjt_call26->children);
#line 52
    sjs_array_heap_iface_element* array9;
#line 52
    array9 = &sjt_call26->children;
#line 52
    sjt_parent114 = array9;
#line 52
    sjt_functionParam134 = 0;
#line 52
    sjt_call32 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
#line 52
    sjt_call32->_refCount = 1;
#line 52
    sjt_call33._refCount = 1;
#line 55
    sjt_call33.offset = 0;
#line 55
    sjt_call33.count = 4;
#line 55
    sjt_call33.data._refCount = 1;
#line 55
    sjt_call33.data.v = &sjg_string25;
#line 55
    sjf_array_char(&sjt_call33.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call33._isnullterminated = false;
#line 16
    sjf_string(&sjt_call33);
#line 55 "layout.sj"
    sjt_functionParam136 = &sjt_call33;
#line 55
    sjf_testelement_heap(sjt_functionParam136, &sjt_call32->child);
#line 53
    sjt_call32->position = g_borderposition_left;
#line 53
    sjt_call32->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call32->_rect.x = 0;
#line 3
    sjt_call32->_rect.y = 0;
#line 4
    sjt_call32->_rect.w = 0;
#line 5
    sjt_call32->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call32->_rect);
#line 5
    sjf_borderchild_heap(sjt_call32);
#line 53 "layout.sj"
    sjt_cast12 = sjt_call32;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_borderchild_as_sji_element(sjt_cast12, &sjt_functionParam135);
    if (sjt_functionParam135._parent != 0) {
        sjt_functionParam135._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent114, sjt_functionParam134, sjt_functionParam135);
#line 52 "layout.sj"
    sjt_parent120 = array9;
#line 52
    sjt_functionParam137 = 1;
#line 52
    sjt_call34 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
#line 52
    sjt_call34->_refCount = 1;
#line 52
    sjt_call35._refCount = 1;
#line 60
    sjt_call35.offset = 0;
#line 60
    sjt_call35.count = 6;
#line 60
    sjt_call35.data._refCount = 1;
#line 60
    sjt_call35.data.v = &sjg_string26;
#line 60
    sjf_array_char(&sjt_call35.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call35._isnullterminated = false;
#line 16
    sjf_string(&sjt_call35);
#line 60 "layout.sj"
    sjt_functionParam139 = &sjt_call35;
#line 60
    sjf_testelement_heap(sjt_functionParam139, &sjt_call34->child);
#line 58
    sjt_call34->position = g_borderposition_bottom;
#line 58
    sjt_call34->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call34->_rect.x = 0;
#line 3
    sjt_call34->_rect.y = 0;
#line 4
    sjt_call34->_rect.w = 0;
#line 5
    sjt_call34->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call34->_rect);
#line 5
    sjf_borderchild_heap(sjt_call34);
#line 58 "layout.sj"
    sjt_cast13 = sjt_call34;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_borderchild_as_sji_element(sjt_cast13, &sjt_functionParam138);
    if (sjt_functionParam138._parent != 0) {
        sjt_functionParam138._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent120, sjt_functionParam137, sjt_functionParam138);
#line 52 "layout.sj"
    sjt_parent121 = array9;
#line 52
    sjt_functionParam140 = 2;
#line 52
    sjt_call36 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
#line 52
    sjt_call36->_refCount = 1;
#line 52
    sjt_call37._refCount = 1;
#line 65
    sjt_call37.offset = 0;
#line 65
    sjt_call37.count = 3;
#line 65
    sjt_call37.data._refCount = 1;
#line 65
    sjt_call37.data.v = &sjg_string27;
#line 65
    sjf_array_char(&sjt_call37.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call37._isnullterminated = false;
#line 16
    sjf_string(&sjt_call37);
#line 65 "layout.sj"
    sjt_functionParam142 = &sjt_call37;
#line 65
    sjf_testelement_heap(sjt_functionParam142, &sjt_call36->child);
#line 63
    sjt_call36->position = g_borderposition_top;
#line 63
    sjt_call36->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call36->_rect.x = 0;
#line 3
    sjt_call36->_rect.y = 0;
#line 4
    sjt_call36->_rect.w = 0;
#line 5
    sjt_call36->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call36->_rect);
#line 5
    sjf_borderchild_heap(sjt_call36);
#line 63 "layout.sj"
    sjt_cast14 = sjt_call36;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_borderchild_as_sji_element(sjt_cast14, &sjt_functionParam141);
    if (sjt_functionParam141._parent != 0) {
        sjt_functionParam141._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent121, sjt_functionParam140, sjt_functionParam141);
#line 52 "layout.sj"
    sjt_parent122 = array9;
#line 52
    sjt_functionParam143 = 3;
#line 52
    sjt_call38 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
#line 52
    sjt_call38->_refCount = 1;
#line 52
    sjt_call39._refCount = 1;
#line 70
    sjt_call39.offset = 0;
#line 70
    sjt_call39.count = 5;
#line 70
    sjt_call39.data._refCount = 1;
#line 70
    sjt_call39.data.v = &sjg_string28;
#line 70
    sjf_array_char(&sjt_call39.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call39._isnullterminated = false;
#line 16
    sjf_string(&sjt_call39);
#line 70 "layout.sj"
    sjt_functionParam145 = &sjt_call39;
#line 70
    sjf_testelement_heap(sjt_functionParam145, &sjt_call38->child);
#line 68
    sjt_call38->position = g_borderposition_right;
#line 68
    sjt_call38->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call38->_rect.x = 0;
#line 3
    sjt_call38->_rect.y = 0;
#line 4
    sjt_call38->_rect.w = 0;
#line 5
    sjt_call38->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call38->_rect);
#line 5
    sjf_borderchild_heap(sjt_call38);
#line 68 "layout.sj"
    sjt_cast15 = sjt_call38;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_borderchild_as_sji_element(sjt_cast15, &sjt_functionParam144);
    if (sjt_functionParam144._parent != 0) {
        sjt_functionParam144._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent122, sjt_functionParam143, sjt_functionParam144);
#line 52 "layout.sj"
    sjt_parent123 = array9;
#line 52
    sjt_functionParam146 = 4;
#line 52
    sjt_call40 = (sjs_borderchild*)malloc(sizeof(sjs_borderchild));
#line 52
    sjt_call40->_refCount = 1;
#line 52
    sjt_call41._refCount = 1;
#line 75
    sjt_call41.offset = 0;
#line 75
    sjt_call41.count = 4;
#line 75
    sjt_call41.data._refCount = 1;
#line 75
    sjt_call41.data.v = &sjg_string29;
#line 75
    sjf_array_char(&sjt_call41.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call41._isnullterminated = false;
#line 16
    sjf_string(&sjt_call41);
#line 75 "layout.sj"
    sjt_functionParam148 = &sjt_call41;
#line 75
    sjf_testelement_heap(sjt_functionParam148, &sjt_call40->child);
#line 73
    sjt_call40->position = g_borderposition_fill;
#line 73
    sjt_call40->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call40->_rect.x = 0;
#line 3
    sjt_call40->_rect.y = 0;
#line 4
    sjt_call40->_rect.w = 0;
#line 5
    sjt_call40->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call40->_rect);
#line 5
    sjf_borderchild_heap(sjt_call40);
#line 73 "layout.sj"
    sjt_cast16 = sjt_call40;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_borderchild_as_sji_element(sjt_cast16, &sjt_functionParam147);
    if (sjt_functionParam147._parent != 0) {
        sjt_functionParam147._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent123, sjt_functionParam146, sjt_functionParam147);
#line 1
    sjt_call26->margin._refCount = 1;
#line 51 "layout.sj"
    sjt_call26->margin.l = 10;
#line 51
    sjt_call26->margin.t = 10;
#line 51
    sjt_call26->margin.r = 10;
#line 51
    sjt_call26->margin.b = 10;
#line 51
    sjf_margin(&sjt_call26->margin);
#line 51
    sjt_call26->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call26->_rect.x = 0;
#line 3
    sjt_call26->_rect.y = 0;
#line 4
    sjt_call26->_rect.w = 0;
#line 5
    sjt_call26->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call26->_rect);
#line 5
    sjf_borderlayout_heap(sjt_call26);
#line 50 "layout.sj"
    sjt_cast9 = sjt_call26;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_borderlayout_as_sji_element(sjt_cast9, &sjt_functionParam128);
    if (sjt_functionParam128._parent != 0) {
        sjt_functionParam128._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent94, sjt_functionParam127, sjt_functionParam128);
#line 31 "layout.sj"
    sjt_parent124 = array8;
#line 31
    sjt_functionParam149 = 2;
#line 31
    sjt_call42 = (sjs_listlayout*)malloc(sizeof(sjs_listlayout));
#line 31
    sjt_call42->_refCount = 1;
#line 31
    sjt_call42->children._refCount = 1;
#line 82
    sjt_call42->children.v = createarray(sizeof(sji_element), 4);
#line 82
    sjf_array_heap_iface_element(&sjt_call42->children);
#line 82
    sjs_array_heap_iface_element* array10;
#line 82
    array10 = &sjt_call42->children;
#line 82
    sjt_parent140 = array10;
#line 82
    sjt_functionParam155 = 0;
#line 82
    sjt_call51._refCount = 1;
#line 83
    sjt_call51.offset = 0;
#line 83
    sjt_call51.count = 1;
#line 83
    sjt_call51.data._refCount = 1;
#line 83
    sjt_call51.data.v = &sjg_string21;
#line 83
    sjf_array_char(&sjt_call51.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call51._isnullterminated = false;
#line 16
    sjf_string(&sjt_call51);
#line 83 "layout.sj"
    sjt_functionParam157 = &sjt_call51;
#line 83
    sjf_testelement_heap(sjt_functionParam157, &sjt_functionParam156);
#line 83
    sjf_array_heap_iface_element_initat(sjt_parent140, sjt_functionParam155, sjt_functionParam156);
#line 82
    sjt_parent141 = array10;
#line 82
    sjt_functionParam158 = 1;
#line 82
    sjt_call52._refCount = 1;
#line 84
    sjt_call52.offset = 0;
#line 84
    sjt_call52.count = 1;
#line 84
    sjt_call52.data._refCount = 1;
#line 84
    sjt_call52.data.v = &sjg_string22;
#line 84
    sjf_array_char(&sjt_call52.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call52._isnullterminated = false;
#line 16
    sjf_string(&sjt_call52);
#line 84 "layout.sj"
    sjt_functionParam160 = &sjt_call52;
#line 84
    sjf_testelement_heap(sjt_functionParam160, &sjt_functionParam159);
#line 84
    sjf_array_heap_iface_element_initat(sjt_parent141, sjt_functionParam158, sjt_functionParam159);
#line 82
    sjt_parent142 = array10;
#line 82
    sjt_functionParam161 = 2;
#line 82
    sjt_call53._refCount = 1;
#line 85
    sjt_call53.offset = 0;
#line 85
    sjt_call53.count = 1;
#line 85
    sjt_call53.data._refCount = 1;
#line 85
    sjt_call53.data.v = &sjg_string23;
#line 85
    sjf_array_char(&sjt_call53.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call53._isnullterminated = false;
#line 16
    sjf_string(&sjt_call53);
#line 85 "layout.sj"
    sjt_functionParam163 = &sjt_call53;
#line 85
    sjf_testelement_heap(sjt_functionParam163, &sjt_functionParam162);
#line 85
    sjf_array_heap_iface_element_initat(sjt_parent142, sjt_functionParam161, sjt_functionParam162);
#line 82
    sjt_parent143 = array10;
#line 82
    sjt_functionParam164 = 3;
#line 82
    sjt_call54._refCount = 1;
#line 86
    sjt_call54.offset = 0;
#line 86
    sjt_call54.count = 1;
#line 86
    sjt_call54.data._refCount = 1;
#line 86
    sjt_call54.data.v = &sjg_string24;
#line 86
    sjf_array_char(&sjt_call54.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call54._isnullterminated = false;
#line 16
    sjf_string(&sjt_call54);
#line 86 "layout.sj"
    sjt_functionParam166 = &sjt_call54;
#line 86
    sjf_testelement_heap(sjt_functionParam166, &sjt_functionParam165);
#line 86
    sjf_array_heap_iface_element_initat(sjt_parent143, sjt_functionParam164, sjt_functionParam165);
#line 86
    sjt_call42->margin._refCount = 1;
#line 81
    sjt_call42->margin.l = 10;
#line 81
    sjt_call42->margin.t = 10;
#line 81
    sjt_call42->margin.r = 10;
#line 81
    sjt_call42->margin.b = 10;
#line 81
    sjf_margin(&sjt_call42->margin);
#line 8 "lib/sj-lib-ui/listLayout.sj"
    sjt_call42->orientation = g_listlayoutorientation_leftright;
#line 8
    sjt_call42->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call42->_rect.x = 0;
#line 3
    sjt_call42->_rect.y = 0;
#line 4
    sjt_call42->_rect.w = 0;
#line 5
    sjt_call42->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call42->_rect);
#line 5
    sjf_listlayout_heap(sjt_call42);
#line 80 "layout.sj"
    sjt_cast17 = sjt_call42;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_listlayout_as_sji_element(sjt_cast17, &sjt_functionParam150);
    if (sjt_functionParam150._parent != 0) {
        sjt_functionParam150._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent124, sjt_functionParam149, sjt_functionParam150);
#line 31 "layout.sj"
    sjt_parent144 = array8;
#line 31
    sjt_functionParam167 = 3;
#line 31
    sjt_call55 = (sjs_flowlayout*)malloc(sizeof(sjs_flowlayout));
#line 31
    sjt_call55->_refCount = 1;
#line 31
    sjt_call55->children._refCount = 1;
#line 92
    sjt_call55->children.v = createarray(sizeof(sji_element), 20);
#line 92
    sjf_array_heap_iface_element(&sjt_call55->children);
#line 92
    sjs_array_heap_iface_element* array11;
#line 92
    array11 = &sjt_call55->children;
#line 92
    sjt_parent160 = array11;
#line 92
    sjt_functionParam181 = 0;
#line 92
    sjt_call64._refCount = 1;
#line 93
    sjt_call64.offset = 0;
#line 93
    sjt_call64.count = 1;
#line 93
    sjt_call64.data._refCount = 1;
#line 93
    sjt_call64.data.v = &sjg_string21;
#line 93
    sjf_array_char(&sjt_call64.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call64._isnullterminated = false;
#line 16
    sjf_string(&sjt_call64);
#line 93 "layout.sj"
    sjt_functionParam183 = &sjt_call64;
#line 93
    sjf_testelement_heap(sjt_functionParam183, &sjt_functionParam182);
#line 93
    sjf_array_heap_iface_element_initat(sjt_parent160, sjt_functionParam181, sjt_functionParam182);
#line 92
    sjt_parent161 = array11;
#line 92
    sjt_functionParam184 = 1;
#line 92
    sjt_call65._refCount = 1;
#line 94
    sjt_call65.offset = 0;
#line 94
    sjt_call65.count = 1;
#line 94
    sjt_call65.data._refCount = 1;
#line 94
    sjt_call65.data.v = &sjg_string22;
#line 94
    sjf_array_char(&sjt_call65.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call65._isnullterminated = false;
#line 16
    sjf_string(&sjt_call65);
#line 94 "layout.sj"
    sjt_functionParam186 = &sjt_call65;
#line 94
    sjf_testelement_heap(sjt_functionParam186, &sjt_functionParam185);
#line 94
    sjf_array_heap_iface_element_initat(sjt_parent161, sjt_functionParam184, sjt_functionParam185);
#line 92
    sjt_parent162 = array11;
#line 92
    sjt_functionParam187 = 2;
#line 92
    sjt_call66._refCount = 1;
#line 95
    sjt_call66.offset = 0;
#line 95
    sjt_call66.count = 1;
#line 95
    sjt_call66.data._refCount = 1;
#line 95
    sjt_call66.data.v = &sjg_string23;
#line 95
    sjf_array_char(&sjt_call66.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call66._isnullterminated = false;
#line 16
    sjf_string(&sjt_call66);
#line 95 "layout.sj"
    sjt_functionParam189 = &sjt_call66;
#line 95
    sjf_testelement_heap(sjt_functionParam189, &sjt_functionParam188);
#line 95
    sjf_array_heap_iface_element_initat(sjt_parent162, sjt_functionParam187, sjt_functionParam188);
#line 92
    sjt_parent163 = array11;
#line 92
    sjt_functionParam190 = 3;
#line 92
    sjt_call67._refCount = 1;
#line 96
    sjt_call67.offset = 0;
#line 96
    sjt_call67.count = 1;
#line 96
    sjt_call67.data._refCount = 1;
#line 96
    sjt_call67.data.v = &sjg_string24;
#line 96
    sjf_array_char(&sjt_call67.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call67._isnullterminated = false;
#line 16
    sjf_string(&sjt_call67);
#line 96 "layout.sj"
    sjt_functionParam192 = &sjt_call67;
#line 96
    sjf_testelement_heap(sjt_functionParam192, &sjt_functionParam191);
#line 96
    sjf_array_heap_iface_element_initat(sjt_parent163, sjt_functionParam190, sjt_functionParam191);
#line 92
    sjt_parent164 = array11;
#line 92
    sjt_functionParam193 = 4;
#line 92
    sjt_call68._refCount = 1;
#line 97
    sjt_call68.offset = 0;
#line 97
    sjt_call68.count = 1;
#line 97
    sjt_call68.data._refCount = 1;
#line 97
    sjt_call68.data.v = &sjg_string21;
#line 97
    sjf_array_char(&sjt_call68.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call68._isnullterminated = false;
#line 16
    sjf_string(&sjt_call68);
#line 97 "layout.sj"
    sjt_functionParam195 = &sjt_call68;
#line 97
    sjf_testelement_heap(sjt_functionParam195, &sjt_functionParam194);
#line 97
    sjf_array_heap_iface_element_initat(sjt_parent164, sjt_functionParam193, sjt_functionParam194);
#line 92
    sjt_parent165 = array11;
#line 92
    sjt_functionParam196 = 5;
#line 92
    sjt_call69._refCount = 1;
#line 98
    sjt_call69.offset = 0;
#line 98
    sjt_call69.count = 1;
#line 98
    sjt_call69.data._refCount = 1;
#line 98
    sjt_call69.data.v = &sjg_string22;
#line 98
    sjf_array_char(&sjt_call69.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call69._isnullterminated = false;
#line 16
    sjf_string(&sjt_call69);
#line 98 "layout.sj"
    sjt_functionParam198 = &sjt_call69;
#line 98
    sjf_testelement_heap(sjt_functionParam198, &sjt_functionParam197);
#line 98
    sjf_array_heap_iface_element_initat(sjt_parent165, sjt_functionParam196, sjt_functionParam197);
#line 92
    sjt_parent166 = array11;
#line 92
    sjt_functionParam199 = 6;
#line 92
    sjt_call70._refCount = 1;
#line 99
    sjt_call70.offset = 0;
#line 99
    sjt_call70.count = 1;
#line 99
    sjt_call70.data._refCount = 1;
#line 99
    sjt_call70.data.v = &sjg_string23;
#line 99
    sjf_array_char(&sjt_call70.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call70._isnullterminated = false;
#line 16
    sjf_string(&sjt_call70);
#line 99 "layout.sj"
    sjt_functionParam201 = &sjt_call70;
#line 99
    sjf_testelement_heap(sjt_functionParam201, &sjt_functionParam200);
#line 99
    sjf_array_heap_iface_element_initat(sjt_parent166, sjt_functionParam199, sjt_functionParam200);
#line 92
    sjt_parent167 = array11;
#line 92
    sjt_functionParam202 = 7;
#line 92
    sjt_call71._refCount = 1;
#line 100
    sjt_call71.offset = 0;
#line 100
    sjt_call71.count = 1;
#line 100
    sjt_call71.data._refCount = 1;
#line 100
    sjt_call71.data.v = &sjg_string24;
#line 100
    sjf_array_char(&sjt_call71.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call71._isnullterminated = false;
#line 16
    sjf_string(&sjt_call71);
#line 100 "layout.sj"
    sjt_functionParam204 = &sjt_call71;
#line 100
    sjf_testelement_heap(sjt_functionParam204, &sjt_functionParam203);
#line 100
    sjf_array_heap_iface_element_initat(sjt_parent167, sjt_functionParam202, sjt_functionParam203);
#line 92
    sjt_parent168 = array11;
#line 92
    sjt_functionParam205 = 8;
#line 92
    sjt_call72._refCount = 1;
#line 101
    sjt_call72.offset = 0;
#line 101
    sjt_call72.count = 1;
#line 101
    sjt_call72.data._refCount = 1;
#line 101
    sjt_call72.data.v = &sjg_string21;
#line 101
    sjf_array_char(&sjt_call72.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call72._isnullterminated = false;
#line 16
    sjf_string(&sjt_call72);
#line 101 "layout.sj"
    sjt_functionParam207 = &sjt_call72;
#line 101
    sjf_testelement_heap(sjt_functionParam207, &sjt_functionParam206);
#line 101
    sjf_array_heap_iface_element_initat(sjt_parent168, sjt_functionParam205, sjt_functionParam206);
#line 92
    sjt_parent169 = array11;
#line 92
    sjt_functionParam208 = 9;
#line 92
    sjt_call73._refCount = 1;
#line 102
    sjt_call73.offset = 0;
#line 102
    sjt_call73.count = 1;
#line 102
    sjt_call73.data._refCount = 1;
#line 102
    sjt_call73.data.v = &sjg_string22;
#line 102
    sjf_array_char(&sjt_call73.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call73._isnullterminated = false;
#line 16
    sjf_string(&sjt_call73);
#line 102 "layout.sj"
    sjt_functionParam210 = &sjt_call73;
#line 102
    sjf_testelement_heap(sjt_functionParam210, &sjt_functionParam209);
#line 102
    sjf_array_heap_iface_element_initat(sjt_parent169, sjt_functionParam208, sjt_functionParam209);
#line 92
    sjt_parent170 = array11;
#line 92
    sjt_functionParam211 = 10;
#line 92
    sjt_call74._refCount = 1;
#line 103
    sjt_call74.offset = 0;
#line 103
    sjt_call74.count = 1;
#line 103
    sjt_call74.data._refCount = 1;
#line 103
    sjt_call74.data.v = &sjg_string23;
#line 103
    sjf_array_char(&sjt_call74.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call74._isnullterminated = false;
#line 16
    sjf_string(&sjt_call74);
#line 103 "layout.sj"
    sjt_functionParam213 = &sjt_call74;
#line 103
    sjf_testelement_heap(sjt_functionParam213, &sjt_functionParam212);
#line 103
    sjf_array_heap_iface_element_initat(sjt_parent170, sjt_functionParam211, sjt_functionParam212);
#line 92
    sjt_parent171 = array11;
#line 92
    sjt_functionParam214 = 11;
#line 92
    sjt_call75._refCount = 1;
#line 104
    sjt_call75.offset = 0;
#line 104
    sjt_call75.count = 1;
#line 104
    sjt_call75.data._refCount = 1;
#line 104
    sjt_call75.data.v = &sjg_string24;
#line 104
    sjf_array_char(&sjt_call75.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call75._isnullterminated = false;
#line 16
    sjf_string(&sjt_call75);
#line 104 "layout.sj"
    sjt_functionParam216 = &sjt_call75;
#line 104
    sjf_testelement_heap(sjt_functionParam216, &sjt_functionParam215);
#line 104
    sjf_array_heap_iface_element_initat(sjt_parent171, sjt_functionParam214, sjt_functionParam215);
#line 92
    sjt_parent172 = array11;
#line 92
    sjt_functionParam217 = 12;
#line 92
    sjt_call76._refCount = 1;
#line 105
    sjt_call76.offset = 0;
#line 105
    sjt_call76.count = 1;
#line 105
    sjt_call76.data._refCount = 1;
#line 105
    sjt_call76.data.v = &sjg_string21;
#line 105
    sjf_array_char(&sjt_call76.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call76._isnullterminated = false;
#line 16
    sjf_string(&sjt_call76);
#line 105 "layout.sj"
    sjt_functionParam219 = &sjt_call76;
#line 105
    sjf_testelement_heap(sjt_functionParam219, &sjt_functionParam218);
#line 105
    sjf_array_heap_iface_element_initat(sjt_parent172, sjt_functionParam217, sjt_functionParam218);
#line 92
    sjt_parent173 = array11;
#line 92
    sjt_functionParam220 = 13;
#line 92
    sjt_call77._refCount = 1;
#line 106
    sjt_call77.offset = 0;
#line 106
    sjt_call77.count = 1;
#line 106
    sjt_call77.data._refCount = 1;
#line 106
    sjt_call77.data.v = &sjg_string22;
#line 106
    sjf_array_char(&sjt_call77.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call77._isnullterminated = false;
#line 16
    sjf_string(&sjt_call77);
#line 106 "layout.sj"
    sjt_functionParam222 = &sjt_call77;
#line 106
    sjf_testelement_heap(sjt_functionParam222, &sjt_functionParam221);
#line 106
    sjf_array_heap_iface_element_initat(sjt_parent173, sjt_functionParam220, sjt_functionParam221);
#line 92
    sjt_parent174 = array11;
#line 92
    sjt_functionParam223 = 14;
#line 92
    sjt_call78._refCount = 1;
#line 107
    sjt_call78.offset = 0;
#line 107
    sjt_call78.count = 1;
#line 107
    sjt_call78.data._refCount = 1;
#line 107
    sjt_call78.data.v = &sjg_string23;
#line 107
    sjf_array_char(&sjt_call78.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call78._isnullterminated = false;
#line 16
    sjf_string(&sjt_call78);
#line 107 "layout.sj"
    sjt_functionParam225 = &sjt_call78;
#line 107
    sjf_testelement_heap(sjt_functionParam225, &sjt_functionParam224);
#line 107
    sjf_array_heap_iface_element_initat(sjt_parent174, sjt_functionParam223, sjt_functionParam224);
#line 92
    sjt_parent175 = array11;
#line 92
    sjt_functionParam226 = 15;
#line 92
    sjt_call79._refCount = 1;
#line 108
    sjt_call79.offset = 0;
#line 108
    sjt_call79.count = 1;
#line 108
    sjt_call79.data._refCount = 1;
#line 108
    sjt_call79.data.v = &sjg_string24;
#line 108
    sjf_array_char(&sjt_call79.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call79._isnullterminated = false;
#line 16
    sjf_string(&sjt_call79);
#line 108 "layout.sj"
    sjt_functionParam228 = &sjt_call79;
#line 108
    sjf_testelement_heap(sjt_functionParam228, &sjt_functionParam227);
#line 108
    sjf_array_heap_iface_element_initat(sjt_parent175, sjt_functionParam226, sjt_functionParam227);
#line 92
    sjt_parent176 = array11;
#line 92
    sjt_functionParam229 = 16;
#line 92
    sjt_call80._refCount = 1;
#line 109
    sjt_call80.offset = 0;
#line 109
    sjt_call80.count = 1;
#line 109
    sjt_call80.data._refCount = 1;
#line 109
    sjt_call80.data.v = &sjg_string21;
#line 109
    sjf_array_char(&sjt_call80.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call80._isnullterminated = false;
#line 16
    sjf_string(&sjt_call80);
#line 109 "layout.sj"
    sjt_functionParam231 = &sjt_call80;
#line 109
    sjf_testelement_heap(sjt_functionParam231, &sjt_functionParam230);
#line 109
    sjf_array_heap_iface_element_initat(sjt_parent176, sjt_functionParam229, sjt_functionParam230);
#line 92
    sjt_parent177 = array11;
#line 92
    sjt_functionParam232 = 17;
#line 92
    sjt_call81._refCount = 1;
#line 110
    sjt_call81.offset = 0;
#line 110
    sjt_call81.count = 1;
#line 110
    sjt_call81.data._refCount = 1;
#line 110
    sjt_call81.data.v = &sjg_string22;
#line 110
    sjf_array_char(&sjt_call81.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call81._isnullterminated = false;
#line 16
    sjf_string(&sjt_call81);
#line 110 "layout.sj"
    sjt_functionParam234 = &sjt_call81;
#line 110
    sjf_testelement_heap(sjt_functionParam234, &sjt_functionParam233);
#line 110
    sjf_array_heap_iface_element_initat(sjt_parent177, sjt_functionParam232, sjt_functionParam233);
#line 92
    sjt_parent178 = array11;
#line 92
    sjt_functionParam235 = 18;
#line 92
    sjt_call82._refCount = 1;
#line 111
    sjt_call82.offset = 0;
#line 111
    sjt_call82.count = 1;
#line 111
    sjt_call82.data._refCount = 1;
#line 111
    sjt_call82.data.v = &sjg_string23;
#line 111
    sjf_array_char(&sjt_call82.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call82._isnullterminated = false;
#line 16
    sjf_string(&sjt_call82);
#line 111 "layout.sj"
    sjt_functionParam237 = &sjt_call82;
#line 111
    sjf_testelement_heap(sjt_functionParam237, &sjt_functionParam236);
#line 111
    sjf_array_heap_iface_element_initat(sjt_parent178, sjt_functionParam235, sjt_functionParam236);
#line 92
    sjt_parent179 = array11;
#line 92
    sjt_functionParam238 = 19;
#line 92
    sjt_call83._refCount = 1;
#line 112
    sjt_call83.offset = 0;
#line 112
    sjt_call83.count = 1;
#line 112
    sjt_call83.data._refCount = 1;
#line 112
    sjt_call83.data.v = &sjg_string24;
#line 112
    sjf_array_char(&sjt_call83.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call83._isnullterminated = false;
#line 16
    sjf_string(&sjt_call83);
#line 112 "layout.sj"
    sjt_functionParam240 = &sjt_call83;
#line 112
    sjf_testelement_heap(sjt_functionParam240, &sjt_functionParam239);
#line 112
    sjf_array_heap_iface_element_initat(sjt_parent179, sjt_functionParam238, sjt_functionParam239);
#line 112
    sjt_call55->margin._refCount = 1;
#line 91
    sjt_call55->margin.l = 10;
#line 91
    sjt_call55->margin.t = 10;
#line 91
    sjt_call55->margin.r = 10;
#line 91
    sjt_call55->margin.b = 10;
#line 91
    sjf_margin(&sjt_call55->margin);
#line 8 "lib/sj-lib-ui/flowLayout.sj"
    sjt_call55->orientation = g_flowlayoutorientation_leftright;
#line 8
    sjt_call55->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call55->_rect.x = 0;
#line 3
    sjt_call55->_rect.y = 0;
#line 4
    sjt_call55->_rect.w = 0;
#line 5
    sjt_call55->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call55->_rect);
#line 5
    sjf_flowlayout_heap(sjt_call55);
#line 90 "layout.sj"
    sjt_cast18 = sjt_call55;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_flowlayout_as_sji_element(sjt_cast18, &sjt_functionParam168);
    if (sjt_functionParam168._parent != 0) {
        sjt_functionParam168._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent144, sjt_functionParam167, sjt_functionParam168);
#line 31 "layout.sj"
    sjt_parent180 = array8;
#line 31
    sjt_functionParam241 = 4;
#line 31
    sjt_call84 = (sjs_centerlayout*)malloc(sizeof(sjs_centerlayout));
#line 31
    sjt_call84->_refCount = 1;
#line 31
    sjt_call84->children._refCount = 1;
#line 120
    sjt_call84->children.v = createarray(sizeof(sji_element), 1);
#line 120
    sjf_array_heap_iface_element(&sjt_call84->children);
#line 120
    sjs_array_heap_iface_element* array12;
#line 120
    array12 = &sjt_call84->children;
#line 120
    sjt_parent202 = array12;
#line 120
    sjt_functionParam255 = 0;
#line 120
    sjt_call89._refCount = 1;
#line 121
    sjt_call89.offset = 0;
#line 121
    sjt_call89.count = 1;
#line 121
    sjt_call89.data._refCount = 1;
#line 121
    sjt_call89.data.v = &sjg_string21;
#line 121
    sjf_array_char(&sjt_call89.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call89._isnullterminated = false;
#line 16
    sjf_string(&sjt_call89);
#line 121 "layout.sj"
    sjt_functionParam257 = &sjt_call89;
#line 121
    sjf_testelement_heap(sjt_functionParam257, &sjt_functionParam256);
#line 121
    sjf_array_heap_iface_element_initat(sjt_parent202, sjt_functionParam255, sjt_functionParam256);
#line 121
    sjt_call84->margin._refCount = 1;
#line 117
    sjt_call84->margin.l = 10;
#line 117
    sjt_call84->margin.t = 10;
#line 117
    sjt_call84->margin.r = 10;
#line 117
    sjt_call84->margin.b = 10;
#line 117
    sjf_margin(&sjt_call84->margin);
#line 118
    sjt_value8 = 0.2f;
#line 118
    sjt_call84->centerx.isvalid = true;
#line 118
    sjt_call84->centerx.value = sjt_value8;
#line 119
    sjt_value9 = 0.8f;
#line 119
    sjt_call84->centery.isvalid = true;
#line 119
    sjt_call84->centery.value = sjt_value9;
#line 119
    sjt_call84->_rect._refCount = 1;
#line 2 "lib/sj-lib-ui/rect.sj"
    sjt_call84->_rect.x = 0;
#line 3
    sjt_call84->_rect.y = 0;
#line 4
    sjt_call84->_rect.w = 0;
#line 5
    sjt_call84->_rect.h = 0;
#line 5
    sjf_rect(&sjt_call84->_rect);
#line 5
    sjf_centerlayout_heap(sjt_call84);
#line 116 "layout.sj"
    sjt_cast19 = sjt_call84;
#line 1 "lib/sj-lib-ui/element.sj"
    sjf_centerlayout_as_sji_element(sjt_cast19, &sjt_functionParam242);
    if (sjt_functionParam242._parent != 0) {
        sjt_functionParam242._parent->_refCount++;
    }

#line 1
    sjf_array_heap_iface_element_initat(sjt_parent180, sjt_functionParam241, sjt_functionParam242);
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
#line 22 "layout.sj"
    sjt_call3->cols.v = createarray(sizeof(sjs_gridunit), 3);
#line 22
    sjf_array_gridunit(&sjt_call3->cols);
#line 22
    sjs_array_gridunit* array1;
#line 22
    array1 = &sjt_call3->cols;
#line 22
    sjt_parent203 = array1;
#line 22
    sjt_functionParam258 = 0;
#line 22
    sjt_call90._refCount = 1;
#line 23
    sjt_call90.amount = 1;
#line 23
    sjt_call90.unittype = g_gridunittype_star;
#line 23
    sjf_gridunit(&sjt_call90);
#line 23
    sjt_functionParam259 = &sjt_call90;
#line 23
    sjf_array_gridunit_initat(sjt_parent203, sjt_functionParam258, sjt_functionParam259);
#line 22
    sjt_parent204 = array1;
#line 22
    sjt_functionParam260 = 1;
#line 22
    sjt_call91._refCount = 1;
#line 24
    sjt_call91.amount = 1;
#line 24
    sjt_call91.unittype = g_gridunittype_star;
#line 24
    sjf_gridunit(&sjt_call91);
#line 24
    sjt_functionParam261 = &sjt_call91;
#line 24
    sjf_array_gridunit_initat(sjt_parent204, sjt_functionParam260, sjt_functionParam261);
#line 22
    sjt_parent205 = array1;
#line 22
    sjt_functionParam262 = 2;
#line 22
    sjt_call92._refCount = 1;
#line 25
    sjt_call92.amount = 1;
#line 25
    sjt_call92.unittype = g_gridunittype_star;
#line 25
    sjf_gridunit(&sjt_call92);
#line 25
    sjt_functionParam263 = &sjt_call92;
#line 25
    sjf_array_gridunit_initat(sjt_parent205, sjt_functionParam262, sjt_functionParam263);
#line 25
    sjt_call3->rows._refCount = 1;
#line 27
    sjt_call3->rows.v = createarray(sizeof(sjs_gridunit), 2);
#line 27
    sjf_array_gridunit(&sjt_call3->rows);
#line 27
    sjs_array_gridunit* array2;
#line 27
    array2 = &sjt_call3->rows;
#line 27
    sjt_parent206 = array2;
#line 27
    sjt_functionParam264 = 0;
#line 27
    sjt_call93._refCount = 1;
#line 28
    sjt_call93.amount = 1;
#line 28
    sjt_call93.unittype = g_gridunittype_star;
#line 28
    sjf_gridunit(&sjt_call93);
#line 28
    sjt_functionParam265 = &sjt_call93;
#line 28
    sjf_array_gridunit_initat(sjt_parent206, sjt_functionParam264, sjt_functionParam265);
#line 27
    sjt_parent207 = array2;
#line 27
    sjt_functionParam266 = 1;
#line 27
    sjt_call94._refCount = 1;
#line 29
    sjt_call94.amount = 1;
#line 29
    sjt_call94.unittype = g_gridunittype_star;
#line 29
    sjf_gridunit(&sjt_call94);
#line 29
    sjt_functionParam267 = &sjt_call94;
#line 29
    sjf_array_gridunit_initat(sjt_parent207, sjt_functionParam266, sjt_functionParam267);
#line 29
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
#line 21 "layout.sj"
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
    sjt_call26->_refCount--;
    if (sjt_call26->_refCount <= 0) {
        weakptr_release(sjt_call26);
        sjf_borderlayout_destroy(sjt_call26);
        free(sjt_call26);
    }
    sjt_call3->_refCount--;
    if (sjt_call3->_refCount <= 0) {
        weakptr_release(sjt_call3);
        sjf_gridlayout_destroy(sjt_call3);
        free(sjt_call3);
    }
    sjt_call32->_refCount--;
    if (sjt_call32->_refCount <= 0) {
        weakptr_release(sjt_call32);
        sjf_borderchild_destroy(sjt_call32);
        free(sjt_call32);
    }
    sjt_call34->_refCount--;
    if (sjt_call34->_refCount <= 0) {
        weakptr_release(sjt_call34);
        sjf_borderchild_destroy(sjt_call34);
        free(sjt_call34);
    }
    sjt_call36->_refCount--;
    if (sjt_call36->_refCount <= 0) {
        weakptr_release(sjt_call36);
        sjf_borderchild_destroy(sjt_call36);
        free(sjt_call36);
    }
    sjt_call38->_refCount--;
    if (sjt_call38->_refCount <= 0) {
        weakptr_release(sjt_call38);
        sjf_borderchild_destroy(sjt_call38);
        free(sjt_call38);
    }
    sjt_call40->_refCount--;
    if (sjt_call40->_refCount <= 0) {
        weakptr_release(sjt_call40);
        sjf_borderchild_destroy(sjt_call40);
        free(sjt_call40);
    }
    sjt_call42->_refCount--;
    if (sjt_call42->_refCount <= 0) {
        weakptr_release(sjt_call42);
        sjf_listlayout_destroy(sjt_call42);
        free(sjt_call42);
    }
    sjt_call5->_refCount--;
    if (sjt_call5->_refCount <= 0) {
        weakptr_release(sjt_call5);
        sjf_gridlayout_destroy(sjt_call5);
        free(sjt_call5);
    }
    sjt_call55->_refCount--;
    if (sjt_call55->_refCount <= 0) {
        weakptr_release(sjt_call55);
        sjf_flowlayout_destroy(sjt_call55);
        free(sjt_call55);
    }
    sjt_call84->_refCount--;
    if (sjt_call84->_refCount <= 0) {
        weakptr_release(sjt_call84);
        sjf_centerlayout_destroy(sjt_call84);
        free(sjt_call84);
    }
    if (sjt_functionParam111._parent != 0) {
        sjt_functionParam111._parent->_refCount--;
        if (sjt_functionParam111._parent->_refCount <= 0) {
            sjt_functionParam111._vtbl->destroy(sjt_functionParam111._parent);
            free(sjt_functionParam111._parent);
        }
    }
    if (sjt_functionParam114._parent != 0) {
        sjt_functionParam114._parent->_refCount--;
        if (sjt_functionParam114._parent->_refCount <= 0) {
            sjt_functionParam114._vtbl->destroy(sjt_functionParam114._parent);
            free(sjt_functionParam114._parent);
        }
    }
    if (sjt_functionParam117._parent != 0) {
        sjt_functionParam117._parent->_refCount--;
        if (sjt_functionParam117._parent->_refCount <= 0) {
            sjt_functionParam117._vtbl->destroy(sjt_functionParam117._parent);
            free(sjt_functionParam117._parent);
        }
    }
    if (sjt_functionParam128._parent != 0) {
        sjt_functionParam128._parent->_refCount--;
        if (sjt_functionParam128._parent->_refCount <= 0) {
            sjt_functionParam128._vtbl->destroy(sjt_functionParam128._parent);
            free(sjt_functionParam128._parent);
        }
    }
    if (sjt_functionParam135._parent != 0) {
        sjt_functionParam135._parent->_refCount--;
        if (sjt_functionParam135._parent->_refCount <= 0) {
            sjt_functionParam135._vtbl->destroy(sjt_functionParam135._parent);
            free(sjt_functionParam135._parent);
        }
    }
    if (sjt_functionParam138._parent != 0) {
        sjt_functionParam138._parent->_refCount--;
        if (sjt_functionParam138._parent->_refCount <= 0) {
            sjt_functionParam138._vtbl->destroy(sjt_functionParam138._parent);
            free(sjt_functionParam138._parent);
        }
    }
    if (sjt_functionParam141._parent != 0) {
        sjt_functionParam141._parent->_refCount--;
        if (sjt_functionParam141._parent->_refCount <= 0) {
            sjt_functionParam141._vtbl->destroy(sjt_functionParam141._parent);
            free(sjt_functionParam141._parent);
        }
    }
    if (sjt_functionParam144._parent != 0) {
        sjt_functionParam144._parent->_refCount--;
        if (sjt_functionParam144._parent->_refCount <= 0) {
            sjt_functionParam144._vtbl->destroy(sjt_functionParam144._parent);
            free(sjt_functionParam144._parent);
        }
    }
    if (sjt_functionParam147._parent != 0) {
        sjt_functionParam147._parent->_refCount--;
        if (sjt_functionParam147._parent->_refCount <= 0) {
            sjt_functionParam147._vtbl->destroy(sjt_functionParam147._parent);
            free(sjt_functionParam147._parent);
        }
    }
    if (sjt_functionParam150._parent != 0) {
        sjt_functionParam150._parent->_refCount--;
        if (sjt_functionParam150._parent->_refCount <= 0) {
            sjt_functionParam150._vtbl->destroy(sjt_functionParam150._parent);
            free(sjt_functionParam150._parent);
        }
    }
    if (sjt_functionParam156._parent != 0) {
        sjt_functionParam156._parent->_refCount--;
        if (sjt_functionParam156._parent->_refCount <= 0) {
            sjt_functionParam156._vtbl->destroy(sjt_functionParam156._parent);
            free(sjt_functionParam156._parent);
        }
    }
    if (sjt_functionParam159._parent != 0) {
        sjt_functionParam159._parent->_refCount--;
        if (sjt_functionParam159._parent->_refCount <= 0) {
            sjt_functionParam159._vtbl->destroy(sjt_functionParam159._parent);
            free(sjt_functionParam159._parent);
        }
    }
    if (sjt_functionParam162._parent != 0) {
        sjt_functionParam162._parent->_refCount--;
        if (sjt_functionParam162._parent->_refCount <= 0) {
            sjt_functionParam162._vtbl->destroy(sjt_functionParam162._parent);
            free(sjt_functionParam162._parent);
        }
    }
    if (sjt_functionParam165._parent != 0) {
        sjt_functionParam165._parent->_refCount--;
        if (sjt_functionParam165._parent->_refCount <= 0) {
            sjt_functionParam165._vtbl->destroy(sjt_functionParam165._parent);
            free(sjt_functionParam165._parent);
        }
    }
    if (sjt_functionParam168._parent != 0) {
        sjt_functionParam168._parent->_refCount--;
        if (sjt_functionParam168._parent->_refCount <= 0) {
            sjt_functionParam168._vtbl->destroy(sjt_functionParam168._parent);
            free(sjt_functionParam168._parent);
        }
    }
    if (sjt_functionParam182._parent != 0) {
        sjt_functionParam182._parent->_refCount--;
        if (sjt_functionParam182._parent->_refCount <= 0) {
            sjt_functionParam182._vtbl->destroy(sjt_functionParam182._parent);
            free(sjt_functionParam182._parent);
        }
    }
    if (sjt_functionParam185._parent != 0) {
        sjt_functionParam185._parent->_refCount--;
        if (sjt_functionParam185._parent->_refCount <= 0) {
            sjt_functionParam185._vtbl->destroy(sjt_functionParam185._parent);
            free(sjt_functionParam185._parent);
        }
    }
    if (sjt_functionParam188._parent != 0) {
        sjt_functionParam188._parent->_refCount--;
        if (sjt_functionParam188._parent->_refCount <= 0) {
            sjt_functionParam188._vtbl->destroy(sjt_functionParam188._parent);
            free(sjt_functionParam188._parent);
        }
    }
    if (sjt_functionParam191._parent != 0) {
        sjt_functionParam191._parent->_refCount--;
        if (sjt_functionParam191._parent->_refCount <= 0) {
            sjt_functionParam191._vtbl->destroy(sjt_functionParam191._parent);
            free(sjt_functionParam191._parent);
        }
    }
    if (sjt_functionParam194._parent != 0) {
        sjt_functionParam194._parent->_refCount--;
        if (sjt_functionParam194._parent->_refCount <= 0) {
            sjt_functionParam194._vtbl->destroy(sjt_functionParam194._parent);
            free(sjt_functionParam194._parent);
        }
    }
    if (sjt_functionParam197._parent != 0) {
        sjt_functionParam197._parent->_refCount--;
        if (sjt_functionParam197._parent->_refCount <= 0) {
            sjt_functionParam197._vtbl->destroy(sjt_functionParam197._parent);
            free(sjt_functionParam197._parent);
        }
    }
    if (sjt_functionParam200._parent != 0) {
        sjt_functionParam200._parent->_refCount--;
        if (sjt_functionParam200._parent->_refCount <= 0) {
            sjt_functionParam200._vtbl->destroy(sjt_functionParam200._parent);
            free(sjt_functionParam200._parent);
        }
    }
    if (sjt_functionParam203._parent != 0) {
        sjt_functionParam203._parent->_refCount--;
        if (sjt_functionParam203._parent->_refCount <= 0) {
            sjt_functionParam203._vtbl->destroy(sjt_functionParam203._parent);
            free(sjt_functionParam203._parent);
        }
    }
    if (sjt_functionParam206._parent != 0) {
        sjt_functionParam206._parent->_refCount--;
        if (sjt_functionParam206._parent->_refCount <= 0) {
            sjt_functionParam206._vtbl->destroy(sjt_functionParam206._parent);
            free(sjt_functionParam206._parent);
        }
    }
    if (sjt_functionParam209._parent != 0) {
        sjt_functionParam209._parent->_refCount--;
        if (sjt_functionParam209._parent->_refCount <= 0) {
            sjt_functionParam209._vtbl->destroy(sjt_functionParam209._parent);
            free(sjt_functionParam209._parent);
        }
    }
    if (sjt_functionParam212._parent != 0) {
        sjt_functionParam212._parent->_refCount--;
        if (sjt_functionParam212._parent->_refCount <= 0) {
            sjt_functionParam212._vtbl->destroy(sjt_functionParam212._parent);
            free(sjt_functionParam212._parent);
        }
    }
    if (sjt_functionParam215._parent != 0) {
        sjt_functionParam215._parent->_refCount--;
        if (sjt_functionParam215._parent->_refCount <= 0) {
            sjt_functionParam215._vtbl->destroy(sjt_functionParam215._parent);
            free(sjt_functionParam215._parent);
        }
    }
    if (sjt_functionParam218._parent != 0) {
        sjt_functionParam218._parent->_refCount--;
        if (sjt_functionParam218._parent->_refCount <= 0) {
            sjt_functionParam218._vtbl->destroy(sjt_functionParam218._parent);
            free(sjt_functionParam218._parent);
        }
    }
    if (sjt_functionParam221._parent != 0) {
        sjt_functionParam221._parent->_refCount--;
        if (sjt_functionParam221._parent->_refCount <= 0) {
            sjt_functionParam221._vtbl->destroy(sjt_functionParam221._parent);
            free(sjt_functionParam221._parent);
        }
    }
    if (sjt_functionParam224._parent != 0) {
        sjt_functionParam224._parent->_refCount--;
        if (sjt_functionParam224._parent->_refCount <= 0) {
            sjt_functionParam224._vtbl->destroy(sjt_functionParam224._parent);
            free(sjt_functionParam224._parent);
        }
    }
    if (sjt_functionParam227._parent != 0) {
        sjt_functionParam227._parent->_refCount--;
        if (sjt_functionParam227._parent->_refCount <= 0) {
            sjt_functionParam227._vtbl->destroy(sjt_functionParam227._parent);
            free(sjt_functionParam227._parent);
        }
    }
    if (sjt_functionParam230._parent != 0) {
        sjt_functionParam230._parent->_refCount--;
        if (sjt_functionParam230._parent->_refCount <= 0) {
            sjt_functionParam230._vtbl->destroy(sjt_functionParam230._parent);
            free(sjt_functionParam230._parent);
        }
    }
    if (sjt_functionParam233._parent != 0) {
        sjt_functionParam233._parent->_refCount--;
        if (sjt_functionParam233._parent->_refCount <= 0) {
            sjt_functionParam233._vtbl->destroy(sjt_functionParam233._parent);
            free(sjt_functionParam233._parent);
        }
    }
    if (sjt_functionParam236._parent != 0) {
        sjt_functionParam236._parent->_refCount--;
        if (sjt_functionParam236._parent->_refCount <= 0) {
            sjt_functionParam236._vtbl->destroy(sjt_functionParam236._parent);
            free(sjt_functionParam236._parent);
        }
    }
    if (sjt_functionParam239._parent != 0) {
        sjt_functionParam239._parent->_refCount--;
        if (sjt_functionParam239._parent->_refCount <= 0) {
            sjt_functionParam239._vtbl->destroy(sjt_functionParam239._parent);
            free(sjt_functionParam239._parent);
        }
    }
    if (sjt_functionParam242._parent != 0) {
        sjt_functionParam242._parent->_refCount--;
        if (sjt_functionParam242._parent->_refCount <= 0) {
            sjt_functionParam242._vtbl->destroy(sjt_functionParam242._parent);
            free(sjt_functionParam242._parent);
        }
    }
    if (sjt_functionParam256._parent != 0) {
        sjt_functionParam256._parent->_refCount--;
        if (sjt_functionParam256._parent->_refCount <= 0) {
            sjt_functionParam256._vtbl->destroy(sjt_functionParam256._parent);
            free(sjt_functionParam256._parent);
        }
    }
    if (sjt_functionParam46._parent != 0) {
        sjt_functionParam46._parent->_refCount--;
        if (sjt_functionParam46._parent->_refCount <= 0) {
            sjt_functionParam46._vtbl->destroy(sjt_functionParam46._parent);
            free(sjt_functionParam46._parent);
        }
    }
    if (sjt_functionParam48._parent != 0) {
        sjt_functionParam48._parent->_refCount--;
        if (sjt_functionParam48._parent->_refCount <= 0) {
            sjt_functionParam48._vtbl->destroy(sjt_functionParam48._parent);
            free(sjt_functionParam48._parent);
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
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
;
    if (sjt_call22._refCount == 1) { sjf_gridunit_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_gridunit_destroy(&sjt_call23); }
;
    if (sjt_call24._refCount == 1) { sjf_gridunit_destroy(&sjt_call24); }
;
    if (sjt_call25._refCount == 1) { sjf_gridunit_destroy(&sjt_call25); }
;
    if (sjt_call33._refCount == 1) { sjf_string_destroy(&sjt_call33); }
;
    if (sjt_call35._refCount == 1) { sjf_string_destroy(&sjt_call35); }
;
    if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
;
    if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
;
    if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
;
    if (sjt_call51._refCount == 1) { sjf_string_destroy(&sjt_call51); }
;
    if (sjt_call52._refCount == 1) { sjf_string_destroy(&sjt_call52); }
;
    if (sjt_call53._refCount == 1) { sjf_string_destroy(&sjt_call53); }
;
    if (sjt_call54._refCount == 1) { sjf_string_destroy(&sjt_call54); }
;
    if (sjt_call64._refCount == 1) { sjf_string_destroy(&sjt_call64); }
;
    if (sjt_call65._refCount == 1) { sjf_string_destroy(&sjt_call65); }
;
    if (sjt_call66._refCount == 1) { sjf_string_destroy(&sjt_call66); }
;
    if (sjt_call67._refCount == 1) { sjf_string_destroy(&sjt_call67); }
;
    if (sjt_call68._refCount == 1) { sjf_string_destroy(&sjt_call68); }
;
    if (sjt_call69._refCount == 1) { sjf_string_destroy(&sjt_call69); }
;
    if (sjt_call70._refCount == 1) { sjf_string_destroy(&sjt_call70); }
;
    if (sjt_call71._refCount == 1) { sjf_string_destroy(&sjt_call71); }
;
    if (sjt_call72._refCount == 1) { sjf_string_destroy(&sjt_call72); }
;
    if (sjt_call73._refCount == 1) { sjf_string_destroy(&sjt_call73); }
;
    if (sjt_call74._refCount == 1) { sjf_string_destroy(&sjt_call74); }
;
    if (sjt_call75._refCount == 1) { sjf_string_destroy(&sjt_call75); }
;
    if (sjt_call76._refCount == 1) { sjf_string_destroy(&sjt_call76); }
;
    if (sjt_call77._refCount == 1) { sjf_string_destroy(&sjt_call77); }
;
    if (sjt_call78._refCount == 1) { sjf_string_destroy(&sjt_call78); }
;
    if (sjt_call79._refCount == 1) { sjf_string_destroy(&sjt_call79); }
;
    if (sjt_call80._refCount == 1) { sjf_string_destroy(&sjt_call80); }
;
    if (sjt_call81._refCount == 1) { sjf_string_destroy(&sjt_call81); }
;
    if (sjt_call82._refCount == 1) { sjf_string_destroy(&sjt_call82); }
;
    if (sjt_call83._refCount == 1) { sjf_string_destroy(&sjt_call83); }
;
    if (sjt_call89._refCount == 1) { sjf_string_destroy(&sjt_call89); }
;
    if (sjt_call90._refCount == 1) { sjf_gridunit_destroy(&sjt_call90); }
;
    if (sjt_call91._refCount == 1) { sjf_gridunit_destroy(&sjt_call91); }
;
    if (sjt_call92._refCount == 1) { sjf_gridunit_destroy(&sjt_call92); }
;
    if (sjt_call93._refCount == 1) { sjf_gridunit_destroy(&sjt_call93); }
;
    if (sjt_call94._refCount == 1) { sjf_gridunit_destroy(&sjt_call94); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
