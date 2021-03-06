/*************************************************************************/
/*  performance.h                                                        */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include "object.h"

#define PERF_WARN_OFFLINE_FUNCTION
#define PERF_WARN_PROCESS_SYNC


class Performance : public Object {

	OBJ_TYPE(Performance,Object);

	static Performance *singleton;
	static void _bind_methods();

	float _process_time;
	float _fixed_process_time;
public:

	enum Monitor {

		TIME_FPS,
		TIME_PROCESS,
		TIME_FIXED_PROCESS,
		MEMORY_STATIC,
		MEMORY_DYNAMIC,
		MEMORY_STATIC_MAX,
		MEMORY_DYNAMIC_MAX,
		MEMORY_MESSAGE_BUFFER_MAX,
		OBJECT_COUNT,
		OBJECT_RESOURCE_COUNT,
		OBJECT_NODE_COUNT,
		RENDER_OBJECTS_IN_FRAME,
		RENDER_VERTICES_IN_FRAME,
		RENDER_MATERIAL_CHANGES_IN_FRAME,
		RENDER_SHADER_CHANGES_IN_FRAME,
		RENDER_SURFACE_CHANGES_IN_FRAME,
		RENDER_DRAW_CALLS_IN_FRAME,
		RENDER_VIDEO_MEM_USED,
		RENDER_TEXTURE_MEM_USED,
		RENDER_VERTEX_MEM_USED,
		RENDER_USAGE_VIDEO_MEM_TOTAL,
		//physics
		MONITOR_MAX
	};


	float get_monitor(Monitor p_monitor) const;
	String get_monitor_name(Monitor p_monitor) const;

	void set_process_time(float p_pt);
	void set_fixed_process_time(float p_pt);

	static Performance *get_singleton() { return singleton; }

	Performance();

};

VARIANT_ENUM_CAST( Performance::Monitor );


#endif // PERFORMANCE_H
