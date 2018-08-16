// Required Include files
#include "video/video.h"

// Global variable pointing to the present memory used as back buffer
// (Changes on every call to switchBuffers).
u8* video_buffer;

u8 offset_x;
u8 offset_y;
u8 viewport_x;
u8 viewport_y;

const u8 width_map;
const u8 height_map;



////////////////////////////////////////////////////////////////////////////////////
// GET BACK BUFFER POINTER
// Returns a pointer to the start of the current memory used as hardware 
// back buffer. There it is safe to draw anything, as it will not be displayed 
// until a call to switchBuffers is performed.
//
u8* video_getBackBufferPtr(){
    return video_buffer;
}

////////////////////////////////////////////////////////////////////////////////////
// SWITCH VIDEO BUFFERS
// Sets the contents of current hardware backbuffer to be displayed as main 
// screen immediately (after next VSYNC), also shadowing current displayed screen,
// that will be considered next hardware backbuffer.
//
void video_switchBuffers(){

    // Check were the current backbuffer is pointing and switch buffers
    // accordingly (if video_buffer points to our default HW_BACKBUFFER,
    // make it point to default VMEM_START, else make it point to HW_BACKBUFFER)
    // and also change CRTC Register R13 (current video memory page) accordingly
    if (video_buffer == HW_BACKBUFFER) {
        // Current Backbuffer is at 0x8000. Make that part of memory
        // displayed changing CRTC Register 13, then point to VMEM_START.
        cpct_setVideoMemoryPage(cpct_page80);
        video_buffer = CPCT_VMEM_START;
    }
    else {
        // Current Backbuffer is at 0xC000. Make that part of memory
        // displayed changing CRTC Register 13, then point to HW_BACKBUFFER.
        cpct_setVideoMemoryPage(cpct_pageC0);
        video_buffer = HW_BACKBUFFER;
    }
}

////////////////////////////////////////////////////////////////////////////////////
// INITIALIZE VIDEO BUFFERS
// Ensures initial conditions for both video buffers to be used.
//
void video_initBuffers(){
    // Hardware backbuffer has to be cleared as it usually has code in it that
    // would be displayed as coloured pixels if not set to 0.
    video_switchBuffers();
    cpct_memset(CPCT_VMEM_START, 240, 0x4000);  // 16K HW_BACKBUFFER set to 0
    video_switchBuffers();
    cpct_memset(HW_BACKBUFFER, 240, 0x4000);  // 16K HW_BACKBUFFER set to 0
    // First call to video Switch Buffers will initialize video_buffer global
    // variable containing a pointer to the current hardware backbuffer.
    // This call will also set CRTC registers that will left video_buffer 
    // undisplayed and the other buffer displayed.
}

void video_resetScreenPtr(){
    cpct_setVideoMemoryPage(cpct_pageC0);
    video_buffer = HW_BACKBUFFER;
}

bool video_isInsideViewport(u8 entity_x, u8 entity_y, u8 entity_width, u8 entity_height){
    if (entity_x >= viewport_x && entity_x + entity_width <= viewport_x + VIEWPORT_WIDTH){
        if (entity_y >= viewport_y + SCREEN_HEIGHT-VIEWPORT_HEIGHT && entity_y + entity_height <= viewport_y + VIEWPORT_HEIGHT + SCREEN_HEIGHT-VIEWPORT_HEIGHT){

            return true;
        }
    }
    return false;
}
