#ifndef __CORETYPES_H__
#define __CORETYPES_H__

#include <stdint.h>
#include <stdio.h>
<<<<<<< HEAD
#include <retro_inline.h>
=======

>>>>>>> d57e9f7 (git subrepo clone (merge) https://github.com/rtissera/libchdr deps/libchdr)
#ifdef USE_LIBRETRO_VFS
#include <streams/file_stream_transforms.h>
#endif

#ifndef ARRAY_LENGTH
#define ARRAY_LENGTH(x) (sizeof(x)/sizeof(x[0]))
#endif

<<<<<<< HEAD
=======
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#endif

>>>>>>> d57e9f7 (git subrepo clone (merge) https://github.com/rtissera/libchdr deps/libchdr)
typedef struct chd_core_file {
	/*
	 * arbitrary pointer to data the implementation uses to implement the below functions
	 */
	void *argp;

	/*
	 * return the size of a given file as a 64-bit unsigned integer.
	 * the position of the file pointer after calling this function is
	 * undefined because many implementations will seek to the end of the
	 * file and call ftell.
	 *
	 * on error, (uint64_t)-1 is returned.
	 */
	uint64_t(*fsize)(struct chd_core_file*);

	/*
	 * should match the behavior of fread, except the FILE* argument at the end
	 * will be replaced with a struct chd_core_file*.
	 */
	size_t(*fread)(void*,size_t,size_t,struct chd_core_file*);

<<<<<<< HEAD
	/* closes the given file. */
	int (*fclose)(struct chd_core_file*);

	/* fseek clone */
	int (*fseek)(struct chd_core_file*, int64_t, int);
} core_file;

static INLINE int core_fclose(core_file *fp) {
	return fp->fclose(fp);
}

static INLINE size_t core_fread(core_file *fp, void *ptr, size_t len) {
	return fp->fread(ptr, 1, len, fp);
}

static INLINE int core_fseek(core_file* fp, int64_t offset, int whence) {
	return fp->fseek(fp, offset, whence);
}

static INLINE uint64_t core_fsize(core_file *fp)
=======
	// closes the given file.
	int (*fclose)(struct chd_core_file*);

	// fseek clone
	int (*fseek)(struct chd_core_file*, int64_t, int);
} core_file;

static inline int core_fclose(core_file *fp) {
	return fp->fclose(fp);
}

static inline size_t core_fread(core_file *fp, void *ptr, size_t len) {
	return fp->fread(ptr, 1, len, fp);
}

static inline int core_fseek(core_file* fp, int64_t offset, int whence) {
	return fp->fseek(fp, offset, whence);
}

static inline uint64_t core_fsize(core_file *fp)
>>>>>>> d57e9f7 (git subrepo clone (merge) https://github.com/rtissera/libchdr deps/libchdr)
{
	return fp->fsize(fp);
}

#endif
