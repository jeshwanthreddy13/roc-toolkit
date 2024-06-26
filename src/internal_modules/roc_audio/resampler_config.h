/*
 * Copyright (c) 2020 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

//! @file roc_audio/resampler_config.h
//! @brief Resampler config.

#ifndef ROC_AUDIO_RESAMPLER_CONFIG_H_
#define ROC_AUDIO_RESAMPLER_CONFIG_H_

#include "roc_audio/latency_tuner.h"

namespace roc {
namespace audio {

//! Resampler backends.
enum ResamplerBackend {
    //! Default backend.
    //! Resolved to one of other backends, depending on what
    //! is enabled at build time.
    ResamplerBackend_Default,

    //! Built-in resampler.
    //! High precision, high quality, slow.
    ResamplerBackend_Builtin,

    //! SpeexDSP resampler.
    //! Low precision, high quality, fast.
    //! May be disabled at build time.
    ResamplerBackend_Speex,

    //! Combined SpeexDSP + decimating resampler.
    //! Tolerable precision, tolerable quality, fast.
    //! May be disabled at build time.
    ResamplerBackend_SpeexDec
};

//! Resampler parameters presets.
enum ResamplerProfile {
    //! Low quality, fast speed.
    ResamplerProfile_Low,

    //! Medium quality, medium speed.
    ResamplerProfile_Medium,

    //! High quality, low speed.
    ResamplerProfile_High
};

//! Resampler config.
struct ResamplerConfig {
    //! Resampler backend.
    ResamplerBackend backend;

    //! Resampler profile.
    ResamplerProfile profile;

    ResamplerConfig()
        : backend(ResamplerBackend_Default)
        , profile(ResamplerProfile_Medium) {
    }

    //! Automatically fill missing settings.
    void deduce_defaults(LatencyTunerBackend latency_backend,
                         LatencyTunerProfile latency_tuner);
};

//! Get string name of resampler backend.
const char* resampler_backend_to_str(ResamplerBackend backend);

//! Get string name of resampler profile.
const char* resampler_profile_to_str(ResamplerProfile profile);

} // namespace audio
} // namespace roc

#endif // ROC_AUDIO_RESAMPLER_CONFIG_H_
