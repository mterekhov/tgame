#import "ARenderView.h"

//==============================================================================

@implementation ARenderView

//==============================================================================

- (id)initWithFrame:(NSRect)frame pixelFormat:(NSOpenGLPixelFormat*)format
{
    
    self = [super initWithFrame:frame pixelFormat:format];
    if (self == nil)
        return nil;

	NSOpenGLContext* viewContext = [[NSOpenGLContext alloc] initWithFormat: format
                                                              shareContext: nil];
    [viewContext setView: self];
    [self setOpenGLContext: viewContext];
    [viewContext makeCurrentContext];

    [self initGL];
    return self;
}

//==============================================================================

- (void) initGL {
	glClearColor(0.0, 1.0, 0.0, 0.0); // Clear background color to black
	glShadeModel(GL_SMOOTH); // Type of shading for the polygons
	
	// Viewport transformation
    glViewport(0, 0, self.bounds.size.width, self.bounds.size.height);
	
    // Projection transformation
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-self.bounds.size.width, self.bounds.size.width, -self.bounds.size.height, self.bounds.size.height, 0.1f, 10000.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	// We enable the depth test (also called z buffer)
    glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	
	//Other initializations
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE); // Enable the back face culling	
}

- (void)drawRect:(NSRect)dirtyRect
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // This clear the background color to dark blue
	
//	glLoadMatrixf(&camera.matrix[0][0]); // At first we load the camera matrix
//	
//	glLightfv (GL_LIGHT1, GL_POSITION, light_position); // We don't want to move the light with the camera so we set again the light position after the camera transformation
//	
//    for (i = 0; i < obj_qty; i++)
//	{
//		glPushMatrix(); // We save the current matrix
//		
//		glMultMatrixf(&object[i].matrix[0][0]); // Now let's multiply the object matrix by the camera matrix
//		
//		if (object[i].id_texture != -1)
//		{
//			glBindTexture(GL_TEXTURE_2D, object[i].id_texture); // We set the active texture
//		    glEnable(GL_TEXTURE_2D); // Texture mapping ON
//		}
//		else
//		    glDisable(GL_TEXTURE_2D); // Texture mapping OFF
//		
//		glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
//		for (j = 0; j < object[i].polygons_qty; j++)
//		{
//			//----------------- FIRST VERTEX -----------------
//			//Normal coordinates of the first vertex
//			glNormal3f( object[i].normal[ object[i].polygon[j].a ].x,
//					   object[i].normal[ object[i].polygon[j].a ].y,
//					   object[i].normal[ object[i].polygon[j].a ].z);
//			// Texture coordinates of the first vertex
//			glTexCoord2f( object[i].mapcoord[ object[i].polygon[j].a ].u,
//						 object[i].mapcoord[ object[i].polygon[j].a ].v);
//			// Coordinates of the first vertex
//			glVertex3f( object[i].vertex[ object[i].polygon[j].a ].x,
//					   object[i].vertex[ object[i].polygon[j].a ].y,
//					   object[i].vertex[ object[i].polygon[j].a ].z);
//			
//			//----------------- SECOND VERTEX -----------------
//			//Normal coordinates of the second vertex
//			glNormal3f( object[i].normal[ object[i].polygon[j].b ].x,
//					   object[i].normal[ object[i].polygon[j].b ].y,
//					   object[i].normal[ object[i].polygon[j].b ].z);
//			// Texture coordinates of the second vertex
//			glTexCoord2f( object[i].mapcoord[ object[i].polygon[j].b ].u,
//						 object[i].mapcoord[ object[i].polygon[j].b ].v);
//			// Coordinates of the second vertex
//			glVertex3f( object[i].vertex[ object[i].polygon[j].b ].x,
//					   object[i].vertex[ object[i].polygon[j].b ].y,
//					   object[i].vertex[ object[i].polygon[j].b ].z);
//			
//			//----------------- THIRD VERTEX -----------------
//			//Normal coordinates of the third vertex
//			glNormal3f( object[i].normal[ object[i].polygon[j].c ].x,
//					   object[i].normal[ object[i].polygon[j].c ].y,
//					   object[i].normal[ object[i].polygon[j].c ].z);
//			// Texture coordinates of the third vertex
//			glTexCoord2f( object[i].mapcoord[ object[i].polygon[j].c ].u,
//						 object[i].mapcoord[ object[i].polygon[j].c ].v);
//			// Coordinates of the Third vertex
//			glVertex3f( object[i].vertex[ object[i].polygon[j].c ].x,
//					   object[i].vertex[ object[i].polygon[j].c ].y,
//					   object[i].vertex[ object[i].polygon[j].c ].z);
//		}
//		glEnd();
//		glPopMatrix(); // Restore the previous matrix
//	}
	
	[[NSOpenGLContext currentContext] flushBuffer];
}

//==============================================================================

@end
