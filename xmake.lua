add_rules("mode.debug", "mode.release")
add_requires("cosmocc")
add_packages("cosmocc")
set_toolchains("@cosmocc")

add_includedirs("./jsoncpp/dist")
add_includedirs("./cryptopp")



target("ZIT_NetworkAutoConnector.com")

    before_build(function (target) 
        --compile libs
        -- local cosmocxx=path.join(target:pkg("cosmocc"):installdir(),"bin","cosmoc++")
        local cosmocxx_x64=path.join(target:pkg("cosmocc"):installdir(),"bin","x86_64-unknown-cosmo-c++")
        local cosmocxx_a64=path.join(target:pkg("cosmocc"):installdir(),"bin","aarch64-unknown-cosmo-c++")
        local apelink=path.join(target:pkg("cosmocc"):installdir(),"bin","apelink")
        os.execv("./compile_cryptopp.sh", {cosmocxx_x64,"amd64"},{shell=true})
        os.execv("./compile_cryptopp.sh", {cosmocxx_a64,"arm64"},{shell=true})


    end)



    set_kind("binary")
    add_files("**.cpp","jsoncpp/dist/jsoncpp.cpp")
    -- add_files("**.cpp","jsoncpp/dist/jsoncpp.cpp","cryptopp/build/libcryptopp.a")





-- target("botan")
--     set_kind("static")




--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

