#include <stdbool.h>
#include <string.h>
#include <vips/vips.h>

int main(int argc, char **argv) {
	if(vips_init(argv[0] )) {
		return -2;
	}

	VipsImage* inputImage;
	if (argc == 2) {
		inputImage = vips_image_new_from_file(argv[1], NULL);
		if (inputImage == NULL){
			printf("Unable to load input image.\n");
			return 1;
		} else {
			printf("Successfully loaded the image.\n");
		}
	} else {
		printf("You need to provide the filename location as second command line parameter.\n");
	}

	if (vips_tiffsave( 	inputImage,
				strcat(argv[1], "_multires.tiff"),
				"pyramid",
				true,
				"tile",
				true,
				"compression",
				VIPS_FOREIGN_TIFF_COMPRESSION_LZW,
				"bigtiff",
				true,
				NULL ) != 0
	) {
		printf("Failed to save the pyramidal tiff image\n");
	}

	g_object_unref(inputImage);
	vips_shutdown();

	printf("VIPS works!!!\n");
    	return 0;
}
